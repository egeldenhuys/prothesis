Prothesis
=========

[Target Life](http://www.targetlife.co.za/) Prothesis Software

### Setting up Development Environment (Windows 7 x64 Professional running in VirtualBox)

1. Install the VirtualBox Guest Additions including experimental Direct3D support. See [Qt Creator FAQ](http://doc.qt.io/qtcreator/creator-faq.html)
2. Disable 3D accelaration in VirtualBox if Qt Creator crashes on startup.
3. Download and install [qt-opensource-windows-x86-mingw492-5.5.0.exe](http://download.qt.io/archive/qt/5.5/5.5.0/)
4. [Set Up Git](https://help.github.com/articles/set-up-git/)
5. Clone this repository
6. Open the Qt Project in Qt Creator (src/prothesis-gui/prothesis-gui.pro)

### Deploying (Windows 7 x64 Professional running in VirtualBox)
1. Run the Windows Deployment Tool. See [Qt for Windows - Deployment](http://doc.qt.io/qt-5/windows-deployment.html#the-windows-deployment-tool)
2. Copy the following .dll files from `Qt/Qt5.5.0/Tools/mingw492_32/bin`: `libgcc_s_dw2-1.dll, linwinpthread-1.dll, libstdc++-6.dll` into the `prothesis-gui.exe` working directory
3. Confirm that everything works.
4. Test software on clean system without no development enviornment installed.
5. Place `prothesis.gui.exe` and the required dependencies in a folder named `prothesis`
6. Create `RUN.cmd` with the following line: `start "" prothesis\prothesis-gui.exe`. Place it outside the `prothesis` directory.
```
Example:
|-- RUN.cmd
|-- prothesis/
|   |-- prothesis-gui.exe
|   |-- Qt5Core.dll
|   |-- ...etc
```
