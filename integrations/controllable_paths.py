import idaapi
import idautils
import idc

importSet = set()


def getImports(ea, name, ord):
    importSet.add((name, ea))
    return True


def getImports_w():
    nimps = idaapi.get_import_module_qty()

    for i in range(0, nimps):
        name = idaapi.get_import_module_name(i)
        if not name:
            continue
        idaapi.enum_import_names(i, getImports)
    return importSet


def addToDict(susImpList, importDict, keyName):
    stopCommand = False
    writable = ""

    if keyName == "patchedList2":
        # print "here"
        for patchedFuncName in susImpList:
            result, addr = isPatchFuncNameFound(patchedFuncName)
            if result:
                for xref in idautils.XrefsTo(addr):
                    if keyName in importDict:
                        if patchedFuncName in importDict[keyName]:
                            importDict[keyName][patchedFuncName].add((xref.frm, writable))
                        else:
                            importDict[keyName][patchedFuncName] = set()
                            importDict[keyName][patchedFuncName].add((xref.frm, writable))
                    else:
                        importDict[keyName] = {}
                        importDict[keyName][patchedFuncName] = set()
                        importDict[keyName][patchedFuncName].add((xref.frm, writable))
        return importDict

    for importNamTuple in importSet:
        importName = importNamTuple[0]
        importNameEa = importNamTuple[1]
        for susImp in susImpList:
            if susImp.lower() in importName.lower():
                for xref in idautils.XrefsTo(importNameEa):
                    stopCommand = False
                    writable = ""
                    if "createfilew" in importName.lower() or "createfilea" in importName.lower():
                        i = 1
                        while i < 50 and not stopCommand:  # search for writable access rights
                            command = idc.GetDisasm(xref.frm - i)
                            if "dwDesiredAccess" in command and not "80000000" in command and not stopCommand:
                                stopCommand = True
                                if "40000000" in command:
                                    # print "%x, write param: %s" %(xref.frm-i,command)
                                    writable = "write"

                                elif '0C0000000' in command:
                                    # print "%x, read_write param: %s" %(xref.frm-i,command)
                                    writable = "read_write"
                                else:
                                    # print "%x, might be writable: %s" %(xref.frm-i,command)
                                    writable = "might_be_writable"
                            i += 1
                    if ("createfilew" in importName.lower() or "createfilea" in importName.lower()) and not stopCommand:
                        continue

                    if keyName in importDict:
                        if importName in importDict[keyName]:
                            importDict[keyName][importName].add((xref.frm, writable))
                        else:
                            importDict[keyName][importName] = set()
                            importDict[keyName][importName].add((xref.frm, writable))
                    else:
                        importDict[keyName] = {}
                        importDict[keyName][importName] = set()
                        importDict[keyName][importName].add((xref.frm, writable))
                    # print "\t[+]%x" %xref.frm
    return importDict


def isPatchFuncNameFound(patchedFuncName):
    result = (False, None)
    for fva in idautils.Functions():
        funcName = idc.get_func_name(fva).lower()
        if funcName is None:
            continue
        if patchedFuncName.lower() in funcName.lower():
            # print funcName
            result = (True, fva)
            break
    return result


def _main():
    # a) file operation
    # 1. createFile,1st arg fileName,2nd access - GENERIC_WRITE=0x40000000,
    # 2. deleteFile
    # 3. copyFile
    # 4. SetFileSecurity - 1st - fileName , 3th - maybe need everyone value
    # b) filePath controled by limited user - temp or other.
    # c) no patch
    # d) no impersonation

    importSet = getImports_w()
    susImpList = ['SetFileSecurity', 'CreateFileA', 'CreateFileW', 'DeleteFileA', 'DeleteFileW', 'CopyFileA',
                  'CopyFileW']
    shouldBeBeforeList = ['revertToSelf', 'GetSecurityDescriptorDacl', 'SetSecurityDescriptorDacl', 'GetFileSecurityW',
                          'GetFileSecurityA']
    shouldNotBeBeforeList = ['ImpersonateLoggedOnUser', 'GetKernelObjectSecurity', 'ImpersonateSelf']
    controlledPathList = ['GetTempPathW', 'GetTempPathA', 'GetTempFileNameW', 'GetTempFileNameA', 'SHGetFolderPathA',
                          'SHGetFolderPathW', 'SHGetSpecialFolderPathA', 'SHGetSpecialFolderPathW',
                          'SHGetKnownFolderPath']
    patchedList = ['GetFinalPathNameByHandleW',
                   'GetFinalPathNameByHandleA']  # ['isFileNotASymLink', 'DetectedSymlinkOnRemoteDatabaseFile','isPortALink','IsPathALink']
    patchedList2 = ['isFileNotASymLink', 'DetectedSymlinkOnRemoteDatabaseFile', 'isPortALink', 'IsPathALink']
    importDict = {}
    importDict = addToDict(susImpList, importDict, "1susAction")
    importDict = addToDict(shouldBeBeforeList, importDict, "shouldBeBeforeList")
    importDict = addToDict(shouldNotBeBeforeList, importDict, "shouldNotBeBeforeList")
    importDict = addToDict(controlledPathList, importDict, "controlledPathList")
    importDict = addToDict(patchedList, importDict, "patchedList")
    importDict = addToDict(patchedList2, importDict, "patchedList2")
    # return
    finalDict = {}  # final dict
    maxDistance = None
    nearDistance = None
    # go over importDict and calc distance of the above functionLis
    for keyName, impDict in importDict.items():
        for importName, xrefSet in impDict.items():
            # print "%s,%s,%s" % (keyName,importName,xref)
            if keyName == "1susAction":
                for xrefTuple in xrefSet:
                    xref = xrefTuple[0]
                    writable = xrefTuple[1]
                    if xref in finalDict:
                        finalDict[xref]["1susAction"] = (importName, str(hex(xref)) , writable)
                    else:
                        finalDict[xref] = {"vulnerable0": False, "1susAction": None, "shouldBeBeforeList": None,
                                           "shouldNotBeBeforeList": None, "controlledPathList": None,
                                           "patchedList": None, "patchedList2": None}
                        finalDict[xref]["1susAction"] = (importName, str(hex(xref)) , writable)
                    for keyName2, impDict2 in importDict.items():
                        for importName2, xref2Set in impDict2.items():
                            if keyName2 == "1susAction":
                                continue
                            if keyName2 == "controlledPathList" or "patchedList" in keyName2:
                                maxDistance = 0x5000000
                                nearDistance = 0x1000
                            else:
                                maxDistance = 0x2000
                                nearDistance = 0x1000
                            for xref2Tuple in xref2Set:
                                xref2 = xref2Tuple[0]
                                distance = xref - xref2
                                if keyName2 == "controlledPathList" or "patchedList" in keyName2 and distance < 0:
                                    distance = 0 - distance  # make it positive
                                if distance > 0:
                                    if distance < maxDistance:
                                        if distance < nearDistance:
                                            if not "NEAR__" in importName2:
                                                importName2 = "NEAR__" + importName2
                                        else:
                                            importName2 = importName2.replace("NEAR__", "")

                                        # print "[-]found %s at %x and %s at %x - diss is %s" % (importName,xref,importName2,xref2,distance)
                                        if xref in finalDict:
                                            if finalDict[xref][keyName2] is None:
                                                finalDict[xref][keyName2] = set()

                                            finalDict[xref][keyName2].add((importName2, hex(xref2)))
                                        else:
                                            finalDict[xref][keyName2] = set()
                                            finalDict[xref][keyName2].add((importName2, hex(xref2)))

    # go over final dict and add vulnerable decision and print dict
    for xref, vulDict in finalDict.items():
        if vulDict is None:
            continue
        if vulDict["shouldBeBeforeList"] is None and vulDict["controlledPathList"] is None:
            continue
        if vulDict["shouldNotBeBeforeList"] is None and vulDict["patchedList"] is None and \
                not vulDict["controlledPathList"] is None:  # and not vulDict["shouldBeBeforeList"] is None
            vulDict["vulnerable0"] = True
        yield sorted(vulDict.items())


def main():
    results = _main()
    for raw_result in results:
        result = dict(raw_result)
        raw_controlled_path_list = result.pop('controlledPathList', set())
        if raw_controlled_path_list is None:
            raw_controlled_path_list = set()

        controlled_path_list = list(raw_controlled_path_list)
        sus_action = list(result.pop('1susAction', set()))
        if len(sus_action) > 1:
            result.update({"susAction_func_name": sus_action[0], "susAction_address": sus_action[1]})

        if len(sus_action) == 3:
            result.update({"susAction_result": sus_action[2]})

        else:
            raise NotImplementedError()

        function_names = {}
        prefix = "controllable_func_"
        for func_name, addr in controlled_path_list:
            function_names.setdefault(prefix + func_name, [])
            function_names[prefix + func_name].append(addr)

        result.update(function_names)
        yield result


if __name__ == "__main__":
    results = list(main())
    print(results)
