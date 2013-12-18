#include <iostream>
#include "stringxxx.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace scorpion;
using namespace std;

int main()
{
	StringXXX *a = createString("abc", 10);
	StringXXX *b = createString("xyz", 4);
	addFristToSecond(a, b);
	addFristToSecond(b, a);
	addFristToSecond(a, b);
	print(a);
	print(b);
	printf("%d\n", areEqual(a, b));
	print(a);
	print(b);
	StringXXX *c = substring(a, 2, length(a) - 4);
	print(c);
	printf("%d\n", length(b));
	deleteString(a);
	deleteString(b);
	deleteString(c);
	system("pause");
	return 0;
}

