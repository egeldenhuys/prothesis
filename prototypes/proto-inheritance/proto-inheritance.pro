#-------------------------------------------------
#
# Project created by QtCreator 2016-02-24T16:15:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proto-inheritance
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    countbox.cpp \
    countboxmanager.cpp

HEADERS  += mainwindow.h \
    countbox.h \
    countboxmanager.h

FORMS    += mainwindow.ui

CONFIG += c++11