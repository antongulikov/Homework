#pragma once
#include "list.h"

class aList : public list
{
public:
	aList();
	~aList();
	void addValue(int value);
	void deleteValue(int numb);
	void printList();

private:
	int size;
	int arr[1000];
};

