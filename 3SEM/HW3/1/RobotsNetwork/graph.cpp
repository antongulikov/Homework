#include "graph.h"

Graph::Graph(int numberOfVertex)
{
    n = numberOfVertex;
    matrix = new bool*[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new bool[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            matrix[i][j] = false;
    robotsPosition = new bool[n];
    used = new bool[n];
    for (int i = 0; i < n; ++i)
    {
        robotsPosition[i] = false;
        used[i] = false;
    }
}

Graph::~Graph()
{
    delete[] robotsPosition;
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;
    delete[] used;
}

void Graph::addEdge(int start, int finish)
{
    matrix[start][finish] = true;
    matrix[finish][start] = true;
}

void Graph::setRobotPosition(int position)
{
    robotsPosition[position] = true;
}

void Graph::removeEdge(int start, int finish)
{
    matrix[finish][start] = false;
    matrix[start][finish] = false;
}

void Graph::removeRobot(int position)
{
    robotsPosition[position] = false;
}

bool Graph::checkRobotsPositions()
{
    for (int i = 0; i < n; ++i)
        used[i] = false;
    for (int i = 0; i < n; ++i)
        if (!used[i] && robotsPosition[i])
        {
            int cntRobots = 0;
            dfs(i, cntRobots);
            if (cntRobots == 1)
                return false;
        }
    return true;
}

void Graph::dfs(int v, int &cnt)
{
    if (used[v])
        return;
    if (robotsPosition[v])
        cnt++;
   used[v] = true;
    for (int i = 0; i < n; ++i)
        if (matrix[v][i])
            for (int j = 0; j < n; ++j)
                if (matrix[i][j])
                    dfs(j, cnt);
}
