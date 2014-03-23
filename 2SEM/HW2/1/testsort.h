#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "quicksort.h"
#include "bubblesort.h"

class TestSort : public QObject
{
	Q_OBJECT
public:
	explicit TestSort(QObject *parent = 0);
	
signals:
	
private slots:

	void initTest(){
		bSort = new BubbleSort();
		qSort = new QuickSort();
		QVERIFY(true);
	}

	void testQuickSort(){
		int args[4];
		for (int i = 3; i >= 0; i--)
			args[i] = i;
		qSort->sort(args, 4);
		QVERIFY(args[0] == 0 && args[1] == 1 && args[2] == 2 && args[3] == 3);
	}

	void testBubbleSort(){
		int args[4];
		for (int i = 3; i >= 0; i--)
			args[i] = i;
		bSort->sort(args, 4);
		QVERIFY(args[0] == 0 && args[1] == 1 && args[2] == 2 && args[3] == 3);
	}

	void cleanupTest(){
		delete qSort;
		delete bSort;
		QVERIFY(true);
	}

private :
	Sort *bSort;
	Sort *qSort;	
};

