#pragma once

class Sort
{
public:
	Sort();
	virtual ~Sort() = 0;
	virtual void sort(int **args, int sizeOfRows, int sizeOfColumns) = 0;
protected :
	void swap(int &firstElement, int &secondElement);
};

