#-------------------------------------------------
#
# Project created by QtCreator 2014-05-26T22:07:33
#
#-------------------------------------------------

QT       += core gui
QT		 += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ServerGun
TEMPLATE = app


SOURCES += \
    gameboard.cpp \
    main.cpp \
    weapons.cpp

HEADERS  += \
    gameboard.h \
    weapons.h

FORMS    += \
    gameboard.ui

OTHER_FILES += \
    moon.png
