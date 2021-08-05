import queue
import string
import time
import pprint
import sys
import cachetools
import networkx as nx
import argparse
import datetime
import os
import logging
import sqlite3
import matplotlib.pyplot as plt

import cfg_extractor.extract_attributes
from cfg_extractor.extract_attributes import _set_nodes_attributes
from cfg_extractor.function import pe_remove_suffix, Function
from core.utils import sql_get_results, convert_to_bool

WINDOWS_APISETS_PREFIXES = ['api-', 'ext-']
IGNORE_FUNCTION_NAMES = ["_guard_check_icall_nop", "__security_check_cookie"]

CFG_TABLE_NAME = "feature_Function_CfgExtractorXref"
# another mapping existing in but it missing some apis.
# https://www.geoffchappell.com/studies/windows/win32/apisetschema/history/sets63.htm?tx=52
PATH_CONFIG_APISETS_MAPPINGS = r".\config\windows_apisets_mapping"
IS_GENERIC_FS = False
OUTPUT_DIR = ".\logs\graph_output"
if __name__ == "__main__":
    LOGGER = None
else:
    LOGGER = logging.getLogger(__name__)


class UniqueQueue(queue.Queue):
    def _init(self, maxsize):
        self.queue = []

    def _put(self, item):
        if item not in self.queue:
            self.queue.append(item)

    def _get(self):
        return self.queue.pop(0)

    def put_multiple(self, items):
        for item in items:
            self.put(item)


def cast_addr(str_addr, base=10):
    if str_addr is not None:
        try:
            return int(str_addr, base)
        except ValueError:
            logging.warning(f"cast address has failed - address is in float format, {str_addr}, base {base}")
            if base != 0:
                raise
            return int(float(str_addr))
        except TypeError:
            if type(str_addr) == int:
                return str_addr
            else:
                logging.warning(f"cast address has failed - address is not string, {str_addr}, base {base}")
    return None


@cachetools.cached({})
def get_config_apisets_mapping(file_path):
    full_mapping = {}
    with open(file_path, "r") as f:
        output = f.read()
    for line in output.splitlines():
        parts = line.split(" -> ")
        if len(parts) != 2:
            logging.warning(f"failed to find 2 parts for line {parts}")
            continue

        import_name, pes = parts
        if "," in pes or not pes.startswith("[ ") or not pes.endswith(" ]"):
            logging.warning(f"Doesn't support multiple mappings {pes}")
            continue

        trimmed_pe = pes[2:-2]
        full_mapping.update({import_name: trimmed_pe})

    return full_mapping


def remove_apiset_prefix(full_apiset_name):
    for prefix in WINDOWS_APISETS_PREFIXES:
        if full_apiset_name.startswith(prefix):
            return full_apiset_name[len(prefix):]

    return full_apiset_name


def get_real_imported_function_name(imported_module):
    removed_prefix = remove_apiset_prefix(imported_module)
    if removed_prefix == imported_module:  # it is not apiset
        return imported_module

    mapping = get_config_apisets_mapping(PATH_CONFIG_APISETS_MAPPINGS)
    if removed_prefix in mapping:
        return mapping[removed_prefix]

    logging.error(f"could not find the correct mapping for {imported_module}")
    raise ValueError(f"could not find the correct mapping for {imported_module}")


def get_apisets_from_module_name(pe_name, is_add_prefix=True):
    """
    :param pe_name:dll name with file suffix.
    :param is_add_prefix: api sets have prefixes described in WINDOWS_APISETS_PREFIXES, is include the prefixes in the
                          return value -> it will create more aliases (and some of them might not exist)
    :return: list of all the aliases matching that with all the optional prefixes WINDOWS_APISETS_PREFIXES
    """
    removed_prefix = remove_apiset_prefix(pe_name)
    if removed_prefix != pe_name:  # it is apiset
        return pe_name

    apisets = []
    mapping = get_config_apisets_mapping(PATH_CONFIG_APISETS_MAPPINGS)
    for apiset, mapped_pe_name in mapping.items():
        if mapped_pe_name.lower() == pe_name.lower():
            if is_add_prefix:
                for prefix in WINDOWS_APISETS_PREFIXES:
                    apisets.append(prefix + apiset)
            else:
                apisets.append(apiset)

    return apisets


def raw_node_xref_from(raw_node, original_node, ranks_db_connection):
    if raw_node['imported_module'] is None:  # internal function
        # Currently we don't know if this function is exported or not.
        addr = cast_addr(raw_node['address_after'])
        # some rows are empty for some reason.
        function_name = raw_node['reason']
        if (function_name is None and addr is None) or len(function_name) == 0:
            return None, None, None

        node = Function(function_name, raw_node['ranked_pe_name'], raw_node['ranked_build_date'],
                        addr, raw_node['ranked_package_name'])
    else:
        imported_module = get_real_imported_function_name(raw_node['imported_module'])
        node = Function(raw_node['imported_function_name'], imported_module, None, None, None, True)

    node_attr = cfg_extractor.extract_attributes.get_node_attributes(node, ranks_db_connection)
    edge_attributes = cfg_extractor.extract_attributes.get_edge_attributes(original_node, node, raw_node,
                                                                           ranks_db_connection)
    return node, node_attr, edge_attributes


def _execute_newest_xrefs(db_connection, sql):
    last_date = {}
    cursor = db_connection.cursor()
    results = sql_get_results(cursor, sql)

    for result in results:
        unique_pe_identifier = result['ranked_package_name'] + result['ranked_pe_name']
        if unique_pe_identifier not in last_date:
            last_date[unique_pe_identifier] = result['ranked_build_date']
        elif result['ranked_build_date'] is not None and last_date[unique_pe_identifier] > result['ranked_build_date']:
            continue  # reached an older version of PE we already found.

        yield result

    cursor.close()


def find_xrefs_from(function, db_connection, max_date=None, unsafe_xrefs=False):
    sql = f"select * from {CFG_TABLE_NAME} where"
    if function.addr is not None:
        sql += f" ranked_address == {function.addr}"
    else:
        sql += f" ranked_function_name == '{function.function_name}'"

    sql += f" AND lower(ranked_pe_name) like '{function.get_pe_name(False, True)}%'"
    if function.package_name is not None:
        sql += f" AND ranked_package_name == '{function.package_name}'"

    if max_date is not None and IS_GENERIC_FS is False:
        sql += f" AND ranked_build_date >= '{max_date}'"

    # I don't use MAX in order to not get only 1 record.
    sql += " order by ranked_build_date desc"
    yield from _execute_newest_xrefs(db_connection, sql)


# TODO: add support with HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\KnownDLLs
# https://docs.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-search-order
def find_xrefs_to(function, db_connection, max_date=None, unsafe_xrefs=False):
    def generate_sql_query_xrefs_to(is_external):
        sql = f"select * from {CFG_TABLE_NAME} where"
        pe_name_without_extensions = function.get_pe_name(False, True)
        if is_external:
            sql += f" imported_function_name == '{function.function_name}' AND"
            apiset_imported_module_name = get_apisets_from_module_name(function.pe_name)
            if len(apiset_imported_module_name) > 0:
                sql += f" (LOWER(imported_module) == '{pe_name_without_extensions}'" \
                       f" OR LOWER(imported_module) IN {tuple(apiset_imported_module_name)} )"
            else:
                sql += f" LOWER(imported_module) == '{pe_name_without_extensions}'"

        else:  # internal
            if function.function_name is not None:
                sql += f" reason == '{function.function_name}'"
            elif function.addr is not None:
                sql += f" address_after == '{function.addr}'"
            else:
                raise ValueError("expected function to have address or function name")

            sql += f" AND LOWER(ranked_pe_name) like '{pe_name_without_extensions}%'"

            if function.package_name is not None:
                sql += f" AND ranked_package_name == '{function.package_name}'"

        if max_date is not None and IS_GENERIC_FS is False:
            sql += f" AND ranked_build_date >= '{max_date}'"
        sql += " order by ranked_build_date desc"
        return sql

    if function.is_exported_function is True or function.is_exported_function is None:  # get external xrefs
        sql = generate_sql_query_xrefs_to(function.is_exported_function)
        yield from _execute_newest_xrefs(db_connection, sql)

    sql = generate_sql_query_xrefs_to(False)  # get internal usage
    yield from _execute_newest_xrefs(db_connection, sql)
    if unsafe_xrefs is True:
        yield from find_xrefs_to_get_unsafe(function, db_connection, max_date)


def find_xrefs_to_get_unsafe(function, db_connection, max_date=None):
    if function.is_exported_function is True or function.is_exported_function is None:  # get external xrefs
        sql = f"select * from {CFG_TABLE_NAME} where"
        sql += f" args like '%{function.function_name}%' or poi_values like '%{function.function_name}%'"

        if max_date is not None and IS_GENERIC_FS is False:
            sql += f" AND ranked_build_date >= '{max_date}'"
        sql += " order by ranked_build_date desc"
        yield from _execute_newest_xrefs(db_connection, sql)


def raw_node_xref_to(raw_node, original_node, ranks_db_connection):
    is_exported_func = raw_node['ranked_is_exported_function']
    addr = cast_addr(raw_node['ranked_address'])
    if is_exported_func in ['True', 'False']:
        is_exported_func = convert_to_bool(is_exported_func)
    else:
        is_exported_func = None

    node = Function(raw_node['ranked_function_name'], raw_node['ranked_pe_name'], raw_node['ranked_build_date'],
                    addr, raw_node['ranked_package_name'], is_exported_func)
    node_attr = cfg_extractor.extract_attributes.get_node_attributes(node, ranks_db_connection)
    edge_attributes = cfg_extractor.extract_attributes.get_edge_attributes(node, original_node, raw_node,
                                                                           ranks_db_connection)
    return node, node_attr, edge_attributes


def is_equal_pes(pe_1, pe_2):
    pe1_core = pe_remove_suffix(pe_1).lower()
    pe2_core = pe_remove_suffix(pe_2).lower()
    if pe1_core == pe2_core:
        return True

    return False


def fill_up_function_data(raw_node, func):
    """

    :param raw_node: referenced to the rank itself (and not the referenced)
    :param func: function object to fill all the misssing info about.
    :return: node, node_attributes
    """

    func_pe_name = func.pe_name.lower()
    raw_node_pe_name = raw_node['ranked_pe_name'].lower()
    if (func.function_name != raw_node['ranked_function_name'] and str(func.addr) != raw_node['ranked_address']) \
            or not is_equal_pes(func_pe_name, raw_node_pe_name):
        raise ValueError(f"raw node doesn't match func, {raw_node}, {func}")

    is_updated = False
    if not func.function_name == raw_node['ranked_function_name']:
        func.function_name = raw_node['ranked_function_name']
        is_updated = True
    if not func.addr == cast_addr(raw_node['ranked_address']):
        func.addr = cast_addr(raw_node['ranked_address'])
        is_updated = True
    if not func.package_name == raw_node['ranked_package_name']:
        func.package_name = raw_node['ranked_package_name']
        is_updated = True

    if not func.build_date == raw_node['ranked_build_date']:
        func.build_date = raw_node['ranked_build_date']
        is_updated = True
    return is_updated


def is_continue_node(graph, node, max_nodes=None, is_extract_cfg_to=True, max_distance_from_root=None,
                     linked_node=None):
    if node.function_name in IGNORE_FUNCTION_NAMES:
        return "ignore list"

    if node in graph:
        return "node in graph"

    if max_distance_from_root is not None and linked_node is not None and \
            nx.get_node_attributes(graph, "distance")[linked_node] > max_distance_from_root:
        return "reached maximum distance from root"

    if max_nodes is not None and len(graph.nodes) > max_nodes:
        LOGGER.warning("reached maximum graph size due user limitations")
        return "Maximum graph size"

    return True


def extract_cfg(start_function, cfg_db_connection, func_stop_condition, is_extract_cfg_to,
                ranks_db_connection, unsafe_xrefs):
    extract_cfg_func = find_xrefs_from
    if is_extract_cfg_to:
        extract_cfg_func = find_xrefs_to

    cfg_graph = nx.DiGraph()
    raw_nodes = list(extract_cfg_func(start_function, cfg_db_connection, start_function.build_date, unsafe_xrefs))
    # TODO: update the data to hte real info (such as build date)
    if len(raw_nodes) < 1:
        raise ValueError(f"Expected to find at least 1 entry record, found {len(raw_nodes)} "f"entry point, "
                         f"if you are using a DB generic, please use --generic-fs argument "
                         f" additional options is - no one is calling that function.")
    else:
        print("found entry point")

    try:
        start_node = start_function
        start_node_attr = cfg_extractor.extract_attributes.get_node_attributes(start_node, ranks_db_connection)
        cfg_graph.add_node(start_node, **start_node_attr)
        cfg_extractor.extract_attributes.set_node_graph_attributes(cfg_graph, start_node, start_node, is_extract_cfg_to)
        nodes_to_cover = UniqueQueue()
        nodes_to_cover.put(start_node)
        while not nodes_to_cover.empty():
            current_node = nodes_to_cover.get()
            raw_nodes = list(extract_cfg_func(current_node, cfg_db_connection, start_function.build_date, unsafe_xrefs))
            if len(raw_nodes) > 0 and not is_extract_cfg_to:  # required only in cfg from.
                is_updated = fill_up_function_data(raw_nodes[0], current_node)
                if is_updated:
                    updated_node_attributes = cfg_extractor.extract_attributes.get_node_attributes(current_node,
                                                                                                   ranks_db_connection)
                    _set_nodes_attributes(cfg_graph, current_node, updated_node_attributes)

            new_nodes_to_cover = link_nodes_to_graph(cfg_graph, current_node, func_stop_condition, is_extract_cfg_to,
                                                     raw_nodes, ranks_db_connection, start_node)
            nodes_to_cover.put_multiple(new_nodes_to_cover)

    except KeyboardInterrupt:
        logging.info("keyboard interrupt was pressed, exiting in the middle")

    cfg_extractor.extract_attributes.post_processing_graph_attributes(cfg_graph, is_extract_cfg_to, start_node)
    return cfg_graph


def link_nodes_to_graph(cfg_graph, current_node, func_stop_condition, is_extract_cfg_to, raw_nodes,
                        ranks_db_connection, root_node):
    nodes_to_add = set()
    extract_raw_node_to_node = raw_node_xref_from
    if is_extract_cfg_to:
        extract_raw_node_to_node = raw_node_xref_to

    for raw_node in raw_nodes:
        node, node_attr, edges_attr = extract_raw_node_to_node(raw_node, current_node, ranks_db_connection)
        if node is None:
            LOGGER.debug(f"reason and addr was None {raw_node}, {current_node} - function has no xrefs")
            continue
        # calling func_stop_condition must happened before adding that node to the graph.
        reason_stop = func_stop_condition(cfg_graph, node, is_extract_cfg_to, current_node)
        if reason_stop is True:  # specific True,
            nodes_to_add.add(node)
        else:
            node_attr.update({"reason_stop": reason_stop})

        if node not in cfg_graph.nodes:  # in order to prevent data from being override specifically reason_stop
            cfg_graph.add_node(node, **node_attr)

        if is_extract_cfg_to:  # the direction of the arrow
            cfg_graph.add_edge(node, current_node, **edges_attr)
        else:
            cfg_graph.add_edge(current_node, node, **edges_attr)

        cfg_extractor.extract_attributes.set_node_graph_attributes(cfg_graph, root_node, node, is_extract_cfg_to)

    return nodes_to_add


def init_argparse():
    parser = argparse.ArgumentParser(description='Generate call graph')
    parser.add_argument('-f', '--entry-function-name', action='store', help='Entry function name')
    parser.add_argument('-a', '--entry-function-address', action='store', help='Entry function address')
    parser.add_argument('--pe', '--entry-pe-name', action='store', help='Entry pe name', required=True)
    parser.add_argument('--package', '--package-name', action='store', help='Name of package the PE found in')
    parser.add_argument('--path-api-set', action='store', required=True,
                        help='Path to the api-set mapping that will be used external dlls')
    parser.add_argument('--unsafe-xrefs', action='store_true',
                        help='include in the graph dynamic xrefs, such as GetProcAddress - '
                             'it might be ambiguous and linked to another PE',
                        default=False)
    parser.add_argument('-i', '--path-to-cfg-db', action='store', help='Path to CFG DB', required=True)
    parser.add_argument('--path-to-ranks-db', action='store', help='Path to ranks DB to extract scores', default=None)
    parser.add_argument('--max-nodes-in-graph', action='store', help='maximum size of graph', default=None)
    parser.add_argument('-m', '--max-distance-from-root', action='store', help='maximum distance (hops) from root',
                        default=None)
    parser.add_argument('-d', '--direction-cfg-from', action='store_true',
                        help='set the direction from address instead of to the function ', default=False)
    parser.add_argument('--date', '-e', action='store', help="The date of the PEs it will extract the CFG  YYYY-MM",
                        type=str, default="1900-01")  # take any file old or new.
    parser.add_argument('--generic-fs', action='store_true',
                        help="if the DB was generated by Generic FS", default=False)
    parser.add_argument('--no-print-graph', action='store_false',
                        help="if you want to see the graph in the default graph view (and not only export it)",
                        default=True)
    args = parser.parse_args()
    global IS_GENERIC_FS
    IS_GENERIC_FS = args.generic_fs
    if args.entry_function_name is None and args.entry_function_address is None:
        LOGGER.critical("you must insert function name or address")
        raise ValueError("missing arguments")

    if args.package is not None and not args.package.endswith(args.pe):
        args.package = f"{args.package}_{args.pe}"

    try:
        datetime.datetime.strptime(args.date, "%Y-%m")
    except Exception:
        LOGGER.critical("argument date have wrong format, exiting program")
        raise ValueError("argument error")

    if args.max_nodes_in_graph is not None:
        args.max_nodes_in_graph = int(args.max_nodes_in_graph)

    if args.max_distance_from_root is not None:
        args.max_distance_from_root = int(args.max_distance_from_root)

    if not os.path.exists(args.path_api_set):
        raise ValueError("Path to api-set is incorrect, could not find the file")
    else:
        global PATH_CONFIG_APISETS_MAPPINGS
        PATH_CONFIG_APISETS_MAPPINGS = args.path_api_set

    if args.path_to_ranks_db is None:
        args.path_to_ranks_db = args.path_to_cfg_db
    if args.entry_function_address is not None:
        if args.entry_function_address.startswith("0x"):
            args.entry_function_address = int(args.entry_function_address, 16)
        else:
            args.entry_function_address = int(args.entry_function_address, 10)

    if not os.path.exists(args.path_to_cfg_db):
        LOGGER.critical("DB location is not found!")
        raise ValueError("failed to find DB")

    return args


def string_to_valid_filename(name, max_size=80):
    new_str = ""
    valid_chars = "-_. %s%s" % (string.ascii_letters, string.digits)
    for i in name:
        if i in valid_chars:
            new_str += i

    if len(new_str) > max_size:
        new_str = new_str[:max_size - 3] + "..."

    return new_str


def extract_graph(graph, entry_function, is_print):
    LOGGER.info(f"graph properties: nodes:{len(graph.nodes)}, edges:{len(graph.edges())}")
    best_format = pprint.pformat(list(graph.nodes()))

    LOGGER.info(f"nodes names: {best_format}")
    valid_file_name = string_to_valid_filename(str(entry_function))
    output_dir = OUTPUT_DIR
    os.makedirs(output_dir, exist_ok=True)
    file_name = fr"{valid_file_name}_graph.graphml"
    file_path = os.path.join(output_dir, file_name)
    nx.write_graphml_lxml(graph, file_path)
    nx.draw(graph, with_labels=True)
    if is_print:
        plt.show()
    # nx.write_gml(graph, r".\logs\graph.gml")


def config_logger():
    root_dir = os.path.dirname(__file__)
    log_file = os.path.join("logs", 'extract_cg.log')
    full_log_file = os.path.join(root_dir, log_file)
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
    logging.getLogger('matplotlib').setLevel(logging.WARNING)


def find_all_entry_points_nodes(graph):
    def check_bool_attribute(attribute):
        if "None" == attribute:
            return False
        if attribute is True or attribute == "True":
            return True
        return False

    all_nodes = graph.nodes(data=True)
    for node, attributes in all_nodes:
        is_exported_function = attributes.get("is_exported_function", False)
        is_documented = attributes.get("is_documented", False)
        is_have_code_example = attributes.get("code_example", False)
        is_entry_point = attributes.get("is_entry_point", False)
        if check_bool_attribute(is_exported_function):
            yield node
        elif check_bool_attribute(is_documented):
            yield node
        elif check_bool_attribute(is_have_code_example):
            yield node
        elif check_bool_attribute(is_entry_point):
            yield node


def print_shortest_path(path, attributes, is_cfg_from):
    path_printable = [str(i) for i in path]
    arrow_direction = " -> "
    if is_cfg_from:
        path_printable = path_printable[::-1]
        arrow_direction = " <- "
    formatted_path = arrow_direction.join(path_printable)
    print(formatted_path)
    ignore_list = ["build_date", "function_name", "pe_name"]
    format_message = "    [+] {key} : {value}"
    for key, val in attributes.items():
        if key in ignore_list:
            continue

        print(format_message.format(key=key, value=val))
    print("")  # separate between each print.


def extract_shortest_entry_points(graph, is_cfg_from, root_function):
    all_entry_points = find_all_entry_points_nodes(graph)
    for leaf in all_entry_points:
        try:
            if is_cfg_from:
                shortest_path = nx.shortest_path(graph, root_function, leaf)
            else:
                shortest_path = nx.shortest_path(graph, leaf, root_function)
            attributes = graph.nodes(data=True)[leaf]
            print_shortest_path(shortest_path, attributes, is_cfg_from)
        except nx.NetworkXNoPath:
            print(f"could not find path with {leaf}")


def generate_stop_condition_func(args):
    def stop_condition(a, b, direction, current_node):
        return is_continue_node(a, b, args.max_nodes_in_graph, direction, args.max_distance_from_root, current_node)

    return stop_condition


def main():
    config_logger()
    LOGGER.info("began!")
    args = init_argparse()
    chosen_date = args.date
    cfg_db_connection = sqlite3.connect(args.path_to_cfg_db)
    ranks_db_connection = sqlite3.connect(args.path_to_cfg_db)
    entry_function = Function(args.entry_function_name, args.pe, chosen_date, args.entry_function_address, args.package,
                              is_exported_function=True)
    stop_condition = generate_stop_condition_func(args)

    start_orchestration = time.time()
    graph = extract_cfg(entry_function, cfg_db_connection, stop_condition, not args.direction_cfg_from,
                        ranks_db_connection, args.unsafe_xrefs)
    cfg_extractor.extract_attributes.append_graph_attributes(graph)
    extract_shortest_entry_points(graph, args.direction_cfg_from, entry_function)
    end_orchestration = time.time()
    extract_graph(graph, entry_function, not args.no_print_graph)
    diff_time = end_orchestration - start_orchestration
    delta_time = datetime.timedelta(seconds=diff_time)
    LOGGER.info(f"time diff seconds: {diff_time}, human readable {delta_time}")
    LOGGER.info("ended!")


if __name__ == "__main__":
    main()
