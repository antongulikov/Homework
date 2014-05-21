#pragma once
#include "commoncomporator.h"
#include <string>
using namespace std;


class StringComporator : public CommonComporator<string>
{
public:	
	bool compare(string first, string second);
	~StringComporator();
};



