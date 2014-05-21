TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
QT += testlib

SOURCES += main.cpp \
    stringcomporator.cpp \
    sorter.cpp \
    intcomporator.cpp \
    sorterttest.cpp \
    floatcomparator.cpp

HEADERS += \
    commoncomporator.h \
    stringcomporator.h \
    sorter.h \
    intcomporator.h \
    sorterttest.h \
    floatcomparator.h

