import compare.compare
import core.score
import features.feature
import features.groupby
import core.function


class GUID_sequences(features.feature.PEFeature):
    METHOD_NAME = "GUID_sequences"

    def __init__(self):
        compared_number = 1
        group_by = features.groupby.GroupByOrderedPE(compared_number)
        super().__init__(type(self).METHOD_NAME, compared_number, group_by)
        feature_config = core.configurations.get_global().configs.features.pe.binary_search_guid
        self.guids = feature_config.guid_to_find
        self.interfaces = feature_config.interface_to_find

    def find_guid_pattern(self, guid, pe, info=None):
        import uuid
        clsid = uuid.UUID(guid)
        raw_clsid = clsid.bytes_le
        for pattern_found in pe.find_sequence_of_bytes(raw_clsid):
            if len(pattern_found) == 0:
                continue

            address_found = list(pattern_found.keys())[0]
            related_functions = list(pattern_found.values())[0]
            is_found = False
            for related_function in related_functions:
                is_found = True
                ranked_feature = pe[related_function]
                yield core.score.Result(type(self), [ranked_feature],
                                        type_of_feature=core.function.Function,
                                        address_sequence_found=address_found,
                                        GUID=guid, GUID_info=info)

            if is_found is False:
                yield core.score.Result(type(self), [pe],
                                        type_of_feature=core.function.Function,
                                        address_sequence_found=address_found,
                                        GUID=guid, GUID_info=info)

    def _score(self, compare_object):
        pe = compare_object.objects_to_compare[compare.compare.OLDEST]
        for guid, info in self.guids.items():
            yield from self.find_guid_pattern(guid, pe, info)

        for interface, info in self.interfaces.items():
            yield from self.find_guid_pattern(interface, pe, info)
