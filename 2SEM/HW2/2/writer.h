#pragma once
#include <algorithm>
using namespace std;

class Writer
{
public:
	virtual ~Writer();
	/// Virtual method which print matrix.
	virtual void print(int **args, int sizeOfMatrix) = 0;
protected:
	/// Method that returns the number's position
	pair <int, int> getPosition(int position, int sizeOfMatrix);
};

