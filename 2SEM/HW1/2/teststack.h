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

	void init(){
		arrayStack = new ArrayStack<int>;
		linStack = new LinStack<int>;
    }

   	void cleanup(){
		delete linStack;
		delete arrayStack;
	}


	void emptyArrayStackTest(){
		QVERIFY(arrayStack->size() == 0);
	}

	void emptyLinStackTest(){
		QVERIFY(linStack->size() == 0);
	}

	void pushElementToArrayStackTest(){
		arrayStack->push(2);
		QVERIFY(arrayStack->top() == 2);
	}

	void pushElementToListStackTest(){
		linStack->push(2);
		QVERIFY(linStack->top() == 2);
    }

	void popElementFromArrayStackTest(){
		arrayStack->push(2);
		arrayStack->pop();
		QVERIFY(arrayStack->size() == 0);
    }

	void popElementFromLinStackTest(){
		linStack->push(2);
		linStack->pop();
		QVERIFY(linStack->size() == 0);
    }


private:
	Stack<int> *arrayStack;
	Stack<int> *linStack;
};


