#include <iostream>
#include "otree.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace scorpion;

int main()
{
	printf("Enter expression!\n Don't forget brackets!!!\n");

	const int maxn = 10000;
	Tree *tree = createTree();
	char *s = new char[maxn];
	fgets(s, maxn, stdin);

	parseString(s, tree);
	printTree(tree);
	printf("  ==  %.10f\n", calc(tree));

	system("pause");

	deleteTree(tree);
	delete[] s;
	delete tree;

	return 0;
}

