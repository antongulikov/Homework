#pragma once

template <typename T> class Stack
{
    public:

	Stack();
	virtual ~Stack() = 0;
	virtual void push(T value) = 0;
	virtual T pop() = 0;
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
};


