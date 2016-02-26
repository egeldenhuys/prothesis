Prothesis
=========

The [Target Life](http://www.targetlife.co.za/) Prothesis Software allows students to enter data regarding their career aptitude. Leaders can then analyse the data from the student using this same program and write them a career recommendation.

----

## Users
### Instructions
1. Download the latest release (v1.0.0) from the [releases](https://github.com/egeldenhuys/prothesis/releases)
2. Extract the archive
3. Run the program using the `Prothesis.cmd` file, 
or run `prothesis-gui.exe` in the `prothesis_files` folder

### User Data
The software stores the user data in `prothesis_files/User_Data.dat`

## Developers
### Setting up Development Environment (Windows 7 x64 Professional running in VirtualBox)

1. Install the VirtualBox Guest Additions including experimental Direct3D support. See [Qt Creator FAQ](http://doc.qt.io/qtcreator/creator-faq.html)
2. Disable 3D accelaration in VirtualBox if Qt Creator crashes on startup.
3. Download and install [qt-opensource-windows-x86-mingw492-5.5.0.exe](http://download.qt.io/archive/qt/5.5/5.5.0/)
4. [Set Up Git](https://help.github.com/articles/set-up-git/)
5. Clone this repository
6. Open the Qt Project in Qt Creator (`src/prothesis-gui/prothesis-gui.pro`)

### Deploying (Windows 7 x64 Professional running in VirtualBox)
1. Use the skeleton in `deploy`
2. Place the release version of `prothesis-gui.exe` in the `prothesis_files` folder
3. Run the Windows Deployment Tool. See [Qt for Windows - Deployment](http://doc.qt.io/qt-5/windows-deployment.html#the-windows-deployment-tool)

`windeployqt --release prothesis-gui.exe`

4. Copy the following files from `Qt/Qt5.5.0/Tools/mingw492_32/bin` to `prothesis_files`

```
libgcc_s_dw2-1.dll
linwinpthread-1.dll
libstdc++-6.dll
```

5. Confirm that everything works.
6. Test software on clean system without no development enviornment installed.

```
Example directory structure:
|-- Prothsis.cmd
|-- README.txt
|-- LICENSE
|-- prothesis_files/
|   |-- prothesis-gui.exe
|   |-- Qt5Core.dll
|   |-- ...etc
```
