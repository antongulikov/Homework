#pragma once
#include "computer.h"
#include <QVector>
#include <QSet>

class Network
{
public:
    Network();
    ~Network();
    /**
     * @brief addNewComputer - adding new computer to network
     * @param comp - new computer
     */
    void addNewComputer(Computer *comp);

    /**
     * @brief addEdge - add edge beetwen the first computer and the second computer in the network
     * @param first
     * @param second
     */
    void addEdge(int first, int second);

    void makeTurn();

    /**
     * @brief isInfected - Is it true that computer with index "indes" is infected
     * @param index - position of computer
     * @return true or false :)
     */
    bool isInfected(int index);

    /**
     * @brief setInfect - infect computer
     * @param index
     */
    void setInfect(int index);

    int getSize();

private:

    QVector<Computer*> computers;

    /**
     * @brief network - adjacency list;
     */
    QVector< QVector<int> > network;
};

