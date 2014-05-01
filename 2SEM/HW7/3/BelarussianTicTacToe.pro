#-------------------------------------------------
#
# Project created by QtCreator 2014-04-30T20:26:33
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BelarussianTicTacToe
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tictactoe.cpp \
    getsizedialog.cpp

HEADERS  += mainwindow.h \
    tictactoe.h \
    getsizedialog.h

FORMS    += mainwindow.ui \
    tictactoe.ui \
    getsizedialog.ui

OTHER_FILES +=
