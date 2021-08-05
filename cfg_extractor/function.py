import core.function
import core.utils

SUFFIXES = ["exe", "dll", "sys", "cpl", "drv", "efi", "ocx"]


def pe_remove_suffix(pe_name):
    parts = pe_name.split(".")
    if parts[-1] in SUFFIXES:
        return ".".join(parts[:-1])
    return pe_name


class Function(object):
    def __init__(self, function_name, pe_name, build_date, addr, package_name, is_exported_function=None):
        self.is_exported_function = is_exported_function
        if function_name is None or pe_name is None:
            raise ValueError("addr or function_name must not be None")

        if addr is not None and type(addr) != int:
            raise ValueError("address must be int")

        if len(function_name) < 2:
            raise ValueError("len function name must be bigger than 1")
        self.package_name = package_name
        self.build_date = build_date
        self.pe_name = pe_name
        self.function_name = function_name
        self._addr = addr

    def get_pe_name(self, is_include_suffix=True, is_lower=False):
        pe = self.pe_name
        if is_lower:
            pe = pe.lower()

        if is_include_suffix:
            return pe

        return pe_remove_suffix(pe)

    @property
    def addr(self):
        return self._addr

    @addr.setter
    def addr(self, x):
        if x is None or type(x) is int:
            self._addr = x
        else:
            raise ValueError("expected address to be int or None")

    def __hash__(self):
        return hash(f"{self.get_pe_name(False, True)} {self.function_name}")

    #   return hash(id(self))
    #     # because it's properties might be change but the hash isn't allowed to change it's hash.
    #     # return hash(self._str(True))

    def get_shorten_func_name(self, is_add_template_indication=True):
        if self.function_name is not None:
            return core.function.Function.get_basic_name(self.function_name, is_add_template_indication)
        return None

    def _str(self, is_create_unique):
        shorten_name = self.get_shorten_func_name()
        if is_create_unique:
            return f"{self.package_name}_{self.pe_name}!{shorten_name}@{self.addr}"

        return f"{self.pe_name}!{shorten_name}"

    def __str__(self):
        return f"{self.get_pe_name(False, True)} {self.function_name}"
        # return self._str(False)

    def __repr__(self):
        return self._str(False)

    def __eq__(self, obj):
        if obj.function_name != self.function_name:
            return False

        if obj.get_pe_name(False, True) != self.get_pe_name(False, True):
            return False

        if obj.addr is not None and self.addr is not None and obj.addr != self.addr:
            return False

        if obj.build_date is not None and self.build_date is not None and obj.build_date != self.build_date:
            return False

        if obj.package_name is not None and self.package_name is not None and \
                obj.package_name != self.package_name:
            return False

        return True

    def get_sql_query(self, table_name, rows=None):
        str_rows = "*"
        if rows is not None:
            str_rows = core.utils.convert_iterable_to_sql_compatible(rows, False, False)

        sql = f"SELECT {str_rows} from {table_name} WHERE"
        if self.function_name is not None:
            sql += f" ranked_function_name == '{self.function_name}'"
        elif self.addr is not None:
            sql += f" ranked_address == '{self.addr}'"
        else:
            raise ValueError(f"function name or address must be not None {self}")

        sql += f" AND lower(ranked_pe_name) like '{self.get_pe_name(False,True)}%'"

        if self.package_name is not None:
            sql += f" AND lower(ranked_package_name) == '{self.package_name.lower()}'"

        if self.build_date is not None:
            sql += f" AND ranked_build_date == '{self.build_date}'"

        return sql
