#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "hashtable.h"

/// class for hash table
class HashTableTest : public QObject
{
	Q_OBJECT
public:
	explicit HashTableTest(QObject *parent = 0);
	
private slots:

	void init(){
		myHashTable = new HashTable(10, 100);
	}
	
	void cleanup(){
		delete myHashTable;
	}
	
	void insertTest(){
		myHashTable->insert("123");
		QVERIFY(myHashTable->find("123"));
	}
	
	void findTest(){
		myHashTable->insert("23");
		QVERIFY(myHashTable->find("23"));
	}
	
	void eraseExistingElementTest(){
		myHashTable->insert("12");
		myHashTable->insert("123");
		myHashTable->erase("12");
		QVERIFY(!myHashTable->find("12"));
	}
	
	void eraseNotExistingElementTest(){
		myHashTable->insert("12");
		myHashTable->insert("123");
		myHashTable->erase("1234");
		QVERIFY(myHashTable->find("12") && myHashTable->find("123"));
	}
	
	void insertDoubleElement(){
		myHashTable->insert("1");
		myHashTable->insert("1");
		myHashTable->erase("1");
		QVERIFY(!myHashTable->find("1"));		
	} 
	
	void changeHashFunction(){
		myHashTable->insert("123");
		myHashTable->insert("1234");
		myHashTable->changeHashFunction(34, 345);
		QVERIFY(myHashTable->find("123") && myHashTable->find("1234"));
	}	

private:
	HashTable *myHashTable;	
};

