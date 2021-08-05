import core.score
import features.feature
import features.groupby
import compare.compare


class AmountOfPEUpdates(features.feature.GlobalFeature):
    METHOD_NAME = "AmountOfPEUpdates"

    def __init__(self):
        super().__init__(type(self).METHOD_NAME)

    def _score(self, compare_object):
        new = compare_object.objects_to_compare[compare.compare.NEWEST]
        old = compare_object.objects_to_compare[compare.compare.OLDEST]
        yield core.score.Score(15, type(self), [new], [old])
        # raise NotImplementedError("override this function")
