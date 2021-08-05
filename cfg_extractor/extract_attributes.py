# FUNCTION_COMPLEXITY - A number represent the amount of edges in the function.
import logging
import sqlite3

import core.utils

NODE_FEATURES_TO_EXTRACT = ["PE_NAME", "FUNCTION_NAME", "CHANGE_SCORE", "COM_GUID", "RPC_GUID",
                            "FUNCTION_COMPLEXITY", "IS_CALLABLE_FUNCTION", "AMOUNT_OF_CHANGES_IN_FUNC"]

# DATE_CONNECTION - when the connection has began (to detect new connections/changes)
# CONNECTION_TYPE - xref, com/rpc client to server...
EDGE_FEATURES_TO_EXTRACT = ["CONNECTION_TYPE", "DATE_CONNECTION", "CALLED_ARGUMENTS"]

# CALLING_METHODS - how can I call each node, exported functions, rpc....
NODE_POST_PROCESSING_FEATURES = ["CALLING_DEPTH", "IS_LEAF"]

# attributes which we should not add prefix to
SHARED_ATTRIBUTES = ["is_entry_point", "is_documented", "code_example"]


def key_wrapper(prefix):
    def decorator(func):
        def added_prefix(*args, **kwargs):
            ret_val = func(*args, **kwargs)
            wrapped = {}
            for key, val in ret_val.items():
                if key not in SHARED_ATTRIBUTES:
                    wrapped[f"{prefix}_{key}"] = val
                else:
                    wrapped[key] = val

            return wrapped
        return added_prefix
    return decorator


def update_attributes(attributes, new_attr):
    for key, val in new_attr.items():
        if key not in SHARED_ATTRIBUTES or key not in attributes:
            attributes.update({key: val})
        else:
            if type(attributes[key]) == bool and type(val) == bool:
                attributes[key] = attributes[key] or val
            else:
                logging.warning(f"warn updating existing key!! {key} {val}")

    return attributes


def validate_params(func):
    def decode_param(*args, **kwargs):
        raw_dict = func(*args, **kwargs)
        for key, val in raw_dict.items():
            if val is None:
                logging.debug(f"setting attribute {key} {val} for {func.__name__} arguments {args}, {kwargs}")
                raw_dict[key] = "None"

        return raw_dict
    return decode_param


@validate_params
def get_node_attributes(node, ranks_db_connection):
    attributes = {"pe_name": node.pe_name,
                  "function_name": node.function_name,
                  "is_exported_function": node.is_exported_function,
                  "build_date": node.build_date
                  }
    list_func = [_get_node_rpc_guid, _get_node_com_guid, _get_node_total_score, _get_is_documented_func,
                 _get_iunknown_objects]
    for func_attr in list_func:
        try:
            new_attr = func_attr(node, ranks_db_connection)
            attributes = update_attributes(attributes, new_attr)
        except sqlite3.OperationalError as e:  # missing table in DB
            logging.warning(f"getting attribute failed due to {e}")

    return attributes


def set_node_graph_attributes(graph, root_node, dest_node, is_extract_cfg_to):
    import networkx as nx
    if is_extract_cfg_to:
        shortest_path = nx.shortest_path_length(graph, dest_node, root_node)
    else:
        shortest_path = nx.shortest_path_length(graph, root_node, dest_node)
    _set_nodes_attributes(graph, dest_node, {"distance": shortest_path})


def post_processing_graph_attributes(graph, is_extract_cfg_to, root_node):
    #The goal of that function is to recalculate the distance from root, because when we built the graph it might look
    # different from now.
    for current_node in graph.nodes:
        set_node_graph_attributes(graph, root_node, current_node, is_extract_cfg_to)


def add_entry_point_attribute(attributes):
    attributes.update({"is_entry_point":True})
    return attributes

#  ################################################################ Node attributes


@key_wrapper("msdn")
def _get_is_documented_func(node, rank_db_connection):
    cursor = rank_db_connection.cursor()
    table_name = "feature_FunctionWebPage_MSDNScraper"
    shorten_func_name = node.get_shorten_func_name(is_add_template_indication=False)
    if "@" in shorten_func_name:  # required to convert it to mangled name from demangled
        logging.warning("doesn't support mangle names")
    # TODO: find a better way to match cpp functions, there are mangle, demangle, with arguments and without arguments, CHARINDEX can be an option.
    query = f"Select ranked_url, ranked_name, ranked_signature, ranked_code_examples from {table_name} where ranked_name == {shorten_func_name}"
    matched_functions = list(core.utils.sql_get_results(cursor, query))
    attributes = {"is_documented": False}
    if len(matched_functions) > 0:
        matched_docs = matched_functions[0]
        if len(matched_functions) > 1: 
            logging.warning(f"found more than a function {node} {matched_functions}")

        attributes.update({"is_documented": True, **matched_docs})
    return attributes


@key_wrapper("github")
def _get_is_have_code_example(node, rank_db_connection):
    cursor = rank_db_connection.cursor()
    table_name = "feature_SearchResult_GithubScraper"
    shorten_func_name = node.get_shorten_func_name(is_add_template_indication=False)
    if "@" in shorten_func_name:  # required to convert it to mangled name from demangled
        logging.warning("doesn't support mangle names")
    # TODO: find a better way to match cpp functions, there are mangle, demangle, with arguments and without arguments, CHARINDEX can be an option.
    query = f"Select ranked_html_url, ranked_path from {table_name} where ranked_name == {shorten_func_name}"
    matched_functions = list(core.utils.sql_get_results(cursor, query))
    attributes = {"code_example": False}
    if len(matched_functions) > 0:
        matched_docs = matched_functions[0]
        if len(matched_functions) > 1:
            logging.warning(f"found more than 1 example {node} {matched_functions}")

        attributes.update({"code_example": True, **matched_docs})
    return attributes


def _get_node_total_score(node, rank_db_connection):
    cursor = rank_db_connection.cursor()
    query = node.get_sql_query("all_features", ["score"])
    # query += " AND score > 0"
    matches = list(core.utils.sql_get_results(cursor, query, False))
    scores = [i[0] for i in matches]
    total_sum = sum(scores)
    amount_of_scores = len(scores)
    return {"total_score": total_sum, "amount_of_scores": amount_of_scores}


@key_wrapper("rpc")
def _get_node_rpc_guid(node, ranks_db_connection):
    cursor = ranks_db_connection.cursor()
    query = node.get_sql_query("feature_Function_CfgExtractorRpcObject", ["is_entry_point", "ServerInterface_GUID"])
    matches = list(core.utils.sql_get_results(cursor, query))
    if len(matches) == 0:
        return {}
    if len(matches) > 1:
        logging.warning(f"amount of RPC matches of the function {node} is more than 1, taking only the first")

    found = matches[0]
    return found


@key_wrapper("comObjects")
def _get_node_com_guid(node, ranks_db_connection):
    cursor = ranks_db_connection.cursor()
    query = node.get_sql_query("feature_Function_CfgExtractorComObject", ["is_entry_point", "guid"])
    matches = list(core.utils.sql_get_results(cursor, query))
    if len(matches) == 0:
        return {}
    if len(matches) > 1:
        logging.warning(f"amount of node_com_guid matches of the function {node} is more than 1, taking only the first")

    found = matches[0]
    #     found_with_exported = add_entry_point_attribute(found) # existed in the DB itself.
    return found


@key_wrapper("comFunctions")
def _get_node_com_guid(node, ranks_db_connection):
    cursor = ranks_db_connection.cursor()
    query = node.get_sql_query("feature_Function_CfgExtractorComFunctions", ["CLSID", "class_name",
                                                                             "amount_of_class_matched",
                                                                             "amount_of_functions_matched_in_class",
                                                                             "amount_of_functions_in_class"])
    matches = list(core.utils.sql_get_results(cursor, query))
    if len(matches) == 0:
        return {}
    if len(matches) > 1:
        logging.warning(f"amount of RPC matches of the function {node} is more than 1, taking only the first")

    found = matches[0]
    found_with_exported = add_entry_point_attribute(found)
    return found_with_exported


@key_wrapper("IUnknown")
def _get_iunknown_objects(node, ranks_db_connection):
    cursor = ranks_db_connection.cursor()
    query = node.get_sql_query("feature_Function_CfgExtractorIUnknown", ["class_name"])
    matches = list(core.utils.sql_get_results(cursor, query))
    if len(matches) == 0:
        return {}
    if len(matches) > 1:
        logging.warning(f"amount of feature_Function_CfgExtractorIUnknown matches of the function {node}"
                        f" is more than 1, taking only the first")

    found = matches[0]
    found_with_exported = add_entry_point_attribute(found)
    return found_with_exported


#  ################################################################ Edge attributes


@validate_params
def get_edge_attributes(src, dest, raw_node, ranks_db_connection):
    attributes = {"connection_type": raw_node['feature_type']}
    args = raw_node.get('args', "")
    if args is not None and dest.function_name in args:
        attributes.update({"is_unsafe": True})
    return attributes

#  ################################################################ Post processing attributes


# attributes related to graph itself.
def append_graph_attributes(graph):
    pass  # TODO:


def _set_nodes_attributes(graph, node, attributes):
    for attr_key, attr_val in attributes.items():
        graph.nodes[node][attr_key] = attr_val