#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "List.h"

/// Tests for List

class ListTest : public QObject
{
    Q_OBJECT
public:
	explicit ListTest(QObject *parent = 0): QObject(parent)
	{
	}

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
        QVERIFY(list->getSize() == 1);
    }
    
    void addTest2Elements()
    {
        list->add("one", 1);
        list->add("two", 2);
        QVERIFY(list->getSize() == 2);
    }
    
    
    void isExistTest()
    {
        list->add("one", 1);
        QVERIFY(list->exists("one") == true);        
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
        list->remove("one");
        QVERIFY(list->getSize() == 1);
        list->remove("two");
        QVERIFY(list->getSize() == 0);
    }
    
    
    void cleanup()
    {
        delete list;
    }
};
