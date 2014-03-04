#pragma once
#include <stack.h>
#include <cstdio>


template <typename T> class LinStack : public Stack<T>
{
    public:
	LinStack(){
		head = new stackElement;
		head->next = NULL;
		actualSize = 0;
	}

	~LinStack(){
		while (head->next != NULL){
			stackElement *tmp = head->next;
			head->next = tmp->next;
			delete tmp;
		}
		delete head;
	}

	void push(T value){
		stackElement *tmp = new stackElement;
		tmp->value = value;
		tmp->next = head->next;
		head->next = tmp;
		actualSize++;
	}

	T top(){
		return head->next->value;
	}

	T pop(){
		actualSize--;
		T result = head->next->value;
		stackElement *tmp = head->next;
		head->next = head->next->next;
		delete tmp;
		return result;
	}

	int size(){
		return actualSize;
	}

	bool isEmpty(){
		return (actualSize == 0);
	}

	private :

	struct stackElement{
		T value;
		stackElement *next;
	};
	stackElement *head;
	int actualSize;
};

