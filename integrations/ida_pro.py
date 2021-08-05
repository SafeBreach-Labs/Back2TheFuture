# Communicate with Ida as an external process over RPC
import weakref
import copy
import zlib
import json

import cachetools
import cachetools.keys
from cachetools import cached, LRUCache
import pickle
import psutil
import logging
import time
import random
import subprocess
import os
import uuid
import rpyc
import rpyc.utils.factory
from rpyc.core.service import ClassicService

import integrations.ida_runner
import core.configurations
import core.exceptions

if __name__ == "__main__":
    logging.basicConfig(level=logging.DEBUG)

logger = logging.getLogger(__name__)


def internal_cache(func_name, default_cache_type):
    def wrapper(func_ptr):
        def wrapper2(my_self, *args, **kwargs):
            if func_name not in my_self.cache_objects:
                my_self.cache_objects[func_name] = copy.copy(default_cache_type)

            cache_obj = my_self.cache_objects[func_name]
            # removed self, in order that it will be deleted (no references)
            key = cachetools.keys.hashkey(*args, **kwargs)
            if key in cache_obj:
                return cache_obj[key]
            ret_val = func_ptr(my_self, *args, **kwargs)
            cache_obj.update({key: ret_val})
            return ret_val

        return wrapper2

    return wrapper


class IdaCommunicatorHandler(object):
    def __init__(self, max_connections=None):
        if max_connections is None:
            max_connection_per_thread = core.configurations.get_global().configs.integrations.ida.max_open_instances
            max_connections = max_connection_per_thread

        self.max_connections = max_connections
        self.communications = []

    def add_connection(self, communicator, close_func, port):
        connection_weakref = weakref.ref(close_func)()
        communicator_weakref = weakref.ref(communicator)()
        self.remove_connection(None)  # cleanup for all deleted objects
        self.communications.append((communicator_weakref, connection_weakref, port))
        if len(self.communications) > self.max_connections:
            object_to_forcely_delete = self.communications[0][0]
            logging.debug(f"removed ida connection {object_to_forcely_delete}")
            self.remove_connection(object_to_forcely_delete)

    def is_can_use_port(self, port):
        for connector, _, comm_port in self.communications:
            if port == comm_port:
                return False
        return True

    def remove_connection(self, communicator):
        for index, i_communicator in enumerate(self.communications):
            if communicator == i_communicator[0]:
                # POP must happen before calling disconnect function (in order it will not be infinite loop)
                _, disconnect_func, port = self.communications.pop(index)
                if disconnect_func is not None:  # because of the weakref.
                    disconnect_func()


COMMUNICATION_HANDLER = None


class IdaCommunicator(object):
    def __init__(self, binary_path, on_disconnect=None, path_ida=None, max_retries=None,
                 ida_max_loading_time_sec=None, min_port=None, max_port=None, max_request_timeout=None,
                 is_reload_symbols=None, seconds_to_close_idb=None):
        if is_reload_symbols is not None:
            self.is_reload_symbols = is_reload_symbols
        else:
            self.is_reload_symbols = core.configurations.get_global().configs.integrations.ida.is_reload_symbols
        self.__is_loaded_symbols_once = False  # load only once symbols
        if max_request_timeout is None:
            max_request_timeout = core.configurations.get_global().configs.integrations.ida.timeout_request_seconds
        self.max_request_timeout = max_request_timeout
        if seconds_to_close_idb is None:
            seconds_to_close_idb = core.configurations.get_global().configs.integrations.ida.seconds_to_close_idb
        self.seconds_to_close_idb = seconds_to_close_idb

        on_disconnect_ref = weakref.ref(on_disconnect)()
        self.on_disconnect = on_disconnect_ref
        if ida_max_loading_time_sec is None:
            ida_max_loading_time_sec = core.configurations.get_global().configs.integrations.ida.max_loading_seconds

        if max_retries is None:
            max_retries = core.configurations.get_global().configs.integrations.ida.max_retries

        self.ida_max_sec_loading_time = ida_max_loading_time_sec
        self.max_retries = max_retries
        if path_ida is None:
            path_ida = core.configurations.get_global().configs.integrations.ida.path_ida
        self.path_ida = path_ida

        if min_port is None:
            min_port = core.configurations.get_global().configs.integrations.ida.min_port
        self.min_port = min_port

        if max_port is None:
            max_port = core.configurations.get_global().configs.integrations.ida.max_port
        self.max_port = max_port

        self.binary_path = binary_path
        self._ida_connection_port = -1
        self._ida_connection_obj = None
        self._ida_process_id = None
        self._ida_process_uuid = None
        self.cache_objects = {}

    def connect(self, is_wait_for_auto_analysis=True):
        global COMMUNICATION_HANDLER
        retries = 0
        logging.debug(f"opening ida {self.binary_path}")
        is_connected_successfully = False
        if self.on_disconnect is not None:
            if COMMUNICATION_HANDLER is None:
                COMMUNICATION_HANDLER = IdaCommunicatorHandler()

        while not self.is_connected() and retries < self.max_retries:
            try:
                retries += 1
                ret_val = self.__try_execute_ida()
                if ret_val is False:
                    logger.debug(f"failed to connect to ida, retry again {retries}")

                is_connected_successfully = self.is_connected(is_validate=True)
                if not is_connected_successfully:
                    self.disconnect_ida()
                    if hasattr(self._ida_process_id, "returncode"):
                        raise OSError("failed to execute ida correctly, return code {ret_code}, binary: {bin}".format(
                            ret_code=self._ida_process_id.returncode, bin=self.binary_path))
                    else:
                        raise OSError(f"failed to execute ida correctly, no return code  {self.binary_path}")

            except Exception as e:
                logger.warning(f"failed to try to connect to ida, "
                               f"exception: {e}, binary:{self.binary_path}")

        if not is_connected_successfully:
            raise core.exceptions.IntegrationTimeout(f"failed to connect to Ida binary {self.binary_path}")
        else:
            COMMUNICATION_HANDLER.add_connection(self, self.disconnect_ida, port=self._ida_connection_port)

        if is_wait_for_auto_analysis:
            try:
                retries = 0
                wait_time = core.configurations.get_global().configs.integrations.ida.max_auto_analysis_seconds
                max_time = wait_time + time.time()
                is_success = False
                while not is_success and time.time() < max_time:  # waiting for the IDB to be ready
                    retries += 1
                    try:
                        # is success can be false
                        is_success = self._ida_connection_obj.root.exposed_wait_finish_loading()
                        if is_success:
                            break

                    except Exception as e:
                        if ((10 + time.time()) > max_time) or self.is_connected(is_validate=False) == False:
                            raise

                    time.sleep(0.1)
            except TimeoutError as e:
                logger.critical(f"failed waiting for finish loading {self}")
                raise core.exceptions.IntegrationTimeout(self.binary_path)
            except AttributeError as e:
                logger.critical(f"failed waiting for finish loading {self} {e}")
                raise core.exceptions.IntegrationTimeout(self.binary_path)

        if self.is_reload_symbols and not self.__is_loaded_symbols_once:
            self._load_symbols()
            self.__is_loaded_symbols_once = True

    # @staticmethod
    def safecall(func):
        def inner_func(self, *args, **kwargs):
            try:
                return func(self, *args, **kwargs)

            except (
            EOFError, AttributeError, core.exceptions.IntegrationTimeout, core.exceptions.FailedToDecompile) as e:
                logger.warning(f"failed to connect ida {e} func {func}")
                is_connected = self.is_connected()
                if not is_connected:
                    self.connect()

                return func(self, *args, **kwargs)

        return inner_func

    @staticmethod
    def kill_all(ida_location):
        process_name = os.path.basename(ida_location)
        for proc in psutil.process_iter():
            # check whether the process name matches
            if proc.name() == process_name:
                proc.kill()

    def disconnect_ida(self):
        global COMMUNICATION_HANDLER
        if self.on_disconnect is not None:
            if COMMUNICATION_HANDLER is None:
                COMMUNICATION_HANDLER = IdaCommunicatorHandler()
            COMMUNICATION_HANDLER.remove_connection(self)

        if self.on_disconnect is not None:
            self.on_disconnect()

        if self._ida_connection_obj is not None:
            self._ida_connection_obj.close()
            self._ida_connection_obj = None

        seconds_left_to_wait = self.seconds_to_close_idb
        while seconds_left_to_wait > 0 and self._ida_process_id is not None and \
                self._ida_process_id.poll() is None:
            time.sleep(0.1)
            seconds_left_to_wait -= 0.1

        if self._ida_process_id is not None and self._ida_process_id.poll() is None:
            self._ida_process_id.kill()
            self._ida_process_id = None

    def is_connected(self, is_validate=False):
        if self._ida_connection_obj is None or self._ida_process_id is None:
            return False
        try:
            self._ida_connection_obj.ping(10)
        except Exception:
            return False

        if is_validate:
            self._validate_connect_correct_node()

        return True

    def __del__(self):
        self.disconnect_ida()

    def __str__(self):
        return f"Ida communicator: {self.binary_path}"

    def __choose_port(self):
        port = random.randrange(self.min_port, self.max_port)
        if COMMUNICATION_HANDLER is None:
            self._ida_connection_port = port
            return
        max_retries = 10
        for i in range(max_retries):
            if not COMMUNICATION_HANDLER.is_can_use_port(port):
                port = random.randrange(self.min_port, self.max_port)
            else:
                break
        if not COMMUNICATION_HANDLER.is_can_use_port(port):
            logger.error(f"could not find a free port to use after {max_retries},using {port}")

        self._ida_connection_port = port

    def _load_symbols(self):
        try:
            result = self._ida_connection_obj.root.exposed_reload_symbols()
            logger.debug(f"loaded symbols {self.binary_path} {result}")
            return result
        except Exception:
            pass  # it will fail on timeout

        time_waited = 0
        max_time = core.configurations.get_global().configs.integrations.ida.max_reload_symbols_seconds
        while time_waited < max_time:
            time_waited += 2
            time.sleep(2)
            try:
                result = self._ida_connection_obj.root.exposed_reload_symbols_result()
                logger.debug(f"loaded symbols {self.binary_path} {result}")
                return result
            except Exception as e:  # the server might not answer while it's handling another
                pass

        logger.warning("failed on timeout getting symbols")

    def __try_execute_ida(self):
        self.disconnect_ida()
        self.__choose_port()
        self._ida_process_uuid = str(uuid.uuid1())
        env = {integrations.ida_runner.ENV_PORT_NAME: str(self._ida_connection_port),
               integrations.ida_runner.ENV_PROCESS_UUID: self._ida_process_uuid}
        env.update(os.environ)
        command_to_run = [self.path_ida, '-A', '-B', '-S' + integrations.ida_runner.__file__, self.binary_path]
        self._ida_process_id = subprocess.Popen(command_to_run, env=env, shell=False, stderr=subprocess.PIPE,
                                                stdout=subprocess.PIPE)
        connection_retries = 0
        max_time = time.time() + self.ida_max_sec_loading_time
        while time.time() < max_time:
            time.sleep(0.1)
            try:
                self._ida_connection_obj = rpyc.utils.factory.connect('localhost',
                                                                      self._ida_connection_port,
                                                                      ClassicService,
                                                                      {'sync_request_timeout': self.max_request_timeout}
                                                                      )
                if self.is_connected(True):
                    return True
            except WindowsError as e:
                logger.debug(f"failed to connect {connection_retries}")
                time.sleep(0.1)  # give time to the process to start.
                if self._ida_process_id.poll() is not None:  # process is not alive
                    cmd = " ".join(command_to_run)
                    logger.warning(f"ida was closed {connection_retries} cmd: {cmd}")
                    self._ida_process_id.kill()
                    return False

            connection_retries += 1

        return False

    def _validate_connect_correct_node(self):
        uuid_got = self._ida_connection_obj.root.exposed_get_uuid()
        if not uuid_got == self._ida_process_uuid:
            log_val = "expected to have same uuid connected to the wrong server!!"
            logger.critical(log_val)
            raise ValueError(log_val)

    def _unpack_encoding(self, data, uncompress=False):
        if uncompress:
            data = zlib.decompress(data)

        return pickle.loads(data)

    ##########################################################################################################
    ## Export functions:

    @safecall
    def get_amount_of_logical_blocks_in_func(self, addr):
        data = self._ida_connection_obj.root.exposed_get_amount_of_logical_blocks_in_func(addr)
        return self._unpack_encoding(data)

    @safecall
    def get_amount_of_blocks_in_func(self, addr):
        blocks = self._ida_connection_obj.root.exposed_get_amount_of_graph_blocks_in_func(addr)
        return blocks

    @safecall
    def get_exported_func_flags(self, addr):
        raw_data = self._ida_connection_obj.root.exposed_get_func_flags(addr)
        return self._unpack_encoding(raw_data, uncompress=False)

    @safecall
    def get_arguments_called_functions(self, addr):
        """
        for eac all functions called by a function, extract all arguments used.
        :param addr: function address to extract all the called arguments
        :return: dict contains {ea,name,ret_type_name, args:[{type, val},{type,val}...]}
        """
        pickle_buffer = self._ida_connection_obj.root.exposed_get_arguments_called_functions(addr)
        return pickle.loads(pickle_buffer)

    @internal_cache("get_function_decompile", {})
    @safecall
    def get_function_decompile(self, address):
        # text decompile
        return self._ida_connection_obj.root.exposed_get_decompiled_func(address)

    def get_value_from_addr(self, address, max_size=16):
        return self._ida_connection_obj.root.exposed_get_value_from_addr(address, max_size)

    def get_all_strings(self):
        start_index = 0
        max_chunk = 1000
        all_results = []
        raw_results = self._ida_connection_obj.root.exposed_get_all_strings(start_index, max_chunk)
        current_results = self._unpack_encoding(raw_results, uncompress=True)
        while len(current_results) != 0:
            all_results += current_results
            start_index += max_chunk
            raw_results = self._ida_connection_obj.root.exposed_get_all_strings(start_index, max_chunk)
            current_results = self._unpack_encoding(raw_results, uncompress=True)

        return all_results

    @safecall
    def search_sequence_of_bytes(self, sequence):
        """
        Search sequence of bytes in the entire binary.
        :param sequence: bytes sequence to search in the binary
        :return: list of dictionaries, [{address_of_matched_pattern:[address_functions]},....]
        """
        hexlifyied_sequence = sequence.hex()  # hex split to chunks was added in python3.8
        split_hex = [hexlifyied_sequence[index:index + 2] for index in range(0, len(hexlifyied_sequence), 2)]
        joined_hex = " ".join(split_hex)
        addresses_found = self._ida_connection_obj.root.exposed_search_binary_sequence(joined_hex)
        found_related = []
        for address_found in addresses_found:
            related_functions = self._ida_connection_obj.root.exposed_find_related_functions(address_found)
            found_related.append({address_found: related_functions})

        return found_related

    @safecall
    def get_all_xxe_results(self):
        raw_results = self._ida_connection_obj.root.exposed_get_all_xxe_results()
        results = self._unpack_encoding(raw_results, True)
        return results

    @safecall
    def get_function_decompile_warnings(self, addr):
        """
        get decompile warnings ida had
        https://www.hex-rays.com/products/decompiler/manual/sdk/hexrays_8hpp.shtml
        :param addr: addr of the function
        :return: tuple of tuples ((warning id, text),....)
        """
        return self._ida_connection_obj.root.exposed_get_decompiled_warnings(addr)

    @internal_cache("get_functions_addresses", {})
    @safecall
    def get_functions_addresses(self, is_include_tiny_functions):
        """

        :param is_include_tiny_functions:
        :return: read only tuple of addresses, due to cache
        """
        # list of addresses
        minimal_function_opcodes = 0
        if not is_include_tiny_functions:
            import core.configurations
            minimal_function_opcodes = core.configurations.get_global().configs.compare.minimal_instructions

        accumulated_functions = []
        max_chunk = 1500
        index = 0
        functions = self._ida_connection_obj.root.exposed_get_functions_addr(index, max_chunk, minimal_function_opcodes)
        while len(functions) > 0:
            accumulated_functions += functions
            index += 1
            functions = self._ida_connection_obj.root.exposed_get_functions_addr(index, max_chunk,
                                                                                 minimal_function_opcodes)
        if len(accumulated_functions) == 0:
            logging.critical(f"amount of functions can't be zero!! {self.binary_path}")

        return accumulated_functions

    @safecall
    def get_function_name_from_addr(self, addr, is_demangled=True):
        return self._ida_connection_obj.root.exposed_get_function_name(addr, is_demangled)

    @internal_cache("get_function_xrefs", {})
    @safecall
    def get_function_xrefs(self, func_addr, is_include_in_function_xrefs=False):
        return self._ida_connection_obj.root.exposed_get_all_xrefs_frm_function(func_addr, is_include_in_function_xrefs)

    @internal_cache("get_xrefs_from", {})
    @safecall
    def get_xrefs_from(self, address):
        # Sark object
        return self._ida_connection_obj.root.exposed_get_xrefs_frm(address)

    @internal_cache("get_xrefs_to", {})
    @safecall
    def get_xrefs_to(self, address):
        # Sark object
        return self._ida_connection_obj.root.exposed_get_xrefs_to(address)

    @safecall
    def get_function_assembly(self, addr):
        # list of strings, each string is opcode.
        return self._ida_connection_obj.root.exposed_get_function_asm_lines(addr)

    @internal_cache("get_module_name_function_imported", {})
    @safecall
    def get_module_name_function_imported(self, addr):
        """
        :param addr: function address to check if the function is imported
        :param is_demangled: is return demangled or mangled
        :return: None if the function is not imported, string name of the module imported (ntdll, KERNEL32...)
                 without extension
        """
        return self._ida_connection_obj.root.exposed_get_address_imported_properties(addr)[0]

    @internal_cache("get_imported_function_name", {})
    @safecall
    def get_imported_function_name(self, addr, is_demangled):
        """
        :param addr: function address to check if the function is imported
        :param is_demangled: is return demangled or mangled
        :return: None if the function is not imported, string name of the module imported (ntdll, KERNEL32...)
                 without extension
        """
        func_name = self._ida_connection_obj.root.exposed_get_address_imported_properties(addr, is_demangled)[1]
        if func_name is not None and func_name.startswith("__imp_"):  # This is a workaround due to bug in Ida
            func_name = func_name[len("__imp_"):]

        return func_name

    @safecall
    def get_is_function_exported(self, addr):
        name = self.get_exported_func_name(addr)
        if name is not None:
            return True
        return False

    def find_controllable_paths(self):
        raw_results = self._ida_connection_obj.root.exposed_find_controllable_paths()
        results = self._unpack_encoding(raw_results, uncompress=True)
        return results

    @internal_cache("get_exported_func_name", {})
    def get_exported_func_name(self, addr, is_demangled=True):
        """

        :param addr:
        :param is_demangled:
        :return: read only exported function names. (due to cache)
        """
        return self._ida_connection_obj.root.exposed_get_function_exported_name(addr, is_demangled)

    @safecall
    def get_find_function_xref_vtable(self, addr):
        return self._ida_connection_obj.root.exposed_find_vtable(addr)

    @safecall
    def get_name_ea_simple(self, name):
        return self._ida_connection_obj.root.exposed_get_name_ea_simple(name)

    @safecall
    def get_GUID_from_addr(self, addr):
        return self._ida_connection_obj.root.exposed_get_GUID(addr)

    @internal_cache("get_rpcs", {})
    @safecall
    def get_rpcs(self):
        """

        :return: Readonly set of rpcs (due to the cache)
        """
        data = self._ida_connection_obj.root.exposed_find_rpc()
        decoded_rpcs = self._unpack_encoding(data, uncompress=True)
        output = []

        if decoded_rpcs is None:  # it means there are no RPCs
            return output

        for decoded_rpc in decoded_rpcs:
            output.append(json.loads(decoded_rpc))

        return output


if __name__ == "__main__":
    logger.info("begin!")
    all_prev = time.time()
    for i in range(100):
        communicator = IdaCommunicator(r"C:\tmp\New folder (4)\wshrm.dll",
                                       path_ida=r"C:\Program Files\IDA Pro 7.5\idat64.exe")
        logger.info("connecting to ida")
        communicator.connect()
        logger.info("connected")
        communicator.disconnect_ida()
        all_new = time.time()
    print(f"total {all_new - all_prev}")
    logger.info("done!")
