#include "scorpionCircleList.h"

namespace scorpion
{

	CircleListElement* createCircleElement(int value){
		CircleListElement *newElement = new CircleListElement;
		newElement->value = value;
		newElement->next = newElement;
		return newElement;
	}

	CircleList* createCircleList(){
		CircleList * newList = new CircleList;
		newList = nullptr;
		return newList;
	}

	void removeFromCircleList(CircleListElement* position){
		CircleListElement* tmp = position->next->next;
		delete position->next;
		position->next = tmp;
	}

	void addToCircleList(CircleListElement* position, CircleListElement* newElement){
		newElement->next = position->next;
		position->next = newElement;
	}

	CircleListElement* next(CircleListElement *position){
		return position->next;
	}

	bool hasOneElement(CircleListElement *position){
		return position->next == position;
	}

}
