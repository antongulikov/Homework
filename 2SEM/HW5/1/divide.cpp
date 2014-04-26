#include "divide.h"

void Divide :: print(){
	cout << " (/";
	left->print();
	cout << " ";
	right->print();
	cout << ")";
}

int Divide :: count(){
	return left->count() / right->count();
}
