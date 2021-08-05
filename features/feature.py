import threading

import core.pe
import abc
import features.groupby
import core.function


class IterableOrchestrator(abc.ABC):
    def __init__(self, type_of_feature, method_name, amount_of_objects_required, group_by):
        """
        An iterator for the orchestrator,
        :param type_of_feature: Type of the feature, which object is it using, it is looking for PEs? functions? ...
        :param method_name: Name of the feature
        :param amount_of_objects_required: Amount of objects required for iteration, 1 - for a specific object,
                                           for 2 or more, if you want to compare versions of the object
        :param group_by: Group by object that will receive list of all the objects and it will group the objects into a
                         format compatible for this instance.
        """
        self.group_by = group_by
        self.amount_of_objects_required = amount_of_objects_required
        self.method_name = method_name
        self.type_of_feature = type_of_feature

    def filter_objects(self, compare_obj):
        """
        Filter, if your feature doesn't support all the objects and you want to investigate only specific features,
        call this feature.
        :param compare_obj: A compare object, in the same format the iterate function will get in case it will
                            not filter out.
        :return: True if to keep the compare, False to discard the object.
        """
        return True

    def iterate(self, input_object):
        """
        Extract all the results (patterns) from an object
        :param input_object: Compare object, even if it is 1 object. it will be a compare object.
        :return: An iterable that contains all the results of the feature for that object
        """
        raise NotImplementedError("This is abstract class")


class Feature(IterableOrchestrator, abc.ABC):
    def __init__(self, type_of_feature, score_method_name, amount_of_object_required, group_by):
        """

        :param type_of_feature:
        :param score_method_name:
        :param amount_of_object_required:
        :param group_by:
        """
        super().__init__(type_of_feature, score_method_name, amount_of_object_required, group_by)

    def _score(self, args):
        """
        Override this function instead of `iterate` function. in order to support all the overrides.
        :param args: compare object like the function `iterate`
        :return: Iterable
        """
        raise NotImplementedError("override this function")

    def iterate(self, compare_object):
        """
        Score the objects according to the feature. the higher the score - the more likely it is to be vulnerable.
        :param compare_object: compare object.
        :return: iterator (list/generator) of scores.
                 In case the feature is not relevant to that objects - returns empty iterator (empty list).
        """
        if self.filter_objects(compare_object):
            return self._score(compare_object)
        return []

    def __str__(self):
        return self.method_name

    def __repr__(self):
        return str(self)


# abstract classes

class PEFeature(Feature, abc.ABC):
    """

    """
    def __init__(self, score_method_name, amount_of_object_required, group_by):
        super().__init__(core.pe.PE, score_method_name, amount_of_object_required, group_by)


class FunctionFeature(Feature, abc.ABC):
    """
    Abstract Function feature facade, it plausible use SimpleFunctionFeature
    """
    def __init__(self, score_method_name, amount_of_object_required, group_by):
        super().__init__(core.function.Function, score_method_name, amount_of_object_required, group_by)


class GlobalFeature(PEFeature, abc.ABC):
    """

    """
    def __init__(self, score_method_name):
        amount_of_object_required = None
        group_by = features.groupby.GroupAllPE()
        super().__init__(core.pe.PE, score_method_name, amount_of_object_required, group_by)


class SingleTimeFeature(Feature, abc.ABC):
    def __init__(self, type_of_feature, score_method_name):
        """

        :param type_of_feature:
        :param score_method_name:
        """
        self.is_returned = False
        self.lock = threading.Lock()
        group_by = features.groupby.GroupOneTime()
        super().__init__(type_of_feature, score_method_name, -1, group_by)

    def iterate(self, compare_object):
        ret_val = []
        self.lock.acquire()
        if not self.is_returned:
            self.is_returned = True
            self.lock.release()
            ret_val = self._score(compare_object)
        else:
            self.lock.release()

        return ret_val


class SimpleFunctionFeature(FunctionFeature, abc.ABC):
    def __init__(self, score_method_name, type_of_change=None, number_of_compared_objects=2):
        """
        simplify way of function feature, that will extract all the patterns found.
        :param score_method_name: the name of the feature.
        :param type_of_change: compare.compare.TypesOfChanges, to filter which changes are you interesting to investigate.
        :param number_of_compared_objects: Number of functions to compare, 1 - no compare, 2 - compare 2 versions.
        """
        compared_number = number_of_compared_objects
        group_by = features.groupby.GroupByChangedFunctions(compared_number, get_changes=lambda x: x.get_changes(type_of_change))
        super().__init__(score_method_name, compared_number, group_by)
