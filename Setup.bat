@echo off

:: Locate vswhere.exe
set VSWHERE="%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"

:: Use vswhere to find the latest VS installation and get its version
for /f "usebackq tokens=*" %%i in (`%VSWHERE% -latest -property catalog_productLineVersion`) do set VSVERSION=%%i

:: Map productLineVersion to Visual Studio year
if "%VSVERSION%"=="15" set VSYEAR=2017
if "%VSVERSION%"=="16" set VSYEAR=2019
if "%VSVERSION%"=="17" set VSYEAR=2022

echo Detected Visual Studio %VSVERSION%

if not "%VSVERSION%"=="" (
    call tools\premake5.exe vs%VSVERSION%
) else (
    echo Visual Studio not found. Please install Visual Studio or set VSWHERE path manually in this batch file.
)

pause