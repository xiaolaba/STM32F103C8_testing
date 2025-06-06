
prompt xiaolaba_burn_STM32F103C8T6 $g$s
cls


st-flash.exe write STM32F103C8T6_Arduino_Hi_LCD1602.ino.bin 0x8000000


REM .\..\stlink-1.8.0-win32\bin\st-flash.exe write STM32F103C8T6_Arduino_Hi_LCD1602.ino.bin 0x8000000

::xiaolaba_burn.bat xiaolaba_STM32F103C8T6_blink_PC13.bin

pause