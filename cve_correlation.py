import pathlib

import requests
import datetime
import urllib3
import sys
import argparse
import re
import os
import sqlite3
import json
import copy
import subprocess
import shutil
from sqlite3 import Error
from datetime import date

# from bs4 import BeautifulSoup

from bs4 import BeautifulSoup  # as bs4

from config.config_cve_correlation import knowledgeDict, serviceDict, cweIdDict

urllib3.disable_warnings()

SUFFIXES = ["exe", "dll", "sys", "cpl", "drv", "efi", "ocx"]
UPDATE_CATALOG_SEARCH_QUERY = "https://www.catalog.update.microsoft.com/Search.aspx?q={}"
DOWNLOAD_CATALOG_LINK = "https://www.catalog.update.microsoft.com/DownloadDialog.aspx"
pageSize = 100
cve_detailed_dict = dict()  # global dict - will hold the descrption of all cve's for the current month
AMD_64_FOLDER_NAME = "amd64"


def get_project_base_dir():
    return os.path.dirname(__file__)


# clean this words from the vulnerable component name after extracting it from cve description
blackList = ['the way that microsoft', 'windows -', 'windows', 'the windows', ' when it']  # 'vulnerability'
blackList2 = ['microsoft', 'the way the ', 'when the ', 'when ', 'the way ', 'the way that ', 'how ', 'the ', 'that',
              'way ']  # used for cleaning the cveDesc after extraction from cve description
blackList3 = ['runtime', '.net', 'windows', 'microsoft', 'service', 'module',
              'library']  # ',kernel' # search desc in filePathes

descDict = {}  # the file descriptions for all files from system32 (built using PEFILE getVersionInfo
descDictPath = os.path.join(get_project_base_dir(), 'config',
                            'dict.csv')  # the fileName to read for building the descDict for method 3 (see below)

# the words after the vulenrable compoenent name in the cve description
# memList = [' that allows ', 'incorrectly',' software when the software fails to',' when the software fails to ','fails to properly','in the way it handles','improperly','mishandles','processes','handles','does not properly','access objects in memory','reads out of bound memory','fails to check','handle objects',' when it process',' when the ',') ',' fails to',' fail to properly',' could allow ',' allows ',' when','.</p>','. '] #due to the
memList = ['memory corruption vulnerability', 'information disclosure vulnerability',
           'elevation of privilege vulnerability', 'windows spoofing vulnerability',
           'security feature bypass vulnerability', 'remote code execution vulnerability',
           'denial of service vulnerability', 'information disclosure in cpu memory', 'tampering vulnerability',
           'information disclosure in cpu memory access', 'denial of service', 'arbitrary file deletion vulnerability']
# the words before the vulenrable compoenent name in the cve description
# memListPre = ['the way that microsoft','vulnerability exists on the way that the way that microsoft ','vulnerability exists on the way that ','vulnerability exists in the way that the ','vulnerability exists on ','vulnerability exists in the ','an exists in the way that the ','an exists when the ','an exists when ', 'the way that ','a exists when the ', 'a exists when ','a exists in ','vulnerability exists when ','vulnerability exists when the ','vulnerability exists in ',' exists in ']
memListPre = []

# total number of cve's that we found at least one file for them.
foundGood = 0


# dict for method 1 - correlating the vulenrable component name (cveDesc) to the relevant file based on manual pre knowledge

# dict for method 2 - correlating the vulenrable component name (cveDesc) to the relevant file based on the service name

# def finddllBydllfileDict(cveDesc,cve_number,resultDict):
# score = 2500

# if cve_number in resultDict:
# return False,resultDict

# index = cveDesc.find(' service')
# if not index==-1:
# cveDesc = cveDesc[:index]
# dllfileDictTemp = {}
# for key,value in dllfileDict.items():
# dllfileDictTemp[key.lower()] = value.lower()

# dllfileDict = dllfileDictTemp
# #print cveDesc
# if cveDesc.lower() in dllfileDict:
# #print "[++] %s,found service: %s, shortName: %s, file: %s" % (cve_number,cveDesc,serviceDict[cveDesc]['shortName'],serviceDict[cveDesc]['file'])
# resultDict[cve_number] = {'score':score, 'fileList':[dllfileDict[cveDesc]['file']],'cveDesc':cveDesc}
# return True,resultDict
# return False,resultDict

# function for correlating the vulenrable component name (cveDesc) to the relevant file based on the service name dll files dict (serviceDict)
def findDllByServiceName(cveDesc, cve_number, resultDict):
    score = 4000

    if cve_number in resultDict:
        return False, resultDict

    index = cveDesc.find(' service')
    if not index == -1:
        cveDesc = cveDesc[:index]

    # print cveDesc
    if cveDesc.lower() in serviceDict:
        print("[++] %s,found service: %s, shortName: %s, file: %s" % (cve_number, cveDesc,
                                                                      serviceDict[cveDesc]['shortName'],
                                                                      serviceDict[cveDesc]['file']))
        resultDict[cve_number] = {'score': score, 'fileList': [serviceDict[cveDesc]['file']], 'cveDesc': cveDesc}
        return True, resultDict
    return False, resultDict


# calculate match score for files that were correlated using method 3 (file description or file name) - the score will increase if the founded string is made out of many words and decrease if more than one file was matched
def calcMatchScore(cveDesc, finalFileList, finalDescSet):
    score = 80
    score -= (len(finalFileList) - 1) * 10
    score -= (len(finalDescSet) - 1) * 10

    score += cveDesc.count(' ') * 20
    if cveDesc.count(' ') == 0 and len(cveDesc) > 8:
        score += 20
    # if score<0:
    # score=0
    # if score>10:
    # score=10
    return score


# function for correlating the vulenrable component name (cveDesc) to the relevant file based on pre manual knowledge
def findDllByKnowledge(cveDesc, cve_number, resultDict):
    score = 500
    cveDesc = cveDesc.strip()
    # if cve_number=='CVE-2020-16902':
    wordList = cveDesc.split(' ')
    # print "----%s" % cveDesc
    if cveDesc in knowledgeDict:
        # print "%s,%s,%s" % (score,cve_number,knowledgeDict[cveDesc])
        if not cve_number in resultDict:
            resultDict[cve_number] = {'score': score, 'fileList': knowledgeDict[cveDesc], 'cveDesc': cveDesc}
            # print "[*11*]%s" % resultDict[cve_number]
            return True, resultDict
    score = 300

    for word in wordList:
        if word in knowledgeDict:
            # print "%s,%s,%s" % (score,cve_number,knowledgeDict[word])
            if not cve_number in resultDict:
                resultDict[cve_number] = {'score': score, 'fileList': knowledgeDict[word], 'cveDesc': word}
                return True, resultDict
    return False, resultDict


# search for specific files ending with 3 possible extensions.
def getSpecficFileFromDesc(cveDesc, fileType):
    dllName = None
    if fileType in cveDesc:  # if cveDesc specify exact vulnerable dll
        wordList = cveDesc.split(' ')
        for word in wordList:
            if fileType in word:
                dllName = word
                return dllName
    return None


#####sqlite3 start
def create_connection(db_file):
    """ create a database connection to the SQLite database
        specified by the db_file
    :param db_file: database file
    :return: Connection object or None
    """
    conn = None
    try:
        conn = sqlite3.connect(db_file)
    except Error as e:
        print(e)

    return conn


def create_table(conn, create_table_sql):
    """ create a table from the create_table_sql statement
    :param conn: Connection object
    :param create_table_sql: a CREATE TABLE statement
    :return:
    """
    try:
        c = conn.cursor()
        c.execute(create_table_sql)
    except Error as e:
        print(e)
    # print ("create_table exception")


def executeCreateTableQuery(conn, tableName, colDict):
    cur = conn.cursor()
    primeKeyColSet = set()
    create_table_sql = "CREATE TABLE IF NOT EXISTS %s (" % tableName
    for colName, colType in colDict.items():
        if colName.startswith("**"):  # ** is a marker for primary key
            colName = colName[2:]  # remove marker
            # create_table_sql += "%s %s PRIMARY KEY," % (colName,colType)
            primeKeyColSet.add(colName)
            # else:
        create_table_sql += "%s %s," % (colName, colType)

        # create_table_sql = create_table_sql[:-1]
    create_table_sql += "PRIMARY KEY ("
    for primary in primeKeyColSet:
        create_table_sql += "%s," % primary
    create_table_sql = create_table_sql[:-1]
    create_table_sql += "));"
    # print ("create_table_sql:%s" %create_table_sql)
    create_table(conn, create_table_sql)


def executeInsertQuery(conn, tableName, paramDict):
    # if not len(colDict)==len(paramDict):
    # print "number of columns %s is not equal to param's number %s\r\nskipping query" % (len(colDict),len(paramDict))
    # return None
    cur = conn.cursor()

    query = "INSERT into %s (" % tableName
    query2 = " VALUES ("
    for colName, param in paramDict.items():
        query += "%s," % colName
        query2 += "'%s'," % param
    query = query[:-1]
    query += ")"
    query2 = query2[:-1]
    query2 += ");"
    query += query2
    # print query
    rows = None
    try:
        cur.execute(query)
        rows = cur.fetchall()
    except:
        # print ("exception in query: %s" %query)
        # print "exception in insert query: %s\r\n%s" % (query,e.message)
        pass

    return rows


######gen db start
# example command
# Powershell -ExecutionPolicy Bypass -File PatchExtract.ps1 -Patch  "C:\playground\superTuesday\KBs\2020\2020_01_windows8.1-kb4534309-x64.msu" -Path C:\playground\supertuesday\patchExtract\kb4534309

# build a dict of all patched files in a patch tuesday for each month release in the year/
def genExecutableDict(monthKbDict, kbMonthDict, year_str, base_msu_extracted_dir):
    exeMonthDict = {}
    fileSet = set()
    dirsList = []

    # #gen kb dir list
    # for root,dirs,files in os.walk(msuDirYear):
    # for dir in dirs:
    # dirPath = os.path.join(root,dir)
    # if not msuFilePath is None: #if the msu file was downloaded, only extract this file and return, else, extract all the msu files in this year
    # if not "kb" + os.path.basename(dirPath) in msuFilePath:
    # #print ("msuFilePath:::%s" %msuFilePath)
    # #print ("dirPath:::%s" %"kb" + os.path.basename(dirPath))
    # continue
    # #kb = root[root.rfind("\\")+1:]

    # dirsList.append(dirPath)
    # break
    # #print ("dirsList:%s"%dirsList)
    # #search for files for each kb dir
    fileDictYear = {}  # to remove files that their version haven't changed
    # for dir in dirsList:
    # kb = dir[dir.rfind("\\")+1:]
    # try:
    # month = kbMonthDict[kb]
    # except:
    # print ("[-] invalid msuPathDir - please provide a valid msu path dir")
    # continue
    # #print ("kb:%s" %kb)
    month = None
    for key, val in monthKbDict.items():
        print("kb_val:%s" % val)
        kb = val
        month = key
        break

    # kb = monthKbDict[str(begin_month)]
    found_dir_name = None
    base_dir = os.path.join(base_msu_extracted_dir, year_str)
    for file_name in os.listdir(base_dir):
        if str(kb) in file_name:
            found_dir_name = file_name

    if found_dir_name is None:
        raise EnvironmentError(f"Expected the directory {found_dir_name} to be found in the FS")

    dir = os.path.join(base_dir, found_dir_name)  # build path to extract kb file
    print("dir:%s" % dir)
    for root, dirs, files in sorted(os.walk(dir)):
        index = root.find(f'\\{AMD_64_FOLDER_NAME}\\')
        if index == -1:
            continue

        r_dir = root[root.rfind('\\') + 1:]
        # print r_dir
        # if not r_dir=='r':
        # continue
        for file_path in files:
            suffix = pathlib.Path(file_path).suffix[1:]  # remove the dot
            if suffix not in SUFFIXES:
                continue  # not executable.

            file_version = root[index + 3:]
            file_version = file_version[file_version.rfind(".") + 1:]
            file_version = file_version[:file_version.find("\\")]
            index = file_version.find("_none_")
            if not index == -1:
                file_version = file_version[:index]
            try:
                dummy = int(file_version)
            except:
                # print "dir does not contain file_version %s" % file_version
                continue
            fileModTime = os.stat(os.path.join(root, file_path)).st_mtime
            if file_path in fileDictYear:
                if file_version in fileDictYear[file_path]:
                    if int(fileModTime) < int(fileDictYear[file_path][file_version]['fileModTime']):
                        # print "found earlier change: %s,%s,%s from %s,%s,%s"% (file,file_version,fileModTime,file,fileDictYear[file][file_version],fileDictYear[file][file_version]['fileModTime'])
                        fileDictYear[file_path][file_version]['fileModTime'] = int(fileModTime)
                        fileDictYear[file_path][file_version]['month'] = month
                    # print "found older change: %s,%s,%s from %s,%s,%s"% (file,file_version,fileModTime,file,fileDictYear[file][file_version],fileDictYear[file][file_version]['fileModTime'])
                    continue
                else:  # another file version for this file name
                    if not file_version in fileDictYear[file_path]:
                        fileDictYear[file_path][file_version] = {}

                    fileDictYear[file_path][file_version]['fileModTime'] = int(fileModTime)
                    fileDictYear[file_path][file_version]['month'] = month

            else:
                fileDictYear[file_path] = {}
                fileDictYear[file_path][file_version] = {}
                fileDictYear[file_path][file_version]['fileModTime'] = int(fileModTime)
                fileDictYear[file_path][file_version]['month'] = month

    # convert fileDictYear to exeMonthDict (for each month the fileSet of really patched files)
    for file, verDict in fileDictYear.items():
        final = "%s" % file
        for ver, valDict in verDict.items():
            final += "," + ver
            for key, val in valDict.items():
                if key == 'month':
                    final += "," + valDict['month']
                    if valDict['month'] in exeMonthDict:
                        exeMonthDict[valDict['month']].add(file)
                    else:
                        exeMonthDict[valDict['month']] = set()
                        exeMonthDict[valDict['month']].add(file)

    ##just for validating windows 10 file version logic works
    # for file,fileDict in fileDictYear.items():
    # for key,val in fileDict.items():
    # if file=='sethc.exe':
    # print "%s,%s,%s" %(file,key,val)

    return exeMonthDict


# build 2 dicts of kb number<->release month
def genMonthKbDict(msuDirFile, year):
    monthKbDict = {}  # mapping of the month of this kb to kb
    kbMonthDict = {}  # mapping of kb to the month of this kb
    # msuDirYear = os.path.join(msuDirPath,year)
    # print ("msuDirYear:%s" %msuDirYear)
    # for root,dirs,files in os.walk(msuDirYear):
    # for file in files:
    # msuDirFile = os.path.join(root,file)
    # if not msuFilePath is None: #if the msu file was downloaded, only extract this file and return, else, extract all the msu files in this year
    #    if not msuFilePath==msuDirFile:
    #        continue
    # command = "Powershell -ExecutionPolicy Bypass -File PatchExtract.ps1 -Patch %s"% (msuDirFile)
    # print ("msuDirFile: %s" %msuDirFile)
    kb = msuDirFile[msuDirFile.find('-kb') + 3:]
    if '-x64' in msuDirFile:
        kb = kb[:kb.find('-x64')]
    elif '-x86' in msuDirFile:
        kb = kb[:kb('-x86')]
    else:
        print("[-] 2cannot find end of kb folder...skipping patch extract for msu: %s" % msuDirFile)
        return None, None
    # print ("kb is:%s" %kb)
    #
    file = os.path.basename(msuDirFile)
    print("file is:%s" % file)
    month = file[file.find(year + "_") + len(year) + 1:]
    if month.startswith('_'):
        month = file[file.find(year + "_") + len(year) + 2:]
    print("[+++] month:%s" % month)
    month = month[:2]
    if month.startswith('0'):
        month = month[1:]
    print("[---]month:%s\r\n" % month)

    monthKbDict[month] = kb
    kbMonthDict[kb] = month
    # break
    return monthKbDict, kbMonthDict


def kb_architecture(raw_kb_name):
    kb_name = os.path.basename(raw_kb_name)
    if "x64" in kb_name:
        return "x64"
    elif "x86" in kb_name:
        return "x86"

    raise NotImplementedError("not implemented non x64 or x86 architecture detaction")


def get_prefix_kb(raw_kb_name):
    kb_name = os.path.basename(raw_kb_name)
    prefix_kb = kb_name.split("kb")[0][:-1]
    return prefix_kb


# extract all files from a directory of msu files for this year
def extractMsuForMonth(msuDirFile, year, os_version, extracted_msu_base_path):
    monthKbDict = {}  # mapping of kb to the month of this kb
    # msuDirYear = os.path.join(msuDirPath,year)

    path_patch_extractor = os.path.join(get_project_base_dir(), "utilities", "PatchExtract.ps1")

    command = "Powershell -ExecutionPolicy Bypass -File %s -Patch %s -x64 amd64 -WOW wow64" % (path_patch_extractor, msuDirFile)
    kb = msuDirFile[msuDirFile.find('-kb') + 3:]
    if '-x64' in msuDirFile:
        kb = kb[:kb.find('-x64')]
    elif '-x86' in msuDirFile:
        kb = kb[:kb('-x86')]
    else:
        print("cannot find end of kb folder...skipping patch extract for msu: %s" % msuDirFile)
        return msuDirFile
    arch_name = kb_architecture(msuDirFile)

    dirP = extracted_msu_base_path
    kb_prefix = get_prefix_kb(msuDirFile)
    extracted_kb_folder_name = f"{kb_prefix}-kb{kb}-{arch_name}"
    outdir = os.path.join(dirP, year, extracted_kb_folder_name)
    os.makedirs(outdir, exist_ok=True)

    # if "windows 10" in os_version.lower():
    #     dirP = dirP.replace("extractedMsuFiles","win10_extractedMsuFiles")

    # subprocess.call(['cmd','/c','md',year])
    # outdir = os.path.join(outdir,kb)
    # subprocess.call(['cmd','/c','cd',year,'&&','cmd','/c','md',kb,'&&','cmd','/c','cd..'])
    if os.path.exists(os.path.join(outdir, AMD_64_FOLDER_NAME)):  # if there is already output in the x64 dir for this patch
        return  # msuDirFile
        # tempDir2 = os.path.join(os.path.join(outdir,kb), AMD_64_FOLDER_NAME)
        # print "%s exists, delete it" %tempDir2
        # shutil.rmtree(tempDir2) #delete it
        # # subprocess.call(['cmd','/c','cd',year,'&&','cmd','/c','md',kb,'&&','cmd','/c','cd..'])
    command += " -Path %s" % outdir
    commandList = command.split(' ')
    print("[+] Extracting msu file %s to %s" % (msuDirFile, outdir))
    print(commandList)
    subprocess.call(commandList, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

    # delete junk folder
    try:
        junkPath = os.path.join(outdir, 'JUNK')
        shutil.rmtree(junkPath)
    except Exception as e:
        print(f"Failed to delete JUNK folder in '{junkPath}', this MSU probbebly failed to get extracted.")


def extractPatchesAndGenerateDB(conn, msuDirPath, year, os_version, firstTime, msuFilePath, doExtract, begin_month,
                                extracted_msu_base_path):
    year_str = str(year)
    os_version_is_not_for_db = False
    if "windows 10" in os_version.lower():
        tableName = "win10_kb_files"
        patchedFilesDir = os.path.join(os.getcwd(), year_str)
        patchedFilesDir = patchedFilesDir.replace('PatchExtract', 'win10_PatchExtract')
    elif "windows 8.1" in os_version.lower():
        tableName = "kb_files"
        patchedFilesDir = os.path.join(os.getcwd(), year_str)
    else:
        os_version_is_not_for_db = True
        patchedFilesDir = os.path.join(os.getcwd(), year_str)
        print("[-] wrong os_version %s\r\nplease choose os_version either %s or %s" % (
        os_version, "windows 8.1", "windows 10"))
        # exit()

    if firstTime:
        print("[+] msuDirPath:%s" % msuDirPath)
        if not os.path.exists(msuDirPath):
            os.mkdir(msuDirPath)
        msuDirYear = os.path.join(msuDirPath, year_str)
        if not os.path.exists(msuDirYear):
            os.mkdir(msuDirYear)
            # print ("cant find %s\r\nplease provide valid year" % msuDirYear)
            # exit()
    else:
        msuDirYear = msuDirPath
        msuDirYear = os.path.join(msuDirPath, year_str)

    foundMsuDir = False
    if not msuFilePath is None and os.path.exists(msuFilePath):  # the msu file was downloaded
        foundMsuDir = True
        msuDirFile = msuFilePath

    else:  # search for msu file - (msuDirFile) for the begin_month
        for root, dirs, files in os.walk(msuDirYear):
            for file in files:
                msuDirFile = os.path.join(root, file)
                begin_month_str = None
                if int(begin_month) < 10:
                    begin_month_str = "0" + str(begin_month)
                else:
                    begin_month_str = str(begin_month)
                begin_month_str = "_" + str(begin_month_str) + "_"

                if not begin_month_str in msuDirFile:
                    continue
                foundMsuDir = True
                break

    if not foundMsuDir:
        print("[-] couldnt find msu files for year:%s month %s" % (year_str, begin_month))
        return

    if doExtract:
        extractMsuForMonth(msuDirFile, year_str, os_version, extracted_msu_base_path)
    else:
        print("[-] skip extracting msu files\r\nif you want to extract files from msu, please add param doExtract")

    # gen mapping of month to the kb number
    monthKbDict, kbMonthDict = genMonthKbDict(msuDirFile, year_str)
    if monthKbDict is None or kbMonthDict is None:
        return
    print("msuDirFile:%s" % msuDirFile)
    print("monthKbDict:%s" % monthKbDict)
    print("kbMonthDict:%s" % kbMonthDict)

    # exeFilesDict = genExecutableDict(patchedFilesDir,monthKbDict,kbMonthDict,msuFilePath)
    exeFilesDict = genExecutableDict(monthKbDict, kbMonthDict, year_str, extracted_msu_base_path)
    colDict = {'**kb_name': 'text not NULL', 'kb_year_month': 'text not NULL', 'os_version': 'text not NULL',
               '**file_in_kb': 'text not NULL'}

    if not os_version_is_not_for_db:
        if firstTime:
            executeCreateTableQuery(conn, tableName, colDict)
        # print (exeFilesDict)

        for month, fileSet in sorted(exeFilesDict.items(), key=lambda x: int(x[0])):
            for file in sorted(fileSet):
                # print "%s,%s,%s,%s" % (year_str,month,monthKbDict[month],file)
                paramDict = {'kb_name': monthKbDict[month], 'kb_year_month': year_str + "_" + month,
                             'os_version': os_version, 'file_in_kb': file}
                with conn:
                    executeInsertQuery(conn, tableName, paramDict)

                ######gen db end


################sqlite3 end

# search for specific files ending with 3 possible extensions wrapper.
def getSpecficFileFromDescWarapper(cveDesc, fileTypeList):
    dllName = None
    for fileType in fileTypeList:
        dllName = getSpecficFileFromDesc(cveDesc, fileType)
        if dllName is not None:
            return dllName
    return dllName


# search for the first words before the vulnerable name and the first words after the vulnerable name, then remove generic words (blacklists for example windows,service...)
def extratcVulnerableComponentNameFromDescription(cveDesc, resultDict, verboseNotFound, cve_number):
    fileFound = False
    minIndex = len(cveDesc)
    memPre = None
    cveDescShort = None

    # now chopped the description after the vulnerable compoenent name based on words the appears after it in the description (words in memList))
    memPost = None
    for memEnd in memList:
        # print "[+]search for end"
        if memEnd in cveDesc:
            index = cveDesc.find(memEnd)
            if index < minIndex:
                minIndex = index
                memPost = memEnd

    # if we havent found any post words, return as no found   
    if minIndex == len(cveDesc) or memPost is None:
        if verboseNotFound:
            print("[-] NOT_FOUND,minIndex == len(cveDesc) or memPost is None,%s,%s" % (cve_number, cveDesc))
        return fileFound, resultDict, cveDesc, cveDescShort

    # print "[+]found best end: %s" %memPost
    try:
        cveDesc = re.sub(r'[^\x00-\x7f]', r'', cveDesc)
        cveDesc = str(cveDesc[:minIndex])
    except:
        print("[-] %s,%s" % (cve_number, repr(cveDesc)))
        exit()
    # remove black list words from cveDesc
    for black in blackList:
        cveDesc = cveDesc.replace(black.lower() + " ", '')
        cveDesc = cveDesc.replace(black.lower(), '')

    for black in blackList2:
        cveDesc = cveDesc.replace(black.lower() + " ", '')
        cveDesc = cveDesc.replace(black.lower(), '')

    if cveDesc.endswith(' '):
        cveDesc = cveDesc[:-1]

    if cveDesc.startswith(' '):
        cveDesc = cveDesc[1:]

    if '</a>' in cveDesc:
        index = cveDesc.find('</a>')
        cveDesc = cveDesc[:index]
        index = cveDesc.find('">')
        if index >= 0:
            cveDesc = cveDesc[index + 2:]

    if '(' in cveDesc:
        index = cveDesc.find('(')
        cveDescShort = cveDesc[index + 1:]
        cveDesc = cveDesc[:index]

    if len(cveDesc) < 2 or cveDesc.count(' ') > 12:
        if verboseNotFound:
            if cveDesc == '':
                print("[-] NOT_FOUND,whole Windows OS was specified as the vulnerable component,%s,%s" % (
                cve_number, cveDesc))
            elif len(cveDesc) < 2:
                print("[-] NOT_FOUND,short cve left,%s,%s" % (cve_number, repr(cveDesc)))
            elif cveDesc.count(' ') > 12:
                print("[-] NOT_FOUND,coulnt not find vulnerable component in description,%s,%s" % (
                cve_number, repr(cveDesc)))
        return fileFound, resultDict, cveDesc, cveDescShort
    fileFound = True
    # print "*******%s" %cveDesc
    return fileFound, resultDict, cveDesc, cveDescShort


# main function for correlating the vulnerable file to the cve description.
def findDllBYDesc(cve_number, cveDesc, descDict, resultDict, verboseNotFound):
    global foundGood  # counter for total cve's that we found at least one file.
    fileFound = False  # found file or not.
    # cveDesc = cve_dict['description'].lower().strip() #the cve description (will be chopped later to find the vulnerable component name
    # try to parse title instead of description
    cveDesc = cveDesc.lower().strip()
    # description2  = cve_dict['description']
    # print "desc:%s" %repr(description2)

    cveDescShort = None  # sometimes the description includes short name, for example (bits)

    if 'win32k' in cveDesc:  # if the cve includes the win32k then we know the vulnerable dll
        dllName = 'win32k.sys'
    else:  # try to search for other specific files ending with 3 possible extensions.
        dllName = getSpecficFileFromDescWarapper(cveDesc, ['.dll', '.exe', '.sys'])

    # if specific dll was found, add it to resultDict and return
    if dllName is not None:
        dllName = dllName.replace('(', '').replace(')', '')
        if resultDict is not None:
            resultDict[cve_number] = {'score': 2000, 'fileList': [dllName], 'cveDesc': dllName}
            fileFound = True

    else:  # no specific dll was found, lets try to find relevant dll based on dict

        # chopp the cve description to extract the vulnerable component name.
        fileFound, resultDict, cveDesc, cveDescShort = extratcVulnerableComponentNameFromDescription(cveDesc,
                                                                                                     resultDict,
                                                                                                     verboseNotFound,
                                                                                                     cve_number)

        # if vulnerable compoenent name was not found return.
        if not fileFound:
            fileFound = False
            if verboseNotFound:
                print("NOT_FOUND,***cant find component,%s,%s" % (cve_number, repr(cveDesc)))
            return resultDict

        # start to search vulenrable names by 3 methods

        # method 1. search it in manual defined dict (see the global dict above) based on past vulnerabilities with the same component name and found pacthed files
        foundKnowledge, resultDict = findDllByKnowledge(cveDesc, cve_number, resultDict)

        if foundKnowledge:
            fileFound = True
            return resultDict

        # method 2. in some cases the vulenrable component name is a service, search it in predefined service dict that was generated by the description fields in registry, for example: Computer\HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\CDPSvc\description
        foundService, resultDict = findDllByServiceName(cveDesc, cve_number, resultDict)
        if foundService:
            fileFound = True
            return resultDict

        # method 3. search in file description dict that was generated based on the description of all the executable files under system32 using PEFILE version info extract.
        #          it will also search the file name itself if it contains the vulnerable component name
        finalFileList = []  # list of all founded files by description or fileName
        finalDescSet = set()  # set of all founded desc

        # try it
        # cveDesc = cveDesc.replace(' service ','')

        for desc, fileList in descDict.items():
            if cveDesc in desc:  # if the extracted vulnerable component is included in the file description
                finalDescSet.add(desc)
                finalFileList += fileList
            elif cveDesc not in blackList3:  # check that its not a general keyword
                for filePath in fileList:  # if the extracted vulnerable component is included in the file name
                    if cveDesc in filePath or ((not cveDescShort is None) and (cveDescShort in filePath)):
                        finalFileList.append(os.path.basename(filePath))
                        finalDescSet.add(desc)

        # if no file was found by method 3, return
        if len(finalFileList) == 0:
            fileFound = False
            if verboseNotFound:
                print("[-] NOT_FOUND,cant find component,%s,%s" % (cve_number, repr(cveDesc)))
                # resultDict[cve_number] = {'score':-10000, 'fileList':finalFileList,'cveDesc':cveDesc}
            return resultDict

        # calc match score for correlating file
        score = calcMatchScore(cveDesc, finalFileList, finalDescSet)

        # here we can decide if we would like to print scores below or equal to 0 or not
        if score <= 0:
            fileFound = False
            # print "[-]%s,%s,%s" % (score,cve_number,cveDesc)
            if not cve_number in resultDict:
                resultDict[cve_number] = {'score': score, 'fileList': finalFileList, 'cveDesc': cveDesc}
                # if verboseNotFound:
                #    print "NOT_FOUND,score less than 0,%s,%s" % (cve_number,cveDesc)

        else:  # positive score - add to result dict and return
            # print "%s,%s,%s,%s,%s" % (score,cve_number,cveDesc,finalDescSet,finalFileList)
            if not cve_number in resultDict:
                fileFound = True
                resultDict[cve_number] = {'score': score, 'fileList': finalFileList, 'cveDesc': cveDesc}
                return resultDict

        # #method 4
        # foundDllfile,resultDict = finddllBydllfileDict(cveDesc,cve_number,resultDict)
        # if foundDllfile:
        # fileFound = True
        # return resultDict

    return resultDict


def get_msrc_vulns_month(monthDateFormetted):
    if monthDateFormetted is None:
        print("[-] bug in the conversion of the dates - in function get_msrc_vulns_month")
        exit()
    url = ("https://api.msrc.microsoft.com/cvrf/v2.0/cvrf/%s" % monthDateFormetted)

    r = requests.get(url, headers={'Accept': 'application/json'})
    if not r.status_code == 200:
        return None
    data = r.json()

    # uncomment to print all data:
    json.dumps(data, indent=4)
    data = data["Vulnerability"]
    return data


# download cve's for this month filtered by os_version (definded in main)
def get_msrc_vulns_page_wrapper(monthDateFormetted, cve_set, os_version):
    # entries_count, bulletins = get_msrc_vulns_page(startDate, endDate, page_number)
    cve_dict = {}
    # cve_detailed_dict = {}
    bulletins = get_msrc_vulns_month(monthDateFormetted)  # get_msrc_vulns_page(startDate, endDate, page_number)
    if bulletins is None:
        return cve_dict, cve_detailed_dict, bulletins
    for bulletin in bulletins:
        # [u'Ordinal', u'ReleaseDateSpecified', u'Threats', u'Remediations', u'Title', u'Notes', u'CVSSScoreSets', u'DiscoveryDateSpecified', u'ProductStatuses', u'RevisionHistory', u'CVE', u'Acknowledgments']
        # the fields are Title and Notes (description)
        for remediationDict in bulletin['Remediations']:
            if 'ProductID' in remediationDict and '10482' in remediationDict[u'ProductID']:
                # print "%s,%s" % (bulletin["CVE"],bulletin["Title"])
                if bulletin['CVE'] in cve_set:
                    continue
                cve_set.add(bulletin['CVE'])
                # print "%s,%s,%s,%s" %(bulletin['cveNumber'],bulletin['cveTitle'],repr(bulletin['description']),bulletin['affectedProducts'])
                if "Value" in bulletin["Title"]:
                    cve_dict[bulletin['CVE']] = bulletin["Title"]["Value"]
                if not bulletin['CVE'] in cve_detailed_dict:
                    cve_detailed_dict[bulletin['CVE']] = copy.deepcopy(cve_dict)

    return cve_dict, cve_detailed_dict, bulletins


# parse args parameters
def init_arg_parser():
    default_extracted_path = os.path.abspath("./extractedMsuFiles")
    import datetime
    today = datetime.datetime.today()
    end_date = today.strftime("%m/01/%Y")
    parser = argparse.ArgumentParser(
        description="Step 2 - vulnerabilities correlation to patch files\r\nusage examples:\r\n\r\n1. 1 minute run (no internet connection is required) - using provided db with kb_files table - c:\Python37\python getCve_match_patched_files_db_outputs.py -d cveDBOutput.db\r\n2. ~20 minutes run - starting from scratch (depends on internet speed) - building a new db with download of msu files and extraction - c:\Python37\python getCve_match_patched_files_db_outputs.py -d <new_db_name.db> -m -o <msu_dir_name> --doExtract \r\n3. 2 minute run (only after #2 was ran at least 1 time) - building a new db with no download of msu files with no extraction of msu files- c:\Python37\python getCve_match_patched_files_db_outputs.py -d <new_db_name.db> -M <existing_msu_dir_name> \r\n4. 10 minutes run - (only after #2 was ran at least 1 time) - building a new db with no download of msu files with extraction of msu files to folder extractedMsuFiles -  c:\Python37\python getCve_match_patched_files_db_outputs.py  -d <new_db_name.db> -M <existing_msu_dir_name> --doExtract")

    parser.add_argument('--dbPath', '-d', nargs='?', help='DB output file')
    parser.add_argument('--msuDirName', '-M', action='store', help='patch folder name for .msu files to extract to')
    parser.add_argument('--msuDownload', '-m', action='store_true',
                        help='Download .msu patch files, please provide -o param')
    parser.add_argument('--outputMsuName', '-o', action='store',
                        help='The folder name which the MSU will be downloaded to')
    parser.add_argument('--doExtract', '-x', action='store_true',
                        help='Extract msu content to msuExtractedPath folder')
    parser.add_argument('--beginningDate', '-b', action='store',
                        help="Start date - MM/DD/YYYY, the default is 03/01/2017", type=str, default="03/01/2017")
    parser.add_argument('--endDate', '-e', action='store', help="End date - MM/DD/YYYY, default is the last one",
                        type=str, default=end_date)
    parser.add_argument('--verboseNotFound', '-V', action='store_true', help="Show also not found vulnerabilities ")
    parser.add_argument('--osVersion', '-O', action='store', default="Windows 8.1",
                        help='OS version to download kb files, default is "Windows 8.1", supports also "Windows 10 Version 1909/2004"...')
    parser.add_argument('--cweUpdate', '-c', action='store_true', help='update CWE data and continue')
    parser.add_argument('--cweUpdateAndExit', '-C', action='store_true', help='Only update CWE data and exit')
    parser.add_argument('--cweUpdatePath', '-p', action='store', help='Update CWE data file path')
    parser.add_argument('--msuExtractedPath', action='store', help='Update CWE data file path',
                        default=default_extracted_path)
    # parser.add_argument('--sum', dest='accumulate', action='store_const',
    #               const=sum, default=max,
    #                help='sum the integers (default: find the max)')

    return parser.parse_args()


# get kb link for msu download (not used)
def get_kb_download_link(update_kb, os_version):
    response = requests.request("POST", UPDATE_CATALOG_SEARCH_QUERY.format(update_kb)).text
    soup = BeautifulSoup(response, features="lxml")

    for link in soup.findAll('a'):
        if link.attrs.get('onclick', None) and 'goToDetails' in link.attrs.get('onclick'):
            # print("get_kb_download_link: %s" %link.text)
            # if 'Cumulative Update' in link.text and 'x64-based' in link.text and update_kb.upper() in link.text and '1809' in link.text:
            if os_version == "Windows 8.1" and not 'Security Only' in link.text:
                continue
            if os_version in link.text and 'x64-based' in link.text and update_kb.upper() in link.text:
                # print("get_kb_download_link: %s" %link.text)
                update_id = re.findall('goToDetails\("(.*)"\)', link.attrs['onclick'])[0]
                headers = {
                    'authority': 'www.catalog.update.microsoft.com',
                    'cache-control': 'max-age=0',
                    'upgrade-insecure-requests': '1',
                    'user-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.83 Safari/537.36',
                    'origin': 'https://www.catalog.update.microsoft.com',
                    'content-type': 'application/x-www-form-urlencoded',
                    'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
                    'sec-fetch-site': 'same-origin',
                    'sec-fetch-mode': 'navigate',
                    'sec-fetch-user': '?1',
                    'sec-fetch-dest': 'document',
                    'referer': 'https://www.catalog.update.microsoft.com/DownloadDialog.aspx',
                    'accept-language': 'en-US,en;q=0.9,he;q=0.8',
                }
                data = {
                    'updateIDs': '[{"size":0,"languages":"","uidInfo":"%s","updateID":"%s"}]' % (update_id, update_id),
                    'updateIDsBlockedForImport': '',
                    'wsusApiPresent': '',
                    'contentImport': '',
                    'sku': '',
                    'serverName': '',
                    'ssl': '',
                    'portNumber': '',
                    'version': ''
                }
                download_text = requests.post(DOWNLOAD_CATALOG_LINK, data=data, headers=headers).text
                msu_url = re.findall("downloadInformation\[0\]\.files\[0\]\.url = '(.*)';", download_text)[0]
                return msu_url
            else:
                continue


# download the msu file (not used)
def download_file(file_url, output_path):
    with open(output_path, 'wb') as f:
        f.write(requests.get(file_url).content)


# check the real files that were updated in 2020 in reqMonth
def getUpdatedFilesInPatch(reqYear, reqMonth):
    # patchedSet = set()
    patchDict = {}
    fileName = os.path.join('config', str(
        reqYear) + '_updated_files_only_gen.csv')  # generated by superTuesday\patchExtract\extract_files_from_msu_files.py script
    if not os.path.exists(fileName):
        print(
            "[-] cant find patches files %s\r\nplease generate it using superTuesday\patchExtract\extract_files_from_msu_files.py script\r\nexiting" % fileName)
        exit()
    print("[+] read_patches from file %s" % fileName)
    with open(fileName, 'rb') as f:
        lines = f.readlines()

    for line in lines:
        line = line.strip()
        line = line.lower()
        year, month, kb, fileName = line.split(',')
        if not int(reqYear) == int(reqYear) or not int(month) == int(reqMonth):
            continue

        if 'patchedSet' in patchDict:
            patchDict['patchedSet'].add(fileName)
        else:
            patchDict['patchedSet'] = set()
            patchDict['patchedSet'].add(fileName)
            patchDict['kb_name'] = kb
            patchDict['year_month'] = year + "_" + month
    return patchDict


def getUpdatedFilesInPatch2(tableName, reqYear, reqMonth, conn):
    # patchedSet = set()
    patchDict = {}

    with conn:
        cur = conn.cursor()
        query = "select kb_year_month,kb_name,file_in_kb from %s where kb_year_month=='%s_%s'" % (
        tableName, reqYear, reqMonth)
        rows = None
        try:
            cur.execute(query)
            rows = cur.fetchall()
        except:
            return None
            # #print "select query exception: %s" %query
            # print ("[-]Exception in getUpdatedFilesInPatch2, in query %s" % (query))
            # print("please first fill table %s in your new db or used the deafult provided db\r\nrequiered columns: kb_year_month,kb_name,file_in_kb(patched file name),os_version ...\r\nexiting" %tableName)
            # exit()

    for row in rows:
        year, month = row[0].split('_')
        if 'patchedSet' in patchDict:
            patchDict['patchedSet'].add(row[2])
        else:
            patchDict['patchedSet'] = set()
            patchDict['patchedSet'].add(row[2])
            patchDict['kb_name'] = row[1]
            patchDict['year_month'] = year + "_" + month
    return patchDict


# download msu files from windows update (not used)
def downloadMsu(args, cve_dict, os_version, bulletins):
    filePath = None
    kbDoneSet = set()
    # print ("os_version: %s" %os_version)
    # if int(args.endDate.split('/')[0]) - int(args.beginningDate.split('/')[0]) > 1:
    #    raise ValueError("Downloading MSU requires to specify up to a single month range only")
    found = False
    foundKB = False
    for bulletin in bulletins:
        foundKB = False
        for remediationDict in bulletin['Remediations']:
            # dict_keys(['Description', 'URL', 'Supercedence', 'ProductID', 'Type', 'DateSpecified', 'AffectedFiles', 'RestartRequired', 'SubType'])
            # if 'x64' in bulletin['name'] and os_version in bulletin['name'] and bulletin['downloadUrl1'] and 'catalog.update.microsoft.com' in bulletin['downloadUrl1']:
            # print ("%s,%s" %(remediationDict['URL'],remediationDict[u'ProductID']))
            # continue

            if 'URL' in remediationDict and 'catalog.update.microsoft.com' in remediationDict['URL']:
                if "Windows 8.1" in os_version:
                    if 'ProductID' in remediationDict and '10482' in remediationDict[u'ProductID']:
                        foundKB = True
                elif "Windows 10" in os_version:
                    if not 'ProductID' in remediationDict:
                        continue
                    for productID in remediationDict[u'ProductID']:
                        # print (productID)
                        if not str(productID) in ['11568', '11569', '11570', '11571',
                                                  '11572']:  # Windows 10 Version 1909
                            continue
                        foundKB = True
                if not foundKB:
                    continue

                update_kb = remediationDict['URL'].split('=')[1]
                # print ("update_kb:%s" %update_kb)
                kb_msu_url = get_kb_download_link(update_kb, os_version)
                if kb_msu_url in kbDoneSet:  # already downloaded
                    found = True
                    break
                if not kb_msu_url:
                    # print ("[-] error in get_kb_download_link for %s" %update_kb)
                    continue
                    raise ValueError("Error in fetching KB MSU URL!")
                if not '/secu/' in kb_msu_url:
                    continue
                if args.outputMsuName:
                    print("[+] Downloading MSU: {}...".format(kb_msu_url))
                    file_name = kb_msu_url.split('/')[-1]
                    # print ("kb_msu_url:%s" %kb_msu_url)
                    if 'http://download.windowsupdate.com/d/msdownload/update/software/secu/' in kb_msu_url:
                        year = kb_msu_url.split('http://download.windowsupdate.com/d/msdownload/update/software/secu/')[
                            1].split('/')[0]
                        month = \
                        kb_msu_url.split('http://download.windowsupdate.com/d/msdownload/update/software/secu/')[
                            1].split('/')[1]
                    elif 'http://download.windowsupdate.com/c/msdownload/update/software/secu/' in kb_msu_url:
                        year = kb_msu_url.split('http://download.windowsupdate.com/c/msdownload/update/software/secu/')[
                            1].split('/')[0]
                        month = \
                        kb_msu_url.split('http://download.windowsupdate.com/c/msdownload/update/software/secu/')[
                            1].split('/')[1]
                    else:
                        print("[-] didnt find /c or /d in :%s kb_msu_url")
                        exit()
                    # fixes errors in the month of specific msu downloads
                    if update_kb.lower() == "kb4012213":
                        month = "03"
                    elif update_kb.lower() == "kb4103715":
                        month = "05"
                    elif update_kb.lower() == "kb4284878":
                        month = "06"
                    elif update_kb.lower() == "kb4507457":
                        month = "07"
                    elif update_kb.lower() == "kb4467703":
                        month = "11"
                    elif update_kb.lower() == "kb4471322":
                        month = "12"
                    elif update_kb.lower() == "kb4480964":
                        month = "01"
                        year = "2019"
                    elif update_kb.lower() == "kb3205400":
                        month = "12"
                    elif update_kb.lower() == "kb4525250":
                        month = "11"

                    if not os.path.exists(args.outputMsuName):
                        os.mkdir(args.outputMsuName)
                    directory_path = os.path.join(args.outputMsuName, year)
                    file_name = year + "_" + str(month).zfill(2) + "_" + file_name
                    filePath = os.path.join(directory_path, file_name)
                    if not os.path.exists(directory_path):
                        os.mkdir(directory_path)
                        if not os.path.exists(directory_path):
                            print(
                                "[-] can't find or create directory %s\r\nplease crate this dir first\r\nskiping download..." % directory_path)
                            exit()
                    download_file(kb_msu_url, filePath)
                    if not os.path.exists(os.path.join(directory_path, file_name)):
                        raise FileNotFoundError("Downloading MSU was failed, file doesn't exist")
                    kbDoneSet.add(kb_msu_url)
                    break
                else:
                    # Didn't downloaded the file.
                    print("outputMsuName is not selected, doesn't download the MSUs")
                    return None
        if found:
            break
    return filePath  # the downloaded msu file path


# return the current month.
def getCurrentMonth(begin_month, year):
    if begin_month < 10:
        cur_begin_month = "0" + str(begin_month) + "/01/" + str(year)
    else:
        cur_begin_month = str(begin_month) + "/01/" + str(year)

    if begin_month + 1 < 10:
        cur_end_month = "0" + str(begin_month + 1) + "/01/" + str(year)
    else:
        # if begin_month==12: #special case for the last month of the year
        #    cur_end_month = "01/01/" + str(year+1)
        # else:
        cur_end_month = str(begin_month + 1) + "/01/" + str(year)
    return cur_begin_month


def printResults(resultDict, conn, os_version):
    tableName = "cve_patch_files"
    firstTime = True
    # paramDict = {'file_name':'gdiplus.dll','kb_name':'kb1234','cve_name':'cve_2020_1337','match_score':501,'cve_desc':'print spooler'}
    for resultD in sorted(resultDict.keys(), key=lambda x: resultDict[x]['score']):
        result_str = resultD
        # print "%s,%s" % (resultD,resultDict[resultD])
        # continue
        result_str2 = ""
        # if os_version=="all":
        # continue
        with conn:
            cur = conn.cursor()
            for key, values in resultDict.items():
                if resultD == key:
                    # for k,value in values.items():
                    #    result_str += "," + str(value)
                    # print (key)
                    result_str += "," + str(values['score']) + "," + values['cveDesc']
                    if 'patchedFile' in values:
                        result_str += ",[**patchedFile**]" + str(values['patchedFile'])
                        for fileName in values['patchedFile']:
                            paramDict = {'file_name': fileName, 'kb_name': values['kb_name'], 'cve_name': key,
                                         'match_score': values['score'], 'cve_desc': values['cveDesc'],
                                         'year_month': values['year_month'], 'vulType': values['vulType'],
                                         'osVersion': values['osVersion']}
                            result_str2 += "," + values['kb_name'] + "," + values['year_month']
                            # print (paramDict)
                            insertQuery(conn, tableName, paramDict, firstTime)
                            firstTime = False
                            ##update the vulType
                            # query = "UPDATE %s SET vulType='%s' WHERE cve_name='%s';" % (tableName,values['vulType'],key)
                            # cur.execute(query)
                            # print query


                    else:
                        result_str += "," + str(values['fileList'])
                        result_str = "[not found patched file]" + result_str

        result_str += result_str2
    # print ("%s" %result_str)
    # print "total foundGood: %s"  %foundGood


def insertQuery(conn, tableName, paramDict, firstTime):
    with conn:
        tableName = "cve_patch_files"
        # colDict = {'**file_name':'text not NULL','**kb_name':'text not NULL','**cve_name':'text not NULL','match_score':'integer','cve_desc':'text','vulType':'text'}
        colDict = {'**file_name': 'text not NULL', '**kb_name': 'text not NULL', '**cve_name': 'text not NULL',
                   'match_score': 'integer', 'cve_desc': 'text', 'year_month': 'text not NULL', 'vulType': 'text',
                   'osVersion': 'text'}
        # paramDict = {'file_name':'gdiplus.dll','kb_name':'kb1234','cve_name':'cve_2020_1337','match_score':501,'cve_desc':'print spooler'}
        if firstTime:
            executeCreateTableQuery(conn, tableName, colDict)

        rows = executeInsertQuery(conn, tableName, paramDict)


# ===cwe===

def download_cveDetails(product_id, sha, numberOfPages=1000):
    cweDict = {}
    base_url = 'https://www.cvedetails.com/vulnerability-list.php?vendor_id=26&product_id=' + product_id + '&version_id=&page='
    end_url = '&hasexp=0&opdos=0&opec=0&opov=0&opcsrf=0&opgpriv=0&opsqli=0&opxss=0&opdirt=0&opmemc=0&ophttprs=0&opbyp=0&opfileinc=0&opginf=0&cvssscoremin=0&cvssscoremax=0&year=0&month=0&cweid=0&order=1&'

    for pageId in range(1, numberOfPages):
        final_url = base_url + str(pageId) + end_url + sha
        res = requests.get(final_url)
        if not res.status_code == 200:
            final_url = base_url + str(pageId + 1) + end_url + sha
            res = requests.get(final_url)
            if not res.status_code == 200:
                print("[+] finish downloading %s CWE pages" % (pageId - 1))
                return

        html_page = res.text

        soup = BeautifulSoup(html_page, features="lxml")
        # print soup
        cve = None
        cwe = None
        cve_str = '/cve/'
        cwe_str = '//www.cvedetails.com/cwe-details/'
        for link in soup.findAll('a'):  # , attrs={'href': re.compile("^http://")}):
            lnk = link.get('href')
            if lnk is not None:
                if lnk.startswith(cve_str):
                    cve = lnk
                elif lnk.startswith(cwe_str):
                    cwe = lnk
                    if cve is None:
                        # print "cannot find cve for cwe %s" % cwe
                        continue

                    cve = cve[len(cve_str):].replace('/', '')
                    cwe = cwe[len(cwe_str):].replace('/cwe.html', '')
                    try:
                        if cve in cweDict:
                            # print "%s was already parsed" %cve
                            return cweDict
                        cweDict[cve] = (cwe, cweIdDict[cwe])
                        # print "[+]%s,%s,%s" %(cve,cwe,cweIdDict[cwe])
                    except:
                        # cweDict[cve] = (cwe,cweIdDict[cwe])
                        print("[-] exception in parsing cwe: %s,%s" % (cve, cwe))
                        continue

                    cve = None
                    cwe = None
    return cweDict


def downloadNvdFile(fileJsonPath):
    url = 'https://nvdmirror.sml.io' + "//" + os.path.basename(fileJsonPath)
    res = requests.get(url)
    chunk_size = 100
    if not res.status_code == 200:
        print("[-] error in dowloading %s from %s" % (fileJsonPath, url))
        return
    with open(fileJsonPath, 'wb') as fd:
        # fd.write(res.content)
        for chunk in res.iter_content(chunk_size):
            fd.write(chunk)
    print("[+] downloaded file %s" % fileJsonPath)


def insertCWE_year_data(cur, fileJsonPath, tableName):
    with open(fileJsonPath, 'rb') as json_file:
        data = json.load(json_file)

    for d in data["CVE_Items"]:
        cve_name = d["cve"]["CVE_data_meta"]["ID"]
        cwe_list = d["cve"]["problemtype"]["problemtype_data"][0]["description"]
        if len(cwe_list) > 0:
            cwe_id = cwe_list[0]["value"]
            if cwe_id == "NVD-CWE-noinfo" or cwe_id == "NVD-CWE-Other":
                continue
            if not cwe_id.startswith('CWE-'):
                print("%s doesnt starts with CWE-\r\n skipping it" % cwe_id)
                continue
            cwe_id = cwe_id.replace('CWE-', '')
            cwe_id = int(cwe_id)
            if str(cwe_id) in cweIdDict:
                cwe_name = cweIdDict[str(cwe_id)]
            else:
                cwe_id = 'null'
            query = "UPDATE %s SET CWE_id=%s, CWE_name='%s' WHERE cve_name='%s';" % (
            tableName, cwe_id, cwe_name, cve_name)
            try:
                cur.execute(query)
                # print query
            except:
                continue
                # print "update query exception: %s" %query
        # print "%s,%s" % (cve_name,cwe_id)


# insert cwe from cvedetails until 2019 data based on output of script cwe_id_description_dict.py
def insertCWE(conn, filePath):
    # nvdcve-1.1-2020.json

    # download cwe data from cvedetails.com
    windows_sever_2016 = '34965'
    win_server_2016_sha = 'trc=889&sha=64feefda476353c176edd1b2bcd7a3bdc2eab939'
    windows_8_1 = '26434'
    win_8_1_sha = 'trc=978&sha=b2fe1f2ba19c52b1aa3751651a09dcf6acb7ff92'
    numberOfPages = 10  # pass this parameter to download_cveDetails if the default of all paged (1000) is not needed

    print("[+] downloading cwe cvedetails, please wait...")
    cweDict = download_cveDetails(windows_8_1, win_8_1_sha)
    print("[+] finish downloading cwe cvedetails")
    rowUpdatedCounter = 0

    tableName = 'cve_patch_files'

    colDict = {'CWE_id': 'integer', 'CWE_name': 'text'}
    cur = conn.cursor()
    with conn:
        for colName, colType in colDict.items():
            try:
                cur.execute("alter table %s add column '%s' '%s'" % (tableName, colName, colType))
            except:
                continue

        # nvd 2020 json file parsing
        fileJsonPath = os.path.join(get_project_base_dir(), 'config', 'vdcve-1.1-2020.json')
        print("[+] updating CWE data from nvd site for file %s" % fileJsonPath)
        downloadNvdFile(fileJsonPath)
        insertCWE_year_data(cur, fileJsonPath, tableName)
        os.remove(fileJsonPath)

        fileJsonPath = os.path.join(get_project_base_dir(), 'config', 'nvdcve-1.1-2021.json')
        print("[+] updating CWE data from nvd site for file %s" % fileJsonPath)
        downloadNvdFile(fileJsonPath)
        insertCWE_year_data(cur, fileJsonPath, tableName)
        os.remove(fileJsonPath)

    # do select to get all cve in cveDB.db and then update the cwe_id in the db"

    colDict = {'CWE_id': 'integer', 'CWE_name': 'text'}
    cur = conn.cursor()
    with conn:
        for colName, colType in colDict.items():
            try:
                cur.execute("alter table %s add column '%s' '%s'" % (tableName, colName, colType))
            except:
                continue

        with open(filePath, 'rb') as f:  # read baseline of cwe data from preprepared base line file
            lines = f.readlines()

        # joing new data with all data in to cweDict
        for line in lines:
            line = line.strip().decode()
            try:
                cve_name, cwe_id, cwe_name = line.split(',')
            except:
                continue
            if cve_name in cweDict:
                continue
            cweDict[cve_name] = (cwe_id, cwe_name)

        with open(filePath, 'w') as fw:  # save new data to baseline file
            for cve_name, cweTuple in sorted(cweDict.items()):
                cwe_id = cweTuple[0]
                cwe_name = cweTuple[1]
                # print ("%s,%s,%s" % (cve,cwe_id,cwe_name))
                # query = "select * from cve_patch_files where cve_name=='%s'" % (cve_name)

                # save data to file
                line = "%s,%s,%s" % (cve_name, cwe_id, cwe_name)
                fw.write(line + "\n")
                rows = None
                query = "UPDATE %s SET CWE_id=%s, CWE_name='%s' WHERE cve_name='%s';" % (
                tableName, cwe_id, cwe_name, cve_name)
                try:
                    cur.execute(query)
                    rowUpdatedCounter += 1
                except:
                    continue
                    # print "update query exception: %s" %query
    print("[+] %s vulnerabilites were updates with cwe data" % rowUpdatedCounter)


# wrapper function to correlate cve to patched files (calls findDllBYDesc - main functionality inner function )
def correlate(args, cve_dict, resultMonthDict, verboseNotFound, os_version, year, begin_month, conn, resultDict,
              foundPatchedFileCounter, cve_set, bulletins, msuDirPath, firstTime):
    # download the msu (not used)
    msuFilePath = None
    if args.msuDownload:  # and not args.dbPath:
        # get_updates(year)
        msuFilePath = downloadMsu(args, cve_dict, os_version, bulletins)
        if msuFilePath is None:
            return resultDict
    # build descDict
    with open(descDictPath, 'rb') as f:
        lines = f.readlines()

    for line in lines:
        line = line.strip()
        line = line.lower().decode()
        lineTuple = line.split(',')
        desc = lineTuple[0]
        lineTuple = lineTuple[1:]
        descDict[desc] = lineTuple

    # loop for finding the relevant patched file for each cve
    # for cve_dict in cve_dicts:
    for cve_number, cveTitle in cve_dict.items():
        resultMonthDict = findDllBYDesc(cve_number, cveTitle, descDict, resultMonthDict, verboseNotFound)

        # print resultMonthDict
        # get attack vector from title
        vulType = "null"
        for memEnd in memList:
            if memEnd.lower() in cveTitle.lower().strip():
                vulType = memEnd
                break
        cve_detailed_dict[cve_number]['vulType'] = vulType

    # read file (generated manually before) to get the patched file names for each month (currently only for windows 8.1)
    # patchedFilesDict = getUpdatedFilesInPatch(year,begin_month)
    if "windows 10" in os_version.lower():
        kbFilesTableName = "win10_kb_files"
    elif "8.1" in os_version.lower():
        kbFilesTableName = "kb_files"
    elif "all" in os_version.lower():
        kbFilesTableName = "kb_files"
    else:
        print("unknown os: %s " % os_version)
        exit()

    # read data from kb_files table from existing db

    patchedFilesDict = getUpdatedFilesInPatch2(kbFilesTableName, year, begin_month, conn)

    if not args.dbPath or patchedFilesDict is None or len(patchedFilesDict) == 0:
        # Extract patches and generate kb_files table in a new db
        if msuDirPath is None:
            msuDirPath = os.path.abspath(args.outputMsuName)
        if not msuDirPath is None:
            extractPatchesAndGenerateDB(conn, msuDirPath, year, os_version, firstTime, msuFilePath, args.doExtract,
                                        begin_month, args.msuExtractedPath)

    # read data from kb_files table from existing db
    patchedFilesDict = getUpdatedFilesInPatch2(kbFilesTableName, year, begin_month, conn)

    # copy the current month results to the final result_dict (so we will be able to sort all results by score)
    # also mark which fileName that were found are actually included in the patched files (msu) for this month.
    for key, valDict in resultMonthDict.items():
        resultDict[key] = valDict
        for filePath in valDict['fileList']:
            if patchedFilesDict is None:
                continue
            if 'patchedSet' not in patchedFilesDict:
                continue
            for fileName in patchedFilesDict['patchedSet']:
                if fileName in filePath:
                    # if "\\" + fileName in filePath:
                    if 'patchedFile' in valDict:
                        valDict['patchedFile'].append(fileName)
                        valDict['score'] = int(valDict['score'] - 500)
                    else:
                        foundPatchedFileCounter += 1  # only add to counter for first time
                        valDict['patchedFile'] = []
                        valDict['score'] = int(valDict['score'] + 5000)
                        valDict['patchedFile'].append(fileName)
                        valDict['kb_name'] = patchedFilesDict['kb_name']
                        valDict['year_month'] = patchedFilesDict['year_month']
                        valDict['vulType'] = cve_detailed_dict[key]['vulType']
                        valDict['osVersion'] = os_version
                    # print "%s,%s,%s,%s" % (key,int(valDict['score']+5000),valDict['cveDesc'],fileName)

    # print result for the current month
    print("[+] found vulnerable component for %s\%s" % (len(resultMonthDict), len(cve_set)))
    print("[+] foundPatchedFileCounter: %s" % foundPatchedFileCounter)
    return resultDict


# usage examples:
# 1. 1 minute run (no internet connection is requiered) - using provided db with kb_files table - c:\Python37\python getCve_match_patched_files_db_outputs.py -d cveDBOutput.db
# 2. ~20 minutes run - starting from scratch (depends on internet speed) - building a new db with download of msu files and extraction - c:\Python37\python getCve_match_patched_files_db_outputs.py -d <new_db_name.db> -m -o <path_to_new_msu_dir> --doExtract
# 3. 2 minute run (only after #2 was ran at least 1 time) - building a new db with no download of msu files with no extraction of msu files- c:\Python37\python getCve_match_patched_files_db_outputs.py -d <new_db_name.db> -M <path_to_existing_msu_dir>
# 4. 10 minutes run - (only after #2 was ran at least 1 time) - building a new db with no download of msu files with extraction of msu files to folder extractedMsuFiles -  c:\Python37\python getCve_match_patched_files_db_outputs.py  -d <new_db_name.db> -M <path_to_existing_msu_dir> --doExtract


def main():
    global cve_detailed_dict  # if more than 1 month was given as input, this dict should be empty every month
    global foundGood  # total number of found cve's
    foundPatchedFileCounter = 0  # counter for how many patched file were found for each month
    verboseNotFound = False  # dont print cve which no file was found as well
    totalFoundPatchedFileCounter = 0  # yearly patched found files
    totalOsCve = 0  # total number of cve for the selected os
    resultDict = {}  # final output result dict, the key is cve id
    resultMonthDict = {}  # output result dict for one month, the key is cve id (empty each month)

    args = init_arg_parser()
    parser = argparse.ArgumentParser()

    update_kb = None
    msuDirPath = None
    outputMsuPath = None
    os_version = args.osVersion  # "Windows 8.1"#"Windows 10 Version 1909"#"Windows 8.1"#"Windows 10 Version 1909" #

    if not "windows 10" in os_version.lower() and not "8.1" in os_version.lower() and not "all" in os_version.lower():
        print("[-] unknown os: %s " % os_version)
        exit()

    if not args.msuDirName is None:
        msuDirPath = os.path.abspath(args.msuDirName)

    if not args.outputMsuName is None:
        outputMsuPath = os.path.abspath(args.outputMsuName)
    if not msuDirPath is None and not outputMsuPath is None:
        print("[-] please provide either -M or -m and -o parameters, -M and -m cannot be provided toghter")
        exit()

    # selected to download MSUs but didn't specify to which folder
    if args.outputMsuName is None and args.msuDownload is True:
        print("Missing argument --outputMsuName exiting program")
        exit()

    dbPath = args.dbPath  # cveDBOutput.db (the file must include the kb_files table which is included in the db provided at the github)

    if dbPath is None and args.msuDirName is None:
        if outputMsuPath is None:
            print(
                "[-] please provide the either -d\-m\-M\r\nmsuDirPath (-M) parameter or provide the outputDirPath to download msu files -m and -o parameters")
            parser.print_help()
            exit()
        msuDirPath = outputMsuPath  # if the outputMsuPath is provided use it as the msuDirPath

    print("[+] using db from %s" % (dbPath))
    conn = create_connection(dbPath)
    # createSqlTables(conn)

    # update CWE from cvedetails until 2019 (no data for 2020)
    if args.cweUpdate or args.cweUpdateAndExit:
        filePath = args.cweUpdatePath
        if filePath is None:
            filePath = os.path.join(get_project_base_dir(), "config", "windows_8_1_output.csv")
        if not os.path.exists(filePath):
            # cvedetails update values until 2019
            filePath = os.path.join(get_project_base_dir(), "config", "windows_8_1_output.csv")
            if not os.path.exists(filePath):
                print(
                    "[-] cannot find cwe file %s, if no cwe update is requiered please remove the -c or -C parameters...\r\nexiting" % filePath)
                exit()
        insertCWE(conn, filePath)
        print("[+] finish updating CWE data based on input file %s" % filePath)
        # if only cwe data update is requested, exit
        if args.cweUpdateAndExit:
            exit()

    try:
        begin_date = datetime.datetime.strptime(args.beginningDate, "%m/%d/%Y")
        end_date = datetime.datetime.strptime(args.endDate, "%m/%d/%Y")
    except Exception:
        print(
            "Failed to parse the format of begin date and end date, it in the format of %m/%d/%Y (full year - 4 digits )")
        exit()

    print(r"[+] run between the dates to run: %s-%s" % (str(begin_date), str(end_date)))
    end_month = end_date.month
    begin_month = begin_date.month
    year = begin_date.year
    end_year = end_date.year

    if args.verboseNotFound:  # print cve which no file was found as well (for result imporovement and research).
        verboseNotFound = True

    # get the current month
    cur_begin_month = getCurrentMonth(begin_month, year)
    cur_end_month = getCurrentMonth(end_month, end_year)
    monthDateFormetted = None
    start_month, start_day, start_year = cur_begin_month.split("/")
    end_month, end_day, end_year = cur_end_month.split("/")
    start_month_original = int(start_month)
    start_day = int(start_day)
    start_year = int(start_year)
    end_month = int(end_month)
    end_year = int(end_year)
    start_month = int(start_month)
    diffrentYears = False
    firstTime = True  # only generate msu output dir if its the first call to correlate function
    data = []
    while int(end_year) >= int(start_year):  # stop the loop when this is the final year
        resultMonthDict = {}  # empty the result dict every month
        foundPatchedFileCounter = 0  # monthly patched found files
        cve_set = set()  # cve_number list

        print("[+] result for OS:%s between: %s-%s" % (os_version, cur_begin_month, cur_end_month))
        if int(end_year) == int(start_year):
            if not diffrentYears:
                start_month = start_month_original
            while int(end_month) >= int(start_month):  # stop the loop when this is the final month
                monthDateFormetted = date(start_year, start_month, start_day).strftime("%Y-%b")
                cve_dict, cve_detailed_dict, bulletins = get_msrc_vulns_page_wrapper(monthDateFormetted, cve_set,
                                                                                     os_version)  # cur_begin_month, cur_end_month, 1, cve_set, os_version)monthDateFormetted)
                if bulletins is None:
                    print(f"[-] Failed to find bulletins for the date: {monthDateFormetted} skipping")
                else:
                    print("[+] add month %s" % monthDateFormetted)
                    resultDict = correlate(args, cve_dict, resultMonthDict, verboseNotFound, os_version, start_year,
                                           start_month, conn, resultDict, foundPatchedFileCounter, cve_set, bulletins,
                                           msuDirPath, firstTime)
                firstTime = False
                start_month += 1
            break
        else:  # not the same year, run on all months from start_month to december
            diffrentYears = True
            while int(start_month) < 13:
                monthDateFormetted = date(start_year, start_month, start_day).strftime("%Y-%b")
                cve_dict, cve_detailed_dict, bulletins = get_msrc_vulns_page_wrapper(monthDateFormetted, cve_set,
                                                                                     os_version)  # cur_begin_month, cur_end_month, 1, cve_set, os_version)monthDateFormetted)
                print("[+] add month %s" % monthDateFormetted)
                resultDict = correlate(args, cve_dict, resultMonthDict, verboseNotFound, os_version, start_year,
                                       start_month, conn, resultDict, foundPatchedFileCounter, cve_set, bulletins,
                                       msuDirPath, firstTime)
                firstTime = False
                start_month += 1
            start_year += 1
            start_month = 1

            # prepare for next month
        cve_detailed_dict = {}  # empty this dict every month
        begin_month += 1
        foundGood += len(resultMonthDict)
        totalFoundPatchedFileCounter += foundPatchedFileCounter
        totalOsCve += len(cve_set)

    # print results and add result to db table cve_patch_files
    printResults(resultDict, conn, os_version)
    if not foundGood == 0:
        print(
            "[+] found percent of patched file out of all founded which vulnerable component was extracted from cve:  %s\%s = %s%%" % (
            totalFoundPatchedFileCounter, foundGood, int(totalFoundPatchedFileCounter / float(foundGood) * 100)))
        print("[+] found percent of possible files found for cve:  %s\%s = %s%%" % (
        foundGood, totalOsCve, int(foundGood / float(totalOsCve) * 100)))
        print("[+] found percent of patched file out of all OS cve:  %s\%s = %s%%" % (
        totalFoundPatchedFileCounter, totalOsCve, int(totalFoundPatchedFileCounter / float(totalOsCve) * 100)))


if __name__ == '__main__':
    main()
