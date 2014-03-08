#include "bubblesort.h"

BubbleSort::BubbleSort()
{
}

BubbleSort :: ~BubbleSort()
{
}

void BubbleSort :: sort(int *args, int length)
{
	for (int firstIndex = 0; firstIndex < length - 1; firstIndex++){
		for (int secondIndex = firstIndex; secondIndex < length; secondIndex++)
			if (args[firstIndex] > args[secondIndex]){
				swap(args[firstIndex], args[secondIndex]);
			}
	}
}
