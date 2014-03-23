QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle


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

