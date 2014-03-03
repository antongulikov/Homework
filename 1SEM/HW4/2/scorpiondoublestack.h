#pragma once

namespace scorpion{

	struct DoubleStackElement{
		double value;	
		DoubleStackElement * next;
	};

	struct DoubleStack{
		DoubleStackElement *head;
	};

	DoubleStack *createNewDoubleStack();

	DoubleStackElement *createNewDoubleStackElement(double value);

	void pushDoubleElement(DoubleStack *myStack, double value);

	double popDoubleElement(DoubleStack *myStack);

	double topDoubleElement(DoubleStack *myStack);

	bool isDoubleStackEmpty(DoubleStack *myStack);
}

