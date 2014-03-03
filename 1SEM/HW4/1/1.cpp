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
	int *b = new int[n+2];
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
	delete[] b;
	return;	
}

int main()
{
	printf("Enter the size of teh array, array. You will give a value of the element i, which are most popular in the array.");
	int n = 0;
	scanf("%d", &n);
	int *a = new int[n+2];

	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	heapSort(a, n);

	bool fl = false;

	for (int i = n; i >= 2; i--)
		if (a[i] == a[i-1]){		 
			printf("Your value is %d", a[i]);
			fl = true;
			break;
		}

	if (!fl)			
		printf("Your array is unique");

	delete[] a;
	return 0;
}