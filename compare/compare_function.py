import collections
import compare.compare
import itertools

# ((addr, count),(addr2, count))


class _ChangedXrefs(object):
    def __init__(self, all_xrefs):
        self.added = set()
        self.removed = set()
        self.no_change = set()
        self.changed = set()
        for i in all_xrefs:
            if i[compare.compare.OLDEST][1] == 0:  # addr first function
                self.added.add(i)
            elif i[compare.compare.NEWEST][1] == 0:  # addr second function
                self.removed.add(i)
            elif i[compare.compare.NEWEST][1] == i[compare.compare.OLDEST][1]:  # same amount of count
                self.no_change.add(i)
            else:
                self.changed.add(i)

        self.all_xrefs = all_xrefs

    def get_change(self, type_of_change=None):
        if type_of_change is None or type_of_change == compare.compare.TypesOfChanges.ALL:
            return self.all_xrefs
        elif type_of_change == compare.compare.TypesOfChanges.REMOVED:
            return self.removed
        elif type_of_change == compare.compare.TypesOfChanges.CHANGED:
            return self.changed
        elif type_of_change == compare.compare.TypesOfChanges.NOT_CHANGED:
            return self.no_change
        elif type_of_change == compare.compare.TypesOfChanges.ADDED:
            return self.added
        else:
            raise NotImplementedError("yet")


class CompareFunctions(compare.compare.Compare):
    def __init__(self, objects_to_compare, compare_pes, type_of_change=None, confidence_match=None, similarity=None):
        super().__init__(objects_to_compare, type_of_change)
        self.similarity = similarity
        self.confidence_match = confidence_match
        self.__compare_pes = compare_pes
        self.__changed_xref = None

    def _compare(self):
        raise NotImplementedError("yet")

    def _get_changes(self):
        # should return the block changed
        raise NotImplementedError("yet")

    def _get_added(self):
        # should return the block added
        raise NotImplementedError("yet")

    def _get_removed(self):
        # should return the block removed
        raise NotImplementedError("yet")

    def get_compared_pes(self):
        return self.__compare_pes.objects_to_compare

    def get_multiple_types_of_changes(self, type_of_changes):
        t = []
        for type_of_change in type_of_changes:
            t.append(self.get_changed_called_functions(type_of_change))

        return itertools.chain(*t)

    def get_changed_called_functions(self, type_of_change=None):
        # should return of the address of functions that has changed and how much xrefs has changed.
        # return value: list( ((xref_addr_oldest, count_oldest), (xref_addr_newest, count_newest)),....]

        if self.__changed_xref is None:
            if len(self.objects_to_compare) != 2:
                raise NotImplementedError("not planned to be implemented")

            oldest = self.objects_to_compare[compare.compare.OLDEST]
            newest = self.objects_to_compare[compare.compare.NEWEST]
            if oldest is not None:
                xrefs_oldest = collections.Counter(oldest.get_all_called_functions())
            else:
                xrefs_oldest = collections.Counter()

            if newest is not None:
                xrefs_newest = collections.Counter(newest.get_all_called_functions())
            else:
                xrefs_newest = collections.Counter()

            addresses_mapping = self.__compare_pes.match_functions(
                self.__compare_pes.objects_to_compare[compare.compare.OLDEST],
                xrefs_oldest.keys(), is_return_mapping=True, is_ignore_tiny_functions=False)
            xref_mapping = []
            for xref_oldest_addr, xref_oldest_count in xrefs_oldest.items():
                xref_newest_addr = addresses_mapping.get(xref_oldest_addr, None)
                if xref_newest_addr is not None:
                    xref_newest_count = xrefs_newest[xref_newest_addr]
                    # remove in order to calculate the new xrefs.
                    # None is for functions with mapping but without xrefs in the newest function (removed functions)
                    xrefs_newest.pop(xref_newest_addr, None)
                else:  # There is no mapping between new and old:
                    xref_newest_count = 0

                xref_mapping.append(((xref_oldest_addr, xref_oldest_count), (xref_newest_addr, xref_newest_count)))

            for xref_newest, count_newest in xrefs_newest.items():
                xref_mapping.append(((None, 0), (xref_newest, count_newest)))

            self.__changed_xref = _ChangedXrefs(xref_mapping)

        return self.__changed_xref.get_change(type_of_change)

    # TODO: remove it?
    def addresses_to_compare_functions(self, addresses, type_of_change=None):
        """

        :param addresses: list of addresses to compare
        :param type_of_change:
        :return:
        """
        number_of_pes = len(self.__compare_pes.objects_to_compare)
        if len(addresses) != number_of_pes:
            raise ValueError(f"len addresses {addresses} doesn't match len {number_of_pes}")

        func_objs = []
        for address, pe in zip(addresses, self.__compare_pes.objects_to_compare):
            func_objs.append(pe[address])

        compare_func_obj = CompareFunctions(func_objs, self.__compare_pes, type_of_change=type_of_change)
        return compare_func_obj
