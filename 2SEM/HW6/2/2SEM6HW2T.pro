TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
QT += testlib
QMAKE_CXXFLAGS += -std=c++0x


SOURCES += main.cpp \
    uniquelist.cpp \
    listexception.cpp \
    duplicateexception.cpp \
    existexception.cpp \
    UniqueListTest.cpp \
    list.cpp \
    linlist.cpp

HEADERS += \
    uniquelist.h \
    listexception.h \
    duplicateexception.h \
    existexception.h \
    uniquelisttest.h \
    list.h \
    linlist.h

