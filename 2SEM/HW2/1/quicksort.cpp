#include "quicksort.h"

QuickSort::QuickSort()
{
}

QuickSort::~QuickSort()
{
}

void QuickSort::qSort(int *args, int leftPosition, int rightPosition){
	int currentLeftPosition = leftPosition;
	int currentRightPosition = rightPosition;
	int seperatingElement = args[currentLeftPosition];
	while (currentLeftPosition <= currentRightPosition){
		while (args[currentLeftPosition] < seperatingElement)
			currentLeftPosition++;
		while (seperatingElement < args[currentRightPosition])	
			currentRightPosition--;
		if (currentLeftPosition <= currentRightPosition){
			swap(args[currentLeftPosition], args[currentRightPosition]);
			currentLeftPosition++;
			currentRightPosition--;		
		}				
	}
	if (leftPosition < currentRightPosition)
		qSort(args, leftPosition, currentRightPosition);
	if (currentLeftPosition < rightPosition)
		qSort(args, currentLeftPosition, rightPosition);
}

void QuickSort :: sort(int *args, int length){
	qSort(args, 0, length - 1);
}
