#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T19:59:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prothesis-gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../tests.cpp \
    ../user.cpp \
    button_list.cpp \
    ColouredButton.cpp

HEADERS  += mainwindow.h \
    ../globals.h \
    ../tests.h \
    ../user.h \
    button_list.h \
    ColouredButton.h

FORMS    += mainwindow.ui

CONFIG += c++11
