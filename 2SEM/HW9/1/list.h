#pragma once
//#include "element.h"

class list
{
public:
	list();
	~list();
	virtual void addValue (int numb) = 0;
	virtual void deleteValue (int numb) = 0;
	virtual void printList() = 0;

};
