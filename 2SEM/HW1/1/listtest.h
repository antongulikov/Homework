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
		
public slots:

	void initTest(){
		linList = new LinList();
		arrayList = new ArrayList();
		QVERIFY(true);
	}
	
	void emptyLinList(){
		QVERIFY(linList->size() == 0);
	}
	
	void emptyArrayList(){
		QVERIFY(arrayList->size() == 0);
	}
	
	void pushElementToArrayList(){
		arrayList->push(3);
		QVERIFY(arrayList->size() == 1);
	}
	
	void pushElementToLinList(){
		linList->push(2);
		QVERIFY(linList->size() == 1);
	}
	
	void popFromLinList(){
		linList->pop(2);
		QVERIFY(linList->size() == 0);
	}
	
	void popFromArrayList(){
		arrayList->pop(3);
		QVERIFY(arrayList->size() == 0);
	}
	
	void cleanupAllTest(){
		delete arrayList;
		delete linList;
		QVERIFY(true);
	}

private :
	List *linList;
	List *arrayList;		
};
