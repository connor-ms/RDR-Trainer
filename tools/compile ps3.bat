@echo off
cd %~dp0
cls
"../../bin/SC-CL.exe" -platform=PS3 -target="RDR_#SC" -out-dir="D:/RDR/scripting/bin/" -vcx="Menu.vcxproj" -- -I "../../include/"
pause