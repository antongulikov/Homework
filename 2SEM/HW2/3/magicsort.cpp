#include "magicsort.h"


MagicSort::~MagicSort()
{
}

void MagicSort :: changeColumns(int **args, int sizeOfRows, int sizeOfColumns, int *position)
{
	int **tmpArgs = new int *[sizeOfRows];
	
	for (int indexOfRows = 0; indexOfRows < sizeOfRows; indexOfRows++)
		tmpArgs[indexOfRows] = new int[sizeOfColumns];
		
	for (int indexOfColums = 0; indexOfColums < sizeOfColumns; indexOfColums++)
	{
		tmpArgs[0][indexOfColums] = args[0][indexOfColums];
		for (int indexOfRows = 1; indexOfRows < sizeOfRows; indexOfRows++)
			tmpArgs[indexOfRows][indexOfColums]	= args[indexOfRows][position[indexOfColums]];
	}
	
	for (int indexOfRows = 0; indexOfRows < sizeOfRows; indexOfRows++)	
		for (int indexOfColumns = 0; indexOfColumns < sizeOfColumns; indexOfColumns++)
			args[indexOfRows][indexOfColumns] = tmpArgs[indexOfRows][indexOfColumns];
			
	for (int indexOfRows = 0; indexOfRows < sizeOfRows; indexOfRows++)
		delete tmpArgs[indexOfRows];
		
	delete tmpArgs;	
}

void MagicSort :: sort(int **args, int sizeOfRows, int sizeOfColumns)
{
	int *position = new int[sizeOfColumns];
	for (int index = 0; index < sizeOfColumns; index++)
		position[index] = index;
	for (int firstIndex = 0; firstIndex < sizeOfColumns - 1; firstIndex++)
		for (int secondIndex = 0; secondIndex < sizeOfColumns; secondIndex++)	
			if (args[0][firstIndex] < args[0][secondIndex])
			{
				swap(args[0][firstIndex], args[0][secondIndex]);
				swap(position[firstIndex], position[secondIndex]);
			}
	changeColumns(args, sizeOfRows, sizeOfColumns, position);
	delete position;								
}
