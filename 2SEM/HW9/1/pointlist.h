#pragma once
#include "list.h"

class PList : public list
{
public:
	PList();
	~PList();
	void addValue(int value);
	void deleteValue(int numb);
	void printList();
	void deleteList();

private:
	struct ListElement
	{
		int value;
		ListElement *next;
	};

	ListElement *first;
};

