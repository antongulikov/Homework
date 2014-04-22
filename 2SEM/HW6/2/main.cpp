#include <QObject>
#include "uniquelisttest.h"

int main()
{
	UniqueListTest listTest;
	QTest::qExec(&listTest);
	return 0;
}

