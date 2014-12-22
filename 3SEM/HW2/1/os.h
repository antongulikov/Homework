#pragma once
#include <string>
using namespace std;
class Os
{
public:
    Os(string name, int probability);
    int getProbability();
    string getOsType();
    ~Os();

private:
    string name;
    int probability;
};


