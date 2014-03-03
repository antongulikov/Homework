#include <iostream>
#include "avlset.h"
#include <stdio.h>
#include <stdlib.h>


using namespace std;
using namespace scorpion;

void printOperation(){
	printf("0 - exit\n");
	printf("1 x - add element to the set\n");
	printf("2 x - remove element from the set\n");
	printf("3 x - find element in the set\n");
	printf("4 - print elements in increasing order\n");
	printf("5 - print elements in decreasing order\n");
	printf("6 - print elements in debuger order\n");
}

enum userCommands{
	uexit,
	uadd,
	uremove,
	ufind,
	uprinti,
	uprintd,
	uprintde
};

int main()
{
	Tree *avl = createTree();
	while (141 < 195){
		printOperation();
		int command = 0;
		scanf("%d", &command);
		if (command == uexit)
			break;
		if (command == uadd){
			int x = 0;
			scanf("%d", &x);
			insert(x, avl);
			printf("Element %d had been added!\n", x);
		}
		if (command == uremove){
			int x = 0;
			scanf("%d", &x);
			remove(x, avl);
			printf("Element %d had been removed!\n", x);
		}
		if (command == ufind){
			int x = 0;
			scanf("%d", &x);
			if (find(x, avl))
				printf("Element %d is in the set\n", x);
			else
				printf("Element %d isn't in the set\n", x);
		}
		if (command == uprinti){
			printInIncreasingOrder(avl);
		}
		if (command == uprintd){
			printInDecreasingOrder(avl);
		}
		if (command == uprintde){
			printDebugerOrder(avl);
		}
	}
	deleteTree(avl);
	return 0;
}

