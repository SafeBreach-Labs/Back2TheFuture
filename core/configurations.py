import os
import pathlib2
import logging
import json
import easydict

logger = logging.getLogger()
__GLOBAL_CONFIGURATIONS = None
ROOT_DIR = os.path.dirname(os.path.dirname(__file__))


def get_global():
    global __GLOBAL_CONFIGURATIONS
    if __GLOBAL_CONFIGURATIONS is None:
        configs = Configurations(str(pathlib2.Path(ROOT_DIR) / "config" / "default_config.json"))
        __GLOBAL_CONFIGURATIONS = configs

    return __GLOBAL_CONFIGURATIONS


# path_log_file = args.logfile, is_include_scores_in_logs = args.write_results_to_log
class Configurations(object):
    def __init__(self, conf_file, ida_location=None, diff_location=None, cve_link_db_location=None,
                 starting_orchestration=None, path_executables=None, path_log_file=None,
                 is_include_scores_in_logs=None, ranks_db_location=None, is_include_cfg=None,
                 extract_additional_params=None, path_output_folder=None, is_extract_cfg_metadata=None):
        self.__path_config_file = conf_file
        self.configs = easydict.EasyDict()
        self.load_configs(self.__path_config_file)
        self._post_processing(cve_link_db_location, diff_location, ida_location, starting_orchestration, path_executables,
                              path_log_file, is_include_scores_in_logs, ranks_db_location, is_include_cfg, extract_additional_params,
                              path_output_folder, is_extract_cfg_metadata)
        super().__init__()

    def _post_processing(self, cve_link_location, diff_location, ida_location, starting_orchestration, path_executables,
                         path_log_file, is_include_scores_in_logs, ranks_db_location, is_include_cfg, extract_additional_params,
                         path_output_folder, is_extract_cfg_metadata):
        if diff_location is not None:
            self.configs.compare.diff_folder = diff_location
        elif self.configs.compare.diff_folder is None:
            raise EnvironmentError("diff location is required, as an argument or in the config file")

        if ranks_db_location is not None:
            self.configs.output.output_db_location = ranks_db_location
        if ida_location is not None:
            self.configs.integrations.ida.path_ida = ida_location

        if path_executables is not None:
            self.configs.orchestration.executables_folder = path_executables

        if path_log_file is not None:
            self.configs.logging_configs.handlers.file_handler.filename = path_log_file

        if is_include_scores_in_logs is not None:
            self.configs.output.is_include_scores_in_stdout_handler = is_include_scores_in_logs
        if is_include_cfg is not None:
            self.configs.features.is_use_cfg = is_include_cfg

        if extract_additional_params is not None:
            self.configs.features.extract_additional_params = extract_additional_params

        if starting_orchestration is not None:
            self.configs.orchestration.pe_start_execution = starting_orchestration

        if path_output_folder is not None:
            self.configs.output.path_output_folder = path_output_folder

        if is_extract_cfg_metadata is not None:
            self.configs.features.include_cfg_metadata = is_extract_cfg_metadata

        if cve_link_location is not None:
            self.configs.features.pe.cve_link.db_location = cve_link_location
        else:
            self.configs.features.pe.cve_link.db_location = \
                os.path.join(ROOT_DIR, self.configs.features.pe.cve_link.db_location)

        self.init_rpc_project_list()

    def init_rpc_project_list(self):
        path_rpc_project_list = self.configs.features.function.rpc_project_list_path
        full_path_rpc_project_list = os.path.join(ROOT_DIR, path_rpc_project_list)
        if not os.path.exists(full_path_rpc_project_list):
            raise EnvironmentError("path RPC project list doesn't exist")
        with open(full_path_rpc_project_list, "r") as f:
            guids_with_project = f.read().splitlines()
        if len(guids_with_project) > 0 and guids_with_project[-1] == "":
            guids_with_project = guids_with_project[:-1]
        self.configs.features.function.rpc_project_list = guids_with_project

    def load_configs(self, path):
        with open(path, "r") as f:
            configs = json.load(f)
            self.configs.update(configs)
