#include "pair.h"

Pair::Pair() : a(0), b(0)
{
}

Pair::~Pair()
{	
}

Pair::Pair(int valueA, int valueB): a(valueA), b(valueB)
{	
}

void Pair::multiply(int value)
{
	a *= value;
	b *= value;
}

Pair Pair::operator +(const Pair &second)
{
	int newA = a + second.a;
	int newB = b + second.b;
	return Pair(newA, newB);
}

int Pair::getA()
{
	return a;
}

int Pair::getB()
{
	return b;
}
