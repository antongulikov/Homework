#pragma once
#include "queueexception.h"

/// Don't want to be a captain.
class MaxSizeQueueException : public QueueException
{
public:
	MaxSizeQueueException(const char *mes);
};
