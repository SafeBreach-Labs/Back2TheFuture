import sark
import idc
import idautils

MAX_VALID_ADDRESS = 0xf11111111


def search_for_sequence(address_start, binary_sequences, max_address, max_offsets):
    if len(max_offsets) != len(binary_sequences):
        raise ValueError("expected the sequences to have the same len as max_offsets")

    ea1 = idc.find_binary(address_start, idc.SEARCH_NEXT | idc.SEARCH_DOWN, binary_sequences)
    if 0 < ea1 < max_address and ea1 - address_start < max_offsets[0]:
        if len(binary_sequences) == 1:  # stop condition
            return ea1

        result = search_for_sequence(ea1, binary_sequences[1:], max_address, max_offsets[1:])
        if result is not None:
            return ea1

    return None


def offsets(vul_func_address, result_dict):
    vul_func_addr_hex = hex(vul_func_address)
    load_found = False
    load_xml_found = False
    put_async = False
    resolve_externals = False
    ea1 = search_for_sequence(vul_func_address, ["208", "15FF"], MAX_VALID_ADDRESS, [0x1000, 0x10])
    if ea1 is not None:
        load_xml_found = True
        result_dict[vul_func_addr_hex]["loadxml"] = hex(ea1)

    ea1 = search_for_sequence(vul_func_address, ["1d0", "15FF"], MAX_VALID_ADDRESS, [0x2000, 0x10])
    if ea1 is not None:
        load_found = True
        result_dict[vul_func_addr_hex]["load"] = hex(ea1)

    ea1 = search_for_sequence(vul_func_address, ["1f8", "15FF"], MAX_VALID_ADDRESS, [0x1000, 0x10])
    if ea1 is not None:
        put_async = True
        result_dict[vul_func_addr_hex]["put_async"] = hex(ea1)

    ea1 = search_for_sequence(vul_func_address, ["230", "15FF"], MAX_VALID_ADDRESS, [0x1000, 0x10])
    if ea1 is not None:
        resolve_externals = True
        result_dict[vul_func_addr_hex]["resolve_Externals"] = hex(ea1)

    if not resolve_externals and (load_xml_found or (load_found and put_async)):
        result_dict[vul_func_addr_hex]["vulnerable"] = True
    return result_dict


def patched(str1, str2, str3, str4, found_str, patched_func_addr_list):
    found = False
    ea1 = idc.find_binary(0x0, idc.SEARCH_NEXT | idc.SEARCH_DOWN, str1)
    ea2 = idc.find_binary(ea1 - 0x2, idc.SEARCH_NEXT | idc.SEARCH_DOWN, str2)
    ea3 = idc.find_binary(ea2 - 0x10, idc.SEARCH_NEXT | idc.SEARCH_DOWN, str3)
    ea4 = 1
    if not str4 == "0":
        ea4 = idc.find_binary(ea3 - 0x50, idc.SEARCH_NEXT | idc.SEARCH_DOWN, str4)

    if 0 < ea1 < MAX_VALID_ADDRESS and \
            0 < ea2 < MAX_VALID_ADDRESS and \
            0 < ea3 < MAX_VALID_ADDRESS and \
            ea3 - ea2 < 10:
        if ea4 > 0 and ea4 - ea3 < 100:
            for xref in idautils.XrefsTo(ea2 - len(str1) // 2, 0):
                patched_func_addr_list.add(xref.frm)
            found = True
    return found, patched_func_addr_list


def find_vul_guid(guid, str1, str2, vul_func_addr_list):
    found = False
    start_addr = 0x0
    ea1 = 1
    ea2 = 1
    while True:
        # print ("start_addr: %s" %hex(ea1)
        ea1 = idc.find_binary(start_addr, idc.SEARCH_NEXT | idc.SEARCH_DOWN | idc.SEARCH_CASE, str1)
        ea2 = idc.find_binary(start_addr, idc.SEARCH_NEXT | idc.SEARCH_DOWN | idc.SEARCH_CASE, str2)
        if ea1 > 0 and ea2 > 0 and ea2 - ea1 < 10 and ea1 < MAX_VALID_ADDRESS:
            for xref in idautils.XrefsTo(ea1, 0):
                vul_func_addr_list.add(xref.frm)
            found = True
            start_addr = ea2 + 0x2
        else:
            break
    return found, vul_func_addr_list


def main():
    result_dict = {}  # {"VulClsidAddr":{"patched":-1/address, "load":, "loadxml":,"put_async","resolve_Externals","vulnerable":bool}}
    vul_func_addr_list = set()
    # found_inter1  = findVulGuid("guid_interfae1","2933bf81","0c0000eb211d27b36")
    # found_inter2,vul_func_addr_list  = findVulGuid("guid_interfae2","2933bf95","0c0000eb211d27b36")
    found_clsid1, vul_func_addr_list = find_vul_guid("guid_clsid1", "0f6d90f11", "0b311d39c73", vul_func_addr_list)
    found_clsid2, vul_func_addr_list = find_vul_guid("guid_clsid2", "0f6d90f12", "0b311d39c73", vul_func_addr_list)
    found_clsid3, vul_func_addr_list = find_vul_guid("guid_clsid3", "2933bf90", "0c0000eb211d27b36", vul_func_addr_list)
    found_clsid4, vul_func_addr_list = find_vul_guid("guid_clsid4", "f5078f32", "d351c5", vul_func_addr_list)
    found_clsid5, vul_func_addr_list = find_vul_guid("guid_clsid5", "2933bf91", "0c0000eb211d27b36", vul_func_addr_list)
    found_clsid6, vul_func_addr_list = find_vul_guid("guid_clsid6", "f5078f33", "d351c5", vul_func_addr_list)

    patched_func_addr_list = set()
    is_patched1, patched_func_addr_list = patched("0068006f00720050", "0074006900620069", "4400540044", "0",
                                                  "ProhibitDTD",
                                                  patched_func_addr_list)
    is_patched2, patched_func_addr_list = patched("006f006c006c0041", "0063006f00440077", "006e0065006d0075",
                                                  "006f006900740063", "AllowDocumentFunction", patched_func_addr_list)
    is_patched3, patched_func_addr_list = patched("006f006c006c0041", "006c007300580077", "0072006300530074",
                                                  "007400700069", "AllowXsltScript", patched_func_addr_list)

    for vul_func_addr in vul_func_addr_list:

        vul_func_addr_hex = hex(vul_func_addr)
        is_patched = False
        function_addr_start = idc.BADADDR
        try:
            function_addr_start = sark.function.Function(int(vul_func_addr_hex, 16)).start_ea
        except Exception:
            pass  # it is not a function
        if vul_func_addr_hex in result_dict:
            result_dict[vul_func_addr_hex] = {"patched": -1, "load": -1, "loadxml": -1, "put_async": -1,
                                              "resolve_Externals": -1, "vulnerable": False,
                                              "function_address": function_addr_start}
        else:
            result_dict[vul_func_addr_hex] = {}
            result_dict[vul_func_addr_hex] = {"patched": -1, "load": -1, "loadxml": -1, "put_async": -1,
                                              "resolve_Externals": -1, "vulnerable": False,
                                              "function_address": function_addr_start}
        for patched_func_addr in patched_func_addr_list:
            if (int(vul_func_addr) > int(patched_func_addr) and int(vul_func_addr) - int(patched_func_addr) < 0x80) or (
                    int(vul_func_addr) < int(patched_func_addr) and int(patched_func_addr) - int(vul_func_addr) < 0x80):
                # print ("the vulnerable address at %s was probably patched at address: %s" %(hex(vul_func_addr),hex(patched_func_addr))
                is_patched = True
                result_dict[vul_func_addr_hex]["patched"] = hex(patched_func_addr)
                break
        if not is_patched:
            #  possible vulnerable address vul_func_addr
            result_dict = offsets(vul_func_addr, result_dict)

    return result_dict
