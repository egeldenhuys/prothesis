#-------------------------------------------------
#
# Project created by QtCreator 2015-10-21T14:39:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = button-list
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../src/tests.cpp \
    ../../src/user.cpp \
    button_list.cpp \
    coloured_button.cpp

HEADERS  += mainwindow.h \
    ../../src/globals.h \
    ../../src/tests.h \
    ../../src/user.h \
    button_list.h \
    coloured_button.h

FORMS    += mainwindow.ui
