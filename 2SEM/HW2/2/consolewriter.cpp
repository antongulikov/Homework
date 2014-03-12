#include "consolewriter.h"
#include <algorithm>
#include <iostream>

using namespace std;


void ConsoleWriter::print(int **args, int sizeOfMatrix)
{
	for (int index = 1; index <= sizeOfMatrix * sizeOfMatrix; index++)
	{
		pair <int, int> position = getPosition(index, sizeOfMatrix);
		cout << args[position.first][position.second] << " ";		
	}
}
