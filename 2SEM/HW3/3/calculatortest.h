#pragma once
#include <QtTest/QtTest>
#include <QObject>
#include "calculator.h"

class CalculatorTest : public QObject
{
	Q_OBJECT
public:
	explicit CalculatorTest(QObject *parent = 0);
	
	
private slots:

	void calculateTest(){
		QVERIFY(calc.calculate("1+2-3*2+6/2") == 0);
	}

	void calculateTest7plus8(){
		QVERIFY(calc.calculate("7+8") == 15);
	}

private :	
	Calculator calc;	
};
