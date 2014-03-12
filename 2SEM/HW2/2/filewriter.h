#pragma once
#include <writer.h>

/// Class which allows print arrays in file.
class FileWriter : public Writer
{
public:
	/// Method which prints array in file.
	void print(int **args, int sizeOfMatrix);
};

