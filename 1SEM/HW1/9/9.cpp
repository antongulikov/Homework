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

	int ans = (int)( power(a, n) );

	printf("[ %.5f ^ %d ] is %d\n", a, n, ans);
}