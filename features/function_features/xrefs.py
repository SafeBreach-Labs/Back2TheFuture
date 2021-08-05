import compare.compare
import core.score
import features.feature
import features.function_features.naming_parsing
import features.groupby
from features.function_features import naming_parsing


import collections
import compare.compare_function
import features.function_features.overview_functions
from features.function_features.build_cfg.utils import cfg_info_to_score
import features.function_features.changed_constants
import core.utils


def score_xref_function_name(feature_type, compare_object, scores, reduce_function, type_of_change=compare.compare.TypesOfChanges.CHANGED, **kwargs):
    for xref_to_look_type_of_change, base_score, pe_index in scores:
        xref_changes = compare_object.get_changed_called_functions(xref_to_look_type_of_change)
        pe_obj = compare_object.objects_to_compare[pe_index].get_pe_obj()
        for added_func in xref_changes:
            function_name = pe_obj.get_function_name(added_func[pe_index][0], False)  # TODO: update to short format
            is_match_lock = reduce_function(function_name)
            if is_match_lock:
                change_calls = {"before": added_func[compare.compare.OLDEST][1],
                                "after": added_func[compare.compare.NEWEST][1],
                                "address_before": added_func[compare.compare.OLDEST][0],
                                "address_after": added_func[compare.compare.NEWEST][0]
                                }
                change_calls.update(kwargs)
                yield core.score.Score(base_score, feature_type,
                                       [compare_object.objects_to_compare[compare.compare.NEWEST]],
                                       [compare_object.objects_to_compare[compare.compare.OLDEST]],
                                       reason=function_name, type_of_change=type_of_change, **change_calls)


def score_mapping_replaced_functions(feature_type, compare_object, base_score, is_functions_are_interesting_replacing
                                     , **kwargs):
    xref_changes = compare_object.get_changed_called_functions(compare.compare.TypesOfChanges.REMOVED)
    xref_changes = xref_changes.union(compare_object.get_changed_called_functions(compare.compare.TypesOfChanges.ADDED))
    xref_changes = xref_changes.union(compare_object.get_changed_called_functions(compare.compare.TypesOfChanges.CHANGED))
    replaced_functions = detect_replaced_functions(xref_changes)
    new_pe_obj = compare_object.objects_to_compare[compare.compare.NEWEST].get_pe_obj()
    old_pe_obj = compare_object.objects_to_compare[compare.compare.OLDEST].get_pe_obj()
    for before_func, after_func, diff in replaced_functions:
        if before_func[0] is None or after_func[0] is None:
            raise ValueError("didn't expect to have mapping with None")

        before_func_name = old_pe_obj[before_func[0]].function_name(True)
        after_func_name = new_pe_obj[after_func[0]].function_name(True)

        is_interesting_replacement = is_functions_are_interesting_replacing(old_pe_obj[before_func[0]].function_name(False),
                                                                            new_pe_obj[after_func[0]].function_name(False))
        if is_interesting_replacement:
            change_calls = {"name_before": before_func_name,
                            "name_after": after_func_name,
                            "before": before_func[1],
                            "after": after_func[1],
                            "diff": diff,
                            "address_before": before_func[0],
                            "address_after": after_func[0]}
            score = base_score
            if type(is_interesting_replacement) == int:
                score = base_score + (is_interesting_replacement / 4)

            change_calls.update(kwargs)
            yield core.score.Score(score, feature_type,
                                   [compare_object.objects_to_compare[compare.compare.NEWEST]],
                                   [compare_object.objects_to_compare[compare.compare.OLDEST]],
                                   type_of_change=compare.compare.TypesOfChanges.CHANGED,
                                   **change_calls)


def detect_replaced_functions(function_calls):
    """

    :param function_calls: list of tuples ((address old (int), number of xrefs before(int)), (address_new(int), number_of_xrefs (int)))
    :return: list of tuples (function_call, function_call)
    """
    added = {}
    removed = {}
    for function_call_before, function_call_after in function_calls:
        before = function_call_before[1]
        after = function_call_after[1]
        diff = after - before

        chosen_dict = added
        chosen_call = function_call_after
        if diff < 0:
            chosen_dict = removed
            chosen_call = function_call_before

        if diff not in chosen_dict:
            chosen_dict[diff] = []

        if chosen_call[0] is None:  # no function address
            continue

        chosen_dict[diff].append(chosen_call)

    swapped = []
    for diff, added_funcs in added.items():
        if diff <= 0:  # we're going to ignore no changes or negative change (to reduce double mapping)
            continue
        for added_func in added_funcs:
            replaced_functions = removed.get(-diff, [])
            for old_fun in replaced_functions:
                swapped.append([old_fun, added_func, diff])

    return swapped


#  ################################ Features from known list ###############################################

class XrefVulnerableFunctions(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "XrefVulnerableFunctions"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        scores = [(compare.compare.TypesOfChanges.CHANGED, 50, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.ADDED, 20, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.REMOVED, 50, compare.compare.OLDEST)
                  ]
        for score in score_xref_function_name(type(self), compare_object, scores,
                                              naming_parsing.is_name_known_vulnerable_func):
            yield score


class XrefLogicalVulnerableFunctions(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "XrefLogicalVulnerableFunctions"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        scores = [(compare.compare.TypesOfChanges.CHANGED, 50, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.ADDED, 25, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.REMOVED, 10, compare.compare.OLDEST)
                  ]
        for score in score_xref_function_name(type(self), compare_object, scores,
                                              features.function_features.naming_parsing.is_name_known_logical_vulnerable_func):
            yield score


class LogicalVulnerableFixup(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "LogicalVulnerableFixup"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        scores = [(compare.compare.TypesOfChanges.CHANGED, 40, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.ADDED, 70, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.REMOVED, 10, compare.compare.OLDEST)
                  ]

        for score in score_xref_function_name(type(self), compare_object, scores,
                                              naming_parsing.is_function_is_fixup):
            yield score


class StrSafeFunction(features.feature.SimpleFunctionFeature):
    #  https://docs.microsoft.com/en-us/windows/win32/api/strsafe/
    #  https://www.defcon.org/images/defcon-18/dc-18-presentations/Oh/DEFCON-18-Oh-Exploit-Spotting.pdf
    METHOD_NAME = "StrSafeFunction"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        scores = [(compare.compare.TypesOfChanges.CHANGED, 10, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.ADDED, 30, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.REMOVED, -5, compare.compare.OLDEST)
                  ]

        for score in score_xref_function_name(type(self), compare_object, scores,
                                              features.function_features.naming_parsing.is_name_is_strsafe_function):
            yield score


class IntSafeFunctions(features.feature.SimpleFunctionFeature):
    # int_safe_functions should be inline but inline (recommended to the compiler) we might catch that.
    METHOD_NAME = "IntSafeFunctions"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        scores = [(compare.compare.TypesOfChanges.CHANGED, 15, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.ADDED, 40, compare.compare.NEWEST),
                  ]

        # TODO: add overflow/underflow CWE score.
        for score in score_xref_function_name(type(self), compare_object, scores,
                                              features.function_features.naming_parsing.is_name_is_int_safe_functions):
            yield score


class DeprecatedFunctions(features.feature.SimpleFunctionFeature):
    # https://docs.microsoft.com/en-us/previous-versions/windows/desktop/legacy/jj635743(v=vs.85)
    METHOD_NAME = "DeprecatedFunctions"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        scores = [(compare.compare.TypesOfChanges.CHANGED, 20, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.ADDED, -5, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.REMOVED, 30, compare.compare.OLDEST)
                  ]

        for score in score_xref_function_name(type(self), compare_object, scores,
                                              features.function_features.naming_parsing.is_function_is_deprecated):
            yield score

#  ###################### by parsing the name ############################


class XrefLockFunction(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "XrefLockFunction"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        scores = [(compare.compare.TypesOfChanges.CHANGED, 30, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.ADDED, 15, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.REMOVED, 5, compare.compare.OLDEST)
                  ]
        for score in score_xref_function_name(type(self), compare_object, scores,
                                              naming_parsing.is_name_related_to_sync,
                                              relevant_cwes=[411]):
            yield score


class FreeFunctions(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "FreeFunctions"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        scores = [(compare.compare.TypesOfChanges.CHANGED, 20, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.ADDED, 15, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.REMOVED, 10, compare.compare.OLDEST)
                  ]

        # TODO: add CWE score.
        for score in score_xref_function_name(type(self), compare_object, scores,
                                              features.function_features.naming_parsing.is_name_related_memory_free):
            yield score


class AllocFunctions(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "AllocFunctions"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        scores = [(compare.compare.TypesOfChanges.CHANGED, 20, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.ADDED, 15, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.REMOVED, 10, compare.compare.OLDEST)
                  ]

        # TODO: add CWE score.
        for score in score_xref_function_name(type(self), compare_object, scores,
                                              features.function_features.naming_parsing.is_name_related_memory_allocation):
            yield score


#  ########################### Mappings #############################################


class ReplacedLogicalFunctions(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "ReplacedLogicalFunctions"

    def __init__(self):
        """
        Looks for functions replaced from PathCombine to PathCchCombine
        """
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        base_score = 75
        for score in score_mapping_replaced_functions(type(self), compare_object, base_score,
                                                      features.function_features.naming_parsing.replaced_logical_vulnerable_function):
            yield score


class ReplacedVulnerableFunctions(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "ReplacedVulnerableFunctions"

    def __init__(self):
        """
        looks for functions such as strcmp to strcmp_s
        """
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        base_score = 70
        for score in score_mapping_replaced_functions(type(self), compare_object, base_score,
                                                      features.function_features.naming_parsing.replaced_vulnerable_function):
            yield score


class ReplacedSimilarFunctions(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "ReplacedSimilarFunctions"

    def __init__(self):
        """
        looks for functions with a similar name (not known functions )
        """
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        base_score = 40
        for score in score_mapping_replaced_functions(type(self), compare_object, base_score,
                                                      features.function_features.naming_parsing.replaced_similar_functions):
            yield score
            

class DirectoryTraversal(features.feature.FunctionFeature):
    METHOD_NAME = "DirectoryTraversal"

    def __init__(self):
        number_of_compared_objects = 2
        self.compatible_functions = ["wcsstr", "strstr", "StrStrIW"]
        changes = [compare.compare.TypesOfChanges.CHANGED, compare.compare.TypesOfChanges.ADDED]
        group_by = features.groupby.GroupByChangedFunctions(number_of_compared_objects,
                                                            get_changes=lambda x: x.get_multiple_changes(changes))
        super().__init__(type(self).METHOD_NAME, number_of_compared_objects, group_by)

    def is_compatible_func(self, found_function_name):
        for referenced_func_name in self.compatible_functions:
            if features.function_features.naming_parsing.compare_names(found_function_name, referenced_func_name, False):
                return True
        return False

    def _score(self, compare_object):
        func_obj = compare_object.objects_to_compare[compare.compare.NEWEST]
        if func_obj is None:
            return

        called_funcs = func_obj.get_arguments_called_functions()
        for ea, function_calls in called_funcs.items():
            for function_call in function_calls:
                isEquals = self.is_compatible_func(function_call['name'])
                if isEquals:
                    args = features.function_features.changed_constants.extract_const_from_function_call(function_call)
                    for arg in args:
                        if arg is not None and ("../" == arg or "..\\"==arg):
                            yield core.score.Score(80, type(self), [func_obj], type_of_change=compare_object.type_of_change, arg="../", args=args)
                        else:
                            yield core.score.Score(5, type(self), [func_obj], type_of_change=compare_object.type_of_change, args=args)
