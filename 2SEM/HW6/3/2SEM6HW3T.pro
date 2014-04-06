TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11
QT += testlib

SOURCES += main.cpp \
    sharedpointertest.cpp

HEADERS += \
    sharedpointer.h \
    sharedpointertest.h

