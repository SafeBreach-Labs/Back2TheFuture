import logging
import compare.compare
import compare.compare_function

RANKED_PREFIX = "ranked_"
REFERENCED_PREFIX = "referenced_"


class Result(object):
    def __init__(self, feature_type, ranked_objects, reference_objects=None, type_of_feature=None, **kwargs):
        self.feature_type = feature_type
        self.ranked_objects = ranked_objects
        if reference_objects is None:
            reference_objects = []

        self.reference_objects = reference_objects
        self.kwargs = kwargs
        self.type_of_feature = type_of_feature
        self.__serialize = self.__generate_serialize()
        self._serialize = self.__serialize

    @staticmethod
    def _add_prefix(dictionary, prefix):
        new_dict = {}
        for key, val in dictionary.items():
            new_dict[prefix + key] = val

        return new_dict

    def strict_serialize(self):  # in order to prevent ida from opening again
        return self._serialize

    def __generate_serialize(self):
        if len(self.ranked_objects) > 1:
            raise NotImplementedError("not planned to be implemented")
        if len(self.ranked_objects) == 1:
            # To support Added or removed features.
            if self.ranked_objects[0] is None:
                ranked_objects = {}
            else:
                raw_ranked_objects = self.ranked_objects[0].strict_serialize()
                ranked_objects = Result._add_prefix(raw_ranked_objects, RANKED_PREFIX)

            if len(self.reference_objects) == 1 and self.reference_objects[0] is not None:
                raw_referenced_objects = self.reference_objects[0].strict_serialize()
                referenced_objects = Result._add_prefix(raw_referenced_objects, REFERENCED_PREFIX)
            elif len(self.ranked_objects) > 1:
                raise NotImplementedError("yet")
            else:
                referenced_objects = {}
        else:  # len 0
            ranked_objects = {}
            referenced_objects = {}

        ranked_objects.update(referenced_objects)
        if type(self.feature_type) == str:
            ranked_objects.update({"feature_type": self.feature_type})
        else:    
            ranked_objects.update({"feature_type": str(self.feature_type.__name__)})

        for temp_ranked in self.ranked_objects + self.reference_objects:
            if temp_ranked is not None:
                ranked_objects.update({"type": type(temp_ranked).__name__})
                break
        if self.type_of_feature is not None:
            ranked_objects.update({"type": self.type_of_feature.__name__})

        if "type" not in ranked_objects: 
            logging.error(f"type is not in score {self}")

        ranked_objects.update(self.kwargs)
        return ranked_objects

    def __str__(self):
        feature_type = self.feature_type
        if type(feature_type) != str:
            feature_type = self.feature_type.__name__ 

        basic_format = f"{feature_type} {self.ranked_objects} {self.reference_objects}"
        if not len(self.kwargs) == 0:
            basic_format += f" {self.kwargs}"

        return basic_format

    def __repr__(self):
        return str(self)


class Score(Result):
    MIN_SCORE = -100
    MAX_SCORE = 100
    MIN_CONFIDENCE_RANK = 0
    MAX_CONFIDENCE_RANK = 100

    def __init__(self, score_value, feature_type, ranked_objects,
                 reference_objects=None, confidence_rank=100.0, relevant_cwes=None,
                 reason=None, type_of_change=None, **kwargs):
        """
        Score to represent the score of feature
        :param score_value: numerical value represent the score
        :param feature_type: the feature that ranked that score
        :param ranked_objects: The objects that were ranked - such as functions, PE versions...
        :param reference_objects: The reference object that were used as a guideline
        :param reason: human readable score (str/number).
        :param type_of_change:
        :param before: a value with a meaning for the feature to represent before change
        :param after:a value with a meaning for the feature to represent the after change
        :type confidence_rank: amount of confidence this score is sure of.
        :type relevant_cwes: list of CWE objects that are relevant to that score (numbers or cwe.Weakness object).
        :param kwargs: additonal parameters
        """
        self.type_of_change = type_of_change
        self.reason = reason
        if relevant_cwes is None:
            relevant_cwes = []

        self.relevant_cwes = relevant_cwes
        self.assured_rank = confidence_rank
        if not (Score.MIN_SCORE <= score_value <= Score.MAX_SCORE):
            # TODO: added normalization instead.
            if score_value > Score.MAX_SCORE:
                score_value = Score.MAX_SCORE
            else:
                score_value = Score.MIN_SCORE

            logging.warning(f"score should be between min_score: {Score.MIN_SCORE} and {Score.MAX_SCORE}, {feature_type}")

        if not (Score.MIN_CONFIDENCE_RANK <= confidence_rank <= Score.MAX_CONFIDENCE_RANK):
            # TODO: added normalization instead.
            logging.warning(f"score should be between min_score: {Score.MIN_SCORE} and {Score.MAX_SCORE}, {feature_type}")

        self.score_value = score_value
        super().__init__(feature_type, ranked_objects, reference_objects, **kwargs)
        self.__serialize = self.__generate_serialize()
        self._serialize = self.__serialize

    def __str__(self):
        basic_format = f"{self.feature_type.__name__} {self.ranked_objects} {self.reference_objects} {self.score_value}"
        if self.type_of_change is not None:
            basic_format += f" {self.type_of_change}"

        if self.reason is not None:
            basic_format += f" {self.reason}"

        if not len(self.kwargs) == 0:
            basic_format += f" {self.kwargs}"

        return basic_format

    def __repr__(self):
        return str(self)

    def __generate_serialize(self):
        result = super(Score, self).strict_serialize()
        result.update({"score": self.score_value})
        if len(self.relevant_cwes) == 1:
            cwes = self.relevant_cwes[0]
            result.update({"cwe": str(cwes)})
        elif len(self.relevant_cwes) > 1:
            cwes = self.relevant_cwes[0]
            result.update({"cwe": str(cwes)})
            logging.warning("failed to serialize multiple CWEs")

        if self.reason is not None:
            result.update({"reason": str(self.reason)})
            try:  # TODO: remove this
                import core.function
                short_reason = core.function.Function.get_basic_name(str(self.reason))
                result.update({"short_reason": str(short_reason)})
            except Exception:
                pass

        if self.type_of_change is not None:
            result.update({"type_of_change": str(self.type_of_change.name)})

        return result


class SimpleCompareObjScore(Score):
    def __init__(self, score_value, feature_type, compare_obj, *args, **kwargs):
        self.compare_obj = compare_obj
        if len(compare_obj.objects_to_compare) != 2:
            logging.warning("doesn't support multiple objects to compare")
        ranked_objects = [compare_obj.objects_to_compare[compare.compare.NEWEST]]
        referenced_objects = [compare_obj.objects_to_compare[compare.compare.OLDEST]]
        type_of_change = compare_obj.type_of_change
        super().__init__(score_value, feature_type, ranked_objects, reference_objects=referenced_objects,
                         type_of_change=type_of_change, *args, **kwargs)
        self.__serialize = self.__generate_serialize()
        self._serialize = self.__serialize

    def __generate_serialize(self):
        serialization = super(SimpleCompareObjScore, self).strict_serialize()

        serialization.update({"confidence_match": self.compare_obj.confidence_match,
                              "similarity": self.compare_obj.similarity})

        if None in self.compare_obj.objects_to_compare:
            if type(self.compare_obj) == compare.compare_function.CompareFunctions and \
                    len(self.compare_obj.objects_to_compare) == 2:
                # added or removed function -> we need to add serialization to the base object (PE)
                pes = self.compare_obj.get_compared_pes()
                if None in self.reference_objects:
                    serialized_pe = pes[compare.compare.OLDEST]
                    updated = serialized_pe.strict_serialize()
                    pe_serialized = Result._add_prefix(updated, REFERENCED_PREFIX)
                    serialization.update(pe_serialized)
                if None in self.ranked_objects:
                    serialized_pe = pes[compare.compare.NEWEST]
                    updated = serialized_pe.strict_serialize()
                    pe_serialized = Result._add_prefix(updated, RANKED_PREFIX)
                    serialization.update(pe_serialized)

            else:
                logging.warning("doesn't support serialize multiple objects to compare")

        return serialization
