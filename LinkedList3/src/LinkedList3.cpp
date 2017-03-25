//============================================================================
// Name        : LinkedList3.cpp
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

// Class definition
class List
{
private:
	node * headPtr;
	node * currPtr;
	node * tempPtr;

public:
	List();
	void AddNode(int key);			// Adds node to the list
	void DeleteNode(int key);		// Delete node to the list
	void PrintList();				// Prints list elements
};

List::List()
{
	headPtr = NULL;
	currPtr = NULL;
	tempPtr = NULL;
}

void List::AddNode(int key)
{
	node * n = new node();
	n->key = key;
	n->next = NULL;

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
	}
}

void List::DeleteNode(int key)
{
	node * delPtr = new node();

	if(headPtr == NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		currPtr = headPtr;

		while(currPtr != NULL && currPtr->key != key)
		{
			tempPtr = currPtr;
			currPtr = currPtr->next;
		}

		if(currPtr == NULL)
		{
			cout<<"Key not in the list"<<endl;
		}
		else
		{
			if(currPtr == headPtr)
			{
				delPtr = currPtr;
				headPtr = headPtr->next;
			}
			else
			{
				delPtr = currPtr ;
				currPtr = currPtr->next;
				tempPtr->next = currPtr;
			}
		}
		delete delPtr;
	}
}

void List::PrintList()
{
	currPtr = headPtr;

	if(headPtr == NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		while(currPtr != NULL)
		{
			cout<<currPtr->key<<endl;
			currPtr = currPtr->next;
		}++
	}
}


int main() {
	List List1;
	List1.AddNode(1);
	List1.AddNode(2);
	List1.AddNode(3);
	List1.AddNode(4);

	List1.PrintList();

	List1.DeleteNode(1);
	List1.PrintList();

	List1.DeleteNode(3);
	List1.DeleteNode(2);
	List1.DeleteNode(4);
	List1.PrintList();

	return 0;
}
