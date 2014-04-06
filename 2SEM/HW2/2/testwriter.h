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

	void init(){
		writer = new FileWriter();
	}

	void cleanup(){
		delete writer;
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

		int *ret = new int[9] {5, 4, 7, 8, 9, 6, 3, 2, 1}

		for (int i = 0; i < 9; i++)
			QCOMPARE(ret[i], res[i]);
		
		delete[] res;
		delete[] ret;
	}
	

private :
	Writer *writer;	
};

