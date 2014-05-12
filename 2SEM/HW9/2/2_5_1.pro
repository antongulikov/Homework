TEMPLATE = app
QT += testlib
CONFIG += console;


SOURCES += main.cpp \
    HashTable.cpp \
    HashFunction.cpp \
    List.cpp \
    HashTableManager.cpp

HEADERS += \
    HashTable.h \
    HashFunction.h \
    ListElement.h \
    List.h \
    ListTest.h \
    HashTableTest.h \
    HashTableManager.h

