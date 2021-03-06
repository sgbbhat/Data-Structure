//============================================================================
// Name        : Queue.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	int value;
	node * next;
};

class Queue
{
private:
	node * frontPtr;
	node * rearPtr;
	node * tempPtr;

public:
	Queue();
	void Enqueue(int Data);
	void Dequeue();
	void print();
};

Queue::Queue()
{
	frontPtr = NULL;
	rearPtr = NULL;
	tempPtr = NULL;
}

void Queue::Enqueue(int Data)
{
	node * n = new node();
	n->value = Data;
	n->next = NULL;

	if(frontPtr == NULL && rearPtr == NULL)
	{
		frontPtr = n;
		rearPtr = n ;
	}
	else
	{
		rearPtr->next = n ;
		rearPtr = n;
	}

	cout<<"Enqueued "<<Data<<endl;
}

void Queue::Dequeue()
{
	node * delptr = new node();

	if(frontPtr == NULL)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		delptr = frontPtr;
		frontPtr = frontPtr->next;
		delptr->next = NULL;
	}
	cout<<"Dequeued "<<delptr->value<<endl;
	delete delptr;
}

void Queue::print()
{
	cout<<"Items in the queue : "<<endl;
	tempPtr = frontPtr;
	while(tempPtr != NULL)
	{
		cout<<tempPtr->value<<endl;
		tempPtr = tempPtr->next;
	}
}

int main() {
	Queue SCH1;
	SCH1.Enqueue(10);
	SCH1.Enqueue(20);
	SCH1.Enqueue(30);
	SCH1.Enqueue(40);
	SCH1.print();
	SCH1.Dequeue();
	SCH1.Dequeue();
	SCH1.print();
	SCH1.Enqueue(50);
	SCH1.Enqueue(60);
	SCH1.print();
	SCH1.Dequeue();
	SCH1.print();
	return 0;
}
