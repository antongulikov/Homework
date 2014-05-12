#include "complexnumber.h"

ComplexNumber::ComplexNumber() : Pair(Pair())
{
}

ComplexNumber::ComplexNumber(int valueA, int valueB) : Pair(valueA, valueB)
{	
}

ComplexNumber::~ComplexNumber()
{	
}

ComplexNumber ComplexNumber::operator *(const ComplexNumber &second)
{
	int newValueA = a * second.a - b * second.b;
	int newValueB = a * second.b + b * second.a;
	return ComplexNumber(newValueA, newValueB);
}

int ComplexNumber::length()
{
	return a * a + b * b;
}
