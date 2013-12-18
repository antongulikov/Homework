#pragma once

namespace scorpion{

	struct CharStackElement{
		char value;
		CharStackElement * next;
	};

	struct CharStack{
		CharStackElement *head;
	};

	CharStack *createNewCharStack();

	CharStackElement *createNewCharStackElement(char value);

	void pushCharElement(CharStack *myStack, char value);

	char topCharElement(CharStack *myStack);

	char popCharElement(CharStack *myStack);

	bool isCharStackEmpty(CharStack *myStack);

}

