#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <pair.h>
/// class for complexnumber
class ComplexNumber : public Pair
{
public:
	ComplexNumber();
	ComplexNumber(int valueA, int valueB);
	~ComplexNumber();
	ComplexNumber operator *(ComplexNumber const &second);
	int length();	
};

#endif // COMPLEXNUMBER_H
