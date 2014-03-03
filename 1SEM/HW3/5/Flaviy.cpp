#include <cstdio>
#include <stdlib.h>
#include "scorpionCircleList.h"

using namespace scorpion;
using namespace std;

void messageToUser(){
	printf("Do you hear about Flaviy's problem? NO? Go and read about it!\n Now exnter the number of mens, kill's step , and i tell you , what is your position)!");
	return;
}

void printAnswer(int x){
	printf("Your place is %d.\n", x);
	return;
}

int main()
{
	messageToUser();
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	if (m == 1){
		printAnswer(n);
		return 0;
	}
	CircleListElement* firstMan = createCircleElement(1);
	CircleListElement* currentElement = firstMan;
	for (int i = 2; i <= n; i++){
		CircleListElement* newMan = createCircleElement(i);
		addToCircleList(currentElement, newMan);
		currentElement = newMan;
	}
	currentElement = firstMan;
	while (!hasOneElement(currentElement)){
		for (int i = 0; i < m - 2; i++){
			currentElement = next(currentElement);
		}
		removeFromCircleList(currentElement);
		currentElement = next(currentElement);
	}
	printAnswer(currentElement->value);
	delete currentElement;
	system("pause");

	return 0;
}
