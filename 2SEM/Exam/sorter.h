#pragma once
#include "commoncomporator.h"

///class for sorting array

class Sorter
{
public:
	Sorter();
	~Sorter();
	template <typename T> void sort(T *array, int size, CommonComporator<T> *cmp){
		for (int i = 0; i < size - 1; i++)
			for (int j = i; j < size; j++)
				if (!cmp->compare(array[i], array[j])){
					T tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
				}
	}
};






