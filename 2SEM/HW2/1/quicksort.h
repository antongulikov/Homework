#pragma once
#include <sort.h>

/// Class which allows you to sort an array by QSort
class QuickSort : public Sort
{
public:
	~QuickSort();
	/// Method which launches qSort
	void sort(int *args, int length);
private:
	/// Quick Sort
	void qSort(int *args, int leftPosition, int rightPosition);
};

