#pragma once
#include "node.h"
/// class for numbers
class Number : public Node
{
public:
	Number(int value);
	void print();
	int count();
private:
	int value;
};

