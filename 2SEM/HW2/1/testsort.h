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

	void init(){
		bSort = new BubbleSort();
		qSort = new QuickSort();
	}

	void cleanup(){
		delete qSort;
		delete bSort;
	}


	void testQuickSort(){
		int args[4];
		for (int i = 3; i >= 0; i--)
			args[i] = i;
		qSort->sort(args, 4);
		for (int i = 0; i < 4; i++)
			QCOMPARE(args[i], i);
	}

	void testBubbleSort(){
		int args[4];
		for (int i = 3; i >= 0; i--)
			args[i] = i;
		bSort->sort(args, 4);
		for (int i = 0; i < 4; i++)
			QCOMPARE(args[i], i);	
	}

private :
	Sort *bSort;
	Sort *qSort;	
};

