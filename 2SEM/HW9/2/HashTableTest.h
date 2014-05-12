#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "HashTable.h"
#include "HashFunction.h"


/// Class for HashTableTest
class HashTableTest : public QObject
{
    Q_OBJECT
private:
    HashTable *table;
    HashFunction *shash;
    HashFunction *xhash;
    static const unsigned int size = 100;
private slots:

    void init()
    {
        shash = new SumHash;
        xhash = new XorHash;
        table = new HashTable(size, shash);
    }
    
    void addTest1Element()
    {
        table->add("one", 1);
        unsigned int key1 = table->getHash()->hash("one") % table->getHTsize();
        QVERIFY(table->getTableElement(key1)->getHead()->getStr() == "one");        
    }
    
    void addTest2Elements()
    {
        table->add("one", 1);
        unsigned int key1 = table->getHash()->hash("one") % table->getHTsize();
        QVERIFY(table->getTableElement(key1)->getHead()->getStr() == "one");
        table->add("two", 1);
        unsigned int key2 = table->getHash()->hash("two") % table->getHTsize();
        QVERIFY(table->getTableElement(key2)->getHead()->getStr() == "two");        
    }
    
    void isExistTest1Element()
    {
        table->add("one", 1);
        QVERIFY(table->isExist("one") == true);        
    }
    
    void isExistTest2Element()
    {
        table->add("one", 1);
        table->add("two", 1);        
        QVERIFY(table->isExist("one") == true);
        QVERIFY(table->isExist("two") == true);        
    }

    
    
    void rebuildTableTest()
    {
        table->add("one", 1);
        table->add("two", 1);
        table->add("three", 1);
        unsigned int oldkey1 = table->getHash()->hash("one") % table->getHTsize();
        unsigned int oldkey2 = table->getHash()->hash("two") % table->getHTsize();
        unsigned int oldkey3 = table->getHash()->hash("three") % table->getHTsize();
        
        table->rebuildTable(100, xhash);
        unsigned int key1 = table->getHash()->hash("one") % table->getHTsize();
        QVERIFY(table->getTableElement(key1)->getHead()->getStr() == "one");
        unsigned int key2 = table->getHash()->hash("two") % table->getHTsize();
        QVERIFY(table->getTableElement(key2)->getHead()->getStr() == "two");
        unsigned int key3 = table->getHash()->hash("three") % table->getHTsize();
        QVERIFY(table->getTableElement(key3)->getHead()->getStr() == "three");
        QVERIFY((key1 != oldkey1 || key2 != oldkey2 || key3 != oldkey3) == true);
    }
    
    void removeTest()
    {
        table->add("one", 1);
        table->add("two", 1);
        table->add("three", 1);
        unsigned int key1 = table->getHash()->hash("one") % table->getHTsize();
        unsigned int key2 = table->getHash()->hash("two") % table->getHTsize();
        unsigned int key3 = table->getHash()->hash("three") % table->getHTsize();
        try
        {
            table->remove("one");
            QVERIFY(table->getTableElement(key1)->isEmpty() == true);
            table->remove("two");
            QVERIFY(table->getTableElement(key2)->isEmpty() == true);
            table->remove("three");
            QVERIFY(table->getTableElement(key3)->isEmpty() == true);
            table->remove("1");
        }
        catch (string exc)
        {
            QVERIFY(exc == "No such word");
        }
    }
    
    void removeTest1Element()
    {
        table->add("one", 1);
        unsigned int key1 = table->getHash()->hash("one") % table->getHTsize();
        try
        {
            table->remove("one");
            QVERIFY(table->getTableElement(key1)->isEmpty() == true);
        }
        catch (string exc)
        {
            QVERIFY(exc == "No such word");
        }
    }
    
    void removeTestNonExistsElement()
    {
        table->add("one", 1);
        try
        {
            table->remove("1");
        }
        catch (string exc)
        {
            QVERIFY(exc == "No such word");
        }
    }
    
    void cleanup()
    {
        delete table;
        delete shash;
        delete xhash;
    }
};
