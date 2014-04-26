#include "plus.h"

void Plus::print()
{
	cout << " (+";
	left->print();
	cout << " ";
	right->print();
	cout << ")";
}

int Plus::count(){
	return left->count() + right->count();
}
