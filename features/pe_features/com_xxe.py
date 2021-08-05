import compare.compare
import core.score
import features.feature
import features.groupby
import core.function


class ComXXE(features.feature.PEFeature):
    METHOD_NAME = "com_xxe"

    def __init__(self):
        compared_number = 1
        group_by = features.groupby.GroupByOrderedPE(compared_number)
        super().__init__(type(self).METHOD_NAME, compared_number, group_by)

    def _score(self, compare_object):
        pe = compare_object.objects_to_compare[compare.compare.OLDEST]
        xxe_results = pe.get_all_xxe_results()
        if xxe_results is None:
            return

        for cls_id_addr, string_in_ida in xxe_results.items():
            related_function = string_in_ida.pop('function_address', None)
            ranked_feature = pe
            if related_function is not None:
                ranked_feature = pe[related_function]

            yield core.score.Result(type(self), [ranked_feature], **string_in_ida,
                                    clsid_addr=cls_id_addr,
                                    type_of_feature=core.function.Function)
