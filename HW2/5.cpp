/*
 Anton Gulikov
*/
#include <stdio.h>

int swapElements(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

bool cmp(int a, int b)
{
	return a < b;
}

void reheapDown(int a[], int currentPosition, int n)
{ 
	int left = currentPosition << 1;
	int right = left + 1;
	int nextPosition = 0;
	if ( left <= n && cmp(a[left],a[currentPosition]) )
		nextPosition = left;
	else
		nextPosition = currentPosition;
	if ( right <= n && cmp(a[right],a[nextPosition]) )
		nextPosition = right;
       	if ( nextPosition != currentPosition)
       	{
       		swapElements(a[nextPosition],a[currentPosition]);
       		reheapDown(a, nextPosition, n);
       	}
       	return;
}

void heapSort(int a[], int n)
{
	for ( int i = n >> 1; i > 0; --i)
		reheapDown(a, i, n);
	int b[n + 1];
	int m = n;
	for (int i = 1; i <= n; ++i)
	{
		b[i] = a[1];
		swapElements(a[1], a[m]);
		--m;
		if (m != 0)
			reheapDown(a, 1, m);
	}
	for (int i = 1; i <= n; ++i)
		a[i] = b[i];
	return;	
}

int main()
{
	printf("Enter to me N and array A, and I will sort it with HeapSort ");
	int n = 0;
	scanf("%d", &n);
	int a[n + 1];
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	heapSort(a, n);
	for (int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}
