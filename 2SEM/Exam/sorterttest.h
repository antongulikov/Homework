#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <sorter.h>
#include <intcomporator.h>
#include <stringcomporator.h>
#include <floatcomparator.h>
#include <string>
#include <iostream>
using namespace std;

/// class for testing sorter
class SortertTest : public QObject
{
	Q_OBJECT
public:
	explicit SortertTest(QObject *parent = 0);
		
private slots:

	
	void init(){
		intArray = new int[nMax];
		stringArray = new string[nMax];
		floatArray = new float[nMax];
		sort = new Sorter();
	}

	void intTestSort(){				
		for (int i = 0; i < nMax; i++) 
			intArray[i] = nMax - i;		
		IntComporator *cmp = new IntComporator();		
		sort->sort(intArray, nMax, cmp);
		delete cmp;		
		for (int i = 0; i < nMax; i++)
			QCOMPARE(intArray[i], i + 1);		
	}
	
	void stringTestSort(){
		stringArray[0] = "anton";
		stringArray[1] = "dlya";
		stringArray[2] = "basha";
		stringArray[3] = "cimofey";
		stringArray[4] = "euxov";		
		StringComporator *cmp = new StringComporator();
		sort->sort(stringArray, nMax, cmp);
		delete cmp;		
		int i = 0;
		for (char ch = 'a'; ch <= 'e'; ch++){			
			QCOMPARE(stringArray[i][0], ch);
			i++;
		}		
	}
	
	void floatTestSort(){
		floatArray[0] = 0.6;
		floatArray[1] = 1.6;
		floatArray[2] = 0.9;
		floatArray[3] = 1.5;
		floatArray[4] = 5.3;
		FloatComparator *cmp = new FloatComparator();
		sort->sort(floatArray, nMax, cmp);
		delete cmp;
		for (int i = 1; i < nMax; i++)				
			QVERIFY(floatArray[i] > floatArray[i - 1]);
	}
	
	void cleanup(){
		delete[] intArray;
		delete[] stringArray;
		delete[] floatArray;
		delete sort;
	}
	
private :
	const int nMax = 5;
	int *intArray;
	string *stringArray;
	float *floatArray;
	Sorter *sort;
		
};
