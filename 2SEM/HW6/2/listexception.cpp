#include "listexception.h"

ListException::ListException(const char *mes) : message(mes)
{
}

const char* ListException :: get() const{
	return message;
}


