//============================================================================
// Name        : LinkedList2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	int key;
	node * next;
};

class LinkedList
{
private:
	node * headPtr;
	node * currPtr;
	node * tempPtr;

public:
	LinkedList();
	void AddNode(int key);
	void DeleteNode(int key);
	void PrintList();
};

LinkedList::LinkedList()
{
	headPtr = NULL;
	currPtr = NULL;
	tempPtr = NULL;
}

void LinkedList::AddNode(int key)
{
	node * n = new node();
	n->key = key;

	if(headPtr == NULL)
	{
		headPtr = n;
	}
	else
	{
		currPtr = headPtr;
		while(currPtr->next != NULL)
		{
			currPtr = currPtr->next;
		}
		currPtr->next = n;
		n->next = NULL;
	}
}

void LinkedList::DeleteNode(int key)
{
	node * delPtr = new node();
	delPtr->next = NULL;

	if(headPtr == NULL)
		cout<<"List is empty"<<endl;
	else
	{
		currPtr = headPtr ;
		while(currPtr != NULL && currPtr->key != key)
		{
			tempPtr = currPtr ;
			currPtr = currPtr->next;
		}

		if(currPtr == NULL)
			cout<<"Key not in the list"<<endl;
		else
		{
			delPtr = currPtr;
			currPtr = currPtr->next;
			tempPtr->next = currPtr;
		}

		delete delPtr;
	}
}

void LinkedList::PrintList()
{
	currPtr = headPtr;
	while (currPtr != NULL)
	{
		cout<<currPtr->key<<endl;
		currPtr = currPtr->next;
	}

	cout<<"Content of the list printed successfully"<<endl;
}

int main() {
	LinkedList List;
	List.AddNode(10);
	List.AddNode(20);
	List.AddNode(30);
	List.AddNode(40);
	List.PrintList();

	List.DeleteNode(30);
	List.PrintList();

	List.DeleteNode(35);
	List.PrintList();

	return 0;
}
