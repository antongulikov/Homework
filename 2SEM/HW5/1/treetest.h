#pragma once
#include "tree.h"
#include <QObject>
#include <QtTest/QTest>
/// class for testing tree
class TreeTest : public QObject
{
	Q_OBJECT
public:
	explicit TreeTest(QObject *parent = 0);
	
private slots:
	
	void initTest(){
		Tree myTree("(+ 1 1)");		
	}
	
	void deleteTest(){
		Tree *myTree = new Tree("(+ 1 1)");
		delete myTree;		
	}
	
	void negateNumberTest(){
		Tree myTree("(- -1 1)");
		QVERIFY(myTree.count() == -2);
	}
	
	void plusTest(){
		Tree myTree("(+ 1 1)");
		QVERIFY(myTree.count() == 2);
	}
	
	void minusTest(){
		Tree myTree("(- 1 1)");
		QVERIFY(myTree.count() == 0);
	}	
	
	void multiplyTest(){
		Tree myTree("(* 2 7)");
		QVERIFY(myTree.count() == 14);
	}
	
	void divideTest(){
		Tree myTree("(/ 12 2)");
		QVERIFY(myTree.count() == 6);
	}
	
	void expressionTest(){
		Tree myTree("(* (+ 1 1) 2)");
		QVERIFY(myTree.count() == 4);
	}
		
};

