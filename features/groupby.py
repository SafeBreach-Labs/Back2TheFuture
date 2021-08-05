import logging
import copy
import abc
import compare.compare
import compare.compare_function
import compare.compare_pe


class GroupBy(abc.ABC):
    def __init__(self, number_of_objects):
        self.number_of_objects = number_of_objects

    def group_by(self, all_objects, objects_to_compare=None):
        """
        Get list of PEs and it will return all the groups of that object.
        :param all_objects: all the objects
        :param objects_to_compare: list of objects from all_objects that should be grouped together
        """
        pass


def is_have_shared_objects(objects_1, objects_2):
    for object_1 in objects_1:
        if object_1 in objects_2:
            return True

    return False


def is_have_major_version_changes(group):
    versions = set()
    for i in group:
        versions.add(i.version.windows_major)

    if len(versions) > 1:
        logging.warning(f"found a major version change {group}")
        return True
    return False


class GroupByOrderedPE(GroupBy):
    def __init__(self, number_of_objects):
        super().__init__(number_of_objects)

    def group_by(self, versions_of_pe_gen, objects_to_compare=None):
        versions_of_pe = list(versions_of_pe_gen)
        versions_of_pe.sort(key=lambda x: x.version)
        total = len(versions_of_pe) - (self.number_of_objects - 1)
        for start_index in range(total):
            group = versions_of_pe[start_index:start_index + self.number_of_objects]
            if objects_to_compare is not None and \
                    is_have_shared_objects(objects_to_compare, group) is False:
                continue

            if is_have_major_version_changes(group):  # such as gdiplus.dll
                continue

            compare_pe = compare.compare_pe.ComparePE(group, type_of_change=compare.compare.TypesOfChanges.CHANGED)
            yield compare_pe


class GroupByChangedFunctions(GroupBy):
    def __init__(self, number_of_objects, get_changes=None):
        """
        Group by function changed order matter. for example
        :param number_of_objects: number of functions to join
        :param get_changes: function which get 1 object (ComparePE) and returns the required changes (such as
                            get_all_changes, get_removed, get_added etc.)
        """
        if get_changes is None:
            self.get_changes = lambda x: x.get_changes()
        else:
            self.get_changes = get_changes

        super().__init__(number_of_objects)

    def group_by(self, versions_of_pe_gen, objects_to_compare=None):
        versions_of_pe = list(versions_of_pe_gen)
        versions_of_pe.sort(key=lambda x: x.version)
        total = len(versions_of_pe) - (self.number_of_objects - 1)
        for start_index in range(total):
            group = versions_of_pe[start_index:start_index + self.number_of_objects]
            if objects_to_compare is not None and \
                    is_have_shared_objects(objects_to_compare, group) is False:
                continue

            if is_have_major_version_changes(group):  # such as gdiplus.dll
                continue

            compare_pe = compare.compare_pe.ComparePE(group, type_of_change=compare.compare.TypesOfChanges.CHANGED)
            changes = self.get_changes(compare_pe)
            for change in changes:
                yield change


class GroupAllPE(GroupBy):
    def __init__(self):
        super(GroupAllPE, self).__init__(None)

    def group_by(self, objects, objects_to_compare=None):
        if objects_to_compare is not None and len(objects_to_compare) == 0:
            return  # raise StopIteration  # ("stop")
        versions_of_pe = list(objects)
        yield compare.compare_pe.ComparePE(versions_of_pe)


class GroupOneTime(GroupBy):
    def __init__(self):
        super(GroupOneTime, self).__init__(None)
        self.is_called = False

    def group_by(self, objects, objects_to_compare=None):
        if not self.is_called:
            yield compare.compare.Compare([None, None], compare.compare.TypesOfChanges.CHANGED)
            self.is_called = True
            
        return
