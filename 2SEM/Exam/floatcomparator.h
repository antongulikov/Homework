#pragma once
#include <commoncomporator.h>

/// comporator for float
class FloatComparator : public CommonComporator<float>
{
public:
	~FloatComparator();
	bool compare(float first, float second);
};

