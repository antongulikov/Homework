#pragma once
#include "duplicateexception.h"
#include "existexception.h"


class UniqueList
{
public:
	UniqueList();
	~UniqueList();
	bool find(int value);
	void insert(int value);
	/// return value iff value is in List
	int erase(int value);
	/// return size of List
	int getSize();	

private :
	
	struct ListElement{
		int value;
		ListElement *next;
	};
	
	ListElement *head;
	int size;		
};
