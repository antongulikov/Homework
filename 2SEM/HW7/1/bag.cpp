#include "bag.h"

Bag::Bag() : size(0){
	helperMap.clear();
}

Bag::~Bag(){
	helperMap.clear();
}

void Bag::insert(int value){
	size++;
	helperMap[value]++;
}

void Bag::erase(int value){
	if (helperMap[value] > 0){
		size--;
		helperMap[value]--;
	}
}

bool Bag::find(int value){
	return (helperMap[value] > 0);
}

int Bag::getSize(){
	return size;
}
