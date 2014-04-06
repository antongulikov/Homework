#pragma once
#include "listexception.h"

class ExistException : public ListException
{
public:
	ExistException(const char *mes);
};
