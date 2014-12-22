#include "computer.h"
#include <QDebug>

Computer::Computer(Os *os) : os(os)
{
    virusHealth = 0;
}

Computer::~Computer()
{
    delete os;
}

bool Computer::isInfected()
{
    return virusHealth > 0;
}

void Computer::tryToInfect()
{
    int probability = std::rand() % 100;    
    if (probability < os->getProbability())
        virusHealth = 3;
}

void Computer::infect()
{
    virusHealth = 3;
}

void Computer::turn()
{
    if (virusHealth > 0)
        virusHealth--;
}
