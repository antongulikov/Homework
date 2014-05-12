#ifndef PAIRTEST_H
#define PAIRTEST_H

#include <QObject>
#include <pair.h>
#include <QtTest/QtTest>

/// class for pair tests

class PairTest : public QObject
{
	Q_OBJECT
public:
	explicit PairTest(QObject *parent = 0);
	
	
private slots:

	void initTest()
	{
		Pair a(1, 2);
		QVERIFY(a.getA() == 1 && a.getB() == 2);
	}

	void sumTest()
	{
		Pair a(1, 2);
		Pair b(2, 4);
		QVERIFY((a + b).getA() == 3 && (a + b).getB() == 6);		
	}
	
	void multiplyTest()
	{
		Pair a(1, 2);
		a.multiply(3);
		QVERIFY(a.getA() == 3 && a.getB() == 6);
	}
	
};

#endif // PAIRTEST_H
