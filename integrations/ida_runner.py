# This function should run in the context of Ida Pro and outside of Ida Pro
# Outside of Ida it should let access to magic numbers, calling to some of
# the functions in here should not be possible
# DO NOT RUN IT FROM A REMOTE PC - IT IS NOT SECURE (CAN LEAD TO RCE)

import sys
import os
import sark
import zlib
import binascii

if __name__ == "__main__" or sark.is_in_ida():
    # Add to the path the root directory of this project so it will be plausible to import from them files
    cwd = os.path.dirname(os.path.dirname(__file__))
    sys.path.append(cwd)

import collections
import os
import struct
import rpyc.utils.server
import rpyc.core.service
import threading
import time
import pickle
import functools

import core.exceptions

if sark.is_in_ida():
    # ida imports
    # noinspection PyUnresolvedReferences
    import sark
    # noinspection PyUnresolvedReferences
    import idautils
    # noinspection PyUnresolvedReferences
    import idc
    # noinspection PyUnresolvedReferences
    import ida_auto
    # noinspection PyUnresolvedReferences
    import idaapi
    # noinspection PyUnresolvedReferences
    import FIDL
    # noinspection PyUnresolvedReferences
    import FIDL.decompiler_utils
    # noinspection PyUnresolvedReferences
    import ida_hexrays
    # noinspection PyUnresolvedReferences
    import ida_name
    # noinspection PyUnresolvedReferences
    import integrations.rpc_dump
    # noinspection PyUnresolvedReferences
    import ida_pro
    # noinspection PyUnresolvedReferences
    import ida_bytes

    # It needs to be inside this if in order to prevent the main program to import that file and fail for not finding
    # FIDL library.
    class MyControlFlowinator(FIDL.decompiler_utils.controlFlowinator):
        def __init__(self, ea=None, fast=True):
            self.cf = self.my_decompile(ea=ea)

            if not self.cf:
                raise core.exceptions.FailedToDecompile("controlFlowinator: failed to decompile because cf is None",
                                                        idaapi.get_root_filename(), ea)

            self.ea = self.cf.entry_ea
            self.fast = fast
            self.g = None

            # Information about local variables within this function
            # This is a dict of `my_var_t` objects
            self.lvars = None

            # Information about _this_ function arguments
            # This is a dict of `my_var_t` objects
            self.args = None

            # The return type of this function
            self.ret_type = None

            # A map of graph nodes and their indexes
            self.index2node = {}

            # Convenient to ve the reverse mapping
            self.node2index = {}

            # Superblock is the root
            superblock = self.cf.body.cblock
            self.i_cfg = self._get_root_cfg(superblock)
            blocks = self._get_blocks_to_expand(superblock)

            # Interim CFG of citem_t indexes
            # It is easier to create the initial graph
            # using indexes as nodes but convoluted to use
            self._generate_i_cfg(blocks_to_expand=blocks)

            # A `nx.Digraph` of `cinsn_t` or `cexpr_t`
            # It is easier to operate on this one,
            # it reduces API complexity
            self._generate_better_cfg()

            # =============================================================
            # The hybrid-CFG is ready now. We add some (optional) features
            # to this object, since they're useful in most cases
            # =============================================================

            # Information about calls within this function
            # This is a list of `callObj` objects
            self.calls = []

            # Retrieves a list of `callObj's`
            self._get_all_function_calls()

            if not fast:
                self.lvars = FIDL.decompiler_utils.get_function_vars(c=self, only_locals=True)
                self.args = FIDL.decompiler_utils.get_function_vars(c=self, only_args=True)
                self.ret_type = FIDL.decompiler_utils.get_return_type(cf=self.cf)

        def my_decompile(self, ea=None):
            """This sets flags necessary to use this programmatically.
            :param ea: Address within the function to decompile
            :type ea: int
            :return: decompilation object
            :rtype: a :class:`cfunc_t`
            """

            if not ea:
                print("Please specify an address (ea)")
                return None

            try:
                cf = None
                for i in range(2):  # 2 retries
                    cf = ida_hexrays.decompile(ea=ea)
                    if cf is not None:
                        break

                if cf is None:
                    raise core.exceptions.FailedToDecompile("because ida_hexrays.decompile is None",
                                                            idaapi.get_root_filename(), ea)

                cf.refresh_func_ctext()
            except ida_hexrays.DecompilationFailure as e:
                print("Failed to decompile @ {:X}".format(ea))
                cf = None

            return cf

ENV_PORT_NAME = "IDA_PRO_PORT"
ENV_PROCESS_UUID = "PROCESS_UUID"
PROCESS_UUID = None
IS_CONNECTED = False
MAX_WAIT_TIMEOUT = 50
IMPORTED_FUNCTIONS = None
IS_USE_BY_CFG = True
MAX_SIZE_VTABLE = 100
ERROR_ADDR = 0xffffffffffffffff
IS_ENABLED_AUTO_ANALYSIS = False


def pack_data(is_compressed=False):
    def called(func_addr):
        @functools.wraps(func_addr)
        def abcd(*args, **kwargs):
            ret_val = func_addr(*args, **kwargs)
            packed = pickle.dumps(ret_val)
            if is_compressed:
                return zlib.compress(packed, level=-1)
            else:
                return packed

        return abcd

    return called


# to disable static inspections
# noinspection PyMethodMayBeStatic
class IdaProService(rpyc.core.service.SlaveService):
    # The first function you need to execute is exposed_get_ready
    # to wait for ida auto analysis to finish.

    def exposed_wait_finish_loading(self):
        global IS_CONNECTED
        global IS_ENABLED_AUTO_ANALYSIS
        IS_CONNECTED = True
        if not IS_ENABLED_AUTO_ANALYSIS:
            IS_ENABLED_AUTO_ANALYSIS = True
            ida_auto.enable_auto(True)

        return ida_auto.auto_wait()

    #  This function don't work for me, auto_is_ok always returns False
    # def exposed_is_finish_loading(self):
    #     global IS_CONNECTED
    #     IS_CONNECTED = True
    #     return ida_auto.auto_is_ok()

    def exposed_get_uuid(self):
        global IS_CONNECTED
        IS_CONNECTED = True
        return PROCESS_UUID

    def exposed_get_functions_addr(self, index, max_list, minimal_number_opcodes_per_function):
        """
        Get list of all the function addresses in the PE
        because the output is limited - we split it to chunks
        :param index: index of the chunk, start with 0
        :param max_list: max amount of function addresses
        :param minimal_number_opcodes_per_function: minimal amount of opcodes in the functions, less
                                                    than that we ignore the function
        :return: list off all the addresses of the functions
        """
        all_function_addr = list(idautils.Functions())  # TODO: do we want to include idc.FUNC_LIB
        start_index = index * max_list
        if minimal_number_opcodes_per_function <= 1:
            all_matched_addr = all_function_addr
        else:
            all_matched_addr = []
            for addr in all_function_addr:
                number_of_opcodes = self.exposed_get_number_of_opcodes_in_function(addr)
                if number_of_opcodes > minimal_number_opcodes_per_function:
                    all_matched_addr.append(addr)

        return tuple(all_matched_addr[start_index: start_index + max_list])

    @pack_data()
    def exposed_get_amount_of_logical_blocks_in_func(self, func_addr):
        if IS_USE_BY_CFG:
            control_flow = MyControlFlowinator(func_addr, fast=False)
        else:
            control_flow = FIDL.decompiler_utils.controlFlowinator(func_addr, fast=False)
        types_of_blocks = control_flow.g.nodes()
        opnames = [i.opname for i in types_of_blocks]
        counters = collections.Counter(opnames)
        return counters

    def exposed_get_amount_of_graph_blocks_in_func(self, func_addr):
        """
        Calculate amount of basic blocks in the function
        :param func_addr: function address
        :return: amount of blocks in the function
        """
        if func_addr == ERROR_ADDR:
            return []

        func = idaapi.get_func(func_addr)
        g = idaapi.FlowChart(func)
        nodes = 0
        for x in g:
            if x.start_ea == ERROR_ADDR:
                print(f"x.start_ea is {x.start_ea} have invalid address, ignoring")
                nodes += 1
                continue
            raw_block = sark.CodeBlock(x.start_ea)
            is_valuable_block = False
            for line in raw_block.lines:
                opcode_name = idc.print_insn_mnem(line.ea)
                is_depends_on_register = any([l.type.is_reg for l in line.insn.operands])
                if opcode_name.lower() == "jmp" and not is_depends_on_register:  # constant jump
                    continue
                if opcode_name.lower() == "nop":
                    continue
                else:
                    is_valuable_block = True

            if is_valuable_block:
                nodes += 1

        return nodes

    def exposed_get_arguments_called_functions(self, func_addr):
        """
        Get all the called functions from the func_addr with the arguments they're getting
        :param func_addr: address of the function
        :return:
        """
        if IS_USE_BY_CFG:
            cfg_obj = MyControlFlowinator(func_addr, fast=False)
        else:
            cfg_obj = FIDL.decompiler_utils.controlFlowinator(func_addr, fast=False)

        called_functions = {}
        for call in cfg_obj.calls:
            call_function = {"ea": call.ea,  # address the function was called (the call itself)
                             "call_ea": call.call_ea,  # address of the called function
                             "name": call.name,
                             "ret_type_name": str(call.ret_type),
                             "args": []}
            cur_index = 0
            for index, arg in call.args.items():
                if cur_index != index:
                    raise NotImplementedError("not implemented")

                serialization_specific_argument = {}
                if hasattr(arg, "type"):
                    serialization_specific_argument.update({"type_param": str(arg.type)})
                if hasattr(arg, "val"):
                    value = arg.val
                    if type(value) == FIDL.decompiler_utils.my_var_t:  # it means it is not a constant fixed value.
                        serialization_specific_argument.update(
                            {"type_name": str(value.type_name), "bytes_size": value.size,
                             })
                    elif type(value) == ida_hexrays.cexpr_t:  # expression.
                        if len(value.operands) == 1:
                            constant_val = list(value.operands.values())[0]
                            if type(constant_val) is not str and type(constant_val) is not int:
                                # TODO: add support with ida_hexrays.var_ref_t
                                serialization_specific_argument.update({"unknown_type": str(type(constant_val)),
                                                                        "unknown_value": str(constant_val)})
                            else:
                                serialization_specific_argument.update({"val": str(constant_val)})
                    elif type(value) == ida_hexrays.carg_t:
                        pass
                    else:  # a number
                        serialization_specific_argument.update({"val": str(value)})

                call_function['args'].append(serialization_specific_argument)
                cur_index += 1

            if call.call_ea not in called_functions:
                called_functions.update({call.call_ea: [call_function]})
            else:
                called_functions[call.call_ea].append(call_function)

        return pickle.dumps(called_functions)

    def exposed_get_decompiled_func(self, addr):
        source = idaapi.decompile(addr)
        return source

    def exposed_get_decompiled_warnings(self, addr):
        """
        get decompile warnings ida had
        https://www.hex-rays.com/products/decompiler/manual/sdk/hexrays_8hpp.shtml
        :param addr: addr of the function
        :return: tuple of tuples ((warning id, text),....)
        """
        warnings = []
        t = idaapi.decompile(addr)
        for i in t.warnings:
            warnings.append((i.id, i.text))

        return tuple(warnings)

    def exposed_get_xrefs_to(self, addr):
        # return list of objects
        xrefs = []
        for xref in idautils.XrefsTo(addr):
            # far call  or near call
            if xref.type == idaapi.fl_CF or xref.type == idaapi.fl_CN:
                xrefs.append(xref.frm)

        return tuple(xrefs)

    def exposed_get_xrefs_frm(self, addr, is_include_offset_xrefs):
        xrefs = []
        for xref in idautils.XrefsFrom(addr):
            # far call  or near call
            if xref.type == idaapi.fl_CF or xref.type == idaapi.fl_CN:
                xrefs.append(xref.to)
            elif is_include_offset_xrefs and xref.type == idaapi.dr_O:
                xrefs.append(xref.to)

        return tuple(xrefs)

    def exposed_get_function_name(self, addr, demangle=True):
        name = idc.get_func_name(addr)

        if name is None or len(name) == 0:  # exported_function?
            name = idaapi.get_name(addr)

        if not demangle:
            return name

        demangled_name = self.demangle_name(name)
        return demangled_name

    def exposed_get_number_of_opcodes_in_function(self, addr):
        number_of_opcodes = len(list(idautils.FuncItems(addr)))
        return number_of_opcodes

    def exposed_get_function_asm_lines(self, addr):
        opcodes = []
        for opcode_addr in idautils.FuncItems(addr):
            opcodes.append(idc.GetDisasm(opcode_addr))
        return tuple(opcodes)

    def exposed_get_all_xrefs_frm_function(self, addr, is_include_in_function_xrefs=False):
        """
        gets all the xrefs from a specific function.
        :rtype: tuple of all the addresses called from the function
        """
        xrefs = []
        for opcode_addr in idautils.FuncItems(addr):
            for xref in self.exposed_get_xrefs_frm(opcode_addr, is_include_in_function_xrefs):
                xrefs.append(xref)

        return tuple(xrefs)

    def exposed_reload_symbols(self):
        # noinspection PyUnresolvedReferences
        import ida_loader
        # pdbnode = idaapi.netnode("$ pdb")
        # is_loaded_correctly = pdbnode.altval(0)
        ida_loader.load_and_run_plugin("pdb", 1)
        # should be is loaded correctly
        pdbnode = idaapi.netnode("$ pdb")
        is_loaded_correctly = pdbnode.altval(0)
        setattr(self, "status_symbol_loaded", is_loaded_correctly)
        return is_loaded_correctly  # zero - correctly, 1 - error

    def exposed_reload_symbols_result(self):
        if hasattr(self, "status_symbol_loaded"):
            return self.status_symbol_loaded
        else:
            # still in progress
            return None

    def exposed_get_imported_modules(self):
        modules = []
        number_of_required_modules = idaapi.get_import_module_qty()
        for i in range(number_of_required_modules):
            module_name = idaapi.get_import_module_name(i)
            modules.append(module_name)

        return tuple(modules)

    def exposed_get_all_imported_functions(self):
        """

        :return: dictionary, keys module names, values (imported address, imported_function_name)
        """
        global IMPORTED_FUNCTIONS
        if IMPORTED_FUNCTIONS is None:
            imported_functions = dict()

            def t(ea, name, ord):
                if module_name not in imported_functions:
                    imported_functions.update({module_name: [(ea, name)]})
                else:
                    imported_functions[module_name].append((ea, name))
                return True

            loaded_modules = self.exposed_get_imported_modules()
            for index, module_name in enumerate(loaded_modules):
                if index is not None:
                    idaapi.enum_import_names(index, t)

            IMPORTED_FUNCTIONS = imported_functions

        return IMPORTED_FUNCTIONS

    def exposed_get_address_imported_properties(self, addr, is_demangled=True):
        all_imported_functions = self.exposed_get_all_imported_functions()
        for module_name, imported_properties in all_imported_functions.items():
            addresses, function_names = zip(*imported_properties)
            if addr in addresses:
                match_index = addresses.index(addr)
                raw_function_name = function_names[match_index]
                function_name = raw_function_name
                if is_demangled:
                    function_name = self.demangle_name(function_name)

                return module_name, function_name

        # rpyc doesn't support return of multiple arguments.
        # noinspection PyRedundantParentheses
        return (None, None)

    def exposed_get_function_exported_name(self, addr, is_demangled):
        func_name = None
        for entry in idautils.Entries():
            if entry[2] == addr:
                func_name = entry[-1]  # exported name
                break

        if func_name is not None and is_demangled:
            return self.demangle_name(func_name)

        return func_name

    def exposed_get_name_ea_simple(self, name):
        addr = idc.get_name_ea_simple(name)
        if addr is not None and (not addr == ERROR_ADDR):
            return addr

        return None

    def exposed_get_GUID(self, ea):
        data1 = idc.get_bytes(ea, 4)
        data1 = struct.unpack("<I", data1)[0]

        ea += 4
        data2 = idc.get_bytes(ea, 2)
        data2 = struct.unpack("<H", data2)[0]

        ea += 2
        data3 = idc.get_bytes(ea, 2)
        data3 = struct.unpack("<H", data3)[0]

        ea += 2
        data4 = idc.get_bytes(ea, 2)
        data4 = struct.unpack(">H", data4)[0]

        ea += 2
        data5 = idc.get_bytes(ea, 6)
        data_5_str = ""
        for b in data5:
            data_5_str += "%02x" % b
        # print data5Str
        return "%08x-%04x-%04x-%04x-%s" % (data1, data2, data3, data4, data_5_str)

    def special_formats(self, ea):
        printable_type_name = idc.guess_type(ea)
        if printable_type_name == "GUID":
            return self.exposed_get_GUID(ea)

        return None

    def exposed_search_binary_sequence(self, sequence):
        if len(sequence) <= 2:
            raise ValueError("sequence must be longer than 2")
        addr = 0
        found_addresses = []
        found_address = idc.find_binary(addr, idc.SEARCH_NEXT | idc.SEARCH_DOWN | idc.SEARCH_CASE, sequence)
        while found_address != idc.BADADDR:
            found_addresses.append(found_address)
            addr = found_address
            found_address = idc.find_binary(addr, idc.SEARCH_NEXT | idc.SEARCH_DOWN | idc.SEARCH_CASE, sequence)

        return tuple(found_addresses)

    @pack_data(is_compressed=True)
    def exposed_get_all_xxe_results(self):
        """
        Get all XXE results from the PE
        :return: dictionary of all the functions, GUIDs and the parameters relevant to it
        """
        import integrations.xxe_find_vulnerable_functions
        results = integrations.xxe_find_vulnerable_functions.main()
        for key, val in results.items():
            guid = self.exposed_get_GUID(int(key, 16))
            val.update({"guid": guid})

        return results

    def exposed_find_related_functions(self, data_addr):
        xrefs = idautils.XrefsTo(data_addr)
        results = []
        for xref in xrefs:
            try:
                function_addr = sark.function.Function(xref.frm).start_ea
                results.append(function_addr)
            except Exception as e:
                pass
        return tuple(results)

    @pack_data(is_compressed=True)
    def exposed_get_all_strings(self, start_index, max_size):
        """
        Get all strings from a binary
        It returns the results in chunks because the result is limited in chunks
        :param start_index: current index
        :param max_size: maximum size of each chunk
        :return: chunk of strings found in the binary - on finish returns list smaller than max_size
        """
        ida_strings = idautils.Strings()
        results = []
        for current_index, ida_string in enumerate(ida_strings):
            if current_index < start_index:
                continue
            if current_index - start_index > max_size:
                return results

            ea = ida_string.ea
            string_value = str(ida_string)
            xrefs = idautils.XrefsTo(ea)
            is_found = False
            base_dict = {"string_value": string_value, "string_addr": ea}
            for xref in xrefs:
                try:
                    function_addr = sark.function.Function(xref.frm).start_ea
                    new_dict = base_dict.copy()
                    new_dict.update({"function_addr": function_addr})
                    results.append(new_dict)
                    is_found = True
                except Exception as e:
                    pass

            if is_found is False:  # found a string but without code xrefs
                results.append(base_dict)

        return results

    @pack_data(False)
    def exposed_get_func_flags(self, addr):
        """
        Get all function flags
        :param addr: address of the function
        :return: dict {'library': True/False, 'static': True/False, 'noret': True/False}
                 is library function (external), statically linked function, function without retun.
        """
        func = idaapi.get_func(addr)
        is_func_lib = 0 != (func.flags & idaapi.FUNC_LIB)
        is_func_static = 0 != (func.flags & idaapi.FUNC_STATICDEF)
        is_func_noret = 0 != (func.flags & idaapi.FUNC_NORET)
        flags = {"library": is_func_lib, "static": is_func_static, "noret": is_func_noret}
        return flags

    def exposed_get_value_from_addr(self, ea, max_size):
        """
        Get the value got from the address
        :param ea: address to redd
        :param max_size: maximum size to read
        :return: tuple (size variable (number), string represent the type, value
        """
        if not ida_bytes.is_mapped(ea):  # invalid addr
            return None

        try:
            f = idc.get_full_flags(ea)
            # we ignore code or non data section and we must have a value there.
            if ida_bytes.is_code(f) or not ida_bytes.is_data(f) or not ida_bytes.is_loaded(ea):
                return None

            data_type = idc.guess_type(ea)
            data_size = ida_bytes.get_item_size(ea)
            if ida_bytes.is_unknown(f):
                data_type = None
            if ida_bytes.is_strlit(f):  # it is a string
                data_value = sark.data.get_string(ea)
            elif ida_bytes.is_struct(f):
                data_value = self.special_formats(ea)
            else:
                size_to_get = min(data_size, max_size)
                raw_data_value = ida_bytes.get_bytes(ea, size_to_get)
                data_value_str = binascii.hexlify(raw_data_value)
                data_value = int(data_value_str, 16)

            return data_size, data_type, data_value

        except sark.exceptions.SarkNoString as e:  # TODO: validate it doesn't raise additional exceptions
            return None

    @pack_data(True)
    def exposed_find_controllable_paths(self):
        """
        Gets list of all the controllable paths (dictionary)
        :return:
        """
        import controllable_paths
        results = []
        for result in controllable_paths.main():
            try:
                raw_func_in_addr = int(result['susAddress'], 16)
                start_func_addr = sark.Function(raw_func_in_addr).start_ea
                result.update({"function_address": start_func_addr})
            except Exception as e:  # it is not inside a function.
                pass
            results.append(result)

        return results

    def exposed_find_vtable(self, func_addr):
        """
        Get list of all the virtual tables points to a function
        :param func_addr: the address of a function
        :return: tuple of all the virtual tables points to the function
        """
        is_vtable = False
        demangled_names = []
        for xref in idautils.XrefsTo(func_addr, 0):
            temp = xref.frm

            is_vtable = False  # TODO: it looks like a bug :<(
            index = 0
            while not is_vtable and index < MAX_SIZE_VTABLE:
                index += 1
                name = ida_name.get_ea_name(temp)
                demangled_name = self.demangle_name(name)
                if demangled_name and 'vftable' in demangled_name:
                    is_vtable = True
                    demangled_names.append(demangled_name)
                    break

                temp -= 8
                if not idc.GetDisasm(temp).startswith('dq offset'):
                    break

        return tuple(demangled_names)

    def demangle_name(self, name):
        """

        :param name: mangle name of a function
        :return: the demangled name
        """
        if name is None or len(name) == 0:
            return None

        demangled_name = idc.demangle_name(name, idc.INF_SHORT_DN)
        # not valid name
        if demangled_name is None or len(demangled_name) == 0:
            return name

        return demangled_name

    @pack_data(is_compressed=True)
    def exposed_find_rpc(self):
        rpc_servers = integrations.rpc_dump.main()
        return rpc_servers


def get_service_port_number():
    if ENV_PORT_NAME not in os.environ:
        print(f"failed to find port: {ENV_PORT_NAME}")
        ida_pro.qexit(-1)
    return int(os.environ[ENV_PORT_NAME])


def timeout_connection():
    """
    Watchdog for ida if the RPC client won't connect to it so it will close the ida.
    :return: On timeout it will close ida
    """
    timeout_waited = 0
    while not IS_CONNECTED:
        timeout_waited += 0.1
        time.sleep(0.1)
        if timeout_waited > MAX_WAIT_TIMEOUT:
            print("killed ida because of timeout not connected")
            ida_pro.qexit(-3)


def init():
    global PROCESS_UUID
    if ENV_PROCESS_UUID not in os.environ:
        print(f"failed to find UUID: {ENV_PROCESS_UUID}")
        ida_pro.qexit(-2)
    PROCESS_UUID = os.environ[ENV_PROCESS_UUID]
    sample_t = threading.Thread(target=timeout_connection)
    sample_t.start()


if __name__ == "__main__":
    init()
    port = get_service_port_number()
    try:
        s = rpyc.utils.server.OneShotServer(IdaProService, auto_register=True, port=port, reuse_addr=False)
    except OSError as e:
        print(f"failed to bind port {port}")
        ida_pro.qexit(-4)
    except Exception as e:
        print(f"exception type: {e}")
        ida_pro.qexit(-5)

    # OneShotServer - Once the connection will be closed it will return from start.
    s.start()
    # close ida process
    ida_pro.qexit(0)
