@ECHO OFF
IF NOT exist prothesis_files\ ( echo The folder "prothesis_files" seems to be missing and is required for this software to work)
cd prothesis_files/
start "" prothesis-gui.exe