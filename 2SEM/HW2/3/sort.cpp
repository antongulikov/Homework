#include "sort.h"

Sort :: ~Sort()
{
}

void Sort :: swap(int &firstElement, int &secondElement)
{
	int tmpElement = firstElement;
	firstElement = secondElement;
	secondElement = tmpElement;
}
