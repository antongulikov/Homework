#pragma once
#include <sort.h>

/// Class which allows you to sort array
class MagicSort : public Sort
{
public:
	~MagicSort();
	/// Method wich sorts an array by the first element
	void sort(int **args, int sizeOfRows, int sizeOfColumns);
private:
	/// Method that changes the columns of array
	void changeColumns(int **args, int sizeOfRows, int sizeOfColumns, int *position);	
};

