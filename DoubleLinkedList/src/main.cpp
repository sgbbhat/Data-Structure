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
		n->prev = tailPtr;
		tailPtr->next = n;
		tailPtr = n;
	}
}

void DoubleLinkedList::PrintList()
{
	currPtr = headPtr;

	if(currPtr == NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		while(currPtr != NULL)
		{
			cout<<currPtr->key<<endl;
			currPtr = currPtr->next;
		}
	}

}

void DoubleLinkedList::PushFront(int key)
{
	node * n = new node();
	n->key = key;
	n->next = NULL;
	n->prev = NULL;

	currPtr = headPtr;

	if(currPtr == NULL)
	{
		headPtr = n;
		tailPtr = n;
	}
	else
	{
		currPtr->prev = n;
		n->next = currPtr;
		headPtr = n;
	}
}

void DoubleLinkedList::PushBack(int key)
{
	node * n = new node();
	n->key = key;
	n->next = NULL;
	n->prev = NULL;

	if(tailPtr == NULL)
	{
		headPtr = n;
		tailPtr = n;
	}
	else
	{
		n->prev = tailPtr ;
		tailPtr->next = n;
		tailPtr = n;
	}
}

void DoubleLinkedList::DeleteNode(int key)
{
	node * delPtr = new node();

	currPtr = headPtr;
	tempPtr = headPtr;

	if(headPtr == NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		while(currPtr != NULL && currPtr->key != key)
		{
			tempPtr = currPtr;
			currPtr = currPtr->next;
		}

		if(currPtr == NULL)
		{
			cout<<"Key "<<key << " not in the list"<<endl;
		}
		else
		{
			delPtr = currPtr;
			currPtr = currPtr->next;
			currPtr->prev = tempPtr;
			tempPtr->next = currPtr;
		}
	}
	delete delPtr;
}

int main() {
	DoubleLinkedList DList;

	cout<<"Testing Add Node"<<endl;
	// Testing Add Node
	DList.AddNode(10);
	DList.AddNode(20);
	DList.AddNode(30);
	DList.AddNode(40);
	DList.PrintList();

	cout<<"Testing Push Front"<<endl;
	// Testing Push Front
	DList.PushFront(50);
	DList.PushFront(60);
	DList.PrintList();

	cout<<"Testing Push Back"<<endl;
	// Testing Push Back
	DList.PushBack(70);
	DList.PushBack(80);
	DList.PrintList();

	cout<<"Testing Delete"<<endl;
	// Testing Delete
	DList.DeleteNode(15);
	DList.DeleteNode(30);
	DList.PrintList();

	return 0;
}
