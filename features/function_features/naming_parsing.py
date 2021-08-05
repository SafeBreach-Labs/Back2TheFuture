import logging
import re
try:
    import Levenshtein
except Exception as e:
    print("failed to import Levenshtein, execute `pip install python-Levenshtein`")
    # raise
from fuzzywuzzy import fuzz
import core.configurations
import core.function

_VULNERABLE_FUNCTIONS = None


def __convert_mapping(mapping):
    t = dict()
    for vulnerable_functions, replaced_functions in mapping:
        for vulnerable_function in vulnerable_functions:
            t.update({vulnerable_function: replaced_functions})

    return t


def _get_vulnerable_functions():
    global _VULNERABLE_FUNCTIONS
    if _VULNERABLE_FUNCTIONS is None:
        mapping = core.configurations.get_global().configs.features.function.xrefs.vulnerable_functions_mapping
        _VULNERABLE_FUNCTIONS = __convert_mapping(mapping)

    return _VULNERABLE_FUNCTIONS


_LOGICAL_VULNERABLE_FUNCTIONS = None


def _get_logical_vulnerable_functions():
    global _LOGICAL_VULNERABLE_FUNCTIONS
    if _LOGICAL_VULNERABLE_FUNCTIONS is None:
        mapping = core.configurations.get_global().configs.features.function.xrefs.logical_vulnerable_fixup_mapping
        _LOGICAL_VULNERABLE_FUNCTIONS = __convert_mapping(mapping)

    return _LOGICAL_VULNERABLE_FUNCTIONS


def get_basic_name(complex_name):
    return core.function.Function.get_basic_name(complex_name, is_add_template_indication=False)


def _compare_regex_names(found_name, reference, is_strict_compare, is_ignore_case):
    flags = 0
    if is_ignore_case:
        flags = re.IGNORECASE

    if is_strict_compare:
        is_found = re.match(reference, found_name, flags)
        return is_found is not None

    amount_of_matches = len(re.findall(reference, found_name, flags))
    return amount_of_matches > 0


def compare_names(found_name, reference, is_strict_compare, is_ignore_args=True, is_support_regex=True, is_ignore_case_sensitive=True):
    if is_ignore_args:
        found_name = get_basic_name(found_name)

    if "*" in reference and is_support_regex:
        return _compare_regex_names(found_name, reference, is_strict_compare, is_ignore_case_sensitive)

    if is_strict_compare:
        # To support with __imp_ prefix.
        if found_name.endswith("_0"):  # Microsoft sometimes adds _0 suffix to functions.
            found_name = found_name[:-2]
        return found_name.endswith(reference)

    return reference in found_name


def extract_class_name(function_name):
    if "::" not in function_name:
        return None
    if function_name.count("::") == 1 and "<" not in function_name and ">" not in function_name:
        class_name = function_name[:function_name.index("::")]
        return class_name.split(" ")[-1]

    return None  # TODO: add parsing here.


def get_class_names_by_function_names(pe, function_names):
    all_function_names = pe.get_all_functions_by_name(is_demangled=True)
    matched = {}
    for function_name in function_names:
        pattern_to_search = f"::{function_name}"
        for ida_function_name, function_obj in all_function_names.items():
            if pattern_to_search in ida_function_name and ida_function_name.endswith(function_name):
                class_name = extract_class_name(ida_function_name)
                matched.setdefault(class_name, [])
                matched[class_name].append((function_obj, function_name))

    max_matches = 0
    for matches in matched.values():
        if len(matches) > max_matches:
            max_matches = len(matches)

    if len(function_names) != max_matches:
        logging.info("max amount of matches doesn't match amount of attributes")

    classes_to_return = {}
    for class_name, matches in matched.items():
        if len(matches) == max_matches:
            classes_to_return.update({class_name: matches})

    return classes_to_return


def _is_replaced_function(old_function_name, new_function_name, is_strict_compare, function_mapping):
    vulnerable_mapping = function_mapping
    for vulnerable_func_name in vulnerable_mapping:
        is_matched = compare_names(old_function_name, vulnerable_func_name, is_strict_compare)
        if not is_matched:
            continue

        mapping = vulnerable_mapping[vulnerable_func_name]
        for mapped_func_name in mapping:
            is_equal = compare_names(new_function_name, mapped_func_name, is_strict_compare)
            if is_equal:
                return True
    return False


def is_ignore_function_name(name):
    if name.startswith("sub_"):
        return True
    return False

#  ######################################Exported functions ###################################################


def is_name_related_to_sync(name):
    return is_name_related_to_lock(name) or is_name_related_to_unlock(name)


def is_name_related_to_lock(name):
    lower = name.lower()
    return "Lock" in name or "_lock" in lower


def is_name_related_to_unlock(name):
    lower = name.lower()
    return "Unlock" in name or "_unlock" in lower


def is_name_related_memory_free(name):
    lower = name.lower()
    return "Free" in name or "_free" in lower


def is_name_related_memory_allocation(name):
    lower = name.lower()
    alloc = "Alloc" in name or "_alloc" in lower
    malloc = "Malloc" in name or "_malloc" in lower
    new = "New" in name or "_new" in lower
    return malloc or alloc or new

#  ######################################## Match functions ###########################################


def is_name_is_strsafe_function(name):
    strsafe_functions = core.configurations.get_global().configs.features.function.xrefs.strsafe_function
    for strsafe_function in strsafe_functions:
        is_matched = compare_names(name, strsafe_function, False)
        if is_matched:
            return True

    return False


def is_name_known_vulnerable_func(name):
    vulnerable_mapping = _get_vulnerable_functions()
    for known_vulnerable_func in vulnerable_mapping:
        is_matched = compare_names(name, known_vulnerable_func, True)
        if is_matched:
            return True

    return False


def is_name_known_logical_vulnerable_func(name):
    """
    :param name: name of function.
    :return: list of replaced function names if found, else: return None.
    """
    vulnerable_mapping = _get_logical_vulnerable_functions()
    for vuln_func_name in vulnerable_mapping:
        if compare_names(name, vuln_func_name, False):
            return True

    return False


def is_function_is_fixup(name):
    function_fixup = core.configurations.get_global().configs.features.function.xrefs.logical_vulnerable_fixup
    for function_name in function_fixup:
        is_matched = compare_names(name, function_name, False)
        if is_matched:
            return True

    return False


def is_function_is_deprecated(name):
    deprecated_functions = core.configurations.get_global().configs.features.function.xrefs.deprecated_functions
    for deprecated_function_name in deprecated_functions:
        is_matched = compare_names(name, deprecated_function_name, True)
        if is_matched:
            return True

    return False


def is_name_is_int_safe_functions(name):
    intsafe_function_names = core.configurations.get_global().configs.features.function.xrefs.int_safe_functions
    for intsafe_function_name in intsafe_function_names:
        is_matched = compare_names(name, intsafe_function_name, False)
        if is_matched:
            return True

    return False

#  ##############################Mapping functions ###############################################


def replaced_logical_vulnerable_function(old_function_name, new_function_name):
    """
    :param new_function_name:
    :param old_function_name: name of function.
    :return: list of replaced function names if found, else: return None.
    """
    is_strict_compare = False
    return _is_replaced_function(old_function_name, new_function_name, is_strict_compare,
                                 _get_logical_vulnerable_functions())


def replaced_vulnerable_function(old_function_name, new_function_name):
    """
    :param new_function_name:
    :param old_function_name: name of function.
    :return: list of replaced function names if found, else: return None.
    """
    is_strict_compare = True
    new_basic_func_name = get_basic_name(new_function_name)
    old_basic_func_name = get_basic_name(old_function_name)
    return _is_replaced_function(old_basic_func_name, new_basic_func_name, is_strict_compare,
                                 _get_vulnerable_functions())


def replaced_similar_functions(old_function_name, new_function_name):
    new_basic_func_name = get_basic_name(new_function_name)
    old_basic_func_name = get_basic_name(old_function_name)
    # the function didn't really changed (name or the parameters)
    if new_function_name == old_function_name or old_basic_func_name == new_basic_func_name:
        return False

    # We're going to ignore that
    if is_ignore_function_name(old_basic_func_name) or is_ignore_function_name(new_basic_func_name):
        return False

    if compare_names(new_basic_func_name, old_basic_func_name, False, is_support_regex=False):
        return True

    received_ratio = fuzz.ratio(old_function_name, new_function_name)
    minimal_ratio = core.configurations.get_global().configs.features.function.minimal_ratio_match
    if received_ratio > minimal_ratio:
        return received_ratio

    return False

