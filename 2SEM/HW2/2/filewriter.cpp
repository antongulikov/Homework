#include "filewriter.h"
#include <fstream>
using namespace std;


FileWriter::~FileWriter()
{
}

void FileWriter::print(int **args, int sizeOfMatrix)
{
	ofstream out;
	out.open("result.txt");
	for (int index = 1; index <= sizeOfMatrix * sizeOfMatrix; index++)
	{
		pair <int, int> position = getPosition(index, sizeOfMatrix);
		out << args[position.first][position.second] << " ";		
	}
	out.close();
}
