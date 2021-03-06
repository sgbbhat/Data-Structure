/*
 * LListWithTail.h
 *
 *  Created on: Mar 4, 2017
 *      Author: shreeganesh
 */

#include <iostream>

#ifndef LLISTWITHTAIL_H_
#define LLISTWITHTAIL_H_


struct node
{
	int key;
	node * next;
};

class ListWithTail
{
private:
	node * headPtr;
	node * tailPtr;
	node * currPtr;
	node * tempPtr;

public:
	ListWithTail();
	void pushFront(int key);
	void pushBack(int key);
	int topFront();
	void popFront();
	int topBack();
	void popBack();
	bool findKey(int key);
	void deleteKey(int key);
	bool isEmpty();
	void printList();
};


#endif /* LLISTWITHTAIL_H_ */
