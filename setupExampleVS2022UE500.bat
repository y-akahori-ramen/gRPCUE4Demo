@echo off

pushd %~dp0
setlocal
set UE_ROOT=C:\Program Files\Epic Games\UE_5.0
set CMAKE_GENERATOR=Visual Studio 17 2022

.\setup.bat

endlocal
popd