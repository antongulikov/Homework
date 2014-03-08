#pragma once
#include <sort.h>

class MagicSort : public Sort
{
public:
	MagicSort();
	~MagicSort();
	void sort(int **args, int sizeOfRows, int sizeOfColumns);
private:
	void changeColumns(int **args, int sizeOfRows, int sizeOfColumns, int *position);	
};

