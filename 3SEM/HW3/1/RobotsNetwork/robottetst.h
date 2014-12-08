#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "graph.h"

class robotTetst : public QObject
{
    Q_OBJECT
public:
    explicit robotTetst(QObject *parent = 0);

private slots:

    void twoRobotsTrueTest()
    {
        Graph g(3);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.setRobotPosition(1);
        g.setRobotPosition(2);
        QVERIFY(g.checkRobotsPositions());
    }

    void oneRobotFalseTest()
    {
        Graph g(3);
        for (int i = 0; i < 3; ++i)
            for (int j = i + 1; j < 3; ++j)
                g.addEdge(i, j);
        g.setRobotPosition(0);
        QVERIFY(!g.checkRobotsPositions());
    }

    void zeroRobotsTrueTest()
    {
        Graph g(5);
        for (int i = 0; i < 5; ++i)
            for (int j = i + 2; j < 5; ++j)
                g.addEdge(i, j);
        QVERIFY(g.checkRobotsPositions());
    }

    void comlexFalseTest()
    {
        Graph g(10);
        for (int i = 3; i < 10; ++i)
            for (int j = i + 3; j < 10; ++j)
                g.addEdge(i, j);
        for (int i = 0; i < 10; i += 2)
            g.setRobotPosition(i);
        QVERIFY(!g.checkRobotsPositions());
    }

    void comlexTrueTest()
    {
        Graph g(10);
        for (int i = 0; i < 10; ++i)
            for (int j = i + 3; j < 10; ++j)
                g.addEdge(i, j);
        for (int i = 1; i < 10; i += 2)
            g.setRobotPosition(i);
        QVERIFY(g.checkRobotsPositions());
    }
};

