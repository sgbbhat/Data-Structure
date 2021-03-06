//============================================================================
// Name        : LListWithTail.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LListWithTail.h"
using namespace std;

ListWithTail::ListWithTail()
{
	headPtr = NULL;
	tailPtr = NULL;
	currPtr = NULL;
	tempPtr = NULL;
}

bool ListWithTail::isEmpty()
{
	if(headPtr == NULL)
		return true;
	else
		return false;
}

void ListWithTail::pushFront(int key)
{
	node * n = new node();
	n->key = key;

	if(headPtr == NULL)
	{
		headPtr = n;
		tailPtr = n;
		n->next = NULL;
	}
	else
	{
		n->next = headPtr;
		headPtr = n;
	}
}

void ListWithTail::pushBack(int key)
{
	node * n = new node();
	n->key = key;
	n->next = NULL;

	if(tailPtr == NULL)
	{
		headPtr = n;
		tailPtr = n;
	}
	else
	{
		tailPtr->next = n ;
		tailPtr = n;
	}
}

void ListWithTail::printList()
{
	currPtr = headPtr;

	if(currPtr == NULL)
	{
		cout<<"List is empty "<<endl;
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

int ListWithTail::topFront()
{
	if(headPtr == NULL)
	{
		cout<<"List is empty"<<endl;
		return 0;
	}
	else
		return headPtr->key;
}

int ListWithTail::topBack()
{
	if(tailPtr == NULL)
	{
		cout<<"List is empty"<<endl;
		return 0;
	}
	else
		return tailPtr->key;
}

void ListWithTail::popFront()
{
	node * delPtr = new node();
	delPtr->next = NULL;
	if(headPtr == NULL)
		cout<<"List is empty"<<endl;
	else
	{
		delPtr = headPtr;
		headPtr = headPtr->next;
		if(headPtr == NULL)
		{
			tailPtr = NULL;
		}
	}
	delete delPtr;
	cout<<"popFront successful"<<endl;
}

bool ListWithTail::findKey(int key)
{
	currPtr = headPtr;

	while(currPtr != NULL && currPtr->key != key)
	{
		currPtr = currPtr->next;
	}

	if(currPtr == NULL)
		return false;
	else
		return true;
}

void ListWithTail::popBack()
{
	node * delptr = new node();
	currPtr = headPtr;

	while(currPtr->next != NULL)
	{
		tempPtr = currPtr;
		currPtr = currPtr->next;
	}

	delptr = tailPtr;
	tailPtr = tempPtr;

	delete delptr;
}

void ListWithTail::deleteKey(int key)
{
	node * delPtr = new node();
	currPtr = headPtr;
	tempPtr = headPtr;

	while(currPtr != NULL and currPtr->key != key)
	{
		tempPtr = currPtr;
		currPtr = currPtr->next;
	}

	if(currPtr == NULL)
	{
		cout<<"Could not be found"<<endl;
	}
	else
	{
		delPtr = currPtr;
		delPtr->next = NULL;
		currPtr = currPtr->next;
		tempPtr->next = currPtr;
	}
	delete delPtr;
}

int main() {
	ListWithTail List;

	// Push Front
	List.pushFront(10);
	List.pushFront(20);
	List.pushFront(30);
	List.pushFront(40);

	// Push Back
	List.pushBack(50);
	List.pushBack(60);
	List.pushBack(70);
	List.pushBack(80);
	List.printList();

	if(List.findKey(10))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;

	if(List.findKey(15))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;

	return 0;
}
