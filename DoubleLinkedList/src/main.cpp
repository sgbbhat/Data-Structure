//============================================================================
// Name        : DoubleLinkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;

using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
	headPtr = NULL;
	tailPtr = NULL;
	currPtr = NULL;
	tempPtr = NULL;
}

void DoubleLinkedList::AddNode(int key)
{
	node * n = new node();
	n->key = key;
	n->next = NULL;
	n->prev = NULL;

	if(headPtr == NULL)
	{
		headPtr = n;
		tailPtr = n;
	}
	else
	{
		currPtr = headPtr;

		while(currPtr != NULL )
		{
			currPtr = currPtr->next;
		}

		currPtr->next = n;
		n->prev = currPtr;
	}
}

void DoubleLinkedList::PrintList()
{
	currPtr = headPtr;

	while(currPtr != NULL)
	{
		cout<<currPtr->key<<endl;
		currPtr = currPtr->next;
	}
}

int main() {
	DoubleLinkedList DList;
	DList.AddNode(10);
	DList.AddNode(20);
	DList.AddNode(30);
	DList.AddNode(40);
	DList.PrintList();
	return 0;
}
