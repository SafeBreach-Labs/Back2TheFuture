import logging

import compare.compare
import core.score
import features.feature
import features.groupby


def is_found_in_iterator(iterator, index, obj_compare):
    for i in iterator:
        if i[index] == obj_compare:
            return True
    return False


class DecompileWarning(features.feature.SimpleFunctionFeature):
    """
    Only changes in decompiler warnings
    """
    METHOD_NAME = "DecompileWarning"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        scores = [(compare.compare.TypesOfChanges.CHANGED, 30, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.ADDED, 20, compare.compare.NEWEST),
                  (compare.compare.TypesOfChanges.REMOVED, 10, compare.compare.OLDEST)
                  ]
        ignored_ids = [9]  # using guessed type
        for type_of_change, base_score, pe_index in scores:
            newest = compare_object.objects_to_compare[compare.compare.NEWEST]
            oldest = compare_object.objects_to_compare[compare.compare.OLDEST]
            newest_warnings = []
            oldest_warnings = []
            try:
                if newest is not None:
                    newest_warnings = newest.get_decompiled_warnings()
                if oldest is not None:
                    oldest_warnings = newest.get_decompiled_warnings()
            except Exception as e:
                logging.warning(f"failed to create decompile binary {compare_object.objects_to_compare[pe_index]}")
                return  # raise StopIteration  # ("failed to generate decompile")

            for oldest_warning in oldest_warnings:  # have the same warning
                if oldest_warning[0] in ignored_ids:
                    continue

                is_found = is_found_in_iterator(newest_warnings, 0, oldest_warning[0])
                if not is_found:  # have the same compiler warning
                    score = base_score * 3
                    yield core.score.Score(score, type(self),
                                           [compare_object.objects_to_compare[compare.compare.NEWEST]],
                                           [compare_object.objects_to_compare[compare.compare.OLDEST]],
                                           reason=oldest_warning, type_of_change=type_of_change)
