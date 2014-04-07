#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "bag.h"

/// Tests for Bag
class BagTest : public QObject
{
	Q_OBJECT
public:
	explicit BagTest(QObject *parent = 0);
	
private slots:

	void init(){
		myBag = new Bag;	
	}
	
	void cleanup(){
		delete myBag;	
	}
	
	void insertTest(){
		myBag->insert(42);
		QVERIFY(myBag->find(42) && myBag->getSize() == 1);	
	}
	
	void eraseTest(){
		myBag->insert(43);	
		myBag->insert(42);
		myBag->erase(43);
		QVERIFY(myBag->find(42) && myBag->getSize() == 1);
	}
	
	void insertTwoEqualElementsTest(){
		myBag->insert(42);
		myBag->insert(42);
		QVERIFY(myBag->find(42) && myBag->getSize() == 2);		
	}
	
	void eraseOneOfTwoEqualElementsTest(){
		myBag->insert(42);
		myBag->insert(43);
		myBag->insert(42);
		myBag->erase(42);
		QCOMPARE(myBag->getSize(), 2);
		QVERIFY(myBag->find(42) && myBag->find(43));
	}
	
	void getSizeTest(){
		myBag->insert(42);
		myBag->insert(42);
		myBag->insert(43);
		QVERIFY(myBag->getSize() == 3);	
	}	

private:
	Bag *myBag;		
};

