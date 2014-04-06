#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "calculator.h"

class CalculatorTest : public QObject
{
	Q_OBJECT
public:
	explicit CalculatorTest(QObject *parent = 0);
	

private slots:
	
	void intit(){
		calc = new Calculator;
	}

	void cleanup(){
		delete calc;
	}

	
	void plusTest(){
		QVERIFY(calc->calculate(1, "+", 2) == 3);
	}
	
	void minusTest(){
		QVERIFY(calc->calculate(1, "-", 2) == -1);
	}
	
	void multiplyTest(){
		QVERIFY(calc->calculate(2, "*", 3) == 6);
	}
	
	void divideTest(){
		QVERIFY(calc->calculate(4, "/", 2) == 2);
	}
	
private :
	Calculator *calc;	
};

