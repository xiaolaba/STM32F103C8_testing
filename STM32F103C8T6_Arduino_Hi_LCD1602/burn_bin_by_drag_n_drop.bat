.echo off

prompt xiaolaba_burn_STM32F103C8T6 $g$s


set driverLetter=%~dp0
set driverLetter=%driverLetter:~0,2%
%driverLetter%
cd %~dp0
rem: the two line below are needed to fix path issues with incorrect slashes before the bin file name
set str=%1
set str=%str:/=\%


rem: ------------- use STLINK CLI
rem stlink\ST-LINK_CLI.exe -c SWD -P %str% 0x8000000 -Rst -Run -NoPrompt

rem: Using the open source https://github.com/stlink-org/stlink instead of the proprietary STM stlink exe
::st-flash.exe write %str% 0x8000000

cls


rem stlink-1.8.0-win32\bin\st-flash.exe write %1% 0x8000000

st-flash.exe write %1% 0x8000000


pause
::cmd