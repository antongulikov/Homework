#pragma once
#include "myset.h"
#include <QObject>
#include <QtTest/QtTest>

class MySetTest : public QObject
{
	Q_OBJECT
public:
	explicit MySetTest(QObject *parent = 0);
	
private slots:

	void init(){
		tmpSet = new MySet<int>;
	}
	
	void cleanup(){
		delete tmpSet;
	}
	
	void insertTest(){
		tmpSet->insert(42);
		QVERIFY(tmpSet->sizeSet() == 1);
	}
	
	void findTest(){
		tmpSet->insert(42);
		QVERIFY(tmpSet->find(42));
	}
	
	void unionSetTest(){
		MySet<int> st;
		st.insert(43);
		tmpSet->insert(42);
		st = tmpSet->unionSet(st);
		QCOMPARE(st.sizeSet(), 2);
		QVERIFY(st.find(42) && st.find(43));
	}
	
	void intersectSetTest(){
		MySet<int> st;
		st.insert(42);
		st.insert(43);
		tmpSet->insert(42);
		tmpSet->insert(41);
		st = tmpSet->intersectSet(st);
		QVERIFY(st.sizeSet() == 1 && st.find(42));		
	}
	
	void eraseTest(){
		tmpSet->insert(42);
		tmpSet->insert(43);
		tmpSet->erase(43);
		QVERIFY(tmpSet->sizeSet() == 1 && tmpSet->find(42));
	}

private:
	MySet<int> *tmpSet;
	
};
