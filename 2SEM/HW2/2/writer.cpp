#include "writer.h"
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

Writer::~Writer()
{
}

pair <int, int> Writer::getPosition(int position, int sizeOfMatrix)
{
	position = sizeOfMatrix * sizeOfMatrix - position;
	int level = static_cast<int>(0.5 * (sizeOfMatrix - (sqrt(0.0 + sizeOfMatrix * sizeOfMatrix - position))));	
	position -= (sizeOfMatrix * 4 * level - 4 * level * level);
	int resultX = level + 1;
	int resultY = level + 1;
	int tmpSize = sizeOfMatrix - 2 * level;
	resultY += min(position, tmpSize - 1);
	position = max(0, position - tmpSize + 1);
	resultX += min(position, tmpSize - 1);
	position = max(0, position - tmpSize + 1);
	resultY -= min(position, tmpSize - 1);
	position = max(0, position - tmpSize + 1);
	resultX -= min(position, max(0, tmpSize - 2));	
	return make_pair(resultX - 1, resultY - 1);
}
