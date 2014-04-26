#include "multiply.h"

void Multiply::print(){
	cout << " (*";
	left->print();
	cout << " ";
	right->print();
	cout << ")";
}

int Multiply::count(){
	return left->count() * right->count();
}

