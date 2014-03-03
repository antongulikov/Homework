#include "polynom.h"
#include <stdio.h>

namespace scorpion{


	
	ListElement* createElement(int power, int ratio){
		ListElement* newElement = new ListElement;
		newElement->power = power;
		newElement->ratio = ratio;
		newElement->next = nullptr;
		return newElement;
	}

	List* createList(){
		List * newList = new List;
		newList->head = createElement(1000000000, 0); 
		return newList;
	}
	

	void removeFromList(ListElement *position){
		if (position->next == nullptr) 
			return;
		ListElement * deleteElement = position->next;
		position->next = position->next->next;
		delete deleteElement;
	}

	void printList(List *myList){

		ListElement *currentPosition = myList->head->next;
		printf("Your Polynom is \n");
		while (currentPosition != nullptr){			
			printf("%d *x ^ %d ", currentPosition->ratio, currentPosition->power);
			currentPosition = currentPosition->next;
			if (currentPosition != nullptr)
				printf("+ ");
		}
		printf("\n");				
	}

	ListElement * getFirstElementLessThan(ListElement * start, int power){
		ListElement * currentElement = start;
		while (currentElement->next != nullptr && currentElement->next->power > power){
			currentElement = currentElement->next;
		}
		return currentElement;				
	}

	void deleteList(List *myList){
		while (myList->head->next != nullptr){
			removeFromList(myList->head);
		}
		delete myList->head;
		delete myList;
	}

	double value(List *myList, double x){
		double res = 0;
		ListElement *currentElement = myList->head->next;
		while (currentElement != nullptr){
			double tmp = currentElement->power;
			double ret = 1;
			while (tmp > 0){
				ret *= x;
				tmp -= 1;
			}
			res += ret * currentElement->ratio;
			currentElement = currentElement->next;
		}
		return res;
	}

	bool equals(List *first, List *second){
		ListElement *currentFirst = first->head->next;
		ListElement *currentSecond = second->head->next;

		while (currentFirst != nullptr && currentSecond != nullptr){
			if (currentFirst->power != currentSecond->power || currentFirst->ratio != currentSecond->ratio)
				return false;
			currentFirst = currentFirst->next;
			currentSecond = currentSecond->next;
		}

		return (currentFirst == nullptr && currentSecond == nullptr);
	}

	List *add(List *first, List *second){
		List *result = createList();
		ListElement *currentFirst = first->head->next;
		ListElement *currentSecond = second->head->next;
		while (currentFirst != nullptr || currentSecond != nullptr){

			if (currentFirst == nullptr){
				addToList(currentSecond->power, currentSecond->ratio, result);
				currentSecond = currentSecond->next;
			}
			else if (currentSecond == nullptr){
				addToList(currentFirst->power, currentFirst->ratio, result);
				currentFirst = currentFirst->next;
			}
			else{
				if (currentFirst->power > currentSecond->power){
					addToList(currentFirst->power, currentFirst->ratio, result);
					currentFirst = currentFirst->next;
				}
				else if (currentFirst->power < currentSecond->power){
					addToList(currentSecond->power, currentSecond->ratio, result);
					currentSecond = currentSecond->next;
				}
				else{
					if (currentSecond->ratio + currentFirst->ratio != 0)
						addToList(currentSecond->power, currentSecond->ratio + currentFirst->ratio, result);
					currentSecond = currentSecond->next;
					currentFirst = currentFirst->next;				
				}
			}

		}

		return result;
	}

	void addToList(int power, int ratio, List *myList){
		ListElement *newElement = createElement(power, ratio);
		ListElement *position = getFirstElementLessThan(myList->head, power);
		newElement->next = position-> next;
		position -> next = newElement;
	}

	void readPolynom(List *polynom){
		printf("Enter the polinom : n - number of members, each memeber represent as power and ratio\n");
		int n = 0;
		int power = 0;
		int ratio = 0;
		printf("Enter n\n");
		scanf("%d", &n);
		while (n--){
			printf("Enter power and ratio\n");
			scanf("%d %d", &power, &ratio);
			if (ratio != 0)
				addToList(power, ratio, polynom);
		}
	}

}
