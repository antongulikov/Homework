TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    writer.cpp \
    consolewriter.cpp \
    filewriter.cpp

HEADERS += \
    writer.h \
    consolewriter.h \
    filewriter.h

