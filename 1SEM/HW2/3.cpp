/*
 Anton Gulikov
*/
#include <stdio.h>

void printRepresentation(int n, int a[], int lastNumber, int currentSize)
{
	if (n == 0)
	{
		for (int i = 0; i < currentSize - 1; ++i)
		{
			printf("%d + ", a[i]);
		}
		printf("%d\n", a[currentSize - 1]);
	}
	for (int i = lastNumber; i <= n; ++i)
	{
		a[currentSize] = i;
		printRepresentation(n - i, a, i, currentSize + 1);
	}
	return;
}


int main(){
	int n = 0;
	printf("Enter N, and you will give representation of a number as a sum of numbers");
	scanf("%d", &n);
	int a[n];
	printRepresentation(n, a, 1, 0);
	return 0;
}
