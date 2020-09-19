@echo off
cd %~dp0
echo ===========================================
echo.
echo          Simple RDR Trainer (360)
echo               Made by Connor
echo.
echo   https://github.com/connorms/RDR-Trainer
echo.
echo ===========================================
echo.
echo            Press any key to build
echo.
echo ===========================================
pause > nul
cls
"../lib/SC-CL/bin/SC-CL.exe" -platform=X360 -target="RDR_#SC" -out-dir="../bin/" -vcx="../src/Menu.vcxproj" -name="menu" -- -I "../include/"
pause