#pragma once
#include "commoncomporator.h"
/// class for int comporator
class IntComporator : public CommonComporator<int>
{
public:
	~IntComporator();
	bool compare(int first, int second);
};

