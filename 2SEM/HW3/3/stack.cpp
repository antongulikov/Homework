#pragma once

template <typename T> class Stack
{
	public:

	Stack(){
	}

	virtual ~Stack(){
	}

	virtual void push(T value) = 0;
	virtual T pop() = 0;
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	virtual T top() = 0;
};


