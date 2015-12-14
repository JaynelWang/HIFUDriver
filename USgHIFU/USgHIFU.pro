TEMPLATE = app

QT += qml quick widgets
QT += gui core
QT += sql

SOURCES += main.cpp \
    login.cpp \
    tablemodel.cpp \
    mainwindow.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    login.h \
    tablemodel.h \
    mainwindow.h

DISTFILES +=
