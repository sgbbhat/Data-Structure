//============================================================================
// Name        : BST.cpp
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
	node * left;
	node * right;
};

class BST
{
private:
	node * root;
	void AddLeafPrivate(int key, node * Ptr);
	void PrintInOrderPrivate(node * Ptr);

public:
	BST();
	node * CreateLeaf(int key);
	void AddLeaf(int key);
	void PrintInOrder();
};

BST::BST()
{
	root = NULL;
}

node * BST::CreateLeaf(int key)
{
	node * n = new node();
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void BST::AddLeafPrivate(int key, node * Ptr)
{
	if(root == NULL)
		root = CreateLeaf(key);
	else if(key < Ptr->key)
	{
		if(Ptr->left != NULL)
			AddLeafPrivate(key, Ptr->left);
		else
			Ptr->left = CreateLeaf(key);
	}
	else if(key > Ptr->key)
	{
		if(Ptr->right != NULL)
			AddLeafPrivate(key, Ptr->right);
		else
			Ptr->right = CreateLeaf(key);
	}
	else
		cout<<"Key "<<key<< " has been already added to the tree"<<endl;
}

void BST::AddLeaf(int key)
{
	AddLeafPrivate(key, root);
}

void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node * Ptr)
{
	if(root != NULL)
	{
		if(Ptr->left != NULL)
		{
			PrintInOrderPrivate(Ptr->left);
		}
		cout<<Ptr->right<<" " ;
		if(Ptr->right != NULL)
		{
			PrintInOrderPrivate(Ptr->right);
		}
	}
	else
		cout<<"Tree is empty"<<endl;
}

int main() {
	int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2,3, 70, 87, 80};
	BST myTree;


	return 0;
}
