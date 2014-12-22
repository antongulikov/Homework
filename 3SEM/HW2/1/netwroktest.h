#pragma once
#include "network.h"
#include <QObject>
#include <QtTest/QtTest>

class netwrokTest : public QObject
{
    Q_OBJECT
public:
    explicit netwrokTest(QObject *parent = 0);

private slots:

    void init()
    {
        srand(0);
       // 38 19 38 37 55 97 65 85 50 12 53 0 42 81 37 21 45 85 97 80
        g = new Network;
    }

    void bambooTest()
    {
        g->addNewComputer(new Computer(new Os("os1", 1)));
        g->addNewComputer(new Computer(new Os("os2", 36)));
        g->addNewComputer(new Computer(new Os("os3", 94)));
        g->setInfect(1);
        g->addEdge(0, 1);
        g->addEdge(1, 2);
        int mask = 0;
        for (int i = 0; i < 6; ++i)
        {
            g->makeTurn();
            mask = mask * 10 + getMask(g);
        }
        QVERIFY(mask == 664466);
    }

    void fullTest()
    {
        g->addNewComputer(new Computer(new Os("os1", 100)));
        g->addNewComputer(new Computer(new Os("os2", 100)));
        g->addNewComputer(new Computer(new Os("os2", 100)));
        g->addEdge(0, 1);
        g->addEdge(0, 2);
        g->addEdge(1, 2);
        g->setInfect(0);
        int mask = 0;
        for (int i = 0; i < 6; i++)
        {
            g->makeTurn();
            mask = mask * 10 + getMask(g);
        }
        QVERIFY(mask == 777777);
    }

    void emptyTest()
    {
        g->addNewComputer(new Computer(new Os("os1", 0)));
        g->addNewComputer(new Computer(new Os("os2", 0)));
        g->addNewComputer(new Computer(new Os("os2", 0)));
        g->addEdge(0, 1);
        g->addEdge(0, 2);
        g->addEdge(1, 2);
        g->setInfect(0);
        g->setInfect(1);
        g->setInfect(2);
        int mask = 0;
        for (int i = 0; i < 6; i++)
        {
            g->makeTurn();
            mask = mask * 10 + getMask(g);
        }
        QVERIFY(mask == 770000);
    }

    void oneVertexTest()
    {
        g->addNewComputer(new Computer(new Os("os1", 50)));
        g->setInfect(0);
        int mask = 0;
        for (int i = 0; i < 8; i++)
        {
            g->makeTurn();
            mask = mask * 10 + getMask(g);
        }
        QVERIFY(mask == 11000000);
    }

    void oneInfectedEverTest()
    {
        g->addNewComputer(new Computer(new Os("os1", 0)));
        g->addNewComputer(new Computer(new Os("os2", 0)));
        g->addNewComputer(new Computer(new Os("os2", 0)));
        g->addEdge(0, 1);
        g->addEdge(0, 2);
        g->addEdge(1, 2);
        g->setInfect(0);
        int mask = 0;
        for (int i = 0; i < 8; i++)
        {
            g->makeTurn();
            mask = mask * 10 + getMask(g);
        }
        QVERIFY(mask == 11000000);
    }

    void hardTest()
    {
        g->addNewComputer(new Computer(new Os("os1", 13)));
        g->addNewComputer(new Computer(new Os("os2", 19)));
        g->addNewComputer(new Computer(new Os("os3", 98)));
        g->addNewComputer(new Computer(new Os("os2", 19)));

        g->addEdge(0, 1);
        g->addEdge(0, 2);
        g->addEdge(1, 2);
        g->addEdge(0, 3);
        g->addEdge(3, 2);

        g->setInfect(0);
        g->setInfect(3);

        QVector<int> res1;

        int tmp[] = {13, 13, 12, 12, 4, 4, 13};
        QVector<int> res2;
        for (int i = 0; i < 7; i++)
            res2.push_back(tmp[i]);

        for (int i = 0; i < 7; ++i)
        {
            g->makeTurn();
            res1.push_back(getMask(g));
        }

        QVERIFY(res1 == res2);
    }



    void cleanup()
    {
        delete g;
    }

private:

    int getMask(Network *g)
    {
        int ans = 0;
        for (int i = 0; i < g->getSize(); ++i)
            if (g->isInfected(i))
                ans += (1 << i);
        return ans;
    }

    Network *g;
};


