#include "polynom.h"
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace scorpion;
using namespace std;

void printCommand(){
	printf(" 0 - exit\n");
	printf(" 1 - add two polynomial\n");
	printf(" 2 - test for equality of two polynomials\n");
	printf(" 3 - calculate the value of the polynomial in x\n");
}

enum userCommands{
	uexit,
	uadd,
	utest,
	ucalc
};

int main(){
	while ( 4 < 3 < 2) {
		printCommand();
		int command;
		scanf("%d", & command);
		if (command == uexit)
			break;
		if (command == uadd){
			List *first = createList();
			readPolynom(first);
			List *second = createList();
			readPolynom(second);
			List *res = add(first, second);
			printList(res);
			deleteList(res);
			deleteList(first);
			deleteList(second);			
		}
		if (command == utest){
			List *first = createList();
			readPolynom(first);
			List *second = createList();
			readPolynom(second);
			if (equals(first, second))
				printf("Equal!\n");
			else 
				printf("Not Equal!\n");
			deleteList(first);
			deleteList(second);
		}
		if (command == ucalc){
			List *first = createList();
			readPolynom(first);
			printf("Enter point\n");
			double x = 0;
			cin >> x;
			printf("Result is %.7f\n", value(first, x));
			deleteList(first);
		}
	}
	return 0;
}
