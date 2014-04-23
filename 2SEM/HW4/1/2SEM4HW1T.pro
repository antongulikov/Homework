TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
QT += testlib


SOURCES += main.cpp \
    hashfunction.cpp \
    hashtable.cpp \
    hashfunctiontest.cpp \
    hashtabletest.cpp

HEADERS += \
    hashfunction.h \
    hashtable.h \
    hashfunctiontest.h \
    hashtabletest.h

