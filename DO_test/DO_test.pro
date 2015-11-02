#-------------------------------------------------
#
# Project created by QtCreator 2015-10-26T15:17:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DO_test
TEMPLATE = app

INCLUDEPATH += ../lib/common\
               ../lib/DO

LIBS += ../bin/DOController.dll


SOURCES += main.cpp\
        mainwindow.cpp \

HEADERS  += mainwindow.h \
