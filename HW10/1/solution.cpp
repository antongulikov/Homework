#include "listtree.h"
#include "htree.h"
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>

using namespace std;
using namespace scorpion;

const int maxn = 100000;
const int sizeAl = 256;

void dfs(TreeElement *currentElement, int mask, int *value){
	if (currentElement == nullptr)
		return;
	if (currentElement->finish){
		value[currentElement->symbol] = mask;		
	}
	dfs(currentElement->left, mask << 1, value);
	dfs(currentElement->right, (mask << 1) | 1, value);
}

void printNumber(int x){
	bool fl = false;
	for (int i = 30; i >= 0; i--){
		if ((x & (1 << i)) > 0)
			fl = true;
		if (fl)
			printf( (x & (1 << i)) ? "1" : "0");
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char *parseString = new char[maxn];
	memset(parseString, '\0', maxn);
	fgets(parseString, maxn, stdin);

	int *ratio = new int[sizeAl];
	int *who = new int[sizeAl];

	for (int i = 0; i < sizeAl; i++)
		ratio[i] = 0;
	for (int i = 0; i < sizeAl; i++)
		who[i] = i;

	for (int i = 0; i < strlen(parseString); i++)
		ratio[parseString[i]]++;

	for (int i = 0; i < sizeAl; i++)
		for (int j = i; j < sizeAl; j++)
			if (ratio[i] < ratio[j]){
				swap(ratio[i], ratio[j]);
				swap(who[i], who[j]);
			}
	int sumAll = 0;
	for (int i = 0; i < sizeAl; i++)
		sumAll += ratio[i];
	for (int i = 0; i < sizeAl; i++)
		if (ratio[i] > 0){
                	printf("%c - %d/%d\n", who[i], ratio[i], sumAll);
		}

	List *myList = createList();

	int allSize = 0;

	for (int i = 0; i < sizeAl; i++)
		if (ratio[i] > 0){
			add(myList, createTreeElement(true, who[i], ratio[i]));
			allSize++;
		}

	TreeElement *first;
	TreeElement *second;
	TreeElement *root;

	for (int i = 0; i < allSize - 1; i++){
		first = pop(myList);
		second = pop(myList);		
		add(myList, merge(first, second)); 
	}

	

	root = pop(myList);

	printTree(root);
	printf("\n");

	int *value = new int[sizeAl];

	for (int i = 0; i < sizeAl; i++)
		value[i] = 0;

	dfs(root, 1, value);

	for (int i = 0; i < sizeAl; i++)
		if (ratio[i] > 0){
			printf("%c is ", who[i]);
			printNumber(value[who[i]]);
			printf("\n");
		}
	
	for (int i = 0; i < strlen(parseString); i++)
		printNumber(value[parseString[i]]);

	delete myList->header->key;
	deleteList(myList);

	deleteTree(root);
	delete[] ratio;
	delete[] who;
	delete[] value;
	delete[] parseString;

	return 0;
}