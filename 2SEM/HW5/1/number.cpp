#include "number.h"

Number::Number(int value): value(value)
{
}

void Number::print(){
	cout << " " << value << " ";
}

int Number::count(){
	return value;
}
