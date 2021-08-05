import copy
import weakref

import cachetools
import pefile
from cachetools import cached
import os.path
import logging
import integrations.ida_pro
import core.function

logger = logging.getLogger(__name__)


class PE(object):
    def __init__(self, path_pe, configuration=None, version=None, name=None, kb_version=None,
                 architecture=None, package_name=None, build_date=None, is_run_as_elevated=None):
        self.build_date = build_date
        self._package_name = package_name
        self._architecture = architecture
        self.__version = version
        self.path_pe = path_pe
        self.configuration = configuration
        self.kb_version = kb_version
        self.__ida_communicator = None
        self.__is_required_to_connect = True
        self.__functions_by_addr = dict()
        self.__functions_by_name = dict()
        self.__not_function_log = False
        if name is None:
            self.name = os.path.basename(path_pe)
        else:
            self.name = name

        self._is_run_as_elevated = is_run_as_elevated

    @property
    def is_run_as_elevated(self):
        if self._is_run_as_elevated is not None:
            return self._is_run_as_elevated

        import core.configurations  # delayed import
        elevated = core.configurations.get_global().configs.features.pe.elevated_pes
        if self.name in elevated:
            return True

        return False

    @property
    def architecture(self):
        return self._architecture

    @property
    def package_name(self):
        return self._package_name

    @property
    def version(self):
        if self.__version is not None:
            return self.__version
        raise NotImplementedError("extract version from PE not implemented yet")

    @property
    def ida_communicator(self):
        if self.__ida_communicator is None:
            logger.debug(f"creating ida communicator to {self.path_pe}")
            ida_path = self._get_ida_path()
            self.__ida_communicator = integrations.ida_pro.IdaCommunicator(self.path_pe, self.__on_disconnect,
                                                                           path_ida=ida_path)

        if self.__is_required_to_connect:
            self.__ida_communicator.connect()
            self.__is_required_to_connect = False

        return self.__ida_communicator

    def _get_ida_path(self):
        arch = self.get_architecture()
        if arch == "x64":
            return core.configurations.get_global().configs.integrations.ida.path_ida
        elif arch == "x86":
            return core.configurations.get_global().configs.integrations.ida.path_ida_32

        logging.debug(f"failed to find compatible ida version for pe {self.path_pe}")
        return core.configurations.get_global().configs.integrations.ida.path_ida

    def get_architecture(self):
        try:
            pe = pefile.PE(self.path_pe)
        except pefile.PEFormatError:
            return None
        if pe.OPTIONAL_HEADER.Magic == 0x10b:
            return "x86"
        elif pe.OPTIONAL_HEADER.Magic == 0x20b:
            return "x64"

        logging.debug(f"failed to find the architecture of pe {self.path_pe}")
        return "x64"  # the default

    def is_dot_net(self):
        try:
            pe = pefile.PE(self.path_pe)
        except pefile.PEFormatError:
            return False
        is_dot_net = pe.OPTIONAL_HEADER.DATA_DIRECTORY[14]
        if is_dot_net.VirtualAddress == 0 and is_dot_net.Size == 0:
            return False

        return True

    def get_all_strings(self):
        return self.ida_communicator.get_all_strings()

    def find_sequence_of_bytes(self, sequence):
        return self.ida_communicator.search_sequence_of_bytes(sequence)

    def get_all_xxe_results(self):
        return self.ida_communicator.get_all_xxe_results()

    def disconnect_connections(self):
        if self.__ida_communicator is None:
            return

        self.__ida_communicator.disconnect_ida()
        self.__ida_communicator = None

    def __on_disconnect(self):
        logger.debug(f"{self} disconnected from Ida ")
        self.__is_required_to_connect = True

    def _get_function_at_addr(self, function_addr):
        if function_addr in self.__functions_by_addr:
            return self.__functions_by_addr[function_addr]

        if not type(function_addr) == int:
            raise ValueError("address can be int only!")
        
        # display this log only once 
        if function_addr not in self.get_all_functions(is_include_tiny_functions=True) and not self.__not_function_log: 
            # raise ValueError("Address must be a function address!") # TODO: return when it will be fixed 
            logging.warning(f"address is not defined function! {function_addr} {self}")
            self.__not_function_log = True
        if function_addr not in self.__functions_by_addr:
            weakref_self = weakref.ref(self)()  # weak ref in order to prevent memory leak.
            self.__functions_by_addr[function_addr] = core.function.Function(function_addr, weakref_self)

        return self.__functions_by_addr[function_addr]

    def __getitem__(self, item):
        return self._get_function_at_addr(item)

    def get_all_functions(self, is_include_tiny_functions=False):
        read_only_addr = self.ida_communicator.get_functions_addresses(is_include_tiny_functions)
        return copy.copy(read_only_addr)

    def is_can_run_as_elevated(self):
        return self.is_run_as_elevated

    def get_all_functions_by_name(self, is_demangled=True):
        results = {}
        for i in self.get_all_functions(is_include_tiny_functions=True):
            function_at_addr = self[i]
            current_function_name = function_at_addr.function_name(is_demangled)
            results[current_function_name] = function_at_addr

        return results

    def get_controllable_paths(self):
        return self.ida_communicator.find_controllable_paths()

    def get_function_by_name(self, function_name, is_demangled=True):
        if function_name in self.__functions_by_name:
            return self.__functions_by_name[function_name]

        for i in self.get_all_functions(is_include_tiny_functions=True):
            function_at_addr = self[i]
            current_function_name = function_at_addr.function_name(is_demangled)
            self.__functions_by_name[current_function_name] = function_at_addr
            if function_name == current_function_name:
                return self[i]
        
        return None

    def get_function_name(self, addr, is_short_format=False):
        full_name = self.ida_communicator.get_function_name_from_addr(addr)
        if is_short_format:
            return core.function.Function.get_basic_name(full_name)

        return full_name

    def strict_serialize(self):
        base_serialized = {"pe_name": self.name, "package_name": self.package_name, "version": str(self.version)}
        if self.kb_version is not None:
            kb = self.kb_version[2:]
            base_serialized.update({"kb": kb})

        if self.build_date is not None:
            build_date = self.build_date.strftime("%Y-%m")
            base_serialized.update({"build_date": build_date})
        else:
            # for the CFG extractor, we have to had build_date row.
            base_serialized.update({"build_date": None})

        return base_serialized

    def get_value_from_addr(self, addr, max_size=16):
        if addr < 0x10000:  # min address filtering optimizations
            return None
        return self.ida_communicator.get_value_from_addr(addr, max_size)

    def get_module_name_function_imported(self, addr):
        """

        :return: None if the function isn't imported, string name if the function is imported
        """
        return self.ida_communicator.get_module_name_function_imported(addr)

    def get_imported_function_name(self, addr, is_demangled=True):
        """

        :return: None if the function isn't imported, string name if the function is imported
        """
        return self.ida_communicator.get_imported_function_name(addr, is_demangled)

    def get_GUID_from_addr(self, addr):
        if addr is None:
            return None

        return self.ida_communicator.get_GUID_from_addr(addr)

    def get_name_ea_simple(self, name):
        return self.ida_communicator.get_name_ea_simple(name)

    def get_rpc_servers(self):
        return self.ida_communicator.get_rpcs()

    def __str__(self):
        return f"{self.name}({self.version})"

    def __repr__(self):
        return str(self)
