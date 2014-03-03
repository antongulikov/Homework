#pragma once
#include <stack.h>

template <typename T> class ArrayStack : public Stack<T>
{
    public:
	ArrayStack();
	~ArrayStack();
	void push(T value);
	T pop();
	int size();
	bool isEmpty();

    private :
	T stack[141195];
	int actualSize;
};


