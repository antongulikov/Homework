#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "sharedpointer.h"
#include <iostream>

/// Tests for shared_ptr
class SharedPointerTest : public QObject
{
	Q_OBJECT
public:
	explicit SharedPointerTest(QObject *parent = 0);
	
private slots:	

	void deleteTest(){
		SharedPointer<int> *mySharedPointer = new SharedPointer<int>(new int(value));
		SharedPointer<int> *tmpPointer = new SharedPointer<int>(*mySharedPointer);
		int size = tmpPointer->getCount();
		delete tmpPointer;
		QVERIFY((mySharedPointer->getCount() + 1) == size);
		delete mySharedPointer;
	}
		
	void givingTest(){
		SharedPointer<int> mySharedPointer;
		SharedPointer<int> tmpPointer(new int(value + 1));
		mySharedPointer = tmpPointer;
		QCOMPARE(*(tmpPointer.getPointer()), *(mySharedPointer.getPointer()));
		QCOMPARE(tmpPointer.getPointer(), mySharedPointer.getPointer());
		QCOMPARE(tmpPointer.getCount(), 2);
	}
	
	
	void copyTest(){
		SharedPointer<int> mySharedPointer(new int(value));	
		SharedPointer<int> tmpPointer(mySharedPointer);
		QCOMPARE(mySharedPointer.getCount(), 2);
		QVERIFY(*(mySharedPointer.getPointer()) == value);
	}	
	
	
private :
	const int value = 42;	
};

