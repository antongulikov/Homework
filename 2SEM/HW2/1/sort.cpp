#include "sort.h"

Sort::Sort()
{
}

Sort:: ~Sort()
{
}

void Sort :: swap(int &firstElement, int &secondElement){
	int tmpElement = secondElement;
	secondElement = firstElement;
	firstElement = tmpElement;
}
