## The goal of this utility is to merge 1 DB into another DB
import copy
import os
import sqlite3
import sys
import argparse
import logging

if __name__ == "__main__":
    LOGGER = None
else:
    LOGGER = logging.getLogger()
import core.utils


def copy_table(connection_src, connection_dest, table_name):
    get_table_property = f"SELECT sql from sqlite_master where tbl_name='{table_name}'"
    src_cur = connection_src.cursor()
    dest_cur = connection_dest.cursor()
    table_property = list(core.utils.sql_get_results(src_cur, get_table_property, False))[0][0]
    dest_cur.execute(f"DROP TABLE IF EXISTS {table_name}")
    dest_cur.execute(table_property)

    results = core.utils.sql_get_results(src_cur, f"SELECT * FROM {table_name}")
    item = 0
    for row in results:
        item += 1
        if item % 50000 == 0:
            LOGGER.debug(f"transferring {item}")
            connection_dest.commit()

        cols = str(tuple(row.keys())).replace("'", "")
        raw_values = []
        for value in row.values():
            if type(value) == str:
                raw_values.append(value.replace("'", "''"))
            else:
                raw_values.append(value)

        values = str(tuple(raw_values)).replace(r"\'", "'").replace("\\\\", "\\")
        query = f'INSERT INTO {table_name} {cols} VALUES {values}'
        dest_cur.execute(query)
    connection_dest.commit()


def get_tables_to_copy(src_table, args):
    all_tables = core.utils.get_all_tables_in_db(src_table)
    if args.tables == "*":
        return all_tables

    n = copy.copy(args.tables)
    for i in args.tables:
        if i in n:
            n.remove(i)

    if len(n) > 0:  # tables doesn't exist
        raise ValueError(f"some tables doens't exist in source {n}")

    return args.tables


def init_argparse():
    parser = argparse.ArgumentParser(description='Copy the content of a DB into another DB')
    parser.add_argument('--src', action='store', required=True, help='source DB')
    parser.add_argument('--dest', action='store', required=True, help='Dest DB')
    parser.add_argument('--tables', nargs='+', action='store', default="*", help='table names to copy')
    args = parser.parse_args()

    if not os.path.exists(args.dest):
        LOGGER.critical("destination DB could not be found")
        raise ValueError("destination DB could not be found")

    if not os.path.exists(args.src):
        LOGGER.critical("source DB could not be found")
        raise ValueError("source DB could not be found")

    return args


def config_logger():
    root_dir = os.path.dirname(os.path.dirname(__file__))
    full_log_file = os.path.join(root_dir, "logs", 'db_merger.log')
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


def main():
    config_logger()
    LOGGER.info("began")
    args = init_argparse()
    source_db = sqlite3.connect(args.src)
    dest_db = sqlite3.connect(args.dest)
    tables = get_tables_to_copy(source_db, args)
    try:
        for table in tables:
            copy_table(source_db, dest_db, table)
    except sqlite3.OperationalError as e:
        LOGGER.error(f"failed to copy {e}")
    source_db.close()
    dest_db.commit()
    dest_db.close()
    LOGGER.info("end")


if __name__ == "__main__":
    main()
