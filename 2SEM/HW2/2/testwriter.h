#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "filewriter.h"
#include <iostream>

class TestWriter : public QObject
{
	Q_OBJECT
public:
	explicit TestWriter(QObject *parent = 0);
	
private slots:

	void initTest(){
		writer = new FileWriter();
		QVERIFY(true);
	}
	
	void printTest(){
		int **args = new int *[3];
		for (int i = 0; i < 3; i++)
			args[i] = new int[3];
		for (int i = 0; i < 3; i++)	
			for (int j = 0; j < 3; j++)
				args[i][j] = i * 3 + j + 1;
		writer->print(args, 3);
		
		using namespace std;
		freopen ("result.txt", "r", stdin);
		int *res = new int[9];
		int x = 0;
		int size = 0;
		while (cin >> x){
			res[size++] = x;
		}
		
		for (int i = 0; i < 3; i++)						
			delete args[i];
		delete args;
		
		QVERIFY(res[0] == 5 && res[1] ==  4 && res[2] == 7 
		&& res[3] == 8 && res[4] == 9 && res[5] == 6
		&& res[6] == 3 && res[7] == 2 && res[8] == 1 );
		delete res;
	}
	
	void cleanupTest(){
		delete writer;
		QVERIFY(true);
	}

private :
	Writer *writer;	
};

