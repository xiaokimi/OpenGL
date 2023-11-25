@echo off

set SOURCE_DIR=%~dp0

set BUILD_DIR=build
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

set BUILD_PLATFORM=x64

set GENERATOR="Visual Studio 17 2022"

cmake -B %BUILD_DIR% ^
    -G %GENERATOR% ^
    -A %BUILD_PLATFORM% ^
    -S %SOURCE_DIR%

pause