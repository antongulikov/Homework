#-------------------------------------------------
#
# Project created by QtCreator 2014-12-21T22:12:15
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Network
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    os.cpp \
    computer.cpp \
    network.cpp \
    netwroktest.cpp

HEADERS  += mainwindow.h \
    os.h \
    computer.h \
    network.h \
    netwroktest.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    in.txt
