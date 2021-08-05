import os, sys
import shutil
import time
import subprocess
import argparse


# Original Author: Copyright (c) SafeBreach Labs (July 2021)
# Module Name:
# Create IDL projects
# Abstract:
# This module is used in step 3 - generating rpc interfaces projects in order to ease the ability to trigger a 1-day vulnerabilty.
# More details on SafeBreach Labs' back2TheFuture Repository on GitHub.
# Environment:
# python user-mode


# ====order idl structs begin
def hasCons(structDict, structName):
    if len(structDict[structName]['constraints']) == 0:
        return False, None
    return True, structDict[structName]['constraints']


def printStruct(structDict, structName, fw):
    # print structDict[structName]['typedef']
    fw.write(structDict[structName]['typedef'] + "\n")
    # print "{"
    fw.write("{" + "\n")
    sortedMemList = list(structDict[structName]['members'])
    sortedMemList.sort(key=lambda x: x[1])  # sort the struct member
    for memberTuple in sortedMemList:
        member = memberTuple[0]
        member = member.replace(']', '] ')  # add space instead of remove tab
        # print member
        fw.write(member + "\n")
    # print "}" + structName + ";"
    fw.write("}" + structName + ";" + "\n")


# recus_count = 0
def orderprint(structDict, structName, fw, recus_count, alreadyAdded):
    hasCon, consSet = hasCons(structDict, structName)
    if not hasCon:
        if structName in alreadyAdded:
            return alreadyAdded
        printStruct(structDict, structName, fw)
        alreadyAdded.add(structName)
        return alreadyAdded
    else:
        ##print the constraints structs
        ##print "[+]struct:%s" % structName
        hasCon, consSet = hasCons(structDict, structName)
        if hasCon:
            noActiveCons = True
            for consName in consSet:
                if consName not in alreadyAdded:
                    noActiveCons = False
                    ##print "%s is not in %s" %(consName,alreadyAdded)
                    break
                ##print "consName:%s" %consName

            # recuservily call with consName
            if noActiveCons and structName not in alreadyAdded:
                printStruct(structDict, structName, fw)
                alreadyAdded.add(structName)
            else:
                ##print "[+]calls consName:%s" % consName
                recus_count += 1
                # print recus_count
                if recus_count == 1:
                    # print "!!!!!recus_count==5"
                    return alreadyAdded
                alreadyAdded = orderprint(structDict, consName, fw, recus_count, alreadyAdded)
    return alreadyAdded


def buildDict(rpcViewFile):
    structDict = {}
    structDictList = []
    flagComment = False  # set to true when next line is still in comment
    flagFirstTypedefFound = False  # set to true when the first typedef is found
    typedef_line = None
    copyAll = False  # set to true when the strcuts part is over
    copyLines = ""  # all the functions after the structs part.
    headerPrinted = False
    structNum = 0
    uuid = None
    # build unordered structDict
    with open(rpcViewFile, 'r') as f:
        lines = f.readlines()

    for line in lines:
        line = line.strip().replace('\t', '')  # remove tabs
        if flagComment:
            commentEndIndex = line.find('*/')
            if commentEndIndex == -1:
                ##print line
                continue  # this line is a continue of a comment started in a previous line
            else:
                flagComment = False
                line = line[commentEndIndex + 2:]  # remove the comment. TBD deal with more than one comment in a line
                continue

        if line.startswith('/*'):  # comment line
            commentEndIndex = line.find('*/')
            if commentEndIndex == -1:
                flagComment = True
                continue  # the line is just a comment
            else:
                line = line[commentEndIndex + 2:]  # remove the comment. TBD deal with more than one comment in a line

        # if not line.find('error_status_t') ==-1: #the structsEnd part is over, copy all functions as is
        if not line.find('Proc0_') == -1:  # the structsEnd part is over, copy all functions as is
            copyAll = True

        if copyAll:
            if line.find('RpcDecompilerUninit') == -1 and line.find('error decompilation failed') == -1:
                copyLines += line
                copyLines += "\n"
                continue
            else:
                # new file begins
                flagComment = False
                flagFirstTypedefFound = False
                typedef_line = None
                copyAll = False

                headerPrinted = False
                # for key,value in structDict.items():
                # print "%s,%s" % (key,value)
                # exit()
                structDictList.append((structDict, structNum, uuid, copyLines))
                structNum += 1
                structDict = {}
                # continue
                # return structDictList,copyLines
                copyLines = ""

        if 'uuid(' in line and not headerPrinted:
            uuid = line[line.find('uuid(') + 5:]
            uuid = uuid[:uuid.find('),')]
            # print(uuid)
            # printHeader(uuid,fw)
            headerPrinted = True
            continue

        indexStructStart = line.find('typedef')
        # if not flagStruct:
        if indexStructStart == -1:
            if not flagFirstTypedefFound:  # we are before the first typedef
                continue
            # flagStruct = True#we are inside a struct, check if we are in the end of it
            structEndIndex = line.find('}')
            if not structEndIndex == -1:
                structEndIndex2 = line.find(';')
                if not structEndIndex2 == -1:
                    # found struct ends
                    structName = line[structEndIndex + 1:structEndIndex2].replace(' ', '')
                    structDict[structName] = {}
                    structDict[structName]['typedef'] = typedef_line
                    structDict[structName]['constraints'] = set()
                    structDict[structName]['members'] = set()
                    structDict[structName]['constraints'] = consSet
                    structDict[structName]['members'] = memSet
                    ##print structName
                    flagStruct = False  # the struct ends, continue to find next struct typedef
                    continue
                else:  # found '}' which is not struct ends line.
                    continue
            # we are inside a struct, start to parse members
            structMemberIndex = line.find('Struct_')

            if not structMemberIndex == -1:
                # found struct type member
                ##print "***struct_line " + line 
                consName = line[structMemberIndex:]  # extract struct name from line
                spaceIndex = consName.find(' ')
                consName = consName[:spaceIndex]
                consName = consName.replace('*', '')
                consSet.add(consName)
                memSet.add((line, memberNumber))
                memberNumber += 1
                continue
            else:
                structMemberIndex = line.find('union union')
                if not structMemberIndex == -1:
                    # found union type member
                    ##print "**union_line " + line
                    consName = line[structMemberIndex + len('union union'):]  # extract struct name from line
                    spaceIndex = consName.find(' ')
                    consName = consName[:spaceIndex]
                    consName = consName.replace('*', '')
                    consSet.add('union' + consName)
                    memSet.add((line, memberNumber))
                    memberNumber += 1
                else:
                    # regular type member
                    ##print "*regular_line " + line \
                    if not line == "{" and not line == "":  # not { line or \r\n line which are not important
                        memSet.add((line, memberNumber))
                        memberNumber += 1
                continue
        else:  # typedef found
            ##print line[indexStructStart:] # this line is typedef struct
            flagFirstTypedefFound = True
            memSet = set()
            consSet = set()

            typedef_line = line  # save it for later
            memberNumber = 0
            continue
    return structDictList


def printHeader(id, fw):
    header = "%s%s%s%s" % ("[\nuuid(", id, ")", ",\nversion(1.0),\n]\ninterface DefaultIfName\n{")
    # print header
    fw.write(header)


def printCopyLines(copyLines, fw):
    # print copyLines
    fw.write(copyLines)
    # fw.write("}"+"\n")


def orderStructInIdl(rpcViewFile, idlPath):
    alreadyAdded = set()
    copyLines = ""  # all the functions after the structs part.
    structDictListTuple = buildDict(rpcViewFile)  # generate unordered dict of structs
    # print "len(structDictListTuple):%s" %len(structDictListTuple)
    # sort the dict and #print to idl file
    for structDictT in sorted(structDictListTuple, key=lambda x: int(x[1])):
        flagStop = False
        structDict = structDictT[0]
        uuid = structDictT[2]
        copyLines = structDictT[3]
        # structNameLast = None
        # print structDict
        # print structDictT[1]
        outFileName = os.path.join(idlPath, 'rpc_' + uuid + '.idl')
        count = 0
        print("[+] start processing file:%s" % uuid)
        # print "\t[-]len(alreadyAdded):%s" %len(alreadyAdded)
        with open(outFileName, 'w') as fw:
            printHeader(uuid, fw)
            # continue
            print("\t[+] start to order the structs in the dict")
            # while (len(alreadyAdded)>7 and (len(alreadyAdded))<len(structDict)-2) or  (len(alreadyAdded)<7 and len(alreadyAdded)<len(structDict)): #need to do multiple cycles to go over all structs.
            while len(alreadyAdded) < len(structDict):  # need to do multiple cycles to go over all structs.
                # print "len(alreadyAdded):%s" %len(alreadyAdded)
                for structName, structMemDict in sorted(structDict.items(), key=lambda x: len(x[1]['constraints'])):
                    alreadyAdded = orderprint(structDict, structName, fw, 0, alreadyAdded)
                    # structNameLast = structName
                    count += 1
                    if count == 10000:
                        flagStop = True
                        # print "\t[-]after cycle, oredered %s/%s structs" %(len(alreadyAdded),len(structDict))
                if flagStop:
                    count = 0
                    break
            # alreadyAdded = orderprint(structDict,structNameLast,fw,0,alreadyAdded)
            # print "\t\t[-]after last cycle, oredered %s/%s structs" %(len(alreadyAdded),len(structDict))
            printCopyLines(copyLines, fw)
            # print "[+] generated file: %s\r\nbuild the project and tets it please" %outFileName
        if flagStop:
            os.remove(outFileName)
        # return
        alreadyAdded = set()


# ====order idl structs end


def copytree(src, dst, symlinks=False, ignore=None):
    if not os.path.exists(dst):
        os.makedirs(dst)
    for item in os.listdir(src):
        s = os.path.join(src, item)
        d = os.path.join(dst, item)
        if os.path.isdir(s):
            copytree(s, d, symlinks, ignore)
        else:
            if not os.path.exists(d) or os.stat(s).st_mtime - os.stat(d).st_mtime > 1:
                shutil.copy2(s, d)


def doExists(filePath):
    if filePath is None:
        print("input is missing, please provide it")
        print(
            'for example\r\npython createIdlProject.py -m "PATH TO MSBuild.exe -s "PATH TO ROOT DIR" -e endpoint_mapping.txt -o idl_projects2')
        print(
            r"if you need to fix the idl files (first run), please also provide -r 'PATH TO one_idl_unordered_ALL.txt'")
        exit()
    if not os.path.exists(filePath):
        os.mkdir(filePath)
        print("[+] creating output dir in %s" % filePath)
        # print "filePath %s doesnt exists\r\n...exiting\r\n" %filePath
        # exit()


def copyProject(uuid, templateVsProjectPath, targetDirExternal):
    src = os.path.join(templateVsProjectPath, 'idl_try-template')
    targetDir = os.path.join(targetDirExternal, 'idl_try-template_') + uuid
    doExists(src)
    print(targetDir)
    copytree(src, targetDir)


def copyIdl(uuid, templateVsProjectPath, targetDirExternal, inputDirName):
    idlFileName = "rpc_" + uuid + ".idl"
    idlSrcFilePath = os.path.join(os.path.join(templateVsProjectPath, inputDirName), idlFileName)
    doExists(idlSrcFilePath)
    targetDir = os.path.join(targetDirExternal, 'idl_try-template_') + uuid
    idlTargetFilePath = targetDir + r"\idl_try - template\rpc.idl"
    shutil.copy(idlSrcFilePath, idlTargetFilePath)

    # remove NotDecoded function from idl()
    with open(idlTargetFilePath, "r") as f:
        lines = f.readlines()

    with open(idlTargetFilePath, "w") as fw:
        for line in lines:
            line = line.strip()
            if line.startswith("_Function_") and not line.find("NotDecoded();") == -1:
                line = "//" + line  # make it a comment
                # continue
            # if line.find("switch_is(, "):
            #    line = line.replace('switch_is(,','switch_is(') #remove comma
            fw.writelines(line + "\n")


def setMainCpp(uuid, mapDict, targetDirExternal):  # endpoint):
    targetDir = os.path.join(targetDirExternal, 'idl_try-template_') + uuid
    mainFilePath = os.path.join(targetDir, "../com/xxe/idl_try - template/main.cpp")
    with open(mainFilePath, 'r') as f:
        data = f.read()
    comment = ""

    data = data.replace("<UUID INPUT>", uuid)
    endpoint = "nullptr"
    flagprint = False
    if uuid in mapDict:
        print(uuid)
        process = mapDict[uuid]
        # print("process is %s" %process.keys())
        for proc in mapDict[uuid].keys():
            processName = proc
            break
        print("process is %s" % processName)
        for t in mapDict[uuid].values():
            tuple = t
            break

        # tuple = mapDict[uuid].values()[0]
        endpoint = tuple[0]
        if len(mapDict[uuid].keys()) > 1:  # more than one process
            comment = mapDict[uuid]
        # print "***" + endpoint
        flagprint = True
        # else:
        #    return
        endpoint = tuple[0]
        dll = tuple[1]

    if endpoint == "nullptr":
        data = data.replace('(RPC_WSTR)L"<ENDPOINT INPUT>"', endpoint)

    if not "," in endpoint and "['" in endpoint:
        endpoint = endpoint.replace("['", '').replace("']", '')

    if not comment == "":
        # endpoint += "/*" + str(comment) + "*/"
        data = data + r"\r\n////!!This dll\\uuid has multiple options for endpoint name (the dll runs in diffrenet processes)" + str(
            comment)
    data = data.replace("<ENDPOINT INPUT>", endpoint)

    # data = data.replace("nullptr, /**/, nullptr, &StringBinding);","nullptr, nullptr, nullptr, &StringBinding);")

    # data = data.replace("nullptr, nullptr, nullptr, &StringBinding);",'nullptr,(RPC_WSTR)L"' + endpoint + '"' + ", nullptr, &StringBinding);")
    with open(mainFilePath, 'w') as fw:
        data = fw.write(data)

    # if flagprint:
    # with open(mainFilePath,'rb') as f:
    # lines = f.readlines()

    # for line in lines:
    # line = line.strip()
    # print line


def createEndpointMapping(filePath):
    counter = 0
    processLine = False
    endpointLine = False
    endpoint = "nullptr2"
    mapDict = {}  # key - uuid
    process = None
    dll = None
    with open(filePath, 'r') as f:
        lines = f.readlines()

    for line in lines:
        line = line.strip()
        if not line.find("<WinProcess") == -1:
            process = line
            counter += 2
            processLine = True
            endpointLine = False
            process = process[len('<WinProcess "'):line.find('" pid')]
        if processLine and counter == 0:
            # this is the endpoint line
            processLine = False
            endpoint = line
            endpointLine = True
            if "Invalid rpcrt4" in endpoint:
                continue
            if line == "":
                endpoint = "nullptr"
            # print endpoint
        if processLine and counter > 0:
            counter -= 1
        if endpointLine and not processLine:
            # parse interface
            if line.startswith('RPC  '):
                uuid = line[len('RPC  '):line.find(' (')]
                dll = line[line.find('-- ') + 3:]
                # print uuid
                # print dll

                if uuid in mapDict:
                    mapDict[uuid][process] = (endpoint, dll)

                else:
                    mapDict[uuid] = {}
                    mapDict[uuid][process] = (endpoint, dll)

    # for uuid,mapD in mapDict.items():
    # #res = uuid
    # print uuid
    # for process,tuple in mapD.items():
    # endpoint = tuple[0]
    # dll = tuple[1]
    # #res += "," + process + "," + endpoint + "," + dll
    # print "," + process + "," + endpoint + "," + dll
    # #res = uuid
    return mapDict


# parse args parameters
def init_arg_parser():
    parser = argparse.ArgumentParser(description='Print MSRC patched vulnerabilities')
    parser.add_argument('--source_path', '-s', action='store', help="Path to the visual studio projects source",
                        type=str)
    parser.add_argument('--msbuild_path', '-m', action='store', help="msbbuild.exe path", type=str)
    parser.add_argument('--endpoint_mapping_file', '-e', action='store',
                        help="path to the endpoint mapping taken from #https://gist.github.com/enigma0x3/2e549345e7f0ac88fad130e2444bb702")
    parser.add_argument('--input_dirname', '-i', action='store',
                        help="input dir name (not path) where the order idls will be written to and read from")
    parser.add_argument('--output_dir', '-o', action='store',
                        help="output dir for projects and final compiled exectuables")
    # only for first run
    parser.add_argument('--rpcview_file', '-r', action='store',
                        help="rpcview output file as an input - for fixing the order of the idl file first")
    return parser.parse_args()


def validateInput(inputList):
    for input in inputList:
        print("[+] validating %s" % input)
        doExists(input)


def main():
    # define variables
    args = init_arg_parser()
    rpcViewFile = args.rpcview_file
    inputDirName = args.input_dirname
    # if rpc view output file is given, first read it, order the structs in each idl and create the ordered idl in the output dir
    if rpcViewFile:
        rpcViewFile = args.rpcview_file
        templateVsProjectPath = args.source_path
        inputList = [templateVsProjectPath, inputDirName]
        validateInput(inputList)
        idlPath = os.path.join(templateVsProjectPath, inputDirName)  # path to pre-generated idl dir
        inputList = [idlPath]
        validateInput(inputList)
        orderStructInIdl(rpcViewFile, idlPath)  # only for first run

    templateVsProjectPath = args.source_path
    if templateVsProjectPath == ".":
        templateVsProjectPath = os.getcwd()

    outputDir = args.output_dir
    fileMappingPath = args.endpoint_mapping_file  # map between uuid and process to rpc endpoint name
    endpoint = "nullptr"  # the default endpoint
    msBuildPath = args.msbuild_path  # msbuild.exe path
    allBuiltList = []  # list of all uuid projects
    errBuiltList = []  # list of uuid that didnt compiled well
    idlPath = os.path.join(templateVsProjectPath, inputDirName)  # path to pre-generated idl dir

    # validate input - will exit if an input is missing or wrong
    inputList = [templateVsProjectPath, msBuildPath, fileMappingPath, outputDir, inputDirName, idlPath]
    validateInput(inputList)

    # targetDirExternal = os.path.join(templateVsProjectPath,outputDir)
    targetDirExternal = os.path.join(os.getcwd(), outputDir)
    targetDir = os.path.join(targetDirExternal, 'idl_try-template_')  # the copied project path
    # print (targetDir)
    # exit()
    # build mapping
    mapDict = createEndpointMapping(fileMappingPath)  # build mapping dict

    for root, dirs, files in os.walk(idlPath):  # for each idl, create and compile project
        for file in files:
            filePath = os.path.join(root, file)
            uuid = file[4:-4]
            print("[+] start building project for uuid: %s" % uuid)
            copyProject(uuid, templateVsProjectPath, targetDirExternal)
            print("[+] copied template project: %s" % uuid)
            copyIdl(uuid, templateVsProjectPath, targetDirExternal, inputDirName)
            print("[+] copied idl file to project")
            setMainCpp(uuid, mapDict, targetDirExternal)
            print("[+] main.cpp - set the uuid and endpoint")
            # print "targetDir+uuid:%s" %targetDir+uuid
            projectPath = os.path.join(targetDir + uuid, "../com/xxe/idl_try - template")
            projectPath += "\\idl_try.vcxproj"  # the project file is the input for msbuild.exe
            # doExists(projectPath)

            # build the project using msbuild
            buildCommandList = []
            buildCommandList.append(msBuildPath)
            buildCommandList.append("/p:Configuration=Debug")
            buildCommandList.append("/p:Platform=x64")
            buildCommandList.append(projectPath)
            subprocess.call(buildCommandList, shell=True)

            # copy the exe path to idl_projects2 dir and clean .vs dir to save storage
            exePath = os.path.join(targetDir + uuid, r"idl_try - template\x64\Debug\idl_try.exe")

            # allBuiltList.append(os.path.basename(targetDir+uuid)) #add to final output file
            allBuiltList.append(uuid)  # add to final output file
            if not os.path.exists(exePath):
                time.sleep(5)
            if os.path.exists(exePath):
                print("[+] exe generated ok")
                targetExePath = os.path.join(targetDirExternal, uuid + ".exe")
                # print "targetExePath:%s"%targetExePath
                shutil.copy(exePath, targetExePath)
                shutil.rmtree(os.path.join(os.path.join(targetDirExternal, 'idl_try-template_' + uuid),
                                           r"../com/xxe/idl_try - template/.vs"))
            else:
                print("[!] exe was not generated")
                errBuiltList.append(uuid)
            # exit()

    # list all errors
    print("[!] this are the uuid that were not built due to build errors:")
    for uuid in errBuiltList:
        print(uuid)

    with open(os.path.join(outputDir, 'rpcSupportedUUID.txt'), 'wb') as fw:
        for uuid in allBuiltList:
            fw.writelines(uuid + "\n")
    print("the supported uuid output was written to: %s\r\nplease copy it to the superTuesday server" % os.path.join(
        outputDir, 'rpcSupportedUUID.txt'))


if __name__ == "__main__":
    main()
