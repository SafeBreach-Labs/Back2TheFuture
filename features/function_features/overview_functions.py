import compare.compare_function
import compare.compare
import core.score
import features.feature
import features.groupby


# all the functions that has changed
class ChangedFunctions(features.feature.FunctionFeature):
    METHOD_NAME = "ChangedFunctions"

    def __init__(self, type_of_changes=None):
        compared_number = 2
        if type_of_changes is None:
            changes = [compare.compare.TypesOfChanges.CHANGED,
                       compare.compare.TypesOfChanges.ADDED,
                       compare.compare.TypesOfChanges.REMOVED]
        else:
            changes = type_of_changes
        group_by = features.groupby.GroupByChangedFunctions(2, get_changes=lambda x: x.get_multiple_changes(changes))
        super().__init__(type(self).METHOD_NAME, compared_number, group_by)

    def _score(self, compare_object):
        function_name = None  # Find function name
        for obj in compare_object.objects_to_compare:
            if obj is None:
                continue
            function_name = obj.function_name(False)
            break

        if function_name is None or len(function_name) == 0:
            raise ValueError("function name expected to be not None")

        score = core.score.SimpleCompareObjScore(0, type(self), compare_object)
        # TODO: add is_exported function
        yield score


# all the xrefs that has changed
class ChangedXrefs(features.feature.FunctionFeature):
    METHOD_NAME = "ChangedXrefs"

    def __init__(self, type_of_changes=None, types_xref_monitored=None):
        """

        :param type_of_changes: (optional) which functions to monitor - list of TypeOfChanges  (compare.compare.TypeOfChanges...)
        :param types_xref_monitored: (optional) which xrefs to monitor in the selected functions list of TypeOfChanges (compare.compare.TypeOfChanges...)
        """
        compared_number = 2
        if type_of_changes is None:
            changes = [compare.compare.TypesOfChanges.CHANGED,
                       compare.compare.TypesOfChanges.ADDED,
                       compare.compare.TypesOfChanges.REMOVED]
        else:
            changes = type_of_changes

        base_scores = [(compare.compare.TypesOfChanges.CHANGED, 0, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.ADDED, 0, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.REMOVED, 0, compare.compare.OLDEST),
                  (compare.compare.TypesOfChanges.NOT_CHANGED, 0, compare.compare.NEWEST)]

        if types_xref_monitored is None:
            base_scores = base_scores[:-1]  # remove not_changed
            self.xref_monitored = base_scores
        elif compare.compare.TypesOfChanges.ALL in types_xref_monitored:
            self.xref_monitored = base_scores
        else:
            self.xref_monitored = []
            for type_xref in types_xref_monitored:
                for x in base_scores:
                    if x[0] == type_xref:
                        self.xref_monitored.append(x)

        group_by = features.groupby.GroupByChangedFunctions(compared_number, get_changes=lambda x: x.get_multiple_changes(changes))
        super().__init__(type(self).METHOD_NAME, compared_number, group_by)

    def _score(self, compare_object):
        scores = self.xref_monitored
        func_obj = compare_object.objects_to_compare[compare.compare.NEWEST]
        if func_obj is None:
            func_obj = compare_object.objects_to_compare[compare.compare.OLDEST]

        pe_obj = func_obj.get_pe_obj()
        for type_of_change, base_score, pe_index in scores:
            xref_changes = compare_object.get_changed_called_functions(type_of_change)
            for changed_function in xref_changes:
                yield self._create_score(base_score, changed_function, compare_object, pe_index, pe_obj)

    def _create_score(self, base_score, changed_function, compare_object, pe_index, pe_obj):
        # TODO: find the correct function name (it might because the PE is exist in both of them but the
        # function might not exist there.
        # TODO: add to score the address of the xref
        function_obj = pe_obj[changed_function[pe_index][0]]
        function_name = function_obj.function_name(False)  # TODO: update to short format
        # if function_name is None or len(function_name) <= 1:
        #     continue
        change_calls = {"before": changed_function[compare.compare.OLDEST][1],
                        "after": changed_function[compare.compare.NEWEST][1],
                        "address_before": changed_function[compare.compare.OLDEST][0],
                        "address_after": changed_function[compare.compare.NEWEST][0]}
        return core.score.SimpleCompareObjScore(base_score, type(self), compare_object,
                                               reason=function_name, **change_calls)
