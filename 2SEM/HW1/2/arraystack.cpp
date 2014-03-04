#include "arraystack.h"

template <typename T> ArrayStack<T> :: ArrayStack() : actualSize(0)
{
}

template <typename T> ArrayStack<T> :: ~ArrayStack()
{
}

template <typename T> void ArrayStack<T> :: push(T value)
{
	stack[actualSize++] = value;
}

template <typename T> T ArrayStack<T> :: pop()
{
	return stack[--actualSize];
}

template <typename T> int ArrayStack<T> :: size()
{
	return actualSize;
}

template <typename T> bool ArrayStack<T> :: isEmpty()
{
	return actualSize == 0;
}
