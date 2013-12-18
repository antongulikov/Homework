/*
 Anton Gulikov
*/
#include <stdio.h>

void printFraction(int a1, int b1, int a2, int b2, int n)
{
	int a3 = a1 + a2;
	int b3 = b1 + b2;
	if (b3 > n)
		return;
	printFraction(a1, b1, a3, b3, n);
	printf("%d / %d\n", a3, b3);
	printFraction(a3, b3, a2, b2, n);
	return ;
}

int main()
{
	int n = 0;
	printf("Enter the maximum number n, and i print to you all numbers a/b, where a,b>=0, a<b, and b<=n ");
	scanf("%d", &n);
	printFraction(0, 1, 1, 1, n);
	return 0;
}
