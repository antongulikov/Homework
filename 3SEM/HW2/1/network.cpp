#include "network.h"
#include "QDebug"

Network::Network()
{
    computers.clear();
    network.clear();
}

Network::~Network()
{
    for (int i = 0; i < (int)computers.size(); ++i)
        delete computers[i];
    computers.clear();
    network.clear();
}

void Network::addNewComputer(Computer *comp)
{
    computers.push_back(comp);
    network.push_back(QVector<int>());
}

void Network::addEdge(int first, int second)
{
    int size = computers.size();
    if (first >= size || second >= size)
        return;
    network[first].push_back(second);
    network[second].push_back(first);
}

void Network::makeTurn()
{
    QVector<int> candidats;
    candidats.clear();
    for (int i = 0; i < (int)computers.size(); ++i)
    {
        if (computers[i]->isInfected())
            for (int j = 0; j < (int)network[i].size(); ++j)
                candidats.push_back(network[i][j]);
        computers[i]->turn();
    }
    sort(candidats.begin(), candidats.end());
    unique(candidats.begin(), candidats.end());
    for (int i = 0; i < (int)candidats.size(); ++i)
        computers[candidats[i]]->tryToInfect();
}

bool Network::isInfected(int index)
{
    return computers[index]->isInfected();
}

void Network::setInfect(int index)
{
    computers[index]->infect();
}

int Network::getSize()
{
    return computers.size();
}
