import compare.compare
import core.score
import features.feature
import features.groupby
import core.function


class ControllablePaths(features.feature.PEFeature):
    METHOD_NAME = "ControllablePaths"

    def __init__(self, is_run_on_elevated_only=True):
        compared_number = 1
        group_by = features.groupby.GroupByOrderedPE(compared_number)
        self.is_run_on_elevated_only = is_run_on_elevated_only
        super().__init__(type(self).METHOD_NAME, compared_number, group_by)

    def filter_objects(self, compare_objects):
        if not self.is_run_on_elevated_only:
            return True

        oldest = compare_objects.objects_to_compare[compare.compare.OLDEST]
        return oldest.is_can_run_as_elevated()

    def _score(self, compare_object):
        pe = compare_object.objects_to_compare[compare.compare.OLDEST]
        results = pe.get_controllable_paths()
        for result in results:
            related_function = result.pop('function_address', None)
            ranked_feature = pe
            if related_function is not None:
                ranked_feature = pe[related_function]

            yield core.score.Result(type(self), [ranked_feature], type_of_feature=core.function.Function, **result)
