#pragma once
#include <writer.h>

/// Class which allows print arrays in console.
class ConsoleWriter : public Writer
{
public:
	/// Method which prints array in console.
	void print(int **args, int sizeOfMatrix);
};

