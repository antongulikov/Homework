#include "minus.h"


void Minus::print()
{
	cout << " (-";
	left->print();
	cout << " ";
	right->print();
	cout << ")";
}

int Minus::count(){
	return left->count() - right->count();
}

