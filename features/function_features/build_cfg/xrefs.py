import collections
import compare.compare_function
import compare.compare
import core.score
import features.feature
import features.function_features.overview_functions
from features.function_features.build_cfg.utils import cfg_info_to_score
import features.function_features.changed_constants
import core.utils


class CfgExtractorXref(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "CfgExtractorXref"

    def __init__(self, is_include_args=False):
        self.is_include_args = is_include_args
        number_of_compared_objects = 1
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.ALL, number_of_compared_objects)

    @staticmethod
    def _get_deref_func_call(pe_obj, values_called):
        values = []
        types = []
        sizes = []
        if len(values_called) == 0:  # no args
            return None, None, None

        for value_called in values_called:
            if type(value_called) != int:
                values.append(None)
                types.append(None)
                sizes.append(None)
            else:
                ret_val = pe_obj.get_value_from_addr(value_called)
                if ret_val is None:
                    values.append(None)
                    types.append(None)
                    sizes.append(None)
                else:
                    arg_size, arg_type, arg_value = ret_val
                    values.append(arg_value)
                    types.append(arg_type)
                    sizes.append(arg_size)

        # ignore values which are empty.
        if set(values) == {None}:
            values = None
        if set(types) == {None}:
            types = None
        if set(sizes) == {None}:
            sizes = None

        return values, types, sizes

    @staticmethod
    def _get_deref_func_calls(pe_obj, values_calls):
        calls = {"poi_values": [], "poi_types": [], "poi_sizes": []}
        if values_calls is None:
            values_calls = []

        for func_call in values_calls:
            values, types, sizes = CfgExtractorXref._get_deref_func_call(pe_obj, func_call)
            calls["poi_values"].append(values)
            calls["poi_types"].append(types)
            calls["poi_sizes"].append(sizes)

        if None in calls["poi_sizes"]:
            calls["poi_sizes"].remove(None)
        if None in calls["poi_types"]:
            calls["poi_types"].remove(None)
        if None in calls["poi_values"]:
            calls["poi_values"].remove(None)
        # if there is no new input - return None.
        if len([i for i in calls["poi_values"] if i is not None]) == 0:
            calls["poi_values"] = None
        if len([i for i in calls["poi_types"] if i is not None]) == 0:
            calls["poi_types"] = None
        if len([i for i in calls["poi_sizes"] if i is not None]) == 0:
            calls["poi_sizes"] = None
        return calls

    def _score(self, compare_object):
        func_obj = compare_object.objects_to_compare[compare.compare.NEWEST]
        pe_obj = func_obj.get_pe_obj()
        called_funcs = {}
        if self.is_include_args:
            called_funcs = core.utils.safe_func_call({}, func_obj.get_arguments_called_functions)

        xrefs_counter = collections.Counter(func_obj.get_all_called_functions(True))
        ranked_function_size = func_obj.get_amount_of_opcodes()
        for address, count in xrefs_counter.items():
            kwargs = self.gather_xref_info(address, called_funcs, pe_obj, ranked_function_size)
            yield cfg_info_to_score(compare_object, type(self), address, count, **kwargs)

        # To support function which are called dynamically and the decompiler resolve them but they are not shown
        # from Xrefs
        for address in called_funcs.keys():
            if address in xrefs_counter:
                continue

            count = len(called_funcs[address])
            kwargs = self.gather_xref_info(address, called_funcs, pe_obj, ranked_function_size)
            yield cfg_info_to_score(compare_object, type(self), address, count, **kwargs)

        if len(xrefs_counter) == 0:  # function without xrefs to know it is not a missing function.
            yield core.score.Score(0, type(self), [func_obj], type_of_change=compare_object.type_of_change)

    def gather_xref_info(self, address, called_funcs, pe_obj, ranked_function_size):
        kwargs = {"ranked_amount_of_opcodes": ranked_function_size}
        found_args = set()  # the function count might be different from ranked_function_size.
        if address in called_funcs:
            for func_call in called_funcs[address]:
                args = features.function_features.changed_constants.extract_const_from_function_call(func_call)
                if len([i for i in args if i is not None]) == 0:
                    continue

                found_args.add(tuple(args))  # list is not hashable, only unique calls.
            found_args_l = list(found_args)
            if len(found_args_l) == 0:
                found_args_l = None
            kwargs.update({"args": found_args_l})
            ref_pointers = type(self)._get_deref_func_calls(pe_obj, found_args_l)
            kwargs.update(ref_pointers)
        return kwargs


