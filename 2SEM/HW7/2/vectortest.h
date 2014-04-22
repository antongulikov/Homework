#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "scorpionvector.h"

/// Class for testing ScorpionVector
class VectorTest : public QObject
{
	Q_OBJECT
public:
	explicit VectorTest(QObject *parent = 0);
	
private slots:

	void isNullTestOnNullVector(){
		ScorpionVector<4> tmp({0, 0, 0, 0});
		QVERIFY(tmp.isNull());		
	}
	
	void isNullTestOnNonNullVector(){
		ScorpionVector<4> tmp({1, 0, 1, 0});
		QVERIFY(!tmp.isNull());		
	}
	
	void copyTest(){
		ScorpionVector<3> tmp1({1, -1, 0});
		ScorpionVector<3> tmp2(tmp1);
		QCOMPARE(tmp1, tmp2);
	}
	
	void scalarProductTest(){
		ScorpionVector<3> tmp({1,-1,0});
		QVERIFY(tmp.scalarProduct(tmp) == 2);
	}
	
	void equalTest(){
		ScorpionVector<3> tmp1({1, 2, 3});
		ScorpionVector<3> tmp2(tmp1);
		QVERIFY(tmp1 == tmp2);
	}	
	
	void plusTest(){
		ScorpionVector<3> tmp1({1, 2, -1});
		ScorpionVector<3> tmp2({-1, -2, 1});
		QVERIFY((tmp1 + tmp2).isNull());
	}
	
	void minusTest(){
		ScorpionVector<3> tmp1({1, 2, -1});
		ScorpionVector<3> tmp2({0, 1, -2});
		QVERIFY((tmp1 - tmp2) == ScorpionVector<3>({1, 1, 1}));
	}	
};
