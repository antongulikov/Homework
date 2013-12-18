#include "scorpioncharstack.h"

namespace scorpion {

   
	CharStack *createNewCharStack(){
		CharStack *newStack = new CharStack;
		newStack->head = nullptr;
		return newStack;
	}


	CharStackElement *createNewCharStackElement(char value){
		CharStackElement *newElement = new CharStackElement;
		newElement->next = nullptr;
		newElement->value = value;
		return newElement;
	}

	void pushCharElement(CharStack *myStack, char value){
		CharStackElement *newElement = createNewCharStackElement(value);
		newElement->next = myStack->head;
		myStack->head = newElement;
	}

	char popCharElement(CharStack *myStack){
		char value = 0;
		if (myStack->head != nullptr){
			CharStackElement *tmp = myStack->head;
			value = myStack->head->value;
			myStack->head = myStack->head->next;
			delete tmp;
		}
		return value;
	}

	char topCharElement(CharStack *myStack){
		return myStack->head->value;
	}

	bool isCharStackEmpty(CharStack *myStack){
		return (myStack->head == nullptr);
	}

}

