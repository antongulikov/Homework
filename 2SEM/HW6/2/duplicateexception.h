#pragma once
#include "listexception.h"

class DuplicateException : public ListException
{
public:
	DuplicateException(const char *mes);
};

