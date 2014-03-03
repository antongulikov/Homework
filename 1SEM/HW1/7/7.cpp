/*
 Anton Gulikov
*/

#include <stdio.h>

int main()
{
	int n = 0;
	printf("Enter the board of the prime numbers = ");
	scanf("%d", &n);

	bool prime[n + 1];
	for (int i = 2; i <= n; ++i)
	{
		prime[i] = true;
	}		


	for (int i = 2; i * i <= n; ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				prime[j] = false;
			}
		}
	}


	int countPrime = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (prime[i])
		{
			++countPrime;
			printf("The %d prime number is %d\n", countPrime, i);
		}
	}


	return 0;
}