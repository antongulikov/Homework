#pragma once
#include "os.h"
#include <cstdlib>

class Computer
{
public:
    /**
     * @brief Computer construtor of Computer
     * @param os - os on computer
     */

    explicit Computer(Os* os);

    ~Computer();

    /**
     * @brief isInfected
     * @return true if computer is an infected, and false otherwise
     */

    bool isInfected();

    /**
     * @brief tryToInfect - method for trying to infect a computer
     */

    void tryToInfect();
    /**
     * @brief infect make a computer infected
     */
    void infect();
    /**
     * @brief turn - a one day passed
     */
    void turn();

private:
    Os* os;
    int virusHealth;
};


