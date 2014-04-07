#include "bagtest.h"

int main()
{
	BagTest myTest;
	QTest :: qExec(&myTest);
	return 0;
}

