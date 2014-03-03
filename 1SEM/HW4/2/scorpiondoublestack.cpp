#include "scorpiondoublestack.h"

namespace scorpion {

	DoubleStack *createNewDoubleStack(){
		DoubleStack *newStack = new DoubleStack;
		newStack->head = nullptr;
		return newStack;
	}

	DoubleStackElement *createNewDoubleStackElement(double value){
		DoubleStackElement *newElement = new DoubleStackElement;
		newElement->next = nullptr;
		newElement->value = value;
		return newElement;
	}

	void pushDoubleElement(DoubleStack *myStack, double value){
		DoubleStackElement *newElement = createNewDoubleStackElement(value);
		newElement->next = myStack->head;
		myStack->head = newElement;
	}

	double popDoubleElement(DoubleStack *myStack){
		double value = 0;
		if (myStack->head != nullptr){
			DoubleStackElement *tmp = myStack->head;
			value = myStack->head->value;
			myStack->head = myStack->head->next;
			delete tmp;
		}
		return value;
	}

	double topDoubleElement(DoubleStack *myStack){
		return myStack->head->value;
	}

	bool isDoubleStackEmpty(DoubleStack *myStack){
		return (myStack->head == nullptr);
	}

}

