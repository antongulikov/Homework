#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "hashfunction.h"

/// Class for tests for Hash Function
class HashFunctionTest : public QObject
{
	Q_OBJECT
public:
	explicit HashFunctionTest(QObject *parent = 0);
	
private slots:

	void init(){
		hashFunction = new HashFunction(10, 100);
	}
	
	void cleanup(){
		delete hashFunction;
	}
	
	void calcHashTest(){
		QCOMPARE(hashFunction->getHash("123"), 51);
	}

private:
	HashFunction *hashFunction;	
};

