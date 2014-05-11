#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "List.h"

///
/// \brief The ListTest class
///

class ListTest : public QObject
{
    Q_OBJECT
private:
    List *list;
private slots:
    void init()
    {
        list = new List;
    }
    void addTest1Element()
    {
        list->add("one", 1);
        QVERIFY(list->getHead()->getStr() == "one");
        QVERIFY(list->getHead()->getElemCounter() == 1);        
    }
    
    void addTest2Elements()
    {
        list->add("one", 1);
        list->add("two", 2);
        QVERIFY(list->getHead()->getStr() == "one");
        QVERIFY(list->getHead()->getNext()->getStr() == "two");
        QVERIFY(list->getHead()->getElemCounter() == 1);
        QVERIFY(list->getHead()->getNext()->getElemCounter() == 2);        
    }
    
    void addTest3Elements()
    {
        list->add("one", 1);
        list->add("two", 2);
        list->add("three", 3);
        QVERIFY(list->getHead()->getStr() == "one");
        QVERIFY(list->getHead()->getNext()->getStr() == "two");
        QVERIFY(list->getTail()->getStr() == "three");
        QVERIFY(list->getHead()->getElemCounter() == 1);
        QVERIFY(list->getHead()->getNext()->getElemCounter() == 2);
        QVERIFY(list->getTail()->getElemCounter() == 3);
    }
    
    void isExistTest1Element()
    {
        list->add("one", 1);
        QVERIFY(list->exists("one") == true);        
    }    
    
    void isExistTest2Element()
    {
        list->add("one", 1);
        list->add("two", 2);
        QVERIFY(list->exists("one") == true);
        QVERIFY(list->exists("two") == true);        
    }

    void removeTest1Element()
    {
        list->add("one", 1);
        list->remove("one");
        QVERIFY(list->getSize() == 0);
    }
    
    void removeTest2Elements()
    {
        list->add("one", 1);
        list->add("two", 2);
        list->remove("two");
        list->remove("one");
        QVERIFY(list->getSize() == 0);
    }
    
    
    void cleanup()
    {
        delete list;
    }
};
