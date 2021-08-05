# Generate all the binary diffs for all the PEs
# There are 3 steps for the code:
# 1. Generate idb for each PE
# 2. Generate .binexport files using bindiff tool (to extract all the information of the DB).
# 3. Generate the SQL DB that contains all the changes between the binexports.
import ctypes
import enum
import shutil
import concurrent.futures
import logging
import subprocess
import os
import sys
import pefile
import argparse
import win32api

import core.filesystem

# INIT logger
ROOT_DIR = os.path.dirname(__file__)
full_log_file = os.path.join(ROOT_DIR, "logs", 'auto_patchdiff.log')
if __name__ == "__main__":
    logging.basicConfig(filename=full_log_file, level=logging.DEBUG,
                        datefmt='%Y-%m-%d %H:%M:%S', format='%(asctime)s - %(levelname)s - %(message)s')

stdout_formatter = logging.Formatter('%(levelname)s - %(message)s')
stream_handler = logging.StreamHandler(sys.stdout)
stream_handler.setFormatter(stdout_formatter)
logging.getLogger().addHandler(stream_handler)
# END INIT logger

# Path of ida
IDA64_PATH = r"C:\Progra~1\IDAPRO~1.5\idat64.exe"
ARCHITECTURES = ['amd64', 'wow64', "x86"]

DIFF_DB_PATH = os.path.join(os.path.dirname(__file__), "diffs")
BINDIFF_PATH = "c:\\progra~1\\BinDiff\\bin\\bindiff.exe"
IS_SKIP_FAILS = False
NUMBER_OF_THREADS = 4
BINDIFF_MAX_SECONDS = 20 * 60


class DiffDepth(enum.Enum):
    INVALID = -1
    FILE = 0
    SPECIFIC_DIFF = 1
    ARCHITECTURE = 2
    ROOT_DIFF = 3


def create_db(binary_path, export_file):
    # added ExportX86NoReturnHeuristic false because of this bug:
    # https://issuetracker.google.com/issues/151242195
    # https://github.com/google/binexport/issues/48
    command_to_run = "{} -A -OBinExportX86NoReturnHeuristic:FALSE -OBinExportModule:{} -OBinExportAutoAction:BinExportBinary {}".format(
        IDA64_PATH,
        export_file,
        binary_path)
    logging.debug(f"running the command {command_to_run}")
    proc = subprocess.Popen(command_to_run)
    try:
        proc.communicate(timeout=BINDIFF_MAX_SECONDS)
    except subprocess.TimeoutExpired:
        logging.warning(f"failed to create bindiff {binary_path}")
        proc.kill()
        raise

    if not os.path.exists(export_file):
        logging.error(f"Bindiff failed to generate export file {export_file}")
        raise ValueError("failed to generate export file")


def diff_between_dbs(db1_path, db2_path, out_db_path):
    logging.info("Diffing between DBs...")
    command_to_run = "{} {} {}".format(BINDIFF_PATH, db1_path, db2_path)
    proc = subprocess.Popen(command_to_run, cwd=out_db_path)
    proc.communicate()


def init_arg_parse():
    global IDA64_PATH
    parser = argparse.ArgumentParser(description='Automatically compare all executables extracted from '
                                                 'mst_patch_extractor using bindiff tool.')
    parser.add_argument('-d', '--dont-diff', action='count', help='')
    parser.add_argument('-e', '--path-executables', action='store',
                        help='Path of a folder that contains all the executables and it\'s versions you want to diff,'
                             'it can be the root folder of executable or any other folder inside it.', required=True)
    parser.add_argument('--path-idat64', '-i', action='store', help="location idat64.exe", type=str, default=IDA64_PATH)
    parser.add_argument('--path-diffs', action='store', help="Root folder to contain all the diff DBs",
                        type=str, default=DIFF_DB_PATH)
    parser.add_argument('-u', '--unaligned-paths', action='store_true',
                        help="to unaligned diff folder in case you're using specific package diff or architecture")
    parser.add_argument('--override-existing-diffs', action='store_true',
                        help="Diff files which was diffed by Diaphora, but not with BinDiff", default=False)
    parser.add_argument('--skip-fails', action='store_true',
                        help="if bindiff fails skip and not raise exception")
    parser.add_argument('--kb-version', action='store', default="",
                        help="Patch diff specifc KB")

    args = parser.parse_args()

    if not os.name == "nt":
        logging.critical("The code must run on Windows")
        exit(-1)

    if not os.path.exists(args.path_diffs):
        logging.critical("creating diff folder {}".format(args.path_diffs))
        os.makedirs(args.path_diffs, exist_ok=True)

    if not os.path.isfile(args.path_idat64):
        logging.critical("location of 'idat64.exe' in not found - exiting program")
        exit(-1)

    if not os.path.isdir(args.path_executables):
        logging.critical("path-executables is not exists -exiting program")
        exit(-1)

    if not os.path.exists(BINDIFF_PATH):
        logging.critical("Path to bindiff tool is invalid - please update it")
        exit(-1)

    if not os.path.exists(IDA64_PATH):
        logging.critical("Path to Ida Pro is invalid - please update it")
        exit(-1)

    global IS_SKIP_FAILS
    IS_SKIP_FAILS = args.skip_fails
    IDA64_PATH = args.path_idat64
    return args


def extract_file_version(pe_path):
    """
    Get the version of a PE according to the format of PE
    :param pe_path: path of the pe
    :return: version of the files
    """
    pe = pefile.PE(pe_path)
    version_info = pe.VS_FIXEDFILEINFO
    version_info = version_info[0]
    file_version = (
        version_info.FileVersionMS >> 16, version_info.FileVersionMS & 0xFFFF, version_info.FileVersionLS >> 16,
        version_info.FileVersionLS & 0xFFFF)
    return file_version


def get_real_path(path):
    real_path = os.path.realpath(path)
    if real_path.endswith(".lnk") or real_path.endswith(".symlink"):
        return os.readlink(real_path)

    return real_path


def compare_two_binaries(file_name, path_new_file, path_old_file, new_binary_prefix,
                         old_binary_prefix, compare_folder_path_diff):
    real_path_old_file = get_real_path(path_old_file)
    real_path_new_file = get_real_path(path_new_file)
    logging.info('comparing old: {} <> new: {}'.format(real_path_old_file, real_path_new_file))
    os.makedirs(compare_folder_path_diff, exist_ok=True)
    old_db_path = os.path.join(compare_folder_path_diff, '%s_%s.binexport' % (old_binary_prefix, file_name))
    new_db_path = os.path.join(compare_folder_path_diff, '%s_%s.binexport' % (new_binary_prefix, file_name))
    executions = []
    with concurrent.futures.ThreadPoolExecutor(2, thread_name_prefix="db_creators") as thread_pool:
        executions.append(thread_pool.submit(create_db, real_path_old_file, old_db_path))
        executions.append(thread_pool.submit(create_db, real_path_new_file, new_db_path))

    for execution in executions:
        if execution.exception() is not None:
            logging.warning(
                "Failed to create one of the DBs of {}, stopping the compare and moving on...".format(file_name))

    logging.info("Diffing: %s <> %s" % (old_db_path, new_db_path))
    output_diff_path = os.path.join(compare_folder_path_diff,
                                    '%s_%s_vs_%s.BinDiff' % (file_name, old_binary_prefix, new_binary_prefix))
    logging.info("Output Diff: %s" % output_diff_path)
    diff_between_dbs(old_db_path, new_db_path, compare_folder_path_diff)


def get_all_files_and_versions(files):
    files_and_versions = []
    for f in files:
        current_version = f.name.split('_')[2]
        path = f.path
        # if path.endswith('.symlink'):
        #     path = os.path.realpath(f.path)

        # IDB file extracted
        if path.endswith(".id1") or path.endswith(".id2") or path.endswith(".id0") or \
                path.endswith(".nam") or path.endswith(".til") or path.endswith(".idb") or path.endswith(".i64"):
            continue

        files_and_versions.append((current_version, path))
    logging.debug(files_and_versions)
    files_and_versions.sort(key=lambda obj: obj[0])  # Sort by version
    return files_and_versions


def has_new_diff(package_path):
    package_name = os.path.basename(package_path)
    if not package_name:
        return

    for root, dirs, files in os.walk(package_path):
        for f in files:
            if '.bindiff' in f.lower():
                return True
            else:
                continue

    return False


def has_old_diff(package_path):
    package_name = os.path.basename(package_path)
    if not package_name:
        return

    for root, dirs, files in os.walk(package_path):
        for f in files:
            if '.sqlite' in f.lower():
                return True
            else:
                continue

    return False


def auto_diff_architecture(path_architecture_dir, path_diff_output_dir, is_skip_existing_diffs=True, specifc_kb=""):
    """
    Generate patch-diffing for entire architecture folder, inside the architecture there are all the packages
    :param path_architecture_dir: path inside the executables folder  architecture
    :param path_diff_output_dir: the folder that will create the patch-diffing files into.
    :param is_skip_existing_diffs: is skip existing diffs or override them (True/False)
    :param specifc_kb: patch-diff only specific KBs
    :return: None
    """
    os.makedirs(path_diff_output_dir, exist_ok=True)
    if NUMBER_OF_THREADS > 1:
        with concurrent.futures.ThreadPoolExecutor(NUMBER_OF_THREADS) as p:
            for package_folder_name in os.listdir(path_architecture_dir):
                path_package = os.path.join(path_architecture_dir, package_folder_name)
                path_package_dir_diffs = os.path.join(path_diff_output_dir, package_folder_name)
                p.submit(auto_diff_package, path_package, path_package_dir_diffs, is_skip_existing_diffs, specifc_kb)
    else:
        for package_folder_name in os.listdir(path_architecture_dir):
            path_package = os.path.join(path_architecture_dir, package_folder_name)
            path_package_dir_diffs = os.path.join(path_diff_output_dir, package_folder_name)
            auto_diff_package(path_package, path_package_dir_diffs, is_skip_existing_diffs, specifc_kb)


def auto_diff_package(package_path, path_diff_output_dir, is_skip_existing_diffs=True, specific_kb=""):
    """
    Generate auto patch-diff of a package
    A package is the folder of all the versions of a specific PE.
    :param package_path: path to the package of a specific PE, in the executables folder.
    :param path_diff_output_dir: Output folder to write into it all the diffs
    :param is_skip_existing_diffs: True/False is skip existing diffs or to calculate them again.
    :param specific_kb: Calculate the changes only for a specific KB version, if "" it will calculate for all the KBs
    :return: None
    """
    package_name = os.path.basename(package_path)
    if not package_name:
        return

    files = [f for f in os.scandir(package_path)]
    logging.debug("Current package name: %s |" % package_path)
    files_and_versions = get_all_files_and_versions(files)

    if len(files_and_versions) <= 1:
        logging.info("There is less than a file in the folder {}".format(package_path))

    files_and_versions.sort(key=lambda obj: obj[0])
    for old_file_and_version, new_file_and_version in zip(files_and_versions, files_and_versions[1:]):
        old_file = old_file_and_version[1]
        new_file = new_file_and_version[1]
        new_version = new_file_and_version[0]
        old_version = old_file_and_version[0]
        new_date = os.path.basename(new_file).split("_")[0]
        old_date = os.path.basename(old_file).split("_")[0]
        old_prefix = f"{old_date}_{old_version}"
        new_prefix = f"{new_date}_{new_version}"
        diff_folder_name = '{}_vs_{}'.format(old_prefix, new_prefix)
        compare_folder_path_diff = os.path.join(path_diff_output_dir, diff_folder_name)
        if specific_kb not in old_file and specific_kb not in new_file:
            logging.info(f"skipping files {compare_folder_path_diff} because it does not exist in KB {specific_kb}")
            continue
        # backward_compatibility_pe_name = os.path.basename(new_file).replace(".symlink", "").split("_")[-1]
        # backward_compatibility_dir_name = f"{backward_compatibility_pe_name}_{old_version}_vs_{backward_compatibility_pe_name}_{new_version}"
        # backward_compatibility_dir_path = os.path.join(path_diff_output_dir, backward_compatibility_dir_name)
        # if os.path.exists(backward_compatibility_dir_path):
        #     logging.info(
        #         f"copying old format to new one {compare_folder_path_diff} from {backward_compatibility_dir_path}")
        #     shutil.move(backward_compatibility_dir_path, compare_folder_path_diff)
        if os.path.exists(compare_folder_path_diff):
            logging.debug("Folder already exists: {}".format(compare_folder_path_diff))
            files_in_folder = os.listdir(compare_folder_path_diff)
            # amount of files should be in a diff
            if not is_skip_existing_diffs:
                logging.info(f"Overriding existing diffs {compare_folder_path_diff}")
                shutil.rmtree(compare_folder_path_diff)
            elif len(files_in_folder) < 5:
                logging.warning(
                    f"There are less than 5 files in the compare folder {compare_folder_path_diff} - deleting and starting again.")
                shutil.rmtree(compare_folder_path_diff)
            else:
                continue  # skipping pe.

        os.makedirs(compare_folder_path_diff, exist_ok=True)
        try:
            compare_two_binaries(package_name, new_file, old_file, new_version, old_version,
                                 compare_folder_path_diff)
        except ValueError:
            logging.warning(f"failed to compare {new_file} and {old_file}")
            os.rmdir(compare_folder_path_diff)
            if not IS_SKIP_FAILS:
                raise
            continue

        try:
            # We used the prefix "new_" and "old_" to differentiate the names of the symlinks.
            new_file_name = "new_" + os.path.basename(new_file)
            old_file_name = "old_" + os.path.basename(old_file)
            os.symlink(get_real_path(new_file), os.path.join(compare_folder_path_diff, new_file_name))
            os.symlink(get_real_path(old_file), os.path.join(compare_folder_path_diff, old_file_name))
        except Exception as e:
            logging.warning("failed to create symlink because {}".format(e))


def align_diff_path_to_executable_path(executable_path, diff_path):
    """
    Align diff path to the path of the executables, the diff path should be the root directory of the diff
    but the executable path can point to a specific architecture
    :param executable_path: path to the executables directory or any folder inside it.
    :param diff_path: base path of diff folder
    :return: aligned path to diff path.
    """
    exec_max_depth = core.filesystem.calculate_max_depth(executable_path)
    folder_type = core.filesystem.ExecutableFolderDepth(exec_max_depth)
    if folder_type == core.filesystem.ExecutableFolderDepth.ROOT_EXECUTABLES:
        return diff_path

    if folder_type == core.filesystem.ExecutableFolderDepth.ARCHITECTURE:
        if os.path.basename(diff_path) in ARCHITECTURES:
            return diff_path
        return os.path.join(diff_path, os.path.basename(executable_path))

    if folder_type == core.filesystem.ExecutableFolderDepth.FILE_VERSIONS:
        optional_architecture = os.path.basename(os.path.dirname(executable_path))
        if os.path.basename(os.path.dirname(diff_path)) == optional_architecture:
            return diff_path
        diff_path = os.path.join(diff_path, optional_architecture, os.path.basename(executable_path))
        return diff_path

    raise ValueError("Can't align paths between executable folder and diff folder, please use flag --unaligned")

def check_is_admin():
    """
    Validate the process is running as elevated user in order to create the symlinks
    :return: True if the process is running as elevated user, False if not.
    """
    try:
        is_admin = os.getuid() == 0
    except AttributeError:
        is_admin = ctypes.windll.shell32.IsUserAnAdmin() != 0
    return is_admin


def main():
    if not check_is_admin():
        logging.error("This script is required to run as elevated user in order to create symlinks\nExiting program....")
        exit(-1)

    args = init_arg_parse()
    if args.unaligned_paths:
        diff_path = args.path_diffs
    else:
        diff_path = align_diff_path_to_executable_path(args.path_executables, args.path_diffs)

    logging.info("began executing")
    max_depth = core.filesystem.calculate_max_depth(args.path_executables)
    directory_type = DiffDepth(max_depth)
    logging.info(f"depth of the executables is {max_depth}")
    skip_existing_diffs = not args.override_existing_diffs
    if directory_type == DiffDepth.ROOT_DIFF:  # root executions
        for architecture in ARCHITECTURES:
            path_diff_output_dir = os.path.join(diff_path, architecture)
            path_diffs_architecture = os.path.join(args.path_executables, architecture)
            auto_diff_architecture(path_diffs_architecture, path_diff_output_dir,
                                   skip_existing_diffs, args.kb_version)

    elif directory_type == DiffDepth.ARCHITECTURE:  # specific architectures
        auto_diff_architecture(args.path_executables, diff_path, skip_existing_diffs, args.kb_version)

    elif directory_type == DiffDepth.SPECIFIC_DIFF:  # specific package folder
        auto_diff_package(args.path_executables, diff_path, skip_existing_diffs)
    else:
        raise ValueError("can't parse the filesystem please specify different executable path")
    logging.info("finished!!")


if __name__ == '__main__':
    main()
