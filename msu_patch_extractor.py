# Extract all the MSU (Windows security updates) into filesystem
import packaging.version
import datetime
import concurrent.futures
import logging
import sys
import subprocess
import os
import glob
import shutil
import pathlib2
import re
import argparse
import hashlib
import ctypes

import core.filesystem
import core.delta_patch

import psutil

THREAD_POOL_WORKERS_DELTAS = 3

PATCH_FILE_EXTENSION = ".msu"
# Powershell script configurations:
PATH_POWERSHELL_PATCH_EXTRACTOR = os.path.join(os.path.dirname(__file__), "utilities", "PatchExtract.ps1")
PATH_POWERSHELL = "Powershell.exe"
CMD_POWERSHELL_PATCH_EXTRACTOR = "{PATH_POWERSHELL} -ExecutionPolicy Bypass -File {PATH_POWERSHELL_PATCH_EXTRACTOR} -x64 amd64 -WOW wow64  -Patch {path_msu_file} -Path {path_output_dir}"

PATH_WINDOWS_SXS_DIR = r"C:\Windows\Winsxs"
OPTIONAL_ARCHITECTURES = ['x86', 'amd64', 'wow64', 'MSIL']
PE_FILE_SUFFIX = ["exe", "dll", "sys", "cpl", "drv", "efi", "ocx"]
IS_FORCE_CREATE = False
BASE_FILE_PREFIX = "2000-01_kb0000000_"

logger = None
if __name__ == "__main__":
    log_file = os.path.join("logs", 'msu_patch_extractor.log')
    logging.basicConfig(level=logging.DEBUG, filename=log_file,
                        datefmt='%Y-%m-%d %H:%M:%S', format='%(asctime)s - %(levelname)s - %(message)s')
    logger = logging.getLogger()
    logger.setLevel(logging.DEBUG)
    file_format = logging.Formatter('%(asctime)s:%(levelname)s:%(message)s', datefmt='%Y-%m-%d %H:%M:%S')
    stdout_handler = logging.StreamHandler(sys.stdout)
    stdout_handler.setLevel(logging.INFO)
    logger.addHandler(stdout_handler)


def __process_wait(process):
    while process.poll() is None:
        output, _ = process.communicate()
        logger.debug(output)

    logger.debug("finished polling - starting to wait")
    process.wait()


def msu_extract_to_files(path_msu, path_output):
    """
    Extract MSU file to a folder that contains delta files according to Microsoft format
    :param path_msu: path to MSU file
    :param path_output: directory path to extract the deltas.
    """
    if not os.path.exists(path_output):
        os.makedirs(path_output, exist_ok=True)
    elif not IS_FORCE_CREATE:
        logger.info(f"skipping {path_output} because it is exist")
        return

    full_cmd = CMD_POWERSHELL_PATCH_EXTRACTOR.format(PATH_POWERSHELL=PATH_POWERSHELL,
                                                     PATH_POWERSHELL_PATCH_EXTRACTOR=PATH_POWERSHELL_PATCH_EXTRACTOR,
                                                     path_msu_file=path_msu,
                                                     path_output_dir=path_output)

    logger.debug("about to extract msu {path_msu} using the command {cmd}".format(path_msu=path_msu, cmd=full_cmd))
    process = subprocess.Popen(full_cmd, stderr=subprocess.STDOUT, stdout=subprocess.PIPE)
    __process_wait(process)
    if not process.returncode == 0:
        logger.warning("powershell msu extractor failed to extract msu {path_msu} "
                       "to delta files in directory {path_deltas}".format(path_msu=path_msu, path_deltas=path_output))
        raise ValueError("Failed to extract the MSU")

    logger.info("extracted the msu {path_msu} successfully".format(path_msu=path_msu))


def __remove_older_deltas_specific_folder(path_delta_folder, full_os_build):
    for file_name in os.listdir(path_delta_folder):
        path_pe_package = os.path.join(path_delta_folder, file_name)
        if not os.path.isdir(path_pe_package):
            logger.warning("Didn't expect to find non-folder file {file_name} inside the path"
                           " {path_delta_folder}, ignoring".format(path_delta_folder=path_delta_folder,
                                                                   file_name=file_name))
            continue

        if full_os_build not in file_name:
            logger.debug("removed folder {folder_path}".format(folder_path=path_pe_package))
            try:
                shutil.rmtree(path_pe_package)
            except Exception as _:
                logger.warning(
                    "failed to remove the directory {path_pe_package}".format(path_pe_package=path_pe_package))


def _remove_older_deltas(path_delta_folder, full_os_build):
    """
    Remove from the extracted delta files structure old patches.
    :param path_delta_folder: path to the root delta folder, it can be the root extracted folder and then
    :param full_os_build: string patch number in the according to windows (for example 19041.508)
    """
    folders_to_reduce = OPTIONAL_ARCHITECTURES
    is_in_inner_folder = os.path.join(path_delta_folder, folders_to_reduce[0])
    if os.path.exists(is_in_inner_folder):  # path_delta_folder in the root dir
        for delta_folder_name in folders_to_reduce:
            path_inner_folder = os.path.join(path_delta_folder, delta_folder_name)
            __remove_older_deltas_specific_folder(path_inner_folder, full_os_build)

    else:  # Path is inside one of the folders
        __remove_older_deltas_specific_folder(path_delta_folder, full_os_build)


def _apply_deltas_to_pe(path_original_file, paths_deltas, path_new_file, is_override_new_file=False):
    """
    Apply delta patches to PE - relevant for Windows 10 updates
    https://wumb0.in/extracting-and-diffing-ms-patches-in-2020.html
    :param path_original_file: original file to apply patches to
    :param paths_deltas: list of paths of delta files (ordered)
    :param path_new_file: path of the new file generated from joining original file with all the deltas.
    """
    new_file_dir = os.path.dirname(path_new_file)
    if not os.path.exists(new_file_dir):
        logger.info("created path {path_new_file_dir} for the output".format(path_new_file_dir=new_file_dir))
        os.makedirs(new_file_dir, exist_ok=True)

    if os.path.exists(path_new_file):
        if not is_override_new_file:
            msg = "output file is exists before creating the operation, please turn on is_override_new_file flag"
            logger.error(msg)
            raise ValueError(msg)

        os.remove(path_new_file)

    core.delta_patch.delta_patch_file(path_original_file, path_new_file, paths_deltas, null_buf=False, legacy=False,
                                      dry_run=False)
    logger.info("finished to apply the patch to original {f}".format(f=path_original_file))
    if not os.path.exists(path_new_file):
        logger.error("could not find the generated file")
        raise ValueError("could not find the generated file")


def get_pkg_name_from_sxs_folder_name(path_folder):
    """
    Get the name of the package from path
    :param path_folder: path of the package
    :return: string name of the package
    """
    folder_name = os.path.basename(path_folder)
    spited_name = folder_name.split("_")
    if len(spited_name) < 2:
        logger.info("could not find package name for {folder_name}".format(folder_name=folder_name))
        return ""
    if len(spited_name) == 2:
        return spited_name[0]
    elif len(spited_name) == 3:
        return spited_name[1]
    elif len(spited_name) == 6:
        return spited_name[1]
    elif len(spited_name) == 7:
        return "_".join(spited_name[1:3])  # take 2 underscores
    elif len(spited_name) == 8:
        return "_".join(spited_name[1:4])  # take 3 underscores
    raise ValueError("didn't expect to have more than 2 underscores in sxs folder name"
                     " {path_folder}".format(path_folder=path_folder))


def get_pe_in_windows_sxs(file_name, architecture, pkg_name, version=None, path_winsxs=None):
    """
    Get PE in windows sxs
    :param pkg_name: name of the package according to winsxs
    :param file_name: name of the file (with extension)
    :param architecture: is architecture is x86 or amd64  or wow64
    :param version: optional param, string contains build major dot build minor, such as 10.0.19041.423
    :return:list of paths of that DLL in WinSxS
    """
    architecture = architecture.lower()
    lower_arch = [x.lower() for x in OPTIONAL_ARCHITECTURES]
    if architecture not in lower_arch:
        msg = "expected architecture to be one of the following {} but was given {}".format(lower_arch,
                                                                                            architecture)
        logger.warning(msg)
        raise ValueError(msg)

    if path_winsxs is None:
        path_winsxs = PATH_WINDOWS_SXS_DIR

    string_search = r"{path_windows_sxs}\{architecture}_*\{file_name}".format(path_windows_sxs=path_winsxs,
                                                                              architecture=architecture,
                                                                              file_name=file_name)
    optional_files_found = glob.glob(string_search)
    files_found = []
    minimal_pkg_name = pkg_name
    if pkg_name[0].isalpha() and pkg_name[1:3] == "..":  # to support short pkg formats [letter]..end_name
        minimal_pkg_name = pkg_name[3:]

    for file_found in optional_files_found:
        pkg_folder_name = os.path.basename(os.path.dirname(file_found))
        if minimal_pkg_name in pkg_folder_name and (version is None or version in pkg_folder_name):
            files_found.append(file_found)

    return files_found


def __get_revert_from_path_winsxs(path_pe_in_sxs):
    path_dir = os.path.dirname(path_pe_in_sxs)
    pe_name = os.path.basename(path_pe_in_sxs)
    path_revert = os.path.join(path_dir, r"r\{pe_name}".format(pe_name=pe_name))
    if not os.path.exists(path_revert):
        path_revert = None
    return path_revert


def is_allowed_version(version):
    all_allowed_chars = set("01234567890.")
    version_sets = set(version)
    return version_sets.issubset(all_allowed_chars)


def __get_full_version_from_path_winsxs(path_pe_sxs):
    if os.path.isdir(path_pe_sxs):
        pkg_folder_name = os.path.basename(path_pe_sxs)
    else:
        pkg_folder_name = os.path.basename(os.path.dirname(path_pe_sxs))
    splitted_name = pkg_folder_name.split("_")
    if len(splitted_name) == 2:
        version = splitted_name[-1]
    else:
        version = splitted_name[-3]

    if not is_allowed_version(version):  # it is not only allowed chars
        found_section = None
        num_found = 0
        for name_part in splitted_name:
            if is_allowed_version(name_part):
                found_section = name_part
                num_found += 1

        if num_found == 1:
            return found_section
        elif num_found == 0:
            logger.warning("generating version number for package {package_name}".format(package_name=path_pe_sxs))
            return "1.0.0.0"
        else:
            logger.warning(
                "version str should contain digits and dots only {path_pe_sxs} found more than 1 matched".format(
                    path_pe_sxs=path_pe_sxs))

            raise ValueError("version expected to contains digits and dots only")

    return version


def _is_file_is_pe(file_path):
    suffix = pathlib2.Path(file_path).suffix[1:]
    return suffix in PE_FILE_SUFFIX


def _get_kb_name(path_kb):
    file_name = os.path.basename(path_kb)
    try:
        return file_name.split("-")[1]
    except:
        return None


def _get_kb_date(path_kb):
    """
    Get the date of a msu
    :param path_kb: path of the KB
    :return: date of the KB
    """
    file_name = os.path.basename(path_kb)
    try:
        full_date = "-".join(file_name.split("_")[0:3])
        #  validate it is legitimate date
        datetime.datetime.strptime(full_date, '%Y-%m-%d')
        return full_date
    except ValueError:
        try:
            year_month = "-".join(file_name.split("_")[0:2])
            datetime.datetime.strptime(year_month, '%Y-%m')
            return year_month
        except Exception:
            return None


def _get_pe_date(path_pe):
    """
    Extract the date of the pe from the name
    :param path_pe: path of the pe
    :return: datetime object
    """
    kb_dir = os.path.dirname(os.path.dirname(os.path.dirname(path_pe)))
    kb_date = _get_kb_date(kb_dir)
    try:
        return datetime.datetime.strptime(kb_date, '%Y-%m-%d')
    except ValueError as e:
        return datetime.datetime.strptime(kb_date, '%Y-%m')


def apply_patch_to_msu(path_extract_package, path_root_lnk, architectures_folders=None, filename_prefix=""):
    if architectures_folders is None:
        architectures_folders = OPTIONAL_ARCHITECTURES

    with concurrent.futures.ThreadPoolExecutor(THREAD_POOL_WORKERS_DELTAS,
                                               thread_name_prefix="TP_patch_apply") as thread_pool:
        for architecture in architectures_folders:
            path_architecture_packages = os.path.join(path_extract_package, architecture)
            if not os.path.exists(path_architecture_packages):
                logging.warning(f"Could not find the path {path_architecture_packages}")
                continue
            for package_name in os.listdir(path_architecture_packages):
                path_package = os.path.join(path_architecture_packages, package_name)
                if not os.path.isdir(path_package):
                    msg = "expect only directories in {}".format(path_package)
                    logger.warning(msg)
                    continue

                thread_pool.submit(apply_patch_for_package, architecture, path_package,
                                   path_root_lnk, filename_prefix)


def create_link(path_symlink, path_src, is_override, file_extension=".symlink"):
    if file_extension is not None:
        path_symlink += file_extension

    if os.path.exists(path_symlink):
        if is_override:
            os.remove(path_symlink)  # removing the file in order to override it.
        else:
            logger.info("didn't create link to {} because it is exist".format(path_src))
            return

    lnk_dir = os.path.dirname(path_symlink)
    if not os.path.exists(lnk_dir):
        logger.debug("created dir {path_lnk}".format(path_lnk=lnk_dir))
        os.makedirs(lnk_dir, exist_ok=True)
    try:
        os.symlink(path_src, path_symlink)
    except Exception as e:
        logger.error(f"Failed to create symlink because {e}")


def create_base_version(path_pe_lnk_dir, architecture, full_build_version, pkg_name, pe_name):
    """
    Add a base version to a specific file type
    :param path_pe_lnk_dir: path of the link dir (inside the executables)
    :param architecture: architecture name
    :param full_build_version: the oldest build version we have, we want to create base version before that.
    :param pkg_name: package name
    :param pe_name: executable name
    :return: None
    """
    base_major_version = ".".join(full_build_version.split(".")[:-1])
    # because we want only the base
    name_base_pe = "{full_version}.1_{pe_name}".format(full_version=base_major_version, pe_name=pe_name)
    path_base_pe = os.path.join(path_pe_lnk_dir, name_base_pe)
    if os.path.exists(path_base_pe):
        return  # there is no need to re-create that.

    pes_in_winsxs = get_pe_in_windows_sxs(pe_name, architecture, pkg_name, base_major_version)
    if len(pes_in_winsxs) < 1:
        raise ValueError("could not find suitable pe in winsxs for {} {} {} {}".format(pe_name, architecture, pkg_name,
                                                                                       base_major_version))

    chosen_pe = pes_in_winsxs[0]
    revert_file = __get_revert_from_path_winsxs(chosen_pe)
    if revert_file is not None:  # there is a revert
        _apply_deltas_to_pe(chosen_pe, [revert_file], path_base_pe, True)
    else:  # the file is the latest version
        sxs_version = __get_full_version_from_path_winsxs(chosen_pe)
        is_found_in_lnk_fs = is_pe_in_lnk_fs(path_pe_lnk_dir, sxs_version, pe_name)
        if not is_found_in_lnk_fs:
            name_base_pe = "{full_version}.1_{pe_name}".format(full_version=sxs_version, pe_name=pe_name)
            path_base_pe = os.path.join(path_pe_lnk_dir, name_base_pe)
            shutil.copy(chosen_pe, path_base_pe)
        create_link(path_base_pe, path_base_pe, True)


def is_pe_in_lnk_fs(path_lnk_pe_dir, full_build_version, pe_name):
    lnk_name = "{build_version}_{pe_name}.symlink".format(build_version=full_build_version, pe_name=pe_name)
    for i in os.listdir(path_lnk_pe_dir):
        if lnk_name in i:
            return True
    return False


def __get_real_path(path):
    full_path = os.path.abspath(os.path.realpath(path))
    if full_path.endswith(".symlink") or full_path.endswith(".lnk"):
        return os.readlink(full_path)
    return full_path


def compare_files_content(file_1, file_2):
    """
    check if the files are equal
    :param file_1: path of the first file
    :param file_2: path of the second file
    :return: True if it is equal, false - not equal.
    """

    def sha_256_file(path):
        sha256 = hashlib.sha256()
        with open(path, 'rb') as f:
            while True:
                data = f.read(5000)
                if not data:
                    break
                sha256.update(data)
        return sha256.hexdigest()

    real_path_1 = __get_real_path(file_1)
    real_path_2 = __get_real_path(file_2)
    sha_file_1 = sha_256_file(real_path_1)
    sha_file_2 = sha_256_file(real_path_2)
    return sha_file_1 == sha_file_2


def _add_pe_to_lnk_fs(path_pe_to_add, architecture, full_build_version, path_root_lnk, pkg_name, prefix=""):
    pe_name = os.path.basename(path_pe_to_add)
    lnk_folder_name = "{pkg_name}_{pe_name}".format(pe_name=pe_name, pkg_name=pkg_name)
    path_pe_lnk_dir = os.path.join(os.path.join(path_root_lnk, architecture), lnk_folder_name)
    if len(prefix) > 0:
        prefix = prefix + "_"

    lnk_name = "{prefix}{build_version}_{pe_name}".format(prefix=prefix, build_version=full_build_version,
                                                          pe_name=pe_name)
    path_pe_lnk = os.path.join(path_pe_lnk_dir, lnk_name)
    if os.path.exists(path_pe_lnk_dir):  # validate there is no file with the same version
        for file_name in os.listdir(path_pe_lnk_dir):
            if full_build_version in file_name:
                full_path_lnk = os.path.join(path_pe_lnk_dir, file_name)
                real_path_lnk = __get_real_path(full_path_lnk)
                if compare_files_content(path_pe_to_add, full_path_lnk):  # check if the files are equal
                    # choose which KB is it related to.
                    existing_pe_date = _get_pe_date(real_path_lnk)
                    new_pe_date = _get_pe_date(path_pe_to_add)
                    if new_pe_date == existing_pe_date:
                        return

                    if existing_pe_date <= new_pe_date:  # existing is older
                        logger.info("skipping adding file {pe_to_add} to PEs because there is existing"
                                    " version and {full_path_lnk}".format(pe_to_add=path_pe_to_add,
                                                                          full_path_lnk=full_path_lnk))
                        return
                    else:
                        logger.info("removing PE file {existing_pe_date} because found older file with same version"
                                    "".format(existing_pe_date=existing_pe_date))
                        os.remove(full_path_lnk)
                else:
                    logger.warning("Added PE with the same version as another version because they are different "
                                   "{original_pe} {new_pe}".format(original_pe=full_path_lnk, new_pe=path_pe_to_add))

    create_link(path_pe_lnk, path_pe_to_add, True)


def apply_patch_for_package(architecture, path_package, path_root_lnk, file_name_prefix):
    """
    Apply patch for specific package
    :param architecture: name of the architecture of the package
    :param path_package: path of the package of the pe we're going to extract
    :param path_root_lnk: path to the folder to create the symlink in
    :param file_name_prefix: prefix of the name of the file to create
    :return: None
    """
    try:
        full_build_version = __get_full_version_from_path_winsxs(path_package)
        path_patch_in_pkg = os.path.join(path_package, "f")  # the name of the folder that contains the patch.
        is_required_to_do_patch = True
        if not os.path.exists(path_patch_in_pkg):  # It is a stack update - without diff but original files.
            is_required_to_do_patch = False
            path_patch_in_pkg = path_package

        pkg_name = get_pkg_name_from_sxs_folder_name(path_package)
    except Exception as e:
        logger.error("failed to parse package {package_name}, exception: {e}".format(package_name=path_package, e=e))
        raise

    for pe_name in os.listdir(path_patch_in_pkg):
        try:
            output_patched_pe = os.path.join(path_package, pe_name)
            path_pe_patch = os.path.join(path_patch_in_pkg, pe_name)
            if not _is_file_is_pe(path_pe_patch):
                continue

            if is_required_to_do_patch:
                paths_pe_in_winsxs = get_pe_in_windows_sxs(pe_name, architecture, pkg_name)
                chosen_winsxs_pe = paths_pe_in_winsxs[0]
                paths_pe_revert_in_winsxs = __get_revert_from_path_winsxs(chosen_winsxs_pe)
                patches = [paths_pe_revert_in_winsxs, path_pe_patch]
                if paths_pe_revert_in_winsxs is None:
                    patches = [path_pe_patch]
                    logger.info("could not find revert for {pe} "
                                "other options are: {other_options}".format(pe=chosen_winsxs_pe,
                                                                            other_options=paths_pe_in_winsxs[1:]))

                _apply_deltas_to_pe(chosen_winsxs_pe, patches,
                                    output_patched_pe, True)

            _add_pe_to_lnk_fs(output_patched_pe, architecture, full_build_version, path_root_lnk, pkg_name,
                              file_name_prefix)
        except ValueError as e:
            logger.error("failed to generate PE {pe_name} because of {error_message}".format(pe_name=pe_name,
                                                                                             error_message=str(e)))
        except IndexError as _:
            logger.error("failed to generate PE {pe_name} {architecture} {pkg_name} "
                         "because it could not be found".format(pe_name=pe_name, architecture=architecture,
                                                                pkg_name=pkg_name))
        except Exception as e:
            logger.critical("failed because of unknown issue {e} {message}".format(e=type(e), message=str(e)),
                            exc_info=True)


def extract_msu(path_msu, path_extracted_folder, path_executables):
    """
    Extract msu file to dir tree of extracted msu files and directory of all the versions of a specific file
    :param path_msu: path to the msu file
    :param path_extracted_folder: path that the script will create in order to extract the msu file
    :param path_executables: path to a directory that contains all the versions of specific PE.
    """
    if not os.path.exists(path_msu):
        raise ValueError("MSU file path is not found {path_msu}".format(path_msu=path_msu))

    msu_extract_to_files(path_msu, path_extracted_folder)
    date_msu = _get_kb_date(path_msu)
    if date_msu is None:
        logger.warning(f"failed to get MSU kb date {path_msu}")
        date_msu = ""

    kb_name = _get_kb_name(path_msu)
    if kb_name is None:
        logger.warning(f"failed to get MSU KB name {path_msu}")
        kb_name = ""

    if len(date_msu) > 0 and len(kb_name) > 0:
        prefix = f"{date_msu}_{kb_name}"
    else:
        prefix = ""

    # not removing older deltas because there are files such as gdiplus.dll (microsoft.windows.gdiplus_gdiplus.dll)
    # with wrong version (from KB itself) starts with 1.1.x.x
    # _remove_older_deltas(path_extracted_folder, build_version)
    apply_patch_to_msu(path_extracted_folder, path_executables, filename_prefix=prefix)


def get_all_msu_files_in_dir(dir_path, regex=".*.msu"):
    for root, dirs, files in os.walk(dir_path, topdown=False):
        for file_name in files:
            if re.match(regex, file_name):
                full_path = os.path.join(root, file_name)
                yield full_path


def _is_have_error_with_arguments(args):
    """
    Validate and update the arguments got from input.
    :param args: args from Argparse
    :return: True in case there is an error in the arguments, False if everything is OK.
    """

    def find_mount_point(path):
        path = os.path.abspath(path)
        while not os.path.ismount(path):
            path = os.path.dirname(path)
        return path

    if not os.name == "nt":
        raise EnvironmentError("The code must run on Windows")

    if args.path_extract_msu is None and args.path_kb_folder is None:
        raise EnvironmentError("You must provide path to KB folder to extract them or path of the extracted MSUs")

    if not os.path.exists(args.path_winsxs):
        raise EnvironmentError("Winsxs folder must exist")

    if args.path_kb_folder is not None and not os.path.exists(args.path_kb_folder):
        raise EnvironmentError("kb folder must exist")

    if args.path_extract_msu is None:
        args.path_extract_msu = args.path_kb_folder

    os.makedirs(args.path_executables, exist_ok=True)
    full_exec_path = os.path.abspath(args.path_executables)
    mount_device = find_mount_point(full_exec_path)
    for disk in psutil.disk_partitions():
        if disk.device == mount_device:
            if disk.fstype == "NTFS":
                return False
            elif "fat" in disk.fstype.lower():
                raise EnvironmentError("executable filesystem has to support symlinks! (not fat filesystem)")

    logger.warning("filesystem is unknown - not sure if it is supported")
    return True


def link_all_base_versions(path_executbles_folder, path_winsxs):
    root_exec_fs = core.filesystem.ExecutablesFileSystem(path_executbles_folder)
    for pe_type_fs in root_exec_fs.get_all_files_group_by_executable_type():
        pes = list(pe_type_fs)
        if len(pes) > 1:
            continue  # no need to add base version
        elif len(pes) == 0:
            logger.warning("didn't expect len of pes to be zero")
            continue
        selected_pe = pes[0]
        real_package_name = selected_pe.package_name
        if real_package_name.endswith(selected_pe.name):
            real_package_name = real_package_name[:len(selected_pe.name) + 1]  # + 1 for the underscore before.
        pes_found = list(get_pe_in_windows_sxs(selected_pe.name, selected_pe.architecture, real_package_name,
                                               path_winsxs=path_winsxs))
        if len(pes_found) == 0:
            logger.info(f"could not find base version for {selected_pe}")
            continue
        elif len(pes_found) == 1:
            logger.info(f"FOUND versions for {selected_pe} {pes_found}")
            found_pe = pes_found[0]
        elif len(pes_found) > 1:
            found_pe = pes_found[0]
            logger.info(f"FOUND more versions for {selected_pe} {pes_found}, chose {found_pe}")
        else:  # for the linter
            raise ValueError("Expected len_found to be integer")

        folder_name = f"{selected_pe.package_name}_{selected_pe.name}"
        pe_collection_folder = os.path.join(path_executbles_folder, selected_pe.architecture, folder_name)
        version = __get_full_version_from_path_winsxs(found_pe)
        found_version = packaging.version.parse(version)
        if found_version.major != selected_pe.version.major and \
                found_version.minor != selected_pe.version.minor:
            logger.info(f"major version doesn't match, skipping version {found_pe}")
            continue

        if compare_files_content(found_pe, selected_pe.path_pe) and found_version == selected_pe.version:
            logger.info(f"base version is the same as the diff {found_pe} {selected_pe} because"
                        f" the version is the same and files have the same hash")
            continue
        if found_version > selected_pe.version:
            logger.info(f"version found is bigger than existing version - skipping")
            continue

        lnk_name = "{prefix}{build_version}_{pe_name}".format(prefix=BASE_FILE_PREFIX, build_version=version,
                                                              pe_name=selected_pe.name)
        full_link_path = os.path.join(pe_collection_folder, lnk_name)
        create_link(full_link_path, found_pe, False)


def init_arg_parse():
    parser = argparse.ArgumentParser(description='Extract KB (msu) files to PE files')
    parser.add_argument('--verbose', '-v', action='count', default=0, help='Verbose mode. Print debug logs')
    parser.add_argument('--path-winsxs', '-w', action='store', help="Path to winsxs folder of the oldest OS you"
                                                                    " can find, it will be used as reference so we'll "
                                                                    "have more files to compare", type=str,
                        default=r"c:\windows\winsxs")
    parser.add_argument('--include-base-files', action='store_true', help="In case only 1 file found - create base file"
                                                                          ", it use the path to winsxs")
    parser.add_argument('--path-executables', '-e', action='store', help="Path to executables symlink root file system",
                        type=str, required=True)
    parser.add_argument('--path-kb-folder', '-k', action='store', help="Path to kb folder", type=str, required=True)
    parser.add_argument('--threads', '-t', action='store', help="Amount of parallel MSUs to extract", type=int,
                        default=3)
    parser.add_argument('--path-extract-msu', action='store', help="Path to extract the msu", type=str)
    args = parser.parse_args()
    is_have_error = _is_have_error_with_arguments(args)
    if is_have_error:
        raise EnvironmentError("validation of arguments failed")
    return args


def extract_all_msu(path_executables_folder, path_msu_folder, path_winsxs, extraction_folder):
    """
    Extract all the msu files
    :param path_executables_folder: path to extract all the msu files into
    :param path_msu_folder: path of the msu folder
    :param path_winsxs: path of the winsxs folder, in order to look for older versions of files
    :param extraction_folder:
    :return: None
    """
    global PATH_WINDOWS_SXS_DIR
    PATH_WINDOWS_SXS_DIR = path_winsxs
    msu_files = get_all_msu_files_in_dir(path_msu_folder)
    with concurrent.futures.ThreadPoolExecutor(THREAD_POOL_WORKERS_DELTAS) as workers_pool:
        for full_path_msu in msu_files:
            msu_relative_path = os.path.relpath(full_path_msu[:-4], path_msu_folder)  # Remove the suffix .msu
            extracted_msu_folder_name = os.path.join(extraction_folder, msu_relative_path)
            extracted_msu_folder_name = "_".join(extracted_msu_folder_name.split("_")[:-1])
            workers_pool.submit(extract_msu, full_path_msu, extracted_msu_folder_name, path_executables_folder)


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
        logging.error("This script is required to run as elevated user\nExiting program....")
        exit(-1)

    logger.info("began")
    args = init_arg_parse()
    global THREAD_POOL_WORKERS_DELTAS
    THREAD_POOL_WORKERS_DELTAS = args.threads
    extract_all_msu(args.path_executables, args.path_kb_folder, args.path_winsxs, args.path_extract_msu)
    logging.info("done extract all KBs!")
    if args.include_base_files:
        link_all_base_versions(args.path_executables, args.path_winsxs)
    else:
        logger.info("skipping base files due arguments")

    logging.info("done!")


if __name__ == "__main__":
    main()
