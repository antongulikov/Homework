#include <iostream>
#include <pairtest.h>
#include <complexnumbertest.h>

using namespace std;

int main()
{
	PairTest pTest;
	QTest::qExec(&pTest);
	ComplexNumberTest cNumberTest;
	QTest::qExec(&cNumberTest);
}

