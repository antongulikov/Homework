TEMPLATE = app

QT += testlib
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    queueexception.cpp \
    emptyqueueexception.cpp \
    queuetest.cpp \
    maxsizequeueexception.cpp

HEADERS += \
    priorityqueue.h \
    queueexception.h \
    emptyqueueexception.h \
    queuetest.h \
    maxsizequeueexception.h

