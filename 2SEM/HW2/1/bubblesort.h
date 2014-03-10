#pragma once
#include <sort.h>

class BubbleSort : public Sort
{
public:
	~BubbleSort();
	/// Bubble sort
	void sort(int *args, int length);
};

