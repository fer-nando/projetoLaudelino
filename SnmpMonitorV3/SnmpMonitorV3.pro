#-------------------------------------------------
#
# Project created by QtCreator 2011-09-03T19:49:19
#
#-------------------------------------------------

QT       += core gui
QT       += sql

TARGET = SnmpMonitorV3
TEMPLATE = app

qtAddLibrary(qwt)

SOURCES += main.cpp\
        mainwindow.cpp \
    device.cpp \
    interface.cpp \
    management.cpp \
    link.cpp \
    linkwindow.cpp \
    devicewindow.cpp \
    dbthread.cpp \
    graphwindow.cpp

HEADERS  += mainwindow.h \
    device.h \
    interface.h \
    management.h \
    link.h \
    linkwindow.h \
    devicewindow.h \
    dbthread.h \
    graphwindow.h

FORMS    += mainwindow.ui \
    linkwindow.ui \
    devicewindow.ui \
    graphwindow.ui
