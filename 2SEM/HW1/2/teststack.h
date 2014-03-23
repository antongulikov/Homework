#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "linstack.h"
#include "arraystack.h"

class TestStack : public QObject
{
	Q_OBJECT
public:
	explicit TestStack(QObject *parent = 0);

private slots:

	void initTest(){
		arrayStack = new ArrayStack<int>;
		linStack = new LinStack<int>;
		QVERIFY(true);
    }

	void emptyArrayStack(){
		QVERIFY(arrayStack->size() == 0);
	}

	void emptyLinStack(){
		QVERIFY(linStack->size() == 0);
	}

	void pushElementToArrayStack(){
		arrayStack->push(2);
		QVERIFY(arrayStack->top() == 2);
	}

	void pushElementToListStack(){
		linStack->push(2);
		QVERIFY(linStack->top() == 2);
    }

	void popElementFromArrayStack(){
		arrayStack->pop();
		QVERIFY(arrayStack->size() == 0);
    }

	void popElementFromLinStack(){
		linStack->pop();
		QVERIFY(linStack->size() == 0);
    }

	void cleanupTest(){
		delete linStack;
		delete arrayStack;
	}

private:
	Stack<int> *arrayStack;

	Stack<int> *linStack;
};


