#pragma once

class Graph
{
public:

    /**
     * @brief Graph constructor for class
     * @param numberOfVertex number of vertices in Graph
     */
    Graph(int numberOfVertex = 1);
    ~Graph();

    /**
     * @brief addEdge adding edge (start, finish) in Graph
     * @param start the first vertex in edge
     * @param finish the second vertex in edge
     */
    void addEdge(int start, int finish);

    /**
     * @brief setRobotPosition adding robot in Graph in position "position"
     * @param position
     */
    void setRobotPosition(int position);

    /**
     * @brief removeEdge removing edge (start, finish) in Graph
     * @param start the first vertex in edge
     * @param finish the second vertex in edge
     */
    void removeEdge(int start, int finish);

    /**
     * @brief removeRobot removing robot from position "position"
     * @param position
     */
    void removeRobot(int position);

    /**
     * @brief checkRobotsPositions check if it's possible for robots to self-destruct
     * @return true if it's posiible and false otherwise
     */
    bool checkRobotsPositions();

private:
    int n;
    bool **matrix;
    bool *robotsPosition;
    bool *used;

    void dfs(int v, int &cnt);
};

