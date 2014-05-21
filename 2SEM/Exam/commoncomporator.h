#pragma once

/// Basic class for Comparator
template <typename T>
class CommonComporator
{
public:	
	virtual ~CommonComporator() {}
	virtual bool compare(T first, T second) = 0;
};

