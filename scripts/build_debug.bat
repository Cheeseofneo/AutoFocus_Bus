@echo off
title qmake and nmake build prompt
set MINGW_PATH=D:\Qt\Tools\mingw1120_64
set QT_DIR=D:\Qt\6.6.3\mingw_64
set BUILD_DIR=%cd%\build
set PRO_DIR=%cd%
set PATH=%MINGW_PATH%\bin;%QT_DIR%\bin;%PATH%

if not exist %BUILD_DIR% (
    md %BUILD_DIR%
)

cd build
qmake.exe %PRO_DIR%\ModbusMaster.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=console" 
if exist %BUILD_DIR%\debug\ModbusMaster.exe del %BUILD_DIR%\debug\ModbusMaster.exe 
@REM c:\Qt\Tools\QtCreator\bin\jom.exe -j4
%MINGW_PATH%\bin\mingw32-make -f Makefile.Debug 
cd debug
if not exist %BUILD_DIR%\debug\Qt5Core.dll (
    windeployqt ModbusMaster.exe
)