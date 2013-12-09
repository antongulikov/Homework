/*
 Anton Gulikov
*/

#include <stdio.h>

int swapElements( int & a, int & b )
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;	
}

void reverseElements(int a[], int l, int r)
{
	for (int i = 1; i <= (r - l + 1) / 2; ++i)
	{
		swapElements(a[l + i - 1], a[r - i + 1]);
	}
	return;
}

int main()
{
	printf("Enter the size n,m and array A\n");

	int n=0;
	int m=0;

	scanf("%d", &n);
	scanf("%d", &m);
	
	int a[n + m + 1];

	for (int i = 1; i <= n + m; ++i)
	{
		scanf("%d", &a[i]);
	}

	reverseElements(a, 1, n);
	reverseElements(a, n + 1, n + m);
	reverseElements(a, 1, n + m);

	for (int i = 1; i <= n + m; ++i)
	{
		printf("%d ", a[i]);
	}

	return 0;
}