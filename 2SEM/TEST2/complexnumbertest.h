#ifndef COMPLEXNUMBERTEST_H
#define COMPLEXNUMBERTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include <complexnumber.h>

/// class for test for complex number

class ComplexNumberTest : public QObject
{
	Q_OBJECT
public:
	explicit ComplexNumberTest(QObject *parent = 0);	
	
private slots:
	
	
	void lengthTest()
	{
		ComplexNumber a(1, 5);
		QVERIFY(a.length() == 26);
	}
	
	
	void multiplyOperatorTest()
	{
		ComplexNumber a(0, 1);
		ComplexNumber b(0, 1);
		QVERIFY((a * b).getA() == -1 && (a * b).getB() == 0);
	}
	
	void sumTest()
	{
		ComplexNumber a(1, 2);
		ComplexNumber b(2, 4);
		QVERIFY((a + b).getA() == 3 && (a + b).getB() == 6);		
	}
	
	void multiplyTest()
	{
		ComplexNumber a(1, 2);
		a.multiply(3);
		QVERIFY(a.getA() == 3 && a.getB() == 6);
	}
	
};

#endif // COMPLEXNUMBERTEST_H
