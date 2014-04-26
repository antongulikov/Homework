TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
QT += testlib
CONFIG += c++11

SOURCES += main.cpp \
    tree.cpp \
    node.cpp \
    plus.cpp \
    minus.cpp \
    multiply.cpp \
    divide.cpp \
    number.cpp \
    treetest.cpp

HEADERS += \
    tree.h \
    node.h \
    plus.h \
    minus.h \
    multiply.h \
    divide.h \
    number.h \
    treetest.h

