#include <iostream>
#include <magicsort.h>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

void testSort()
{
	srand( time ( NULL ) );	
	
	int sizeOfRows = 5;
	int sizeOfColumns = 5;
	int **args = new int *[sizeOfRows];
	for (int indexOfRows =  0; indexOfRows < sizeOfRows; indexOfRows++)
		args[indexOfRows] = new int[sizeOfColumns];
		
	for (int indexOfRows = 0; indexOfRows < sizeOfRows; indexOfRows++)
		for (int indexOfColumns = 0; indexOfColumns < sizeOfColumns; indexOfColumns++)
			args[indexOfRows][indexOfColumns] = rand() & ((1 << 16) - 1);
			
	Sort *sortingMachine = new MagicSort();
	
	cout << "Before\n";
	for (int indexOfRows = 0; indexOfRows < sizeOfRows; indexOfRows++)
	{
		for (int indexOfColumns = 0; indexOfColumns < sizeOfColumns; indexOfColumns++)
		{
			cout << args[indexOfRows][indexOfColumns] << " ";
		}
		cout << endl;
	}
	
	sortingMachine->sort(args, sizeOfRows, sizeOfColumns);
	
	cout <<"After\n";
	
	for (int indexOfRows = 0; indexOfRows < sizeOfRows; indexOfRows++)
	{
		for (int indexOfColumns = 0; indexOfColumns < sizeOfColumns; indexOfColumns++)
		{
			cout << args[indexOfRows][indexOfColumns] << " ";
		}
		cout << endl;
	}
	
	for (int indexOfRows =  0; indexOfRows < sizeOfRows; indexOfRows++)
		delete args[indexOfRows];
		
	delete[] args;
	delete sortingMachine;
	
}

int main()
{
	testSort();
	return 0;		
}

