import logging

import compare.compare
import core.score
import features.feature
import features.groupby
import core.function


def calculate_block_changes(type_feature, compare_object, features_to_check, is_include_raw_blocks):
    newest = compare_object.objects_to_compare[compare.compare.NEWEST]
    oldest = compare_object.objects_to_compare[compare.compare.OLDEST]
    kwargs = {}
    is_changed = False
    score = 0
    try:
        new_logical_blocks_types = newest.get_types_of_blocks(features_to_check)
        old_logical_blocks_types = oldest.get_types_of_blocks(features_to_check)
        diff_count_new = sum(new_logical_blocks_types.values())
        diff_count_old = sum(old_logical_blocks_types.values())
        logical_diff = new_logical_blocks_types - old_logical_blocks_types
        diff_count_changes = sum(logical_diff.values())
        if diff_count_changes > 0:
            is_changed = True
            kwargs.update({"before": diff_count_old, "after": diff_count_new, "reason": str(logical_diff)})
            score = 50 / diff_count_changes

    except Exception as e:
        logging.info(f"failed to get types of block {newest} vs {oldest}, {e}")

    new_num_of_blocks = newest.get_amount_of_blocks()
    old_num_of_blocks = oldest.get_amount_of_blocks()
    if is_include_raw_blocks and new_num_of_blocks != old_num_of_blocks: 
        is_changed = True

    if is_changed:
        score += 20 / (abs(new_num_of_blocks - old_num_of_blocks) + 1) # +1 for divide by zero, the is_changed is not good enough.

        return core.score.SimpleCompareObjScore(score, type_feature, compare_object,
                                               raw_before=old_num_of_blocks, raw_after=new_num_of_blocks, **kwargs)
    return None


class ChangedAmountOfConditions(features.feature.SimpleFunctionFeature):
    """
    monitor amount of IFs added to the function
    """
    METHOD_NAME = "ChangedAmountOfConditions"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        features_to_check = [core.function.TypesOfBlocks.CONDITIONS]
        ret_val = calculate_block_changes(type(self), compare_object, features_to_check, True)
        if ret_val is not None:
            yield ret_val


class ChangedAmountOfLoops(features.feature.SimpleFunctionFeature):
    """
    monitor amount of FORs & whiles added to the function
    """
    METHOD_NAME = "ChangedAmountOfLoops"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.CHANGED)

    def _score(self, compare_object):
        features_to_check = [core.function.TypesOfBlocks.LOOPS]
        ret_val = calculate_block_changes(type(self), compare_object, features_to_check, False)
        if ret_val is not None:
            yield ret_val
