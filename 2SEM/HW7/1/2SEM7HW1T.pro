TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11
QT += testlib

SOURCES += main.cpp \
    bag.cpp \
    bagtest.cpp

HEADERS += \
    bag.h \
    bagtest.h

