//============================================================================
// Name        : LinkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	int data;
	node * next;
};

class LinkedList
{
private:
	node * currPtr;
	node * tempPtr;
	node * headPtr;

public:
	LinkedList();
	void addNode(int Data);
	void deleteNode(int Data);
	void print();
};

LinkedList::LinkedList()
{
	currPtr = NULL;
	tempPtr = NULL;
	headPtr = NULL;
}

void LinkedList::addNode(int Data)
{
	node * n = new node();
	n->data = Data;
	n->next = NULL;

	if(headPtr == NULL)
	{
		headPtr = n;
	}
	else
	{
		currPtr = headPtr ;
		while(currPtr->next == NULL)
		{
			currPtr = currPtr->next;
		}

		currPtr->next = n;
	}
}

void LinkedList::deleteNode(int Data)
{
	node * delPtr = new node();
	currPtr = headPtr;
	tempPtr = headPtr;

	if(headPtr == NULL)
	{
		cout<< "Nothing to delete"<<endl;
	}
	else
	{
		while(currPtr != NULL && currPtr->data != Data)
		{
			tempPtr = currPtr;
			currPtr = currPtr->next;
		}

		if(currPtr == NULL)
		{
			cout<< "Data passed not in the list"<<endl;
		}
		else
		{
			delPtr = currPtr;
			currPtr = currPtr->next;
			tempPtr->next = currPtr;

			if(delPtr == headPtr)
			{
				headPtr = headPtr->next;
				tempPtr = NULL;
			}
		}
		cout<<Data<<" was deleted"<<endl;
		delete delPtr;
	}
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
