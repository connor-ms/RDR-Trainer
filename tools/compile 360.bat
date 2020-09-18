@echo off
cd %~dp0
:start
echo SC-CL menu.c
echo Press ENTER to launch
pause > nul
cls
"../../bin/SC-CL.exe" -platform=X360 -target="RDR_#SC" -out-dir="D:/script dev/bin/" -vcx="Menu.vcxproj" -- -I "../../include/"
goto start