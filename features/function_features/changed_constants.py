import logging

import compare.compare
import core.score
import features.feature
import features.groupby
import core.function
import core.configurations

IGNORE_LIST = ["__security_check_cookie"]

def index_function_argument_in_list(function_call, function_calls):
    func_call_args = extract_const_from_function_call(function_call)
    for index, current_func_call in enumerate(function_calls):
        cur_args = extract_const_from_function_call(current_func_call)
        # TODO: check it is not a global PTR because it means that after each compilation it's address will be changed
        if func_call_args == cur_args:
            return index
    return -1


def extract_const_from_function_call(function_arguments):
    arguments = []
    for arg in function_arguments['args']:
        value = arg.get("val", None)
        if arg.get("type_param", None) == "number" or arg.get("type_param", None) == "ref":
            try:
                value = int(value)
            except (ValueError, TypeError):
                pass
        arguments.append(value)
    return arguments


def compare_functions_constants(type_feature, compare_object, base_score, match_func):
    """

    :param type_feature: class type of the feature
    :param compare_object: func compare obj
    :param base_score: a number for calculating the score
    :param match_func: function which gets function_call and function_calls and return index if it found a match
                        incase it didn't find - return negative number.
    :return:
    """
    is_debug = core.configurations.get_global().configs.is_debug
    invalid_addr = 0xffffffffffffffff
    new = compare_object.objects_to_compare[compare.compare.NEWEST]
    old = compare_object.objects_to_compare[compare.compare.OLDEST]
    new_arguments = new.get_arguments_called_functions()
    old_arguments = old.get_arguments_called_functions()
    # TODO: we might want to add "compare.compare.TypesOfChanges.CHANGED" to the list and change the success condition.
    all_changes = compare_object.get_multiple_types_of_changes([compare.compare.TypesOfChanges.NOT_CHANGED])
    for function_called in all_changes:
        old_func_addr = function_called[compare.compare.OLDEST][0]  # address
        new_func_addr = function_called[compare.compare.NEWEST][0]
        if new_func_addr not in new_arguments or old_func_addr not in old_arguments:
            # for cases such as __guard_dispatch_icall_fptr which ida doesn't know which function is getting called.
            if (invalid_addr not in new_arguments or invalid_addr not in old_arguments) and is_debug:
                new_func_mangled_name = new.get_pe_obj().get_function_name(new_func_addr)
                old_func_mangled_name = old.get_pe_obj().get_function_name(old_func_addr)
                if new_func_mangled_name in IGNORE_LIST or old_func_mangled_name in IGNORE_LIST:
                    continue

                logging.info(
                    f"expected {new_func_addr} to be in {new_arguments.keys()} and {old_func_addr} to be in {old_arguments.keys()}, "
                    f"not found function_name: {new_func_mangled_name}, {old_func_mangled_name}")

            continue

        for new_func_call in new_arguments[new_func_addr]:
            score = base_score
            index = match_func(new_func_call, old_arguments[old_func_addr])
            if index < 0:  # not found -> should return score.
                new_function_name = new.get_pe_obj()[new_func_addr].function_name()
                amount_of_new_values = len([i for i in extract_const_from_function_call(new_func_call) if i is not None])
                score += 10 / (amount_of_new_values + 1)
                kwargs = {"args_after": new_func_call['args'],
                          "func_name_new": new_function_name,
                          "address_after": new_func_call['call_ea'],
                          "amount_of_arguments_new": len(new_func_call['args']),
                          "amount_of_const_values_new": amount_of_new_values}
                if len(old_arguments[old_func_addr]) == 1:
                    old_func_call = old_arguments[old_func_addr][0]
                    old_func_name = old.get_pe_obj()[old_func_addr].function_name()
                    is_good_match = True
                    score += 15
                    #  Some times the amount of parameters has changed such as argv/kwargs and it is still a good match
                    # but most of the times it will be an compiler issues.
                    if (len(old_func_call['args']) != len(new_func_call['args']) or old_func_name != new_function_name)\
                            and is_debug:
                        is_good_match = False
                        score += 30
                    amount_of_old_values = len(
                        [i for i in extract_const_from_function_call(old_func_call) if i is not None])
                    score += amount_of_old_values
                    kwargs.update({
                        "args_before": old_func_call['args'],
                        "address_before": old_func_call['call_ea'],
                        "is_good_match": is_good_match,
                        "func_name_old": old_func_name,
                        "amount_of_arguments_old": len(old_func_call['args']),
                        "amount_of_const_values_old": amount_of_old_values
                    })

                yield core.score.SimpleCompareObjScore(score, type_feature, compare_object, **kwargs)
            else:
                val = old_arguments[old_func_addr][index]
                old_arguments[old_func_addr].remove(val)  # it will remove only 1 instance of that.


class ChangedFunctionConstant(features.feature.SimpleFunctionFeature):
    """
    monitor amount of IFs added to the function
    """
    METHOD_NAME = "ChangedFunctionConstant"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        base_score = 20
        for i in compare_functions_constants(type(self), compare_object, base_score, index_function_argument_in_list):
            yield i
