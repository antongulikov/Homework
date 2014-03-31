#include "queueexception.h"

QueueException::QueueException(const char *mes) : message(mes)
{
}

const char* QueueException :: get() const{
	return message;
}


