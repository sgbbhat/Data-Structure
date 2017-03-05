/*
 * DoubleLinkedList.h
 *
 *  Created on: Mar 4, 2017
 *      Author: shreeganesh
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

struct node
{
	int key;
	node * next;
	node * prev;
};

class DoubleLinkedList
{
private:
	node * headPtr;
	node * tailPtr;
	node * currPtr;
	node * tempPtr;

public:
	DoubleLinkedList();
	void AddNode(int key);
	void DeleteNode(int key);
	void PushFront(int key);
	void PushBack(int key);
	void PrintList();
};


#endif /* DOUBLELINKEDLIST_H_ */
