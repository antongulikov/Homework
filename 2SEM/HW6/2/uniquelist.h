#pragma once
#include "duplicateexception.h"
#include "existexception.h"
#include "linlist.h"
/// Class for Unique List
class UniqueList : public LinList
{
public:
	void insert(int value) throw (DuplicateException);
	int erase(int value) throw(ExistException);	
};
