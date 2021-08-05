import logging
import re
import collections

import integrations.com_server_attributes
import compare.compare
import core.score
import features.feature
import features.function_features.naming_parsing
from features.function_features.build_cfg.utils import additional_params, add_entry_point_indication


class CfgExtractorComObject(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "CfgExtractorComObject"

    def __init__(self):
        number_of_compared_objects = 1
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.ALL, number_of_compared_objects)

    @staticmethod
    def extract_class_name(vtable_name):
        class_name = re.findall('.*\<class (.*)\>', vtable_name)
        if class_name:
            return class_name[0]

    def _score(self, compare_object):
        # a better way to find all the COM objects:
        # 1. in each vtable - look for https://docs.microsoft.com/en-us/windows/win32/api/unknwn/nn-unknwn-iunknown
        #                               AddRef, Release, QueryInterface functions (not sure if it is required to be or between them or and).
        # 2.
        func_obj = compare_object.objects_to_compare[compare.compare.NEWEST]
        pe_obj = func_obj.get_pe_obj()
        clsids = set()
        vtables_xrefs = func_obj.get_all_vtables_points_to_func()
        for vtbl_name in vtables_xrefs:
            class_name = type(self).extract_class_name(vtbl_name)
            if not class_name:
                continue

            if class_name.startswith("CC"):  # TODO: @peleg find a better workaround.
                class_name = class_name[1:]

            clsid_addr = pe_obj.get_name_ea_simple('CLSID_' + class_name)
            if clsid_addr:
                clsids.add((clsid_addr, class_name))

        for clsid_addr, class_name in clsids:
            guid = pe_obj.get_GUID_from_addr(clsid_addr)
            kwargs = {"guid": guid, "class_name": class_name}
            kwargs.update(additional_params(func_obj))
            kwargs.update(add_entry_point_indication(func_obj))
            yield core.score.Score(0, type(self), [func_obj], type_of_change=compare_object.type_of_change, **kwargs)


class CfgExtractorIUnknown(features.feature.PEFeature):
    METHOD_NAME = "CfgExtractorIUnknown"
    def __init__(self):
        compared_number = 1
        group_by = features.groupby.GroupByOrderedPE(compared_number)
        super().__init__(type(self).METHOD_NAME, compared_number, group_by)

    def _score(self, compare_object):
        pe = compare_object.objects_to_compare[compare.compare.OLDEST]
        functions_to_find = ["QueryInterface", "AddRef", "Release"]
        classes_names = {}
        for ida_function_name, function_obj in pe.get_all_functions_by_name(True).items():
            class_obj = features.function_features.naming_parsing.extract_class_name(ida_function_name)
            matched_index = -1
            for index, matched_name in enumerate(functions_to_find):
                if features.function_features.naming_parsing.compare_names(ida_function_name, matched_name,
                                                                           is_strict_compare=False):
                    matched_index = index
                    break

            if matched_index != -1 and class_obj is not None:
                classes_names.setdefault(class_obj, set())
                classes_names[class_obj].add(matched_index)

        classes_found = []
        for class_name, matched_functions in classes_names.items():
            if len(matched_functions) == len(functions_to_find):
                classes_found.append(class_name)

        for ida_function_name, function_obj in pe.get_all_functions_by_name(True).items():
            class_obj = features.function_features.naming_parsing.extract_class_name(ida_function_name)
            if class_obj in classes_found and class_obj is not None:
                yield core.score.Result(type(self), [function_obj], class_name=class_obj)


class CfgExtractorComFunctions(features.feature.PEFeature):
    METHOD_NAME = "CfgExtractorComFunctions"

    def __init__(self):
        compared_number = 1
        group_by = features.groupby.GroupByOrderedPE(compared_number)
        super().__init__(type(self).METHOD_NAME, compared_number, group_by)

    def _generate_scores(self, class_attributes, matched_classes):
        amount_of_matches = len(matched_classes)
        for class_name, matched_functions_in_class in matched_classes.items():
            for function_obj, related_class_attribute in matched_functions_in_class:

                kwargs = {"amount_of_class_matched": amount_of_matches,
                          "amount_of_functions_matched_in_class": len(matched_functions_in_class),
                          "amount_of_functions_in_class": len(class_attributes)}

                for class_attribute in class_attributes:
                    if class_attribute['function_name'] == related_class_attribute:
                        kwargs.update(class_attribute)
                        break

                yield core.score.Result(type(self), [function_obj], **kwargs)

    def _score(self, compare_object):
        pe = compare_object.objects_to_compare[compare.compare.OLDEST]
        try:
            com_interfaces = integrations.com_server_attributes.extract_com_info(pe.path_pe)
        except ValueError:  # no com was found
            return
        for com_interface in com_interfaces:
            pe_functions_per_guid = self._extract_com_functions(com_interface)

            for guid, functions in pe_functions_per_guid.items():
                function_attributes = []
                for func in functions:
                    function_attributes.append(func["function_name"])

                classes = features.function_features.naming_parsing.get_class_names_by_function_names(pe, function_attributes)
                if len(classes) == 0:  # no matches
                    logging.info(f"could not find the class for {guid} {pe} with {function_attributes}")
                    continue

                yield from self._generate_scores(functions, classes)

    def _extract_com_functions(self, com_interfaces):
        pe_functions_per_guid = {}
        for com_interface, attributes in com_interfaces.items():
            pe_functions_per_guid.update({com_interface: []})
            for attribute in attributes:
                if not attribute["type_of_export"] == "function":
                    continue
                if not attribute['CLSID'] == com_interface:
                    logging.warning("clsid doesn't match to the one returned")

                pe_functions_per_guid[com_interface].append(attribute)
        return pe_functions_per_guid


def extract_arguments(minimal_arguments, com_guid_index, com_iid_index):
    def extract(all_consts, func_obj):
        if len(all_consts) < minimal_arguments:
            return {}
        if type(all_consts[com_guid_index]) is not int and type(all_consts[com_iid_index]) is not int:
            return {}

        pe_obj = func_obj.get_pe_obj()
        com_guid = pe_obj.get_GUID_from_addr(all_consts[com_guid_index])
        com_iid = pe_obj.get_GUID_from_addr(all_consts[com_iid_index])
        kwargs = {"com_guid": com_guid, "com_iid": com_iid}
        return kwargs

    return extract


class CfgExtractorComClientObject(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "CfgExtractorComClientObject"

    def __init__(self):
        number_of_compared_objects = 1
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.ALL, number_of_compared_objects)
        self.client_com_obj = {"CoCreateInstance": self._handle_CoCreateInstance,
                               "CoCreateInstanceEx": self._handle_CoCreateInstanceEx,
                               "CoGetClassObject": self._handle_CoGetClassObject}

    def _handle_CoCreateInstance(self, all_consts, func_obj):
        return extract_arguments(4, 0, 3)(all_consts, func_obj)

    def _handle_CoGetClassObject(self, all_consts, func_obj):
        return extract_arguments(5, 0, 3)(all_consts, func_obj)

    def _handle_CoCreateInstanceEx(self, all_consts, func_obj):
        if len(all_consts) < 4:
            return {}

        pe_obj = func_obj.get_pe_obj()
        com_guid = pe_obj.get_GUID_from_addr(all_consts[0])
        kwargs = {"com_guid": com_guid}
        return kwargs

    def _score(self, compare_object):
        # get_GUID_from_addr
        func_obj = compare_object.objects_to_compare[compare.compare.NEWEST]
        called_funcs = core.utils.safe_func_call({}, func_obj.get_arguments_called_functions)
        for called_func in called_funcs:
            for function_call in called_funcs[called_func]:
                kwargs = {}
                func_name = function_call['name']
                matched_func_found = None
                for reference_func_name in self.client_com_obj.keys():
                    is_matched = features.function_features.naming_parsing.compare_names(func_name, reference_func_name,
                                                                                         is_strict_compare=True,
                                                                                         is_ignore_args=True,
                                                                                         is_support_regex=False,
                                                                                         is_ignore_case_sensitive=True)
                    if is_matched:
                        matched_func_found = reference_func_name
                        break

                if matched_func_found is None:  # function wasn't found.
                    continue

                all_consts = features.function_features.changed_constants.extract_const_from_function_call(
                    function_call)  # co create instance
                kwargs = self.client_com_obj[matched_func_found](all_consts, func_obj)
                kwargs.update({"reason": matched_func_found})
                yield core.score.Score(0, type(self), [func_obj], type_of_change=compare_object.type_of_change,
                                       **kwargs)
