QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle


SOURCES += \
	main.cpp \
	calculator.cpp \
    teststack.cpp

HEADERS += \
	stack.h \
	arraystack.h \
	linstack.h \
	calculator.h \
    teststack.h

