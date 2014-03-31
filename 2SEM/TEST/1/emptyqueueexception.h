#pragma once
#include "queueexception.h"

/// Don't want to be a captain.
class EmptyQueueException : public QueueException
{
public:
	EmptyQueueException(const char *mes);
};

