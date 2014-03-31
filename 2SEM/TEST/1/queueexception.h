#pragma once

/// My basic exception class.
class QueueException
{
public:

	QueueException(const char *mes);
	const char* get() const;
	
private:
	const char* const message;
};
