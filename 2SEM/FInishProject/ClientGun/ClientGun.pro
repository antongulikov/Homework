QT       += core gui
QT		 += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClientGun
TEMPLATE = app

SOURCES += \
    main.cpp \
    gameboard.cpp \
    weapons.cpp

HEADERS += \
    gameboard.h \
    weapons.h

FORMS += \
    gameboard.ui
