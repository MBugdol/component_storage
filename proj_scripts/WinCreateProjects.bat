echo off
CLS
cd ..
echo ---Creating Visual Studio 2022 project---
call vendor\premake5.exe vs2022
echo ---Creating Makefile---
call vendor\premake5.exe gmake2
cd proj_scripts
PAUSE