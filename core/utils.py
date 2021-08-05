def safe_func_call(default_value, function, *args, **kwargs):
    try:
        return function(*args, **kwargs)
    except Exception:
        return default_value


def sql_get_results(cursor, sql_query, is_include_column_names=True):
    results = cursor.execute(sql_query)
    if is_include_column_names:
        columns = get_db_columns(cursor)
        for result in results:
            if not len(columns) == len(result):
                raise ValueError("len of result should be equal to len of columns")

            ret_val = dict(zip(columns, result))
            yield ret_val
    else:
        yield from results


def get_db_columns(cursor_obj):
    row_descriptions = cursor_obj.description
    columns = []
    for row_description in row_descriptions:
        columns.append(row_description[0])

    return columns


def get_all_tables_in_db(db_connection):
    cur = db_connection.cursor()
    results = cur.execute('SELECT name FROM sqlite_master WHERE type = "table"')
    l = list(results)
    cur.close()
    return [i[0] for i in l]


def convert_iterable_to_sql_compatible(iterable, is_include_quotes, is_include_brackets):
    if len(iterable) > 1:
        formatted = str(tuple(iterable))[1:-1]
    elif len(iterable) == 1:
        formatted = f"'{iterable[0]}'"
    else:
        raise ValueError("not supported empty iterable")

    if not is_include_quotes:
        formatted = formatted.replace("'", "")

    if not is_include_brackets:
        return formatted

    return f"({formatted})"


def convert_to_bool(bool_string):
    """
    because bool(str) will check if len(str) > 0 or 0
    :param bool_string: "True"/"False"
    :return: True or False, and raise Value error on fail
    """
    if bool_string.lower() == "true":
        return True
    elif bool_string.lower() == "false":
        return False
    raise ValueError("Failed to convert str bool to bool")