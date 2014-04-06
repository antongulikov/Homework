#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "sharedpointer.h"

class SharedPointerTest : public QObject
{
	Q_OBJECT
public:
	explicit SharedPointerTest(QObject *parent = 0);
	
private slots:	
	void init(){
		mySharedPointer = new SharedPointer<int>(new int(value));
	}
	
	void cleanup(){
		delete mySharedPointer;
	}
	
	
	void givingTest(){
		SharedPointer<int> tmpPointer(new int(value + 1));
		*mySharedPointer = tmpPointer;
		QCOMPARE(tmpPointer.getCount(), 2);
		QCOMPARE(*(tmpPointer.getPointer()), *(mySharedPointer->getPointer()));
		QCOMPARE(tmpPointer.getPointer(), mySharedPointer->getPointer());
	}
	
	
	void copyTest(){
		SharedPointer<int> tmpPointer(*mySharedPointer);
		QCOMPARE(mySharedPointer->getCount(), 2);
		QVERIFY(*(mySharedPointer->getPointer()) == value);
	}
	
	
	void deleteTest(){
		SharedPointer<int> *tmpPointer = new SharedPointer<int>(*mySharedPointer);
		int size = tmpPointer->getCount();
		delete tmpPointer;
		QVERIFY(mySharedPointer->getCount() + 1 == size);
	}	
	
private :
	SharedPointer<int> *mySharedPointer;
	const int value = 42;	
};

