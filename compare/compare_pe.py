import logging
import os
import sqlite3
import compare.compare
import compare.compare_function
import core.configurations
import pathlib2
import re
import shutil


def get_compare_location(pe1, pe2):
    root_compare_dir = core.configurations.get_global().configs.compare.diff_folder
    pe1_compare_dir = pathlib2.Path(root_compare_dir) / pe1.architecture / (pe1.package_name + "_" + pe1.name)
    if not os.path.exists(str(pe1_compare_dir)):
        raise FileNotFoundError("didn't find any compare", str(pe1_compare_dir))

    compiled_re = re.compile(rf".*_{pe1.version}_vs_.*_{pe2.version}")
    for file_name in os.listdir(str(pe1_compare_dir)):
        is_matched = compiled_re.match(file_name)
        if is_matched is not None:
            return pe1_compare_dir / file_name

    raise FileNotFoundError(f"could not find the compare folder {pe1} vs {pe2}")


def get_compare_db(pe1, pe2):
    location = get_compare_location(pe1, pe2)
    for file_name in os.listdir(location):
        if file_name.endswith(".BinDiff"):
            return os.path.join(location, file_name)

    files = os.listdir(location)
    logging.warning(f"failed to find *.bindiff list of files {files}  location: {location}")
    shutil.rmtree(location)
    raise EnvironmentError(f"didn't find BinDiff file {location} {pe1} {pe2}")


class ComparePE(compare.compare.Compare):
    def __init__(self, objects_to_compare, type_of_change):
        self.minimal_ratio = core.configurations.get_global().configs.compare.minimal_compare_ratio
        self.minimal_instructions = core.configurations.get_global().configs.compare.minimal_instructions
        self.full_mapping = None
        super().__init__(objects_to_compare, type_of_change)

    def _compare(self):
        raise NotImplementedError("yet")

    def _get_changes(self):
        for i in self._get_all_mappings():
            if i.similarity == 1.0:
                continue
            yield i

    def _get_all_mappings(self, is_include_all_matches=False, is_ignore_tiny_functions=True,
                          is_compare_by_func_name=True):
        if self.full_mapping is not None:
            return self.full_mapping

        full_mapping = []

        # is_showed_log = False
        if not len(self.objects_to_compare) == 2:
            raise NotImplementedError("not implemented")
        try:
            compare_db = get_compare_db(self.objects_to_compare[0], self.objects_to_compare[1])
        except FileNotFoundError as e:
            logging.error(f"could not find {e}")
            raise

        conn = sqlite3.connect(compare_db)
        cur = conn.cursor()
        all_new_functions = self.objects_to_compare[compare.compare.NEWEST].get_all_functions(
            not is_ignore_tiny_functions)  # compare by name
        sql_query = f'SELECT address1, address2, confidence, similarity from function'
        is_require_and = False
        if not is_include_all_matches:
            sql_query += f' WHERE CAST(confidence AS FLOAT) > {self.minimal_ratio}'
            is_require_and = True

        if is_ignore_tiny_functions:
            if is_require_and:
                sql_query += " AND"
            else:
                sql_query += " WHERE"
            sql_query += f" instructions > {self.minimal_instructions}"

        for function_addr1, function_addr2, confidence, similarity in cur.execute(sql_query):
            func_obj1 = self.objects_to_compare[compare.compare.OLDEST][function_addr1]
            func_obj2 = self.objects_to_compare[compare.compare.NEWEST][function_addr2]
            if func_obj2.addr in all_new_functions:  # For some reason there are more functions in the DB than in the IDB
                all_new_functions.remove(func_obj2.addr)
            # elif not is_showed_log:
            # logging.warning(f"{func_obj2.addr} is not in all_new_functions {self}")
            # is_showed_log = True

            mapping_by_bindiff = compare.compare_function.CompareFunctions([func_obj1, func_obj2], self,
                                                                           type_of_change=compare.compare.TypesOfChanges.CHANGED,
                                                                           confidence_match=confidence,
                                                                           similarity=similarity)
            full_mapping.append(mapping_by_bindiff)

        conn.close()
        if not is_compare_by_func_name:  # do not include the rest of the function.
            return

        for new_func_addr in all_new_functions:
            new_func = self.objects_to_compare[compare.compare.NEWEST][new_func_addr]
            new_func_name = new_func.function_name(is_short_format=False)  # full function name
            if new_func_name.startswith("sub_"):  # auto generated name by ida.
                continue

            old_func = self.objects_to_compare[compare.compare.OLDEST].get_function_by_name(new_func_name)
            if old_func is None:
                continue

            mapping_by_name = compare.compare_function.CompareFunctions([old_func, new_func], self,
                                                                        type_of_change=compare.compare.TypesOfChanges.CHANGED,
                                                                        confidence_match=0,
                                                                        similarity=0)
            full_mapping.append(mapping_by_name)

        # in order to not miss events in case of exception.
        self.full_mapping = full_mapping
        return self.full_mapping

    def _get_all_types(self):
        if len(self.objects_to_compare) == 2:
            gen = super()._get_all_types()
            for change in gen:
                yield change

        elif len(self.objects_to_compare) == 1:
            for func_addr in self.objects_to_compare[0].get_all_functions():
                func_obj = self.objects_to_compare[0][func_addr]
                yield compare.compare_function.CompareFunctions([func_obj], self, type_of_change=None)
        else:
            raise NotImplementedError("Not implemented yet")

    def _get_added(self):
        all_new_function_addr = set(self.objects_to_compare[compare.compare.NEWEST].get_all_functions())
        shared_func_addr = self.match_functions(self.objects_to_compare[compare.compare.NEWEST], all_new_function_addr,
                                                False)
        # match_functions returns all the functions in newest that exist on oldest.
        diff_function_addresses = all_new_function_addr.difference(shared_func_addr)
        for added_function in diff_function_addresses:
            added_func = self.objects_to_compare[compare.compare.NEWEST][added_function]
            yield compare.compare_function.CompareFunctions([None, added_func],
                                                            self,
                                                            type_of_change=compare.compare.TypesOfChanges.ADDED,
                                                            confidence_match=1)

    def _get_removed(self):
        all_function_addr = set(self.objects_to_compare[compare.compare.OLDEST].get_all_functions())
        shared_func_addr = self.match_functions(self.objects_to_compare[compare.compare.OLDEST], all_function_addr,
                                                False)
        # take only the unmatched functions, match_functions returns all the functions in oldest that exist on newest.
        diff_function_addresses = all_function_addr.difference(shared_func_addr)
        for removed_addr in diff_function_addresses:
            removed_func = self.objects_to_compare[compare.compare.OLDEST][removed_addr]
            yield compare.compare_function.CompareFunctions([removed_func, None], self,
                                                            type_of_change=compare.compare.TypesOfChanges.REMOVED,
                                                            confidence_match=1)

    def match_functions(self, object_to_compare, addresses, is_return_mapping, is_ignore_tiny_functions=True,
                        is_include_all_matches=False):
        """
        Match functions in a specific object to compare with all the other objects.
        :param is_return_mapping: is return tuple of address in 1 and addr in second object or return only matched functions.
        :param object_to_compare: one of the objects
        :param addresses: list of addresses to match or mapping, depends on is_return_mapping
        """
        key_index = compare.compare.OLDEST
        value_index = compare.compare.NEWEST
        if self.objects_to_compare[compare.compare.NEWEST] == object_to_compare:
            key_index = compare.compare.NEWEST
            value_index = compare.compare.OLDEST

        if not len(self.objects_to_compare) == 2:
            raise NotImplementedError("it is not planned to compare more objects than 2")

        if is_return_mapping:
            ret_val = dict()
        else:
            ret_val = set()

        for i in self._get_all_mappings(is_include_all_matches=is_include_all_matches,
                                        is_ignore_tiny_functions=is_ignore_tiny_functions):
            if i.objects_to_compare[key_index].addr in addresses:
                if is_return_mapping:
                    ret_val.update({i.objects_to_compare[key_index].addr: i.objects_to_compare[value_index].addr})
                else:
                    ret_val.add(i.objects_to_compare[key_index].addr)

        return ret_val

    def _get_not_changed(self):
        for i in self._get_all_mappings():
            if i.similarity == 1.0:
                i.type_of_change = compare.compare.TypesOfChanges.NOT_CHANGED
                yield i

    def __str__(self):
        return f"compare: {self.objects_to_compare}, type_of_change: {self.type_of_change}"
