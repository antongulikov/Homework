#-------------------------------------------------
#
# Project created by QtCreator 2014-03-22T18:33:45
#
#-------------------------------------------------

QT       += core gui

QT		 += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2SEM3HWT3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp \
    calculatortest.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    stack.h \
    arraystack.h \
    linstack.h \
    calculatortest.h

FORMS    += mainwindow.ui
