import logging
import logging.config
import time
from datetime import timedelta
import os
import sys
import pathlib2
import argparse

import core
import compare.compare
import core.configurations
import features.orchestration_features
import core.filesystem
import features.pe_features.overview_pe
import integrations

# for configurations.features
import features.function_features.xrefs
import features.pe_features.overview_pe
import features.function_features.func_logic
import features.pe_features.cve_link
import features.function_features.build_cfg
import features.function_features.overview_functions
import features.function_features.code_flow
import features.function_features.changed_constants
import features.function_features.build_cfg.xrefs
import features.function_features.build_cfg.com_object
import features.function_features.build_cfg.rpc_objects
import features.global_features.msdn_scraper
import features.pe_features.string_extractor
import features.global_features.github_scraper
import features.pe_features.ipc_patterns
import features.pe_features.com_xxe
import features.dotnet_features.decompiler
import features.pe_features.vulnerable_file_operations

if sys.version_info.major != 3 and sys.version_info.minor >= 6:
    raise ValueError("Python version should be 3.6 or newer")

ROOT_DIR = os.path.dirname(__file__)
CONFIG_FILE_PATH = str(pathlib2.Path(ROOT_DIR) / "config" / "default_config.json")
LOGGER = None

if not __name__ == "__main__":
    LOGGER = logging.getLogger()


def init_logging(logging_config):
    logging.config.dictConfig(logging_config)
    logging.info("configured logging")
    return logging.getLogger()


def init_argparse():
    """
    Get the execution arguments
    :return: argparse object
    """
    parser = argparse.ArgumentParser(description='Find patch patterns and ')
    parser.add_argument('--conf-file', action='store', help="Configuration file", default=CONFIG_FILE_PATH, type=str)
    parser.add_argument('--path-diff', action='store', help="Root path folder of diffs", default=None,
                        type=str)
    parser.add_argument('--path-executables', action='store', help="Path x64 executables", default=None,
                        type=str)
    parser.add_argument('--path-logfile', action='store', help="Location to store the log file", default=None,
                        type=str)
    parser.add_argument('--path-output-folder', action='store',
                        help="Directory to write the output of features (such as decompiler)",
                        default=None,
                        type=str)
    parser.add_argument('--path-db', action='store', help="Location to store the output DB", default=None,
                        type=str)
    parser.add_argument('--write-results-to-log', action='store_true', help="Is store all scores and scores to logfile",
                        default=False)
    parser.add_argument('--include-cg', action='store_true', help="Is include CG features (takes lots of time)",
                        default=False)
    parser.add_argument('--include-cg-metadata', action='store_true',
                        help="Is scrape information from external sources for the call graphs",
                        default=False)
    parser.add_argument('--generic-filesystem', action='store_true',
                        help="if --path-executables points to generic filesystem and non standard fs,"
                             "(FS not built by msu_patch_extractor)",
                        default=False)
    parser.add_argument('--skip-winsxs', action='store_true', help="in generic FS only", default=False)
    parser.add_argument('--extract-additional-params', action='store_true',
                        help="extract additional params to the DB - double the execution time", default=False)
    parser.add_argument('--orchestrate-specific-kb', action='store', help="specify specific KB to go over",
                        default=None)
    parser.add_argument('--continue-execution', action='store', help="continue execution for a specific PE",
                        default=None)
    parser.add_argument('--orchestrate-specific-pes', nargs='+', help="specify list of pes to go over", default=None)
    args = parser.parse_args()
    if not os.name == "nt":
        logging.critical("The code must run on Windows")
        exit(-1)

    if args.orchestrate_specific_kb is not None:
        lower = args.orchestrate_specific_kb.lower()
        args.orchestrate_specific_kb = lower
        if not lower.startswith("kb"):
            raise EnvironmentError("kb doesn't start with the prefix kb")

        if not lower[2:].isnumeric():
            raise EnvironmentError(r"kb must be in the following format: kb\d+")

    if args.path_diff is not None and args.generic_filesystem is True:
        logging.critical("Can't choose generic filesystem and path-diff")
        raise EnvironmentError("Can't choose generic filesystem and path-diff")

    if args.skip_winsxs and args.generic_filesystem is False:
        logging.critical("Can't choose skip winsxs without generic filesystem")
        raise EnvironmentError("Can't choose skip winsxs without generic filesystem")

    if args.path_output_folder is not None and os.path.exists(args.path_output_folder):
        if not os.path.isdir(args.path_output_folder):
            logging.critical("output folder must be a folder or not exist")
            raise EnvironmentError("output folder must be a folder or not exist")
        elif len(os.listdir(args.path_output_folder)) > 0:
            logging.critical("feature output folder is exist, please choose another folder")
            raise EnvironmentError("feature output folder is exist, please choose another folder")

    if not os.path.isdir(args.path_executables):
        logging.critical("Executable path should be a directory")
        raise EnvironmentError("Executable path should be a directory")

    return args


def get_features(configurations):
    """
    Get a list of all the features for the configuration
    :param configurations: configuration object that contains all the settings of the current execution
    :return: list of features
    """
    is_extract_additional_params = configurations.features.extract_additional_params
    is_extract_cfg_metadata = configurations.features.include_cfg_metadata
    root_filesystem = configurations.orchestration.executables_folder

    function_feature_list = [features.function_features.xrefs.XrefLockFunction(),
                             features.function_features.xrefs.FreeFunctions(),
                             features.function_features.xrefs.AllocFunctions(),
                             features.function_features.xrefs.XrefVulnerableFunctions(),
                             features.function_features.xrefs.LogicalVulnerableFixup(),
                             features.function_features.xrefs.XrefLogicalVulnerableFunctions(),
                             features.function_features.xrefs.StrSafeFunction(),
                             features.function_features.xrefs.IntSafeFunctions(),
                             features.function_features.xrefs.ReplacedLogicalFunctions(),
                             features.function_features.xrefs.ReplacedVulnerableFunctions(),
                             features.function_features.xrefs.ReplacedSimilarFunctions(),
                             features.function_features.overview_functions.ChangedXrefs(),
                             features.function_features.overview_functions.ChangedFunctions(),
                             features.function_features.changed_constants.ChangedFunctionConstant(),
                             # might be not interesting because the functions are deprecated for a long time.
                             # it might require a new location
                             features.function_features.xrefs.DeprecatedFunctions(),
                             # features.function_features.func_logic.DecompileWarning(),  # takes lots of time
                             # this features sometimes raise exception because of decompiler error, keep them last.
                             features.function_features.code_flow.ChangedAmountOfConditions(),
                             features.function_features.code_flow.ChangedAmountOfLoops(),
                             features.function_features.xrefs.DirectoryTraversal(),
                             ]
    pe_feature_list = [features.pe_features.cve_link.LinkCVEToUpdate(),
                       features.pe_features.overview_pe.ChangesPes()
                       ]

    # this one gets special treatment because githubscraper needs token for init.
    if is_extract_cfg_metadata:
        global_features_list = [
            features.global_features.msdn_scraper.MSDNScraper(max_pages=None),
            features.global_features.github_scraper.GithubScraper()
        ]
    else:
        global_features_list = []

    cfgs = [features.function_features.build_cfg.xrefs.CfgExtractorXref(is_include_args=is_extract_additional_params),
            features.function_features.build_cfg.com_object.CfgExtractorComObject(),
            features.function_features.build_cfg.com_object.CfgExtractorComClientObject(),
            features.function_features.build_cfg.rpc_objects.CfgExtractorRPCObject(),
            features.pe_features.string_extractor.StringExtractor(),
            features.pe_features.com_xxe.ComXXE(),
            features.pe_features.ipc_patterns.GUID_sequences(),
            features.dotnet_features.decompiler.DotNetDecompiler(root_filesystem),
            features.function_features.build_cfg.com_object.CfgExtractorComFunctions(),
            features.function_features.build_cfg.com_object.CfgExtractorIUnknown(),
            features.pe_features.vulnerable_file_operations.ControllablePaths()
            ]
    full_list = []
    full_list += global_features_list

    if configurations.features.is_use_cfg:
        full_list += pe_feature_list + function_feature_list + cfgs
    else:
        full_list += pe_feature_list + function_feature_list

    return full_list


def init_output_handlers(args):
    """
    Init all output handlers that will receive all the 'result' objects from the features
    :param args: argparse object
    :return: iterable of all the output handlers (such as DB, stdout...)
    """
    import core.output_handler
    db_location = core.configurations.get_global().configs.output.output_db_location
    is_include_stdout_output_handler = core.configurations.get_global().configs.output.is_include_scores_in_stdout_handler
    is_keep_db = core.configurations.get_global().configs.output.is_keep_db
    begin_pe_execution = args.continue_execution
    if is_keep_db is True or is_keep_db is False:
        is_create_new_db = not is_keep_db
    else:
        is_create_new_db = begin_pe_execution is None

    if args.orchestrate_specific_kb is not None and is_keep_db is None:
        is_create_new_db = False

    basic_output_handler = [core.output_handler.SaveToDB(db_location, is_create_new_db=is_create_new_db)]
    if is_include_stdout_output_handler:
        basic_output_handler.append(core.output_handler.PrintResults(LOGGER))

    return basic_output_handler


def print_summery(summery):
    LOGGER.info("############################## begin summery ##############################")
    for feature, statistic in summery:
        LOGGER.info(str(feature) + "\n\n")
    LOGGER.info("################################ ended summery ##############################")


def handle_result(result, handlers):
    """
    Propagate the result got from the feature to all the output handlers.
    :param result: a result object got from the features
    :param handlers: List of all the output handlers (such as write to stdout, write to DB....)
    :return: None
    """
    try:
        for hndl in handlers:
            hndl.get_output(result)
    except KeyboardInterrupt:
        raise
    except Exception as e:
        data_failed = ""
        try:
            # Some times serialized output fails.
            data_failed = str(result)
        except Exception:
            pass
        logging.critical(f"failed to update output while handling result to output {data_failed} "
                         f" exception:{e}", exc_info=True)


def main_loop(orchestrator, exec_fs, output_handlers, generator=None):
    """
    Orchestrate all the permutations of the filesystem on the features
    :param orchestrator: an instance of the orchestrator  you want to execute it on
    :param exec_fs: filesystem object (ArchitectureFileSystem/GenericFilesystem/...)
    :param output_handlers: all the output handlers - that will parse the results of the features
    :param generator: do not pass
    :return:
    """
    if generator is None:
        generator = orchestrator.orchestrate_all(exec_fs)
    try:
        for score in generator:
            handle_result(score, output_handlers)
    except KeyboardInterrupt:
        logging.critical("Ctrl +c was caught, continue execution")
        main_loop(orchestrator, exec_fs, output_handlers, generator)


def main():
    global LOGGER
    args = init_argparse()
    # Creating the singleton object that will contain all the settings for the current execution
    configs = core.configurations.Configurations(args.conf_file, diff_location=args.path_diff,
                                                 ranks_db_location=args.path_db, path_executables=args.path_executables,
                                                 path_log_file=args.path_logfile,
                                                 is_include_scores_in_logs=args.write_results_to_log,
                                                 is_include_cfg=args.include_cg,
                                                 extract_additional_params=args.extract_additional_params,
                                                 path_output_folder=args.path_output_folder,
                                                 is_extract_cfg_metadata=args.include_cg_metadata)
    core.configurations.__GLOBAL_CONFIGURATIONS = configs
    logger = init_logging(configs.configs.logging_configs)
    LOGGER = logger
    logger.info("began program!!")
    # kill all all leftovers from the previous executions
    integrations.init_integrations()
    output_handlers = init_output_handlers(args)
    # Detect which filesystem we're using, is it generic - no compare features.
    if args.generic_filesystem:
        exec_fs = core.filesystem.GenericFilesystem(configs.configs.orchestration.executables_folder,
                                                    configs.configs, is_skip_winsxs=args.skip_winsxs)
    else:
        max_depth = core.filesystem.calculate_max_depth(configs.configs.orchestration.executables_folder)
        folder_type = core.filesystem.ExecutableFolderDepth(max_depth)
        if folder_type == core.filesystem.ExecutableFolderDepth.ARCHITECTURE:
            filesystem_type = core.filesystem.ArchitectureFileSystem
        elif folder_type == core.filesystem.ExecutableFolderDepth.FILE_VERSIONS:
            filesystem_type = core.filesystem.ExecutableVersionsFileSystem
        elif folder_type == core.filesystem.ExecutableFolderDepth.ROOT_EXECUTABLES:
            logging.warning("We're not fully support executable file-system "
                            "because we're not ignoring the Dot-Net executables in the root, it might raise errors.")
            filesystem_type = core.filesystem.ExecutablesFileSystem
        else:
            raise ValueError(f"doesn't support file system: {max_depth} {folder_type}")

        exec_fs = filesystem_type(configs.configs.orchestration.executables_folder,
                                  configs.configs)

    all_features = get_features(configs.configs)
    start_orchestration = time.time()

    pe_begin_execution = args.continue_execution
    pes_to_orchestrate = args.orchestrate_specific_pes
    count_not_none = 0
    for i in [pe_begin_execution, pes_to_orchestrate, args.orchestrate_specific_kb]:
        if i is not None:
            count_not_none += 1

    if count_not_none > 1:
        raise EnvironmentError(
            "Please choose only 1 argument: --orchestrate-specific-kb  --continue-execution --orchestrate-specific-pes")

    if pe_begin_execution is not None:
        feature_orchestration = features.orchestration_features.OrchestrationContinueExecution(all_features, configs,
                                                                                               pe_begin_execution)
    elif pes_to_orchestrate is not None:
        feature_orchestration = features.orchestration_features.OrchestrationSpecificPEs(all_features, configs,
                                                                                         pes_to_orchestrate)
    elif args.orchestrate_specific_kb is not None:
        feature_orchestration = features.orchestration_features.OrchestrationSpecificKB(all_features, configs,
                                                                                        args.orchestrate_specific_kb,
                                                                                        False, False)
    else:
        feature_orchestration = features.orchestration_features.OrchestrationFeatures(all_features, configs)

    try:
        main_loop(feature_orchestration, exec_fs, output_handlers)
    except Exception as e:
        logger.critical(f"raised exception to main!!! {e}", exc_info=True)

    logger.info("finished main loop")
    summery = feature_orchestration.get_summary()
    logger.info("got summery")
    finish_output_handlers(output_handlers)
    print_summery(summery)
    end_orchestration = time.time()
    diff_time = end_orchestration - start_orchestration
    delta_time = timedelta(seconds=diff_time)
    logger.info(f"time diff seconds: {diff_time}, human readable {delta_time}")
    logger.info("end program!!")


def finish_output_handlers(output_handlers):
    """
    Cleanup on the output handlers to signal we finished all the outputs, for statistics and
    post-calculations
    :param output_handlers: all output handlers
    :return: None
    """
    for output_handler in output_handlers:
        output_handler.finish()


if __name__ == "__main__":
    main()
