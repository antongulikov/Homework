#include <iostream>
#include <consolewriter.h>
#include <filewriter.h>

using namespace std;

int main()
{
	cout << "Enter the size of matrix\n";
	
	int sizeOfMatrix = 0;	
	cin >> sizeOfMatrix;
	
	cout << "Enter the matrix\n";
	
	int **args = new int *[sizeOfMatrix];
	for (int index = 0; index < sizeOfMatrix; index++)
		args[index] = new int[sizeOfMatrix];
		
	for (int indexOfRow = 0; indexOfRow < sizeOfMatrix; indexOfRow++)	
		for (int indexOfColumn = 0; indexOfColumn < sizeOfMatrix; indexOfColumn++)
			cin >> args[indexOfRow][indexOfColumn];
			
	enum usersCommand { console, file };
	
	cout << " If you want to print your matrix in file , please press 1, else press 0\n";
	int command = 0;
	cin >> command;
	
	switch (static_cast<usersCommand>(command))
	{
		case (console):
		{
			Writer *writer = new ConsoleWriter();
			writer->print(args, sizeOfMatrix);	
			delete writer;			
			break;
		}
		case (file):
		{
			Writer *writer = new FileWriter();
			writer->print(args, sizeOfMatrix);	
			delete writer;			
			break;
		}
		
	}	
	
	for (int index = 0; index < sizeOfMatrix; index++)
		delete args[index];
		
	delete[] args;
	
	return 0;
}

