#pragma once
#include "emptyqueueexception.h"
#include "maxsizequeueexception.h"
#include <iostream>
using namespace std;

template <typename T, int maxSize>

/// Class for priority queue
class PriorityQueue
{
public:

	PriorityQueue(){
		size = 0;
	}
	
	/// Push in Queue
 	void enqueue(T value, int priority){
		if (size == maxSize)
			throw MaxSizeQueueException("Queue is full!");
		size++;
		q[size].value = value;
		q[size].priority = priority;
		reheap_up(size);		
	}
	
	/// Pop from Queue
	T dequeue(){
		if (size != 0){
			T result = q[1].value;
			swap(q[1], q[size--]);
			reheap_down(1);
			return result;			
		} else{			
			throw EmptyQueueException("Queue is empty!");				
		}
	}	
	
	
	
private:	
	
	struct QueueElement{
		T value;
		int priority;
	};
	
	
	void swap(QueueElement &a, QueueElement &b){
		QueueElement c;
		c = a;
		a = b;
		b = c;		
	}
	
	QueueElement q[maxSize];
	int size;
	
	/// Push up element
	void reheap_up(int position){
		int parent = position >> 1;
		if (parent == 0)
			return;
		if (q[parent].priority < q[position].priority){
			swap(q[parent], q[position]);
			reheap_up(parent);							
		}	
	}
	
	/// Push down element
	void reheap_down(int position){
		int leftPosition = (position << 1);
		int rightPosition = leftPosition + 1;
		int resultPostion = position;
		if (rightPosition <= size && q[rightPosition].priority > q[resultPostion].priority)
			resultPostion = rightPosition;
		if (leftPosition <= size && q[leftPosition].priority > q[resultPostion].priority)
			resultPostion = leftPosition;
		if (resultPostion != position){
			swap(q[resultPostion], q[position]);
			reheap_down(resultPostion);		
		}			
	}
	
};
