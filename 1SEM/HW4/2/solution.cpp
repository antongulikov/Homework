#include <cstdio>
#include "scorpioncharstack.h"
#include "scorpiondoublestack.h"
#include "calculator.h"
#include <stdlib.h>
#include <string.h>

using namespace std;
using namespace scorpion;

int main()
{
	printf("Enter you expressions.\n");

	const int maxn = 100500;
	char *message = new char[maxn];
	memset (message, 0, maxn * sizeof(char));
	fgets(message, maxn, stdin);

	char *polish = toPolish(message);
	
	double result = calcResult(polish);

	delete[] message;
	delete[] polish;

	printf("Answer is %.7f", result);
	system("pause");
	return 0;
}

