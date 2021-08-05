import traceback
import sys
import itertools
import logging
import abc
import enum

OLDEST = 0
NEWEST = -1


class TypesOfChanges(enum.Enum):
    # Added feature, something that didn't existed in the older version
    ADDED = 1
    # Removed a feature, something that existed in the older version and not exist in the current version
    REMOVED = 2
    # Feature that existed in the older version but is not the same as the version in the newer version
    CHANGED = 3
    # Feature that didn't change at all.
    NOT_CHANGED = 4
    #
    ALL = None

    def __str__(self):
        return self.name


def safe_iterator(iterator, exception_to_catch):
    while True:
        try:
            yield next(iterator)
        except StopIteration:
            break
        except FileNotFoundError as ex:
            logging.error(f"caught exception {ex}")
        except exception_to_catch as ex:
            traceback.print_exc(file=sys.stdout)
            logging.error(f"caught exception {ex}", exc_info=True)


class Compare(abc.ABC):
    def __init__(self, objects_to_compare, type_of_change):
        """
        Create compare object
        :param objects_to_compare: list of objects to compare, from the oldest to the newest
        """
        self.type_of_change = type_of_change
        self.objects_to_compare = objects_to_compare

    def _compare(self):
        raise NotImplementedError("yet")

    def get_multiple_changes(self, type_of_changes):
        iterators = []
        for change in type_of_changes:
            iterators.append(self.get_changes(change))

        return itertools.chain(*iterators)

    def get_changes(self, type_of_change=None):
        """
        Get all the changes
        :param type_of_change:one of options in the enum in compare.compare.TypesOfChanges
        :rtype: object
        """
        if type_of_change is None or type_of_change == TypesOfChanges.ALL:
            generator = self._get_all_types()
        elif type_of_change == TypesOfChanges.ADDED:
            generator = self._get_added()
        elif type_of_change == TypesOfChanges.REMOVED:
            generator = self._get_removed()
        elif type_of_change == TypesOfChanges.CHANGED:
            generator = self._get_changes()
        else:
            raise ValueError(f"doesn't support other types {type_of_change}")

        for i in safe_iterator(generator, (FileNotFoundError, EnvironmentError)):
            yield i

    def _get_all_types(self):
        return itertools.chain(self._get_changes(), self._get_removed(), self._get_added(), self._get_not_changed())

    def _get_changes(self):
        raise NotImplementedError("Abstract class")

    def _get_added(self):
        raise NotImplementedError("Abstract class")

    def _get_removed(self):
        raise NotImplementedError("Abstract class")

    def _get_not_changed(self):
        raise NotImplementedError("Abstract class")

