#pragma once
#include <QtTest/QtTest>
#include <QObject>
#include "magicsort.h" 


class TestSort : public QObject
{
	Q_OBJECT
public:
	explicit TestSort(QObject *parent = 0);
	
signals:
	
private slots:

	void initTest(){
		sMachine = new MagicSort();
		QVERIFY(true);
	}

	void testSort(){
		int **args = new int*[2];
		for (int i = 0; i < 2; i++)
			args[i] = new int[2];
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				args[i][j] = 4 - i - j;
		sMachine->sort(args, 2, 2);
		QVERIFY(args[0][0] > args[0][1]);
		for (int i = 0; i < 2; i++)
			delete args[i];
		delete args;
	}

	void cleanupTest(){
		delete sMachine;
		QVERIFY(true);
	}

private :
	Sort *sMachine;   	
};


