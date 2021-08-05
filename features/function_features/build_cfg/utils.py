import logging

import compare.compare
import core.score


def additional_params(func_obj):
    ranked_is_exported_function = func_obj.is_exported_func()
    exported_name = func_obj.get_exported_name()
    basic_dict = {}
    if exported_name is not None:
        basic_dict.update(add_entry_point_indication(func_obj))

    basic_dict.update({"ranked_is_exported_function": ranked_is_exported_function,
                       "ranked_exported_name": exported_name})
    return basic_dict


def imported_xref_arguments(xref_addr, pe_obj):
    xref_imported_func_name = pe_obj.get_imported_function_name(xref_addr)
    xref_imported_module = pe_obj.get_module_name_function_imported(xref_addr)
    return {
        "imported_module": xref_imported_module,
        "imported_function_name": xref_imported_func_name
    }


def cfg_info_to_score(compare_obj, type_of_feature, xref_addr, number_of_xrefs, **kwargs):
    func_obj = compare_obj.objects_to_compare[compare.compare.NEWEST]
    pe_obj = func_obj.get_pe_obj()
    if type(xref_addr) != int:  # TODO: because of a bug in combase.dll
        logging.error(f"{xref_addr} is not Int but {type(xref_addr)}, it's value is {xref_addr}")

    name_called_func = func_obj.get_pe_obj().get_function_name(xref_addr)
    change_calls = {"after": number_of_xrefs,
                    "address_after": xref_addr}
    change_calls.update(imported_xref_arguments(xref_addr, pe_obj))
    change_calls.update(additional_params(func_obj))
    change_calls.update(kwargs)
    base_score = 0
    return core.score.Score(base_score, type_of_feature, [func_obj],
                            type_of_change=compare_obj.type_of_change, reason=name_called_func, **change_calls)


def add_entry_point_indication(func_obj):
    return {"is_entry_point": True}
