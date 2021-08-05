# Features 
Features group similar patterns together, it can be similar patch patterns or similar code logic, and totally ignore the patches. 

Each feature has a specific goal, for example: number of xrefs - searches for specific function calls that 
has changed, removed or added. 

All the features can be found in the folder `features/`  The base features is found in the `features/feature.py`.

# An example of feature 
An example of a simple feature is "string extractor", it will extract all the strings from a specific executable.
`METHOD_NAME` is the name of the feature, that will be used in the output handlers.

In the `__init__` function you can see an init of `GroupByOrderedPE` which is the grouping object.
This object gets all the versions of a specific PE and returns all the compare objects that 
will be sent to the function  `_score`. 
There are multiple ways to group PEs, all of them you can find in `features/groupby.py` file.
 
The function `_score` function returns a generator that returns `Result` object,
that contains all the results it found.
For results with score (how interesting the finding is use `Score`).
```python
class StringExtractor(features.feature.PEFeature):
    METHOD_NAME = "StringExtractor"

    def __init__(self):
        compared_number = 1
        group_by = features.groupby.GroupByOrderedPE(compared_number)
        super().__init__(type(self).METHOD_NAME, compared_number, group_by)

    def _score(self, compare_object):
        pe = compare_object.objects_to_compare[compare.compare.OLDEST]
        for string_in_ida in pe.get_all_strings():
            related_function = string_in_ida.pop('function_addr', None)
            ranked_feature = pe
            if related_function is not None:
                ranked_feature = pe[related_function]

            yield core.score.Result(type(self), [ranked_feature], **string_in_ida,
                                    type_of_feature=core.function.Function)
```

# Registering feature
In order to register a feature - so the code will use it, you need to add it to the feature handler.
The feature handler holds all the features, and it can be found in `rank_changes.py`
in the function `get_features`.

