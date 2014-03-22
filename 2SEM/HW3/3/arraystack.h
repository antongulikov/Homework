#pragma once
#include <stack.h>

template <typename T> class ArrayStack : public Stack<T>
{
	public:
	ArrayStack(){
		actualSize = 0;
	}

	~ArrayStack(){
	}

	void push(T value){
		stack[actualSize++] = value;
	}

	T pop(){
		return stack[--actualSize];
	}

	T top(){
		return stack[actualSize - 1];
	}

	int size(){
		return actualSize;
	}

	bool isEmpty(){
		return (actualSize == 0);
	}

	private :
		T stack[141195];
		int actualSize;
};


