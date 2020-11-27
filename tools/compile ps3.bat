@echo off
cd %~dp0
echo ===========================================
echo.
echo          Simple RDR Trainer (PS3)
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
if exist "../lib/SC-CL/bin/SC-CL.exe" (
    "../lib/SC-CL/bin/SC-CL.exe" -platform=PS3 -target="RDR_#SC" -out-dir="../bin/" -vcx="../src/Menu.vcxproj" -name="menu" -- -I "../include/"
) else (
    echo Error: SC-CL not found! Make sure to include submodules when cloning.
    echo        You can do this by going to the root folder and running the following 2 commands:
    echo          - git submodule init
    echo          - git submodule update
    echo.
)
pause