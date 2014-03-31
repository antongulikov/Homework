#pragma once
#include <QtTest/QtTest>
#include <QObject>
#include "priorityqueue.h"
#include <iostream>
#include "queueexception.h"

using namespace std;

class QueueTest : public QObject
{
	Q_OBJECT
public:
	explicit QueueTest(QObject *parent = 0);
	
private slots:

	void init(){
		intQueue = new PriorityQueue<int, 100>;
		doubleQueue = new PriorityQueue<double, 100>;		
	}
	
	void cleanup(){
		delete intQueue;
		delete doubleQueue;
	}

	void pushTest(){
		intQueue->enqueue(1, 1);
		doubleQueue->enqueue(1.5, 1);
	}
	
	void popTest(){
		intQueue->enqueue(1, 1);
		doubleQueue->enqueue(1.5, 1);
		QCOMPARE(1, intQueue->dequeue());
		QCOMPARE(1.5, doubleQueue->dequeue());		
	}
	
	void popFromEmptyTest(){
		try{
			intQueue->dequeue();			
		}
		catch(const QueueException &exec){
			QCOMPARE("Queue is empty!",exec.get());
		}
		try{
			doubleQueue->dequeue();
		}
		catch(const QueueException &exec){
			QCOMPARE("Queue is empty!",exec.get());
		}
	}
	
	void sortElementTest(){
		intQueue->enqueue(6, 1);
		intQueue->enqueue(1, 6);
		intQueue->enqueue(2, 5);
		intQueue->enqueue(5, 2);
		intQueue->enqueue(4, 3);
		intQueue->enqueue(3, 4);
		for (int i = 1; i <= 6; i++)
			QCOMPARE(i, intQueue->dequeue());		
	}
	
	void MaxSizeTest(){
		for (int i = 1; i <= 100; i++)
			intQueue->enqueue(i, i);
		try{
			intQueue->enqueue(101, 101);
		}
		catch(const QueueException &exec){	
			QCOMPARE("Queue is full!",exec.get());		
		}	
	}

private :
	PriorityQueue<int, 100> *intQueue;
	PriorityQueue<double, 100> *doubleQueue;
	
};

