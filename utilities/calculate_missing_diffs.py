# (CWD: executables/amd64 folder)
# TODO: finish this
import os
packages = []
total_executables_packages = len(os.listdir("."))
for package_name in os.listdir("."):
    packages.append(os.path.join(".", package_name))
without_diffs = []
expected_diffs = 0
for package_path in packages:
    match_found = os.listdir(package_path)
    if len(match_found) >= 2:
        expected_diffs += len(match_found) - 1
        continue
    without_diffs.append(package_path)
print("total amount of packages: {}".format(total_executables_packages))
print("total packages with only 1 version: {}".format(len(without_diffs)))
print("total amount of expected diffs: {}".format(expected_diffs))