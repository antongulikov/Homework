#include <QObject>
#include <iostream>
#include "uniquelisttest.h"

using namespace std;

int main()
{
	UniqueListTest listTest;
	QTest::qExec(&listTest);
	return 0;
}

