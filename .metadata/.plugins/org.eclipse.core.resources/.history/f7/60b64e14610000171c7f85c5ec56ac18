//============================================================================
// Name        : Stack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Stack Data Structure implementation in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>

using namespace std;

class Stack
{
private:
	struct item
	{
		string name;
		int value;
		item * prev;
	};
	item * stackPtr;
public:
	Stack();
	~Stack();
	void pop();
	void push(string name, int value);
	void readItem(item * r);
	void print();
};

Stack::Stack()
{
	stackPtr = NULL;
}


Stack::~Stack()
{
	item * p1;
	item * p2;

	p1 = stackPtr; 				// Pointing to top of the stack or NULL

	while(p1 != NULL)
	{
		p2 = p1;
		p1 = p1->prev;
		p2->prev = NULL;
		delete p2;
	}
}

void Stack::push(string name, int value)
{
	item * n = new item();
	n->name = name;
	n->value = value;

	if(stackPtr == NULL)
	{
		stackPtr = n;
		stackPtr->prev = NULL;
	}
	else
	{
		n->prev = stackPtr;
		stackPtr = n;

	}
}

void Stack::readItem(item * r)
{
	cout<<"-------------------------"<<endl;
	cout<<"name : "<< r->name <<endl;
	cout<<"value : "<< r->value <<endl;
	cout<<"-------------------------"<<endl;
}

void Stack::pop()
{
	if(stackPtr == NULL)
	{
		cout<<"Nothing to pop"<<endl;
	}
	else
	{
		item * n = new item();
		n = stackPtr;
		readItem(n);
		stackPtr = stackPtr->prev;
		n->prev = NULL;
		delete n;
	}
}

void Stack::print()
{
	item * p = stackPtr;

	if(p == NULL)
	{
		cout<<"No items in stack";
	}
	else
	{
		while(p->prev != NULL)
		{
			readItem(p);
			p = p->prev;
		}
	}
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
