import copy
import datetime
import os
import re
import shutil
import sys
import argparse
import logging
if __name__ == "__main__":
    LOGGER = None
else:
    LOGGER = logging.getLogger()


def init_argparse():
    parser = argparse.ArgumentParser(description='Copy diff folder to a different location and '
                                                 'keep all the symlinks updated')
    parser.add_argument('--diff-folder', action='store', required=True, help='path of the diff folder')
    parser.add_argument('--dest', action='store', required=True, help='Dest folder to extract')
    parser.add_argument('--date-kb', action='store', required=True, help='month of the kb in the format: YYYY-MM')
    args = parser.parse_args()

    if os.path.exists(args.dest):
        LOGGER.critical("destination folder exist - exit the program")
        raise ValueError("destination folder exist - exit the program")
    try:
        datetime.datetime.strptime(args.date_kb, '%Y-%m')
    except ValueError:
        logging.critical("kb date month is not according to the format, YYYY-MM")
        raise

    if len(args.date_kb) != 7:
        logging.critical("kb date must be full format (with padding), YYYY-MM")
        raise EnvironmentError("kb date must be full format (with padding), YYYY-MM")
    return args


def config_logger():
    root_dir = os.path.dirname(os.path.dirname(__file__))
    full_log_file = os.path.join(root_dir, "logs", 'bindiff_extractor.log')
    logging.basicConfig(filename=full_log_file, level=logging.WARNING)
    root = logging.getLogger("main")
    root.setLevel(logging.DEBUG)
    handler = logging.StreamHandler()
    handler.setLevel(logging.DEBUG)
    root.addHandler(handler)
    global LOGGER
    LOGGER = root
    stdout_formatter = logging.Formatter('%(levelname)s - %(message)s')
    stream_handler = logging.StreamHandler(sys.stdout)
    stream_handler.setFormatter(stdout_formatter)
    root.addHandler(stream_handler)


def get_diff_kb_directories(diff_folder, date_kb):
    directories_with_latest_kb = []
    for root, folders, files in os.walk(diff_folder):
        for name in folders:
            is_matched = re.match(f".*?_vs_{date_kb}_", name)
            if not is_matched:
                continue

            full_dir_name = os.path.join(root, name)
            directories_with_latest_kb.append(full_dir_name)

    return directories_with_latest_kb


def copy_directories(directories_to_copy, dest_dir):
    for directory in directories_to_copy:
        compare_name = os.path.basename(directory)
        package_name = os.path.basename(os.path.dirname(directory))
        arch = os.path.basename(os.path.dirname(os.path.dirname(directory)))
        dest_full_file_path = os.path.join(dest_dir, arch, package_name, compare_name)
        shutil.copytree(directory, dest_full_file_path)


def main():
    config_logger()
    LOGGER.info("began")
    args = init_argparse()
    directories_to_copy = get_diff_kb_directories(args.diff_folder, args.date_kb)
    copy_directories(directories_to_copy, args.dest)
    LOGGER.info("end")


if __name__ == "__main__":
    main()
