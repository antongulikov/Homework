#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "uniquelist.h"
#include "listexception.h"

class UniqueListTest : public QObject
{
	Q_OBJECT
public:
	explicit UniqueListTest(QObject *parent = 0);
	
private slots:

void init(){
	list = new UniqueList();
}

void cleanup(){
	delete list;
}

void insertOneElementTest(){
	list->insert(2);
	QVERIFY(list->getSize() == 1);
}

void insertTwoElementsTest(){
	list->insert(3);
	list->insert(5);
	QVERIFY(list->getSize() == 2);
}

void findTrueTest(){
	list->insert(42);
	QVERIFY(list->find(42));
}

void findFalseTest(){
	list->insert(42);
	QVERIFY(!list->find(41));
}

void eraseTest(){
	list->insert(2);
	QVERIFY(list->erase(2) == 2);
}

void eraseFromEmptyListTest(){
	try{
		list->erase(42);
	}
	catch(const ListException &exec){
		QCOMPARE("Element doesn't exists!", exec.get());
	}
}

void insertDuplicateElementTest(){
	try{
		list->insert(42);
		list->insert(42);
	}
	catch(const ListException &exec){
		QCOMPARE("Already exists!",exec.get());	
	}
}

void eraseNotExistingElementTest(){
	list->insert(42);
	try{
		list->erase(41);
	}
	catch(const ListException &exec){
		QCOMPARE("Element doesn't exists!", exec.get());
	}
}

private :
	UniqueList *list;	
};

