#-------------------------------------------------
#
# Project created by QtCreator 2014-03-15T16:48:37
#
#-------------------------------------------------

QT       += core gui

QT		 += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SEM2HW3T2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp \
    calculatortest.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    calculatortest.h

FORMS    += mainwindow.ui
