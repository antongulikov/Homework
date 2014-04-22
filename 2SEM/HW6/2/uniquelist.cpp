#include "uniquelist.h"

void UniqueList :: insert(int value) throw(DuplicateException){
	if (find(value))
		throw DuplicateException("Already exists!");
	push(value);	
}

int UniqueList :: erase(int value) throw(ExistException){
	if (!find(value))
		throw ExistException("Element doesn't exists!");
	pop(value);		
	return value;
}
