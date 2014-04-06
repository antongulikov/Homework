#include "mysettest.h"

int main()
{
	MySetTest sTest;
	QTest :: qExec(&sTest);
	return 0;
}

