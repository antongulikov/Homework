/*
 Anton Gulikov
*/
#include <stdio.h>

int divide(int a, int b)
{
	if (a < b)
	{
		return 0;
	}
	return 1 + divide(a - b, b);
}

int main()
{
	int a = 0;
	int b = 0;
	printf("Enter value of the variables\n");
	printf("a= ");
	scanf("%d", &a);
	printf("b= ");
	scanf("%d", &b);
	printf("[a/b] = %d\n", divide(a, b));
	return 0;
}
