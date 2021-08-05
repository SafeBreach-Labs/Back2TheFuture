import logging
import subprocess

import compare.compare
import core.score
import features.feature
from features.function_features.build_cfg.utils import additional_params, add_entry_point_indication


def _validate_requirements():
    output = subprocess.check_output(["powershell", "-Command",  "Get-Module -ListAvailable -Name NtObjectManager"])
    decoded_output = output.decode('ascii')
    if len(decoded_output) < 10:
        print("please run as admin: Install-Module 'NtObjectManager' ")
        logging.critical("powershell module NtObjectManager is not installed, please install it!!")
        raise EnvironmentError("Failed to import NtObjectManager required for the rpc object")
    return True


class CfgExtractorRPCObject(features.feature.SimpleFunctionFeature):
    METHOD_NAME = "CfgExtractorRPCObject"

    def __init__(self):
        _validate_requirements()
        number_of_compared_objects = 1
        super().__init__(type(self).METHOD_NAME, compare.compare.TypesOfChanges.ALL, number_of_compared_objects)

    def _score(self, compare_object):
        func_obj = compare_object.objects_to_compare[compare.compare.NEWEST]
        rpc_settings = func_obj.get_rpc_info()
        for rpc_setting in rpc_settings:
            rpc_setting.update(additional_params(func_obj))
            rpc_setting.update(add_entry_point_indication(func_obj))
            yield core.score.Score(0, type(self), [func_obj], type_of_change=compare_object.type_of_change, **rpc_setting)