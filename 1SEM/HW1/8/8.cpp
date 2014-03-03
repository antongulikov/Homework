/*
 Anton Gulikov
*/
#include <stdio.h>

long long factorial1(long long n)
{
	if (n == 0ll)
	{
		return 1ll;
	}
	return factorial1(n - 1) * n;
}

long long factorial2(long long n)
{
	long long result = 1ll;
	for (long long i = 1ll; i <= n; ++i)
	{
		result *= i;
	}

	return result;
}

int main()
{
	long long n = 0;
	// факториал каккого числа вы хотите получить, того и вводите.
	// длинку писать не собирался, так что желательно, чтобы n<=20;
	scanf("%I64d", &n);
	if ( factorial1(n) == factorial2(n) )
	{
		printf("Answer is %I64d\n", factorial1(n));
	}

	return 0;
}