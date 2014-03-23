#include <bubblesort.h>
#include <quicksort.h>
#include <iostream>
#include "testsort.h"

using namespace std;

void testBubbleSort(){
	int length = 10;
	int args[length];
	cout <<"Before :";
	for (int index = 0; index < length; index++){
		args[index] = ((1 << index) ^ (1 << (2 * index))) ^ (1 << (1 << index));
		cout << args[index] << " ";
	}
	cout << endl;		
	Sort *bSort = new BubbleSort();
	bSort->sort(args, length);
	cout << "After :";
	for (int index = 0; index < length; index++){
		cout << args[index] << " ";
	}
	cout << endl;
	delete bSort;
}

void testQuickSort(){
	int length = 10;
	int args[length];
	cout <<"Before :";
	for (int index = 0; index < length; index++){
		args[index] = (((1 << index) | (1 << (2 * index))) ^ (1 << (1 << index))) | (1 << index) >> 1;
		cout << args[index] << " ";
	}
	cout << endl;		
	Sort *qSort = new QuickSort();
	qSort->sort(args, length);
	cout << "After :";
	for (int index = 0; index < length; index++){
		cout << args[index] << " ";
	}
	cout << endl;
	delete qSort;
}

int main(){
	TestSort test;
	QTest :: qExec(&test);
	testQuickSort();
	testBubbleSort();
}
