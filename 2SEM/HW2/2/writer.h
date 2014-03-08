#pragma once
#include <algorithm>
using namespace std;

class Writer
{
public:
	Writer();
	virtual ~Writer();
	virtual void print(int **args, int sizeOfMatrix) = 0;
protected:
	pair <int, int> getPosition(int position, int sizeOfMatrix);
};

