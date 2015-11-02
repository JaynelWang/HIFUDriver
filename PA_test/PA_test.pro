#-------------------------------------------------
#
# Project created by QtCreator 2015-10-26T20:26:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PA_test
TEMPLATE = app

INCLUDEPATH += ../lib/common\
               ../lib/PA

LIBS += ../bin/PowerAmp.dll

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h
