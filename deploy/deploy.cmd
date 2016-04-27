@ECHO OFF

REM TODO: qmake
mkdir prothesis-release\prothesis_files\

COPY ..\src\build-prothesis-gui-Desktop_Qt_5_5_0_MinGW_32bit-Release\release\prothesis-gui.exe prothesis-release\prothesis_files\

COPY ..\CHANGELOG.md prothesis-release\

REM TODO: Get system var instead of hard link
cd prothesis-release\prothesis_files\
E:\Qt\Qt5.5.0\5.5\mingw492_32\bin\windeployqt --release --force --compiler-runtime prothesis-gui.exe
COPY E:\Qt\Qt5.5.0\5.5\mingw492_32\bin\libgcc_s_dw2-1.dll .
COPY E:\Qt\Qt5.5.0\5.5\mingw492_32\bin\libwinpthread-1.dll .
COPY "E:\Qt\Qt5.5.0\5.5\mingw492_32\bin\libstdc++-6.dll" .

cd ..\..\