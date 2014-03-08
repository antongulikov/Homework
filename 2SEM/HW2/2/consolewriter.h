#pragma once
#include <writer.h>

class ConsoleWriter : public Writer
{
public:
	ConsoleWriter();
	~ConsoleWriter();
	void print(int **args, int sizeOfMatrix);
};

