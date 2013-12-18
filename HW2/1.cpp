/*
 Anton Gulikov
*/
#include <stdio.h>

long long fibonachiNumber(long long fib[], int n)
{
	if (fib[n] != 0)
		return fib[n];
	fib[n] = fibonachiNumber(fib, n - 1) + fibonachiNumber(fib, n - 2);
	return fib[n];
}

int main(){
	int n = 0;
	printf("Enter the position of fib number");
	scanf("%d", &n);
	long long fN1 = 0;
	long long fN2 = 1;
	long long tmpValue = 0;
	long long fib[n + 3];
	for (int i = 0; i <= n + 2; ++i)
		fib[i] = 0;
	fib[0] = 1;
	fib[1] = 1;

	for (int i = 1; i <= n; ++i)
	{
		tmpValue = fN1 + fN2;
		fN1 = fN2;
		fN2 = tmpValue;
	}
	if (fN2 == fibonachiNumber(fib, n))
		printf("%I64d", fN2);
	return 0;
}