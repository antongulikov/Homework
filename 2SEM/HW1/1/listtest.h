#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "linlist.h"
#include "alist.h"


class ListTest : public QObject
{
	Q_OBJECT
	
public:
	explicit ListTest(QObject *parent = 0);
		
private slots:

	void init(){
		linList = new LinList();
		arrayList = new ArrayList();
	}

	void cleanup(){
		delete arrayList;
		delete linList;
	}

	
	void emptyLinListTest(){
		QVERIFY(linList->size() == 0);
	}
	
	void emptyArrayListTest(){
		QVERIFY(arrayList->size() == 0);
	}
	
	void pushElementToArrayListTest(){
		arrayList->push(3);
		QVERIFY(arrayList->size() == 1);
	}
	
	void pushElementToLinListTest(){
		linList->push(2);
		QVERIFY(linList->size() == 1);
	}
	
	void popFromLinListTest(){
		linList->push(2);
		linList->pop(2);
		QVERIFY(linList->size() == 0);
	}
	
	void popFromArrayListTest(){
		arrayList->push(3);
		arrayList->pop(3);
		QVERIFY(arrayList->size() == 0);
	}	

private :
	List *linList;
	List *arrayList;		
};
