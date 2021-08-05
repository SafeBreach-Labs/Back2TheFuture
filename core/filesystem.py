import enum

import pefile
import logging
import datetime
import abc
import os
import core.pe
import packaging.version


class WindowsVersion(packaging.version.Version):
    @property
    def windows_major(self):
        return f"{self.major}.{self.minor}"


class FileSystem(abc.ABC):
    def __init__(self, root_filesystem, configurations=None):
        if root_filesystem is None:
            raise ValueError("expected not None value as root_filesystem")
        self.configurations = configurations
        self.root_filesystem = root_filesystem

    def get_all_executables(self):
        raise NotImplementedError("abstract object")

    def get_all_files_group_by_executable_type(self):
        raise NotImplementedError("abstract object")


class ExecutableVersionsFileSystem(FileSystem):
    @staticmethod
    def __get_real_path(path):
        full_path = os.path.abspath(os.path.realpath(path))
        if full_path.endswith(".symlink") or full_path.endswith(".lnk"):
            return os.readlink(full_path)
        return full_path

    @staticmethod
    def __get_version_from_executable(path_exe):
        """

        :param path_exe: Gets the path inside the FS not the real path.
        :return:
        """
        path_name = os.path.basename(path_exe).split("_")
        if len(path_name) < 3:
            raise IndexError("error in name {path_name}".format(path_name=path_exe))

        return WindowsVersion(path_name[2])

    @staticmethod
    def __get_pe_name(path):
        real_path = ExecutableVersionsFileSystem.__get_real_path(path)
        return os.path.basename(real_path)

    @staticmethod
    def __get_pe_name(path):
        real_path = ExecutableVersionsFileSystem.__get_real_path(path)
        return os.path.basename(real_path)

    @staticmethod
    def __get_pe_kb_version(path_pe):
        return os.path.basename(path_pe).split("_")[1]

    @staticmethod
    def __get_pe_architecture(path_pe):
        return os.path.basename(os.path.dirname(os.path.dirname(path_pe)))

    @staticmethod
    def __get_pe_package_name(path_pe):
        pe_name = ExecutableVersionsFileSystem.__get_pe_name(path_pe)
        folder_name = os.path.basename(os.path.dirname(path_pe))
        if pe_name.lower() not in folder_name.lower():
            logging.warning(f"pe name is not in folder name {pe_name}, {folder_name}")
            return "_".join(folder_name.split("_")[
                            :-1])  # folder name format is PackageName_fileName we want only the package name.

        return folder_name[: -(len(pe_name) + 1)]  # +1 for the _

    @staticmethod
    def __get_kb_date(path_pe):
        date_kb = os.path.basename(path_pe).split("_")[0]
        try:
            return datetime.datetime.strptime(date_kb, '%Y-%m')
        except ValueError:
            return datetime.datetime.strptime(date_kb, '%Y-%m-%d')

    def get_all_executables(self):
        all_package = []
        for file_name in os.listdir(self.root_filesystem):
            fs_filesystem = os.path.join(self.root_filesystem, file_name)
            full_pe_path = ExecutableVersionsFileSystem.__get_real_path(fs_filesystem)
            pe_version = ExecutableVersionsFileSystem.__get_version_from_executable(fs_filesystem)
            pe_name = ExecutableVersionsFileSystem.__get_pe_name(fs_filesystem)
            kb_version = ExecutableVersionsFileSystem.__get_pe_kb_version(fs_filesystem)
            architecture = ExecutableVersionsFileSystem.__get_pe_architecture(fs_filesystem)
            package_name = ExecutableVersionsFileSystem.__get_pe_package_name(fs_filesystem)
            build_date = ExecutableVersionsFileSystem.__get_kb_date(fs_filesystem)
            all_package.append(core.pe.PE(full_pe_path, self.configurations, pe_version, pe_name, kb_version=kb_version,
                                          architecture=architecture, package_name=package_name, build_date=build_date))
        return all_package

    def get_all_files_group_by_executable_type(self):
        return [self.get_all_executables()]


class ArchitectureFileSystem(FileSystem):
    def get_all_executables(self):
        for file_name in os.listdir(self.root_filesystem):
            full_path = os.path.join(self.root_filesystem, file_name)
            exec_fs = ExecutableVersionsFileSystem(full_path, self.configurations)
            for executable in exec_fs.get_all_executables():
                yield executable

    def get_all_files_group_by_executable_type(self):
        for file_name in os.listdir(self.root_filesystem):
            full_path = os.path.join(self.root_filesystem, file_name)
            exec_fs = ExecutableVersionsFileSystem(full_path, self.configurations)
            yield exec_fs.get_all_executables()


class ExecutablesFileSystem(FileSystem):
    def get_all_executables(self):
        for file_name in os.listdir(self.root_filesystem):
            full_path = os.path.join(self.root_filesystem, file_name)
            exec_fs = ArchitectureFileSystem(full_path)
            for executable in exec_fs.get_all_executables():
                yield executable

    def get_all_files_group_by_executable_type(self):
        for file_name in os.listdir(self.root_filesystem):
            full_path = os.path.join(self.root_filesystem, file_name)
            exec_fs = ArchitectureFileSystem(full_path)
            for versions_of_executable in exec_fs.get_all_files_group_by_executable_type():
                yield versions_of_executable


class GenericFilesystem(FileSystem):
    def __init__(self, root_filesystem, configurations=None, file_extensions=None, is_skip_winsxs=False):
        if root_filesystem is None:
            raise ValueError("expected not None value as root_filesystem")
        if file_extensions is None:
            file_extensions = ["exe", "dll", "sys", "cpl", "drv", "efi", "ocx"]
        self.file_extensions = file_extensions
        self.is_skip_winsxs = is_skip_winsxs
        super().__init__(root_filesystem, configurations)

    def filter_pe(self, path):
        if self.is_skip_winsxs and type(self)._is_path_in_winsxs(path):
            logging.debug(f"skip path {path} because it is in winsxs")
            return False
        return True

    def _extract_file_paths(self):
        for root, dirs, files in os.walk(self.root_filesystem):
            for file in files:
                for file_extension in self.file_extensions:
                    if file.endswith(file_extension):
                        yield os.path.join(root, file)
                        break

    def get_all_executables(self):
        arr = []
        for i in self.get_all_files_group_by_executable_type():
            for m in i:
                arr.append(m)
        return arr

    @staticmethod
    def _is_path_in_winsxs(path):
        if "\\winsxs\\" in path.lower():
            return True
        return False

    def get_all_files_group_by_executable_type(self):
        all_pes = self._extract_file_paths()
        pes_obj = []
        for path_pe in all_pes:
            default_version = WindowsVersion("1.0.0.0")
            package_name = os.path.dirname(path_pe)
            pe = core.pe.PE(path_pe, self.configurations, version=default_version, package_name=package_name)
            if not self.filter_pe(path_pe):
                logging.info(f"filtering out {path_pe}")
                continue
            pes_obj.append([pe])

        return pes_obj


class GenericFileSystemAMD64(GenericFilesystem):
    def _is_compatible_file(self, file_path):
        """

        :param file_path:
        :return: False if the file is not compatible, True - if it is compatible
        """
        try:
            p = pefile.PE(file_path)
            if p.OPTIONAL_HEADER.Magic == 0x10b:  # 32 bits
                return False
            if p.OPTIONAL_HEADER.Magic == 0x20b:  # 64 bits
                return True
        except pefile.PEFormatError as e:  # it is not a PE file.
            logging.warning(f"pe failed getting magic isn't recognized {file_path}")
            return False

        logging.warning(f"optional magic isn't recognized {file_path}")
        return True

    def filter_pe(self, path):
        is_filter = super(GenericFileSystemAMD64, self).filter_pe(path)
        if is_filter is False:
            return False
        is_amd64 = self._is_compatible_file(path)
        return is_amd64


class ExecutableFolderDepth(enum.Enum):
    """
    Correlation between the depth of the folders to which folder are we in
    """
    SPECIFIC_FILE = 0
    FILE_VERSIONS = 1
    ARCHITECTURE = 2
    ROOT_EXECUTABLES = 3
    INVALID = -1


def calculate_max_depth(path):
    """
    Return maximum amount of folders inside folder (depth)
    :param path: path of the folder
    :return: a number of maximum recursive
    """
    if not os.path.exists(path):
        return -1

    if os.path.isfile(path):
        return 0

    max_result = 0
    for file in os.listdir(path):
        full_path = os.path.join(path, file)
        max_depth = calculate_max_depth(full_path)
        if max_depth == ExecutableFolderDepth.INVALID:
            return max_depth

        max_result = max(max_depth + 1, max_result)

    return max_result


