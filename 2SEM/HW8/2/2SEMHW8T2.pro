#-------------------------------------------------
#
# Project created by QtCreator 2014-05-08T17:39:06
#
#-------------------------------------------------

QT       += core gui
QT += webkit webkitwidgets
QT += core gui webkitwidgets xml

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2SEMHW8T2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bash.cpp

HEADERS  += mainwindow.h \
    bash.h

FORMS    += mainwindow.ui
