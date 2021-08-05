import os
import logging
import core.configurations
import sqlite3


class OutputHandler(object):
    """
    Handle all the output handlers, write to files, db, print to screen...
    """
    def __init__(self):
        pass

    def get_output(self, output):
        """
        Pass the result object to all the output handlers
        :param output: Result object that contains all the information
        :return: None
        """
        pass

    def finish(self):
        """
        When the program finished and no new results will enter into the system - for summaries and statistics
        :return: None
        """
        pass


class PrintResults(OutputHandler):
    """
    Output handler - stdout
    """
    def __init__(self, logger):
        self.logger = logger
        self.is_print_negative_scores = core.configurations.get_global().configs.output.is_print_negative_scores_as_debug
        super().__init__()

    def get_output(self, output):
        if self.is_print_negative_scores and output.score_value <= 0:
            self.logger.debug(output)
        else:
            self.logger.info(output)


class SaveToDB(OutputHandler):
    """
    Store all results into a SQL DB
    """
    def __init__(self, db_location, is_create_new_db=False, prefix_feature="feature_",
                 prefix_type="type_", non_str_rows=None, number_of_inserts_between_commits=None,
                 feature_types_exclude_from_main_tables=None):
        self.prefix_type = prefix_type
        self.prefix_feature = prefix_feature
        self.db_location = db_location
        if os.path.exists(self.db_location) and is_create_new_db is True:
            logging.warning("removed db.")
            os.remove(self.db_location)

        if non_str_rows is None:
            self.non_str_rows = core.configurations.get_global().configs.output.non_str_db_rows
        else:
            self.non_str_rows = {}
        self.conn = sqlite3.connect(self.db_location)
        self._all_results = {}
        self.index = 0
        if number_of_inserts_between_commits is None:
            self.number_of_inserts_between_commits = \
                core.configurations.get_global().configs.output.number_of_inserts_between_commits
        else:
            self.number_of_inserts_between_commits = number_of_inserts_between_commits

        if feature_types_exclude_from_main_tables is None:
            self.feature_types_exclude_from_main_tables = core.configurations.get_global().configs.output.feature_types_exclude_from_main_tables
        else:
            self.feature_types_exclude_from_main_tables = feature_types_exclude_from_main_tables

        self.tables_to_index = core.configurations.get_global().configs.output.index_tables
        super().__init__()

    def get_output(self, output):
        serialized = output.strict_serialize()
        obj_type = serialized.pop('type')
        second_table_name = self.prefix_type + obj_type
        table_name = self.prefix_feature + obj_type + "_" + serialized['feature_type']
        self.add_to_results(serialized, table_name)  # by feature
        if serialized['feature_type'] not in self.feature_types_exclude_from_main_tables:
            self.add_to_results(serialized, second_table_name)  # by type (pe, function...)
            self.add_to_results(serialized, "all_features")  # ALL features

    def add_to_results(self, serialized, table_name):
        if table_name not in self._all_results:
            self._create_table(table_name, serialized)
            self._all_results[table_name] = set(serialized.keys())

        missing_keys = set(serialized.keys()).difference(self._all_results[table_name])
        for missing_key in missing_keys:
            self.add_column_to_table(table_name, missing_key, serialized[missing_key])
            self._all_results[table_name].add(missing_key)

        self.add_to_table(table_name, serialized)

    def _create_table(self, table_name, obj_to_fit):
        if self._is_table_exists(table_name):
            for column, val in obj_to_fit.items():
                self.add_column_to_table(table_name, column, val)
            return

        cur = self.conn.cursor()
        param_sql_section = ""
        for key_name, example_val in obj_to_fit.items():
            type_param = self.resolve_param_type(example_val, key_name)
            param_sql_section += f"{key_name} {type_param},"
        param_sql_section = param_sql_section[:-1]

        sql = f"""CREATE TABLE IF NOT EXISTS {table_name} ( id integer PRIMARY KEY, {param_sql_section});"""

        cur.execute(sql)
        cur.close()

    def _is_table_exists(self, table_name):
        cur = self.conn.cursor()
        results = cur.execute("SELECT name FROM sqlite_master WHERE type='table'")
        for current_table_name in results:
            if table_name == current_table_name[0]:  # it returns as tuple.
                cur.close()
                return True

        cur.close()
        return False

    def resolve_param_type(self, example_value, column_name):
        if column_name in self.non_str_rows:
            return self.non_str_rows[column_name]

        return "text"

    def add_column_to_table(self, table_name, column_name, example_value):
        try:
            param_type = self.resolve_param_type(example_value, column_name)
            sql = f"ALTER TABLE {table_name} ADD {column_name} {param_type} default NULL"
            cur = self.conn.cursor()
            cur.execute(sql)
            cur.close()
        except sqlite3.OperationalError as e:
            if len(e.args) >= 1 and 'duplicate column name' in e.args[0]:
                return
            logging.info(f"failed to alter table: {table_name} {column_name} exception: {e}")

    @staticmethod
    def _remove_unused_types(obj):
        full_dict = {}
        for key, val in obj.items():
            updated_key = key
            updated_val = val
            if val is None:
                continue
            elif val is False or val is True:
                updated_val = str(val)
            elif type(val) is dict:
                updated_val = str(val)
            elif type(val) is list:
                updated_val = str(val)
            elif type(val) is set:
                updated_val = str(val)
                
            if type(updated_val) == str:
                updated_val = updated_val.replace(r"'", r"''")

            full_dict.update({updated_key: updated_val})

        return full_dict

    def add_to_table(self, table_name, raw_obj):
        obj = type(self)._remove_unused_types(raw_obj)
        try:
            self.index += 1
            cur = self.conn.cursor()
            keys = str(tuple(obj.keys()))
            values = str(tuple(obj.values())).replace(r"\'", "'")
            sql = f"INSERT INTO {table_name}{keys} VALUES{values}"
            cur.execute(sql)
            cur.close()
            if self.index >= self.number_of_inserts_between_commits:
                self.conn.commit()  # save the changes
                self.index = 0

        except sqlite3.OperationalError as e:
            logging.error(f"failed to insert into table info: {sql}")

    @staticmethod
    def _get_keys(list_of_obj):
        keys = set()
        for obj in list_of_obj:
            keys = keys.union(obj.keys())

        return keys

    def add_indexes(self):
        logging.info("starting to indexing tables")
        cur = self.conn.cursor()
        for table_name, rows in self.tables_to_index.items():
            str_rows = str(tuple(rows)).replace("'", "").replace('"', "")
            sql = f'create index {table_name}_index on {table_name} {str_rows}'
            try:
                cur.execute(sql)
            except Exception as e:
                logging.error(f"failed to add an index {sql}")

    def finish(self):
        self.conn.commit()
        self.add_indexes()
        self.conn.commit()

    def __del__(self):
        if hasattr(self, "conn"):
            self.conn.commit()
            self.conn.close()
