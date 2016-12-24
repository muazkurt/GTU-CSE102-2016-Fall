@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvarsall.bat" x64
cl.exe HW8_2_MUAZ_KURT.c
start HW8_2_MUAZ_KURT.exe
exit