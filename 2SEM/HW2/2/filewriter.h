#pragma once
#include <writer.h>
class FileWriter : public Writer
{
public:
	FileWriter();
	~FileWriter();
	void print(int **args, int sizeOfMatrix);
};

