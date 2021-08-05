import compare.compare
import core.score
import features.feature
import features.groupby


class ChangesPes(features.feature.PEFeature):
    METHOD_NAME = "ChangesPes"

    def __init__(self):
        compared_number = 2
        group_by = features.groupby.GroupByOrderedPE(compared_number)
        super().__init__(type(self).METHOD_NAME, compared_number, group_by)

    def _score(self, compare_object):
        changed = len(list(compare_object.get_changes(compare.compare.TypesOfChanges.CHANGED)))
        added = len(list(compare_object.get_changes(compare.compare.TypesOfChanges.ADDED)))
        removed = len(list(compare_object.get_changes(compare.compare.TypesOfChanges.REMOVED)))
        total_sum = changed + added + removed
        if total_sum > 0:
            score = 100 / (total_sum * 2)
        else:
            score = -10
        new = compare_object.objects_to_compare[compare.compare.NEWEST]
        old = compare_object.objects_to_compare[compare.compare.OLDEST]
        is_dot_net = new.is_dot_net()
        if is_dot_net:
            score = 30

        yield core.score.Score(score, type(self), [new], [old], diff=total_sum, is_dotnet=is_dot_net)


class Mock(features.feature.PEFeature):
    METHOD_NAME = "Mock"

    def __init__(self):
        compared_number = 2
        group_by = features.groupby.GroupByOrderedPE(compared_number)
        super().__init__(type(self).METHOD_NAME, compared_number, group_by)

    def _score(self, compare_object):
        score = 10
        new = compare_object.objects_to_compare[compare.compare.NEWEST]
        old = compare_object.objects_to_compare[compare.compare.OLDEST]
        first_func = list(new.get_all_functions())
        if len(first_func) > 0:
            first_name = new.get_function_name(first_func[0])
        else:
            first_name = "none"
        old_func = list(old.get_all_functions())
        if len(old_func)> 0:
            old_name = new.get_function_name(old_func[0])
        else:
            old_name = "none"
        for i in range(1000):
            yield core.score.Score(score, type(self), [new], [old], name=first_name, old_name=old_name)
