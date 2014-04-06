#pragma once

/// My basic exception class.
class ListException
{
public:

	ListException(const char *mes);
	const char* get() const;
	
private:
	const char* const message;
};
