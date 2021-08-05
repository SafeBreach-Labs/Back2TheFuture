import abc
import features.feature
import features.groupby
import core.function
import core.pe


class Statistic(features.feature.IterableOrchestrator, abc.ABC):
    def __init__(self, type_of_feature, method_name, amount_of_objects_required, group_by):
        """
        Sub-type of a feature that can extract result objects in the end of the execution, used for gather statistics
        that required to view all the PEs.
        :param type_of_feature: Type of the feature, function feature, PE feature...
        :param method_name: The name of the feature
        :param amount_of_objects_required: amount of objects required for the statistic,
        :param group_by: GroupBy object that groups PEs together.
        """
        super().__init__(type_of_feature, method_name, amount_of_objects_required, group_by)

    def iterate(self, input_object):
        ret_val = self.update_statistics(input_object)
        # I'm not sure why but raising StopIteration stops the next iterables there for this function returns empty list
        # raise StopIteration("statistic doesn't return value")
        if ret_val is None:
            return []

        return ret_val

    def update_statistics(self, compare_object):
        raise NotImplementedError("Abstract class")

    def get_summary(self):
        return self.stats_value

    def __str__(self):
        return f"{self.method_name} {self.stats_value}"

    def __repr__(self):
        return f"{self.method_name}"


class FunctionStatistic(Statistic, abc.ABC):
    def __init__(self, method_name, amount_of_objects_required, group_by):
        type_of_feature = core.function.Function
        super().__init__(type_of_feature, method_name, amount_of_objects_required, group_by)

    def normalize_object(self, compare_objs):
        """

        :rtype: object list of list of functions, first list is
        """
        #  convert list of objects(PEs) to list tuples, each tuple contains functions
        for compare_objs in compare_objs:
            yield compare_objs.get_all_functions()


class PEStatistic(Statistic, abc.ABC):
    def __init__(self, method_name, amount_of_objects_required, group_by):
        type_of_feature = core.pe.PE
        super().__init__(type_of_feature, method_name, amount_of_objects_required, group_by)

    def get_statistic(self):
        raise NotImplementedError("Abstract class")

    def normalize_object(self, compare_objs):
        return compare_objs
