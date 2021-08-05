import logging
import os
import shutil
import subprocess

import compare.compare
import core.score
import features.feature
import features.groupby
import core.function

# execute: ilspycmd "E:\windows10\Windows\Microsoft.NET\Framework64\v4.0.30319\AddInProcess32.exe" -o c:\tmp\abc -p
# install using:  dotnet tool install --global ilspycmd
# filter only dotnet files.


class DotNetDecompiler(features.feature.PEFeature):
    METHOD_NAME = "DotNetDecompiler"

    def __init__(self, filesystem_root_folder, output_root_folder=None, seconds_timeout=None):
        self.filesystem_root_folder = filesystem_root_folder
        configurations = core.configurations.get_global().configs.features.dotnet.decompiler
        raw_output_root_folder = output_root_folder
        if output_root_folder is None:
            raw_output_root_folder = core.configurations.get_global().configs.output.path_output_folder

        if raw_output_root_folder is None:
            raise ValueError("feature output folder must not be None!!")

        self.dotnet_root_folder = os.path.join(raw_output_root_folder, type(self).METHOD_NAME)
        self.seconds_timeout = seconds_timeout
        if seconds_timeout is None:
            self.seconds_timeout = configurations.seconds_timeout

        self.tool_name = configurations.tool_name
        self.command_format = configurations.command_format
        compared_number = 1
        group_by = features.groupby.GroupByOrderedPE(compared_number)
        super().__init__(type(self).METHOD_NAME, compared_number, group_by)
        self._validate_requirements()

    def _validate_requirements(self):
        is_found = False
        try:
            t = subprocess.Popen([self.tool_name, "/?"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            t.communicate(timeout=10)
            if t.returncode == 0 or t.returncode == 1:
                is_found = True
            elif t.returncode == 9009:
                is_found = False

        except FileNotFoundError:
            is_found = False

        if not is_found:
            raise EnvironmentError(f"failed to find {self.tool_name} "
                                   f"please run command 'dotnet tool install --global ilspycmd' if 'dotnet' is not found - download .net")

    def filter_objects(self, compare_objects):
        oldest = compare_objects.objects_to_compare[compare.compare.OLDEST]
        return oldest.is_dot_net()

    def _run_decompiler(self, pe):
        pe_path = pe.path_pe
        relative_path_to_root = os.path.relpath(pe_path, start=self.filesystem_root_folder)

        output_dir = os.path.join(self.dotnet_root_folder, relative_path_to_root)
        formatted_command = self.command_format.format(self.tool_name, pe_path, output_dir)
        if os.path.exists(output_dir):
            shutil.rmtree(output_dir)
        os.makedirs(output_dir, exist_ok=True)
        process_obj = subprocess.Popen(formatted_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        try:
            stdout, stderr = process_obj.communicate(timeout=self.seconds_timeout)
        except subprocess.TimeoutExpired:
            logging.warning(f"failed to decompile pe {pe_path}")

    def _score(self, compare_object):
        pe = compare_object.objects_to_compare[compare.compare.OLDEST]
        self._run_decompiler(pe)
        return []
