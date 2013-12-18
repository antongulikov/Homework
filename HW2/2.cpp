/*
 Anton Gulikov
*/

#include <stdio.h>

float power(float a, int n)
{
	if (n == 0)
	{
		return 1.0;
	}
	if (n & 1 == 0)
	{
		float tmpValue = power(a, n >> 1);
		return tmpValue * tmpValue;
	}
	return a * power(a, n - 1);
}
	

int main()
{
	printf("Please, enter a,n and you will give a^n");

	float a = 0;
	int n = 0;

	scanf("%f %d", &a, &n);

	if (a == 0)
	{
		if (n > 0)
			printf("Answer is 0");
		else
			printf("Error");
		return 0;
	}
	else if (n < 0)
	{
		a = 1.0 / a;
		n = -n;
	}

	float ans = power(a, n);

	printf("answer is %.6f", ans);
}