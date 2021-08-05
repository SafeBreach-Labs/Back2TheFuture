import collections
import logging

import cachetools
from cachetools import cached
import enum
import re

import core.configurations

INVALID_ADDR = 0xffffffffffffffff


class TypesOfBlocks(enum.Enum):
    LOOPS = ["for", "while"]
    CONDITIONS = ["if", "switch"]
    ASSIGNMENT = ["asg"]
    GOTO = ["goto"]
    RETURN = ["return"]
    BREAK = ["break"]


class Function(object):
    def __init__(self, address, pe_object, function_name=None):
        self.addr = address
        self._full_function_name = function_name
        self.__module = pe_object  # we might want to add a weak ref to that object.

    @property
    def version(self):
        return self.__module.version

    def get_assembly(self):
        # It can be replaced with diaphora api...
        return self.__module.ida_communicator.get_function_assembly(self.addr)

    def get_decompiled(self):
        return self.__module.ida_communicator.get_function_decompile(self.addr)

    def get_arguments_called_functions(self):
        return self.__module.ida_communicator.get_arguments_called_functions(self.addr)

    def get_types_of_blocks(self, types_of_blocks=None):
        """
        Get counts of all specific type of blocks in the function
        :param types_of_blocks: list of TypesOfBlocks
        :return: {type_of_block: count,.... }
        """
        if types_of_blocks is None:
            return self.__module.ida_communicator.get_amount_of_logical_blocks_in_func(self.addr)
        values = collections.Counter()
        for feature, count in self.__module.ida_communicator.get_amount_of_logical_blocks_in_func(self.addr).items():
            for type_of_block in types_of_blocks:
                if feature in type_of_block.value:
                    values.update({feature: count})

        return values

    def get_amount_of_opcodes(self):
        return len(self.__module.ida_communicator.get_function_assembly(self.addr))

    def get_amount_of_blocks(self):
        return self.__module.ida_communicator.get_amount_of_blocks_in_func(self.addr)

    def get_decompiled_warnings(self):
        """
        get decompile warnings ida had
        https://www.hex-rays.com/products/decompiler/manual/sdk/hexrays_8hpp.shtml#aebdeaae88840f33976d20594542de4b5
        :return: tuple of tuples ((warning id, text),....)
        """
        return self.__module.ida_communicator.get_function_decompile_warnings(self.addr)

    @staticmethod
    def __solve_more_complex_names(complex_name, is_add_template_indication):
        def _count_parenthesis(char_start, char_end, name):  # TODO: add support with ::operator-> function name
            count_parenthesis = 0
            for index, current_digit in enumerate(name[::-1]):
                if current_digit == char_end:
                    count_parenthesis += 1
                elif current_digit == char_start:
                    count_parenthesis -= 1

                if count_parenthesis == 0:
                    return -index - 1

            return None

        if complex_name.endswith("const"):
            complex_name = complex_name[:-len("const")]

        if complex_name.startswith("public: "):
            complex_name = complex_name[len("public: "):]

        if complex_name.startswith("private: "):
            complex_name = complex_name[len("private: "):]

        if complex_name.startswith("class "):
            complex_name = complex_name[len("class "):]

        if not complex_name[-1] == ")":
            return None
        # TODO: support names such as
        # private: static int CensusAttributes::CallFunctionOnMatch<__int64 (*)(void)>(unsigned short const *,class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class std::allocator<unsigned short>> &,unsigned short const *,__int64 (*)(void),enum UserContexts)
        # public: static long _tlgWriteTemplate<long (struct _tlgProvider_t const *,void const *,struct _GUID const *,struct _GUID const *,unsigned int,struct _EVENT_DATA_DESCRIPTOR *),&long _tlgWriteTransfer_EventWriteTransfer(struct _tlgProvider_t const *,void const *,struct _GUID const *,struct _GUID const *,unsigned int,struct _EVENT_DATA_DESCRIPTOR *),struct _GUID const *,struct _GUID const *>::Write<struct _tlgWrapSz<char>,struct _tlgWrapperByVal<8>,struct _tlgWrapSz<char>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>>(struct _tlgProvider_t const *,void const *,struct _GUID const *,struct _GUID const *,struct _tlgWrapSz<char> const &,struct _tlgWrapperByVal<8> const &,struct _tlgWrapSz<char> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &,struct _tlgWrapperByVal<2> const &)
        index = _count_parenthesis("(", ")", complex_name)
        if index is None:
            return None

        correct_end_name = complex_name[:index]
        if correct_end_name[-1] == ">":  # Template
            end_template_prefix = _count_parenthesis("<", ">", correct_end_name)
            prefix = correct_end_name[:end_template_prefix]
            if "<" not in prefix and ">" not in prefix:
                prefix = prefix.split(" ")[-1]

            if is_add_template_indication:
                correct_name = prefix + " <>"  # An indication it is template
            else:
                correct_name = prefix
        elif "<" in correct_end_name or ">" in correct_end_name:
            correct_name = correct_end_name

        else:
            correct_name = correct_end_name.split(" ")[-1]
            if "<" in correct_name:  # template and I don't know yet to parse it
                return correct_end_name

            if correct_name is None or len(correct_name) == 0:
                return None

            if not re.match("[_a-zA-Z]", correct_name[0]):
                return None

        return correct_name

    @staticmethod
    def get_basic_name(complex_name, is_add_template_indication=True):
        if len(complex_name) == 0:
            return complex_name  # some times the function name is ""

        if complex_name.count("(") > 1 or "<" in complex_name:
            result = Function.__solve_more_complex_names(complex_name, is_add_template_indication)
            if result is None:
                return complex_name  # failed to convert to short name
            return result

        function_name_with_prefix = complex_name.split("(")[0]
        function_name = function_name_with_prefix.split(" ")[-1]
        return function_name

    def function_name(self, is_short_format=True):
        if self._full_function_name is None:
            self._full_function_name = self.__module.ida_communicator.get_function_name_from_addr(self.addr)

        if is_short_format:
            return Function.get_basic_name(self._full_function_name)

        return self._full_function_name

    def get_function_assembly(self):
        return self.__module.ida_communicator.exposed_get_function_asm_lines()

    def get_all_blocks(self):
        raise NotImplementedError("not yet")

    def get_all_called_functions(self, is_include_in_function_xrefs=False):
        """

        :param is_include_in_function_xrefs: such as lea, func_addr or other xrefs to that data. and not direct calls.
        :return:
        """
        return self.__module.ida_communicator.get_function_xrefs(self.addr, is_include_in_function_xrefs)

    def get_all_vtables_points_to_func(self):
        """

        :return: tuple of all the virtual tables points to this function
        """
        return self.__module.ida_communicator.get_find_function_xref_vtable(self.addr)

    def is_exported_func(self):
        return self.__module.ida_communicator.get_is_function_exported(self.addr)

    def get_exported_name(self):
        return self.__module.ida_communicator.get_exported_func_name(self.addr)

    def get_pe_obj(self):
        return self.__module

    def is_function_is_library(self):
        return self.__module.ida_communicator.get_exported_func_flags(self.addr)["library"]

    def get_rpc_info(self):
        """

        :return: list of guids compatible with this function
        """
        rpcs = self.__module.get_rpc_servers()
        found_compatible_guids = []
        for rpc in rpcs:
            if rpc['ProcHandlers'] is None:
                logging.warning(f" {self.__module} rpc['ProcHandlers'] is None")
                continue

            if self.addr in rpc['ProcHandlers']:
                server_interface_guid = rpc['ServerInterface'].get('InterfaceId', {}).get('SyntaxGUID', None)
                rpc_prject_base_path = core.configurations.get_global().configs.features.function.rpc_project_base_path
                rpc_project_list = core.configurations.get_global().configs.features.function.rpc_project_list
                kwargs = {"ServerInterface_GUID": server_interface_guid}
                if server_interface_guid in rpc_project_list:
                    rpc_project_path = rpc_prject_base_path.format(server_interface_guid)
                    kwargs.update({"project_path": rpc_project_path})
                found_compatible_guids.append(kwargs)

        return found_compatible_guids

    def strict_serialize(self):
        base_serialization = self.get_pe_obj().strict_serialize()
        try:
            flags = self.__module.ida_communicator.get_exported_func_flags(self.addr)
        except Exception as e:
            flags = {}
            pe_name = None
            if self.get_pe_obj() is not None:
                pe_name = self.get_pe_obj().name

            logging.warning(f"failed to extract flags of function {pe_name}")

        base_serialization.update(flags)
        # TODO: update function name to short
        base_serialization.update({"function_name": self.function_name(False), "address": self.addr})
        return base_serialization

    def __str__(self):
        return self._to_str(True)

    def _to_str(self, is_long_format):
        output = f"{self.__module}"
        if core.configurations.get_global().configs.output.is_show_function_name:
            if is_long_format:
                output += "!{}".format(self.function_name(False))
            else:
                function_name = self.function_name(True)
                output += "!{}".format(function_name)
        if core.configurations.get_global().configs.output.is_show_function_addr:
            output += "@{:x}".format(self.addr)
        return output

    def __repr__(self):
        return self._to_str(False)
