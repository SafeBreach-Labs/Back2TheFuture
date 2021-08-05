import collections
import inspect
import logging

import pythoncom
import pywintypes
import win32com.client.makepy
import win32com.client.gencache

path = r"E:\windows10\Windows\System32\inetcomm.dll"

BLACK_LIST = ['CLSID', '_ApplyTypes_', '__class__', '__delattr__', '__dict__', '__dir__',
              '__doc__', '__eq__', '__format__', '__ge__', '__getattr__', '__getattribute__', '__gt__',
              '__hash__', '__init__', '__init_subclass__', '__iter__', '__le__', '__lt__', '__module__',
              '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__del__',
              '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_get_good_object_',
              '_get_good_single_object_', '_prop_map_get_', '_prop_map_put_', 'coclass_clsid']

# https://github.com/SublimeText/Pywin32/blob/master/lib/x32/win32com/client/combrowse.py
# EXPORT_TYPE = {pythoncom.INVOKE_FUNC: "Function",
#                pythoncom.INVOKE_PROPERTYGET: "Property Get",
#                pythoncom.INVOKE_PROPERTYPUT: "Property Put",
#                pythoncom.INVOKE_PROPERTYPUTREF: "Property Put by reference",
#                }
#
type_flags = {pythoncom.VT_VECTOR: "Vector",
              pythoncom.VT_ARRAY: "Array",
              pythoncom.VT_BYREF: "ByRef",
              pythoncom.VT_RESERVED: "Reserved"
              }

vartypes = {pythoncom.VT_EMPTY: "Empty",
            pythoncom.VT_NULL: "NULL",
            pythoncom.VT_I2: "Integer 2",
            pythoncom.VT_I4: "Integer 4",
            pythoncom.VT_R4: "Real 4",
            pythoncom.VT_R8: "Real 8",
            pythoncom.VT_CY: "CY",
            pythoncom.VT_DATE: "Date",
            pythoncom.VT_BSTR: "String",
            pythoncom.VT_DISPATCH: "IDispatch",
            pythoncom.VT_ERROR: "Error",
            pythoncom.VT_BOOL: "BOOL",
            pythoncom.VT_VARIANT: "Variant",
            pythoncom.VT_UNKNOWN: "IUnknown",
            pythoncom.VT_DECIMAL: "Decimal",
            pythoncom.VT_I1: "Integer 1",
            pythoncom.VT_UI1: "Unsigned integer 1",
            pythoncom.VT_UI2: "Unsigned integer 2",
            pythoncom.VT_UI4: "Unsigned integer 4",
            pythoncom.VT_I8: "Integer 8",
            pythoncom.VT_UI8: "Unsigned integer 8",
            pythoncom.VT_INT: "Integer",
            pythoncom.VT_UINT: "Unsigned integer",
            pythoncom.VT_VOID: "Void",
            pythoncom.VT_HRESULT: "HRESULT",
            pythoncom.VT_PTR: "Pointer",
            pythoncom.VT_SAFEARRAY: "SafeArray",
            pythoncom.VT_CARRAY: "C Array",
            pythoncom.VT_USERDEFINED: "User Defined",
            pythoncom.VT_LPSTR: "Pointer to string",
            pythoncom.VT_LPWSTR: "Pointer to Wide String",
            pythoncom.VT_FILETIME: "File time",
            pythoncom.VT_BLOB: "Blob",
            pythoncom.VT_STREAM: "IStream",
            pythoncom.VT_STORAGE: "IStorage",
            pythoncom.VT_STORED_OBJECT: "Stored object",
            pythoncom.VT_STREAMED_OBJECT: "Streamed object",
            pythoncom.VT_BLOB_OBJECT: "Blob object",
            pythoncom.VT_CF: "CF",
            pythoncom.VT_CLSID: "CLSID",
            }


def extract_type(type_value):
    raw_param_type = type_value & 0xfff
    parameter_type = vartypes.get(raw_param_type, None)

    raw_parameter_flags = type_value & 0xffff000
    parameter_flags = type_flags.get(raw_parameter_flags, None)
    return [parameter_flags, parameter_type]


# def parse_attribute(attribute):
#     function_name = attribute[0][0]
#     argument_names = attribute[0][1:]
#     complex_properties = attribute[2]
#
#     arguments = parse_arguments(argument_names, complex_properties[2])
#     type_of_exported = EXPORT_TYPE[complex_properties[4]]
#     result = {"ordinal": attribute[1], "function_name": function_name, "offset": complex_properties[7],
#               "type_of_exported": type_of_exported,
#               }
#     result.update(arguments)
#     return result
#
#
# def extract_all_methods(obj):
#     exposed_classes = obj.VTablesToClassMap # OR we want to use CLSIDToClassMap
#     for guid, obj_name in exposed_classes.items():
#         virtual_table_name = f"{obj_name}_vtables_"
#         if not hasattr(obj, virtual_table_name):
#             print(f"failed to find attribute {virtual_table_name}")
#             continue
#
#         virtual_table = getattr(obj, virtual_table_name)
#         for attribute in virtual_table:
#             parsed_attribute = parse_attribute(attribute)

def extract_functions_from_class(class_type):
    members = inspect.getmembers(class_type)
    for member_name, member_value in members:

        if member_name in BLACK_LIST:
            continue
        if not isinstance(member_value, collections.Callable):  # not a function ## replace with? inspect.isfunction
            continue
        func_name = member_value.__name__
        if func_name.startswith("__"):  # internal function.
            continue
        signature = inspect.signature(member_value)
        arguments = list(signature.parameters.keys())
        try:
            arg_count = member_value.__code__.co_argcount
        except AttributeError:
            arg_count = None
        yield {"function_name": func_name, "amount_of_arguments": arg_count, "argument_names": arguments}


def extract_all_getters(class_type):
    if not hasattr(class_type, "_prop_map_get_"):
        return []

    for attribute_name, values in class_type._prop_map_get_.items():
        param_type = extract_type(values[2][0])
        yield {"ordinal": values[0], "param_type": param_type, "param_name": attribute_name}


def extract_all_setters(class_type):
    if not hasattr(class_type, "_prop_map_put_"):
        return []

    for attribute_name, values in class_type._prop_map_put_.items():
        # TODO: convert to - extract_type, I'm not sure enugh it is the param type.
        yield {"ordinal": values[0][0], "param_type": values[0][2], "param_name": attribute_name}


def extract_inherited_coclass_sources(class_type):
    if not hasattr(class_type, "coclass_sources"):
        return []
    return []  # TODO:


def extract_inherited_coclass_interfaces(class_type):
    if not hasattr(class_type, "coclass_interfaces"):
        return []
    for coclass_interface in class_type.coclass_interfaces:
        yield from extract_all_methods(coclass_interface)


def extract_all_methods(class_type):
    key_of_operator = "type_of_export"
    clsid = str(class_type.CLSID).replace("{", "").replace("}", "").lower()
    class_info = {"CLSID": clsid, "class_name": class_type.__name__}

    if hasattr(class_type, "co_class_clsid"):
        co_clsid = str(class_type.coclass_clsid).replace("{", "").replace("}", "").lower()
        class_info.update({"co_class_clsid": co_clsid})

    operators_to_extract = [(extract_all_setters, {key_of_operator: "setter"}),
                            (extract_all_getters, {key_of_operator: "getter"}),
                            (extract_functions_from_class, {key_of_operator: "function"}),
                            (extract_inherited_coclass_interfaces, {}), (extract_inherited_coclass_sources, {})]
    for function_ptr, additional_arguments in operators_to_extract:
        attributes = function_ptr(class_type)
        for attribute in attributes:
            attribute.update(additional_arguments)
            attribute.update(class_info)
            yield attribute


def extract_com_info(path):
    infos = win32com.client.makepy.GetTypeLibsForSpec(path)
    for (tlb, tlbSpec) in infos:
        try:
            gencache = win32com.client.gencache.EnsureModule(tlbSpec.clsid, tlbSpec.lcid, tlbSpec.major, tlbSpec.minor)
            for guid, class_type in gencache.CLSIDToClassMap.items():
                guid = guid.replace("{", "").replace("}", "").lower()
                yield {guid: extract_all_methods(class_type)}
        except pywintypes.com_error as e:
            logging.warning(f"failed to load library {e} {type(e)} {e.args} {path}")
