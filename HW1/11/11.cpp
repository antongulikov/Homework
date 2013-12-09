/*
 Anton Gulikov
*/
#pragma comment(linker,"/STACK:300000000")
#include <stdio.h>

void swapElements(int & a, int & b)
{
	int c = a;
	a = b;
	b = c;
}

void qSort(int a[], int l, int r)
{
	int i = l;
	int j = r;
	int key = a[ (i + j) >> 1 ];  // будет работать за квадрат. ((

	while ( i <= j )
	{
		while (a[i] < key)
		{
			++i;
		}
		while (key < a[j])
		{
			--j;
		}
		if (i <= j)
		{
			swapElements(a[i], a[j]);
			++i;
			--j;
		}
	}

	if (l < j)
	{
		qSort(a, l, j);
	}
	if (i < r)
	{
		qSort(a, i, r);
	}
}

int main()
{
	printf("On the first raw enter the size of the array. On the second - array of integers.\n");
	int n = 0;
	scanf("%d ", &n);
	int a[n + 1];
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
	}

	qSort(a, 1, n);

	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}