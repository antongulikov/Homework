#pragma once
#include <sort.h>

class QuickSort : public Sort
{
public:
	QuickSort();
	~QuickSort();
	void sort(int *args, int length);
private:
	void qSort(int *args, int leftPosition, int rightPosition);
};

