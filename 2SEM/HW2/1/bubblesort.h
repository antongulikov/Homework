#pragma once
#include <sort.h>

class BubbleSort : public Sort
{
public:
	BubbleSort();
	~BubbleSort();
	void sort(int *args, int length);
};

