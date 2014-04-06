QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11


SOURCES += main.cpp \
    writer.cpp \
    consolewriter.cpp \
    filewriter.cpp \
    testwriter.cpp

HEADERS += \
    writer.h \
    consolewriter.h \
    filewriter.h \
    testwriter.h

