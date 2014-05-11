#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "List.h"

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
    void addTest()
    {
        list->add("one", 1);
        list->add("two", 2);
        list->add("three", 3);
        QVERIFY(list->head->str == "one");
        QVERIFY(list->head->next->str == "two");
        QVERIFY(list->tail->str == "three");
        QVERIFY(list->head->elemCounter == 1);
        QVERIFY(list->head->next->elemCounter == 2);
        QVERIFY(list->tail->elemCounter == 3);
    }
    void isExistTest()
    {
        list->add("one", 1);
        list->add("two", 2);
        list->add("three", 3);
        QVERIFY(list->exists("one") == true);
        QVERIFY(list->exists("two") == true);
        QVERIFY(list->exists("three") == true);
    }

    void removeTest()
    {
        list->add("one", 1);
        list->add("two", 2);
        list->add("three", 3);
        list->remove("one");
        QVERIFY(list->head->str == "two");
        QVERIFY(list->head->prev == NULL);
        QVERIFY(list->size == 2);
        list->remove("two");
        QVERIFY(list->head->str == "three");
        QVERIFY(list->head->prev == NULL);
        QVERIFY(list->head->next == NULL);
        QVERIFY(list->head == list->tail);
        QVERIFY(list->size == 1);
        list->remove("three");
        QVERIFY(list->size == 0);
    }
    void cleanup()
    {
        delete list;
    }
};
