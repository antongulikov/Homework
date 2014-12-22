#include "os.h"


Os::Os(string name, int probability) : name(name), probability(probability){}

int Os::getProbability()
{
    return probability;
}

string Os::getOsType()
{
    return name;
}

Os::~Os(){}
