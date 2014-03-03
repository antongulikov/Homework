#include "scorpionList.h"
#include <cstdio>
#include <stdlib.h>

using namespace scorpion;
using namespace std;

void messageToUser(){
	printf("------------------\n");
	printf("-  User comands  -\n");
	printf("-    0 - exit    -\n");
	printf("-   1 x - add x  -\n");
	printf("- 2 x - delete x -\n");
	printf("- 3 - print list -\n");
	printf("------------------\n");
}

void enterTheCommand(){
	printf("Enter the command!\n");
	return;
}

void enterTheElement(){
	printf("Enter the element!\n");
	return;
}

enum userCommand{
	uexit,
	uadd,
	udelete,
	uprint
};

int main(){

	messageToUser();
	int command = 0;
	enterTheCommand();
	scanf("%d", &command);
	List *myList = createList();
	ListElement *protectedElement = createElement(-(1 << 30));
	myList->head = protectedElement;

	 while (command != uexit){

		int value = 0;

		if (command == uadd || command == udelete){
			enterTheElement();
			scanf("%d", &value);
		}

		if (command == uadd){
			ListElement *currentElement = getFirstElementLessThan(myList->head, value);
			addToList(value, currentElement);
			printf("Element %d has been added to the list.\n", value);
		}

		if (command == udelete){
			ListElement *currentElement = getFirstElementLessThan(myList->head, value);
			removeFromList(currentElement);
			printf("Element %d has been removed from the list.\n", value);
		}

		if (command == uprint){
			printf("Current list : ");
			printList(myList);
			printf("\n");
		}
		enterTheCommand();
		scanf("%d", &command);
	}

	deleteList(myList);
	
	return 0;
}
