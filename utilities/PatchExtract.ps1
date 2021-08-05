<#
 ____     ______   ______  ____     __  __     
/\  _`\  /\  _  \ /\__  _\/\  _`\  /\ \/\ \    
\ \ \L\ \\ \ \L\ \\/_/\ \/\ \ \/\_\\ \ \_\ \   
 \ \ ,__/ \ \  __ \  \ \ \ \ \ \/_/_\ \  _  \  
  \ \ \/   \ \ \/\ \  \ \ \ \ \ \L\ \\ \ \ \ \ 
   \ \_\    \ \_\ \_\  \ \_\ \ \____/ \ \_\ \_\
    \/_/     \/_/\/_/   \/_/  \/___/   \/_/\/_/
                                               
                                               
 ____     __   __   ______  ____     ______   ____     ______   
/\  _`\  /\ \ /\ \ /\__  _\/\  _`\  /\  _  \ /\  _`\  /\__  _\  
\ \ \L\_\\ `\`\/'/'\/_/\ \/\ \ \L\ \\ \ \L\ \\ \ \/\_\\/_/\ \/  
 \ \  _\L `\/ > <     \ \ \ \ \ ,  / \ \  __ \\ \ \/_/_  \ \ \  
  \ \ \L\ \  \/'/\`\   \ \ \ \ \ \\ \ \ \ \/\ \\ \ \L\ \  \ \ \ 
   \ \____/  /\_\\ \_\  \ \_\ \ \_\ \_\\ \_\ \_\\ \____/   \ \_\
    \/___/   \/_/ \/_/   \/_/  \/_/\/ / \/_/\/_/ \/___/     \/_/
                                                                
                                                                
 __  __      _          __     
/\ \/\ \   /' \       /'__`\   
\ \ \ \ \ /\_, \     /\_\L\ \  
 \ \ \ \ \\/_/\ \    \/_/_\_<_ 
  \ \ \_/ \  \ \ \  __ /\ \L\ \
   \ `\___/   \ \_\/\_\\ \____/
    `\/__/     \/_/\/_/ \/___/ 
================
PATCHEXTRACT.PS1
=================
Version 1.3 Microsoft MSU Patch Extraction and Patch Organization Utility by Greg Linares (@Laughing_Mantis)
This Powershell script will extract a Microsoft MSU update file and then organize the output of extracted files and folders.
Organization of the output files is based on the patch's files and will organize them based on their archicture (x86, x64, or wow64)
as well as their content-type, ie: resource and catalog files will be moved to a JUNK subfolder and patch binaries and index files will 
goto a PATCH folder.
This script was developed in order to aid reverse engineers in quickly organizing patches so they can be binary diffed faster and easier. 
This was especially developed with the new bulk Microsoft Kernel patches in mind.
Example output folder structure ouput would be similar to this:
C:\PATCHES\MS15-XXX\PRE
    -x86
        - x86 Binary patched files
    -x64
        - x64 binary patched files
    -WOW64 
        - syswow64 binary patched files
    -JUNK
        - resource, catalog, mum, and other non-binary based patched files
    -PATCH
        - original patch, cabs and xml files from the extraction
    -MSIL 
        - MSIL .NET binary patched files ***New in Version 1.1***
    Directories will automagically be organized into filename-version to remove garbage filler folder names
        
        
=============
REQUIREMENTS
=============
'expand.exe' to be present in %WINDIR%\SYSTEM32 (it is by default) - It will execute this file @ the current users permissions
A valid Microsoft MSU patch file to extract (PATCH variable)
Directory and File write/creation permissions to the PATH folder specified
        
    
=======    
USAGE
=======
Powershell -ExecutionPolicy Bypass -File PatchExtract.ps1 -Patch C:\Patches\Windows6.1-KB3088195-x64.msu -Path C:\Patches\MS15-XXX\POST\ 
This would extract the patch file C:\Patches\Windows6.1-KB3088195-x64.msu to the folder C:\Patches\MS15-XXX\POST\.
It will then create all the sub organization folders within C:\Patches\MS15-XXX\POST\ folder.
(Note: the optional Powershell parameters '-ExecutionPolicy Bypass' is necessary in some environments to overcome Powershell execution restrictions)
==========
ARGUMENTS
==========
-PATCH <STRING:Filename> [REQUIRED] [NO DEFAULT]
    Specifies the MSU file that will be extracted to the specified PATH folder and then organized into the x86, x64, WOW, JUNK, and BIN folders specified
    Extract command will be "expand -F:* <PATCH> <PATH>"
    Non MSU files have not been tested however if the extraction does not generate a CAB file of the same name (indicator of successful extraction of MSU files)
    the script assumes extraction failed.
    
-PATH <STRING:FolderPath> [REQUIRED] [NO DEFAULT]
    Specified the folder that the PATCH file will be extracted and organized into
    If the specified folders does not exist yet, the user will be prompted if they want to create it.
    Relative paths '.\POST' can be used but it has not extensively been tested.
    ***New in Version 1.1***
    The -PATH variable may be now omitted to expand to current directory
    
-x86 <STRING:Foldername> [OPTIONAL] [DEFAULT='x86']
    Specifies the folder name within $PATH to store x86 patch binaries
    example: -x86 32bit
    
    
-x64 <STRING:Foldername> [OPTIONAL] [DEFAULT='x64']
    Specifies the folder name within $PATH to store x64 patch binaries
    example: -x64 64bit
    
-WOW <STRING:Foldername> [OPTIONAL] [DEFAULT='WOW64']
    Specifies the folder name within $PATH to store wow64 type patch binaries
    example: -WOW sysWOW64
-MSIL <STRING:Foldername> [OPTIONAL] [DEFAULT='MSIL']
    *** New in Version 1.1***
    Specifies the folder name within $PATH to store .NET type patch binaries
    example: -MSIL DOTNET
    
-JUNK <STRING:Foldername> [OPTIONAL] [DEFAULT='JUNK']
    Specifies the folder name within $PATH to store resource, catalog, and other generally useless for diffing patch binaries
    example: -JUNK res
    
    
-BIN <STRING:Foldername> [OPTIONAL] [DEFAULT='PATCH']
    Specifies the folder name within $PATH to store extraction xml and original patch msu and cab files
    example: -BIN bin
================
VERSION HISTORY
================
I originally wrote this as an ugly batch file sometime between 2014 and 2015 as a way to organize folders but it was incomplete and buggy
Oct 15, 2015 - Initial Public Release 1.0
Oct 20, 2016 - Version 1.1 Released
                * Bug fixes handling new naming format for patch .cab files
                * Added the ability to auto-extract to the same directory as current PATCH 
                * filtered output directory name format to aid in bindiffing
Oct 20, 2016 - Version 1.2 Released
                * Bug fixes handling MSIL renaming issues and collisions in renameing patch folders
Nov 7, 2016 - Version 1.25 Released
                * Added hack to handle subsequent CAB files Microsoft Added in Windows 10 Cumulative Patches - will make a better way to handle this in 1.3 
March 15, 2017 - Version 1.3 Released
                * Color Change to sweet vaporwave retro 80s colors
                * Cleaned up some awful code that I must have been on some amazing substances when I wrote
                * Spent several hours making a rad ASCII Logo
                * Most importantly fixed the Sub-cab auto-extraction method that Microsoft introduced late 2016
August 23, 2020 - Version 1.31 - Unofficial update by wumb0
                * Fixed extracting command (Start-Process -> iex). There's a bug in powershell that breaks Start-Process with arg lists that have literal quotes
                * Supressed output of expand.exe commands to cut down on script runtimes
==========
LICENSING
==========
This script is provided free as beer.  It probably has some bugs and coding issues, however if you like it or find it useful please give me a shout out on twitter @Laughing_Mantis.  
Feedback is encouraged and I will be likely releasing new scripts and tools and training in the future if it is welcome.
-GLin
#>




Param
(

    [Parameter(ValueFromPipelineByPropertyName = $true)]
    [ValidateNotNullOrEmpty()]
    [string]$PATCH = "",
    
    [Parameter(ValueFromPipelineByPropertyName = $true)]
    [string]$PATH = "",
    
    [Parameter(ValueFromPipelineByPropertyName = $true)]
    [string]$x86 = "x86",
    
    [Parameter(ValueFromPipelineByPropertyName = $true)]
    [string]$x64 = "x64",
    
    [Parameter(ValueFromPipelineByPropertyName = $true)]
    [string]$WOW = "WOW64",

    [Parameter(ValueFromPipelineByPropertyName = $true)]
    [string]$MSIL = "MSIL",
    
    [Parameter(ValueFromPipelineByPropertyName = $true)]
    [string]$JUNK = "JUNK",
    
    [Parameter(ValueFromPipelineByPropertyName = $true)]
    [string]$BIN = "PATCH"
        
)

Clear-Host
$ASCIIART = @"
 ____     ______   ______  ____     __  __     
/\  _`\  /\  _  \ /\__  _\/\  _`\  /\ \/\ \   
\ \ \L\ \\ \ \L\ \\/_/\ \/\ \ \/\_\\ \ \_\ \   
 \ \ ,__/ \ \  __ \  \ \ \ \ \ \/_/_\ \  _  \  
  \ \ \/   \ \ \/\ \  \ \ \ \ \ \L\ \\ \ \ \ \ 
   \ \_\    \ \_\ \_\  \ \_\ \ \____/ \ \_\ \_\
    \/_/     \/_/\/_/   \/_/  \/___/   \/_/\/_/
                                               
                                               
 ____     __   __   ______  ____     ______   ____     ______   
/\  _`\  /\ \ /\ \ /\__  _\/\  _`\  /\  _  \ /\  _`\  /\__  _\  
\ \ \L\_\\ `\`\/'/'\/_/\ \/\ \ \L\ \\ \ \L\ \\ \ \/\_\\/_/\ \/  
 \ \  _\L `\/ > <     \ \ \ \ \ ,  / \ \  __ \\ \ \/_/_  \ \ \  
  \ \ \L\ \  \/'/\`\   \ \ \ \ \ \\ \ \ \ \/\ \\ \ \L\ \  \ \ \ 
   \ \____/  /\_\\ \_\  \ \_\ \ \_\ \_\\ \_\ \_\\ \____/   \ \_\
    \/___/   \/_/ \/_/   \/_/  \/_/\/ / \/_/\/_/ \/___/     \/_/
                                                                
                                                                
 __  __      _          __     
/\ \/\ \   /' \       /'__`\   
\ \ \ \ \ /\_, \     /\_\L\ \  
 \ \ \ \ \\/_/\ \    \/_/_\_<_ 
  \ \ \_/ \  \ \ \  __ /\ \L\ \
   \ `\___/   \ \_\/\_\\ \____/
    `\/__/     \/_/\/_/ \/___/ 
"@

Write-Host $ASCIIART -ForegroundColor Magenta
Start-Sleep -s 3


if ($PATCH -eq "")
{
    Throw ("Error: No PATCH file specified.  Specify a valid Microsoft MSU Patch with the -PATCH argument")
   
}

if ((Split-Path $PATCH -Parent) -eq "")
{
    # First look in current working directory for the relative filename
    $CurrentDir = $(get-location).Path;
    $PATCH = $CurrentDir + "\" + $PATCH

    # if that doesnt work we look in the current script directory (less likely)
    # but hey we tried
    if (!(Test-Path $PATCH))
    {
        $scriptDir = Split-Path -Path $MyInvocation.MyCommand.Definition -Parent
        $PATCH = $scriptDir + "\" + $PATCH
    }
}

if (!(Test-Path $PATCH))
{
    Throw ("Error: Specified PATCH file ($PATCH) does not exist.  Specify a valid Microsoft MSU Patch file with the -PATCH argument.")
}

if ($PATH -eq "")
{
    $PATH = Split-Path $PATCH -Parent
    write-Host ("PATH = $PATH") -ForegroundColor White
    Write-Host ("No PATH folder specified.  Will extract to $PATH folder.") -ForegroundColor White
    
}

#Bug Fix (Resolve-Path Error if invalid path was specified before the path was created)




if (!($PATCH.ToUpper().EndsWith(".MSU")))
{
    Do 
    {
        $Attempt = Read-Host ("Warning: Specified PATCH file ($PATCH) is not a MSU file type. Do you still want to attempt extraction? [Y] or [N]")
    }
    Until ('Y', 'y', 'n', 'N' -ccontains $Attempt)
    if ($Attempt.ToUpper() -eq 'N')
    {
        Write-Host ("Exiting...") -ForegroundColor DarkMagenta
        Exit
    }
}

if (!(Test-Path $PATH))
{
    Do 
    {
        $Attempt = Read-Host ("Warning: Specified PATH folder ($PATH) does not exist. Do you want to create it? [Y] or [N]")
    }
    Until ('Y', 'y', 'n', 'N' -ccontains $Attempt)
    if ($Attempt.ToUpper() -eq 'N')
    {
        Write-Host ("Exiting...") -ForegroundColor DarkMagenta
        Exit
    }
    else
    {
        New-Item $PATH -Force -ItemType Directory
        Write-Host "Created $PATH Folder" -ForegroundColor Cyan
    }
}

$PATCH = Resolve-Path $PATCH
$PATH = Resolve-Path $PATH

Write-Host "Patch to Extract: $PATCH" -ForegroundColor Magenta
Write-Host "Extraction Path: $PATH" -ForegroundColor Magenta
Write-Host "x86 File Storage Folder Name: $x86" -ForegroundColor Magenta
Write-Host "x64 File Storage Folder Name: $x64" -ForegroundColor Magenta
Write-Host "WOW64 File Storage Folder Name: $WOW" -ForegroundColor Magenta
Write-Host "MSIL File Storage Folder Name: $MSIL" -ForegroundColor Magenta
Write-Host "Junk File Storage Folder Name: $JUNK" -ForegroundColor Magenta
Write-Host "Orignal Patch File Storage Folder Name: $BIN" -ForegroundColor Magenta



$PATCHx86 = Join-Path -path $PATH -ChildPath $x86
$PATCHx64 = Join-Path -path $PATH -ChildPath $x64
$PATCHWOW = Join-Path -path $PATH -ChildPath $WOW
$PATCHMSIL = Join-Path -path $PATH -ChildPath $MSIL
$PATCHJUNK = Join-Path -path $PATH -ChildPath $JUNK
$PATCHCAB = Join-Path -path $PATH -ChildPath $BIN


if (!(Test-Path $PATCHx86 -pathType Container))
{
    New-Item $PATCHx86 -Force -ItemType Directory
    Write-Host "Making $PATCHx86 Folder" -ForegroundColor Cyan
}

if (!(Test-Path $PATCHx64 -pathType Container))
{
    New-Item $PATCHx64 -Force -ItemType Directory
    Write-Host "Making $PATCHx64 Folder" -ForegroundColor Cyan
}

if (!(Test-Path $PATCHWOW -pathType Container))
{
    New-Item $PATCHWOW -Force -ItemType Directory
    Write-Host "Making $PATCHWOW Folder" -ForegroundColor Cyan
}

if (!(Test-Path $PATCHMSIL -pathType Container))
{
    New-Item $PATCHMSIL -Force -ItemType Directory
    Write-Host "Making $PATCHMSIL Folder" -ForegroundColor Cyan
}

if (!(Test-Path $PATCHJUNK -pathType Container))
{
    New-Item $PATCHJUNK -Force -ItemType Directory
    Write-Host "Making $PATCHJUNK Folder" -ForegroundColor Cyan
}

if (!(Test-Path $PATCHCAB -pathType Container))
{
    New-Item $PATCHCAB -Force -ItemType Directory
    Write-Host "Making $PATCHCAB Folder" -ForegroundColor Cyan
}


$SYSPATH = Join-Path -path (get-item env:\windir).Value -ChildPath "system32"

$EXPAND = Join-Path -path $SYSPATH -ChildPath "expand.exe"


if (!(Test-Path $EXPAND))
{
    Throw ("Error: Cannot find 'Expand.exe' in the $SYSPATH folder.")
} 

$ARG = '-F:* ' + '"' + $PATCH + '" ' + '"' + $PATH + '"'

Write-Host "Executing the following command: $EXPAND $ARG" -ForegroundColor Cyan

# https://github.com/PowerShell/PowerShell/issues/5576
iex("$EXPAND $ARG | Out-Null") | Out-Null

$CABS = Get-Childitem -Path $PATH -Filter *.cab
foreach ($CAB in $CABS)
{
    Write-Host "CAB File: $CAB" -ForegroundColor White
    if (!($CAB.Name -eq "WSUSSCAN.cab"))
    {
        $CAB = Join-Path -path $PATH -ChildPath $CAB
        Write-Host "Main-Cab: $CAB" -ForegroundColor Magenta
        if (Test-Path $CAB)
        {
            $ARG = '-F:* ' + '"' + $CAB + '" ' + '"' + $PATH + '"'
            Write-Host "Executing the following command: $EXPAND $ARG" -ForegroundColor Cyan
            iex("$EXPAND $ARG | Out-Null") | Out-Null
            Write-Host "Moving $CAB to $PATCHCAB" -ForegroundColor Magenta
            Move-Item $CAB $PATCHCAB -Force -ErrorAction SilentlyContinue
        }
        else
        {
            Throw "Error: Patch .CAB File [$CAB] could not be located.  Patch Extraction failed - please send notification of this error to @Laughing_Mantis."
        }
    }
    else
    {
        Write-Host "Moving $CAB to $PATCHCAB" -ForegroundColor Magenta
        Move-Item $CAB $PATCHCAB -Force -ErrorAction SilentlyContinue
    }
}

#Now for subcabs we do it again
$CABS = Get-Childitem -Path $PATH -Filter *.cab
foreach ($CAB in $CABS)
{
    if (!($CAB.Name -eq "WSUSSCAN.cab"))
    {
        $CAB =  Join-Path -path $PATH -ChildPath $CAB
        Write-Host "Sub-Cab: $CAB" -ForegroundColor Magenta
        if (Test-Path $CAB)
        {
            $ARG = '-F:* ' + '"' + $CAB + '" ' + '"' + $PATH + '"'
            Write-Host "Executing the following command: $EXPAND $ARG" -ForegroundColor Cyan
            iex("$EXPAND $ARG | Out-Null") | Out-Null
            Write-Host "Moving $CAB to $PATCHCAB" -ForegroundColor Magenta
            Move-Item $CAB $PATCHCAB -Force -ErrorAction SilentlyContinue
        }
        else
        {
            Throw "Error: Patch .CAB File [$CAB] could not be located.  Patch Extraction failed - please send notification of this error to @Laughing_Mantis."
        }
    }
}

$PATCHFolders = Get-ChildItem -Path $PATH -Force -ErrorAction SilentlyContinue | where {$_.Attributes -eq 'Directory'}

foreach ($folder in $PATCHFolders)
{
    if ($folder.Name.Contains(".resources_"))
    {
        Move-Item $folder.FullName $PATCHJUNK -Force
        Write-Host "Moving $folder to $PATCHJUNK" -ForegroundColor Cyan
        Continue
    }
    else
    {
        if ($folder.Name.StartsWith("x86_"))
        {
            Move-Item $folder.FullName $PATCHx86 -Force
            Write-Host "Moving $folder to $PATCHx86" -ForegroundColor Cyan
            Continue
        }
        
        if ($folder.Name.StartsWith("amd64_"))
        {
            Move-Item $folder.FullName $PATCHx64 -Force
            Write-Host "Moving $folder to $PATCHx64" -ForegroundColor Cyan
            Continue
        }
        
        if ($folder.Name.StartsWith("wow64_"))
        {
            Move-Item $folder.FullName $PATCHWOW -Force
            Write-Host "Moving $folder to $PATCHWOW" -ForegroundColor Cyan
            Continue
        }

        if ($folder.Name.StartsWith("msil_"))
        {
            Move-Item $folder.FullName $PATCHMSIL -Force
            Write-Host "Moving $folder to $PATCHMSIL" -ForegroundColor Cyan
            Continue
        }
    }
}

<# PRETTY BINDIFF OUTPUT - changes folder names from x86-microsoft-windows-filename-hash-version-garbage to filename-version #>

$PATCHFolders = Get-ChildItem -Path $PATCHx86 -Force -ErrorAction SilentlyContinue | where {$_.Attributes -eq 'Directory'}

foreach ($folder in $PATCHFolders)
{
    if ($folder -like "x86_microsoft-windows-*")
    {
        $newfolder = $folder.Name.Replace("x86_microsoft-windows-", "")
        $newname = $newfolder.Split("_")[0]
        $version = $newfolder.Split("_")[2]
        $newname = $newname + "_" + $version
        Write-Host ("Renaming $folder to $newname") -ForegroundColor Magenta
        Rename-Item -path $folder.FullName -newName ($newname)
    }
    elseif ($folder -like "x86_*")
    {
        $newfolder = $folder.Name.Replace("x86_", "")
        $newname = $newfolder.Split("_")[0]
        $version = $newfolder.Split("_")[2]
        $newname = $newname + "_" + $version
        Write-Host ("Renaming $folder to $newname") -ForegroundColor Cyan
        Rename-Item -path $folder.FullName -newName ($newname)
    }
}

$PATCHFolders = Get-ChildItem -Path $PATCHx64 -Force -ErrorAction SilentlyContinue | where {$_.Attributes -eq 'Directory'}

foreach ($folder in $PATCHFolders)
{
    if ($folder -like "amd64_microsoft-windows-*")
    {
        $newfolder = $folder.Name.Replace("amd64_microsoft-windows-", "")
        $newname = $newfolder.Split("_")[0]
        $version = $newfolder.Split("_")[2]
        $newname = $newname + "_" + $version
        Write-Host ("Renaming $folder to $newname") -ForegroundColor Magenta
        Rename-Item -path $folder.FullName -newName ($newname)
    }
    elseif ($folder -like "amd64_*")
    {
        $newfolder = $folder.Name.Replace("amd64_", "")
        $newname = $newfolder.Split("_")[0]
        $version = $newfolder.Split("_")[2]
        $newname = $newname + "_" + $version
        Write-Host ("Renaming $folder to $newname") -ForegroundColor Cyan
        Rename-Item -path $folder.FullName -newName ($newname)
    }
}

$PATCHFolders = Get-ChildItem -Path $PATCHWOW -Force -ErrorAction SilentlyContinue | where {$_.Attributes -eq 'Directory'}

foreach ($folder in $PATCHFolders)
{
    if ($folder -like "wow64_microsoft-windows-*")
    {
        $newfolder = $folder.Name.Replace("wow64_microsoft-windows-", "")
        $newname = $newfolder.Split("_")[0]
        $version = $newfolder.Split("_")[2]
        $newname = $newname + "_" + $version
        Write-Host ("Renaming $folder to $newname") -ForegroundColor Magenta
        Rename-Item -path $folder.FullName -newName ($newname)
    }
    elseif ($folder -like "wow64_*")
    {
        $newfolder = $folder.Name.Replace("wow64_", "")
        $newname = $newfolder.Split("_")[0]
        $version = $newfolder.Split("_")[2]
        $newname = $newname + "_" + $version
        Write-Host ("Renaming $folder to $newname") -ForegroundColor Cyan
        Rename-Item -path $folder.FullName -newName ($newname)
    }
}

$PATCHFolders = Get-ChildItem -Path $PATCHMSIL -Force -ErrorAction SilentlyContinue | where {$_.Attributes -eq 'Directory'}

foreach ($folder in $PATCHFolders)
{
    if ($folder -like "msil_*")
    {
        $newfolder = $folder.Name.Replace("msil_", "")
        $newname = $newfolder.Split("_")[0]
        $version = $newfolder.Split("_")[2]
        $newname = $newname + "_" + $version
        Write-Host ("Renaming $folder to $newname") -ForegroundColor Cyan
        Rename-Item -path $folder.FullName -newName ($newname)
    }

}

$Junkfiles = Get-ChildItem -Path $PATH -Force -ErrorAction SilentlyContinue


foreach ($JunkFile in $Junkfiles)
{
    
    try
    {
        if (($JunkFile.Name.EndsWith(".manifest")) -or ($JunkFile.Name.EndsWith(".cat")) -or ($JunkFile.Name.EndsWith(".mum")))
        {
            Move-Item $JunkFile.FullName $PATCHJUNK -Force -ErrorAction SilentlyContinue
            Write-Host "Moving $JunkFile to $PATCHJUNK" -ForegroundColor Magenta
            Continue
        }
        
        if (($JunkFile.Name.EndsWith(".cab")) -or ($JunkFile.Name.EndsWith(".xml")) -or ($JunkFile.Name.EndsWith(".msu")) -or ($JunkFile.Name.EndsWith("pkgProperties.txt")))
        {
            Move-Item $JunkFile.FullName $PATCHCAB -Force -ErrorAction SilentlyContinue
            Write-Host "Moving $JunkFile to $PATCHCAB" -ForegroundColor Cyan
            Continue
        }
        if ($JunkFile.Name -eq "patch")
        {
            Move-Item $JunkFile.FullName $PATCHCAB -Force -ErrorAction SilentlyContinue
            Write-Host "Moving $JunkFile to $PATCHCAB" -ForegroundColor Magenta
            Continue
        }
    }
    catch
    {
        Write-Host "Error Processing ($JunkFile.Fullname)" -ForegroundColor DarkMagenta
    }
}