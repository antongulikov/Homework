#include "sort.h"

Sort::Sort()
{
}

Sort :: ~Sort()
{
}

void Sort :: swap(int &firstElement, int &secondElement)
{
	int tmpElement = firstElement;
	firstElement = secondElement;
	secondElement = tmpElement;
}
