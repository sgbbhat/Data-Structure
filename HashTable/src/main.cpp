//============================================================================
// Name        : HashTable.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

struct item
{
	string name;
	string drink;
	item * next;
};

class hashTable
{
private:
	static const int tableSize = 10;
	item * tableHash[tableSize];

public:
	hashTable();
	int HashFunction(string key);
	void AddItem(string name, string drink);
	int NoOfItemInIndex(int index);
	void PrintTable();
};

void hashTable::PrintTable()
{
	for(int j=0; j<tableSize ; j++)
	{
		cout<<"----------------------"<<endl;
		cout<<"Index = "<<j<<endl;
		cout<<tableHash[j]->name<<endl;
		cout<<tableHash[j]->drink<<endl;
		cout<<"No of items = "<<NoOfItemInIndex(j)<<endl;
		cout<<"----------------------"<<endl;
	}
}

int hashTable::NoOfItemInIndex(int index)
{
	int count = 0;
	if(tableHash[index]->name == "empty")
	{
		return count;
	}
	else
	{
		count++;
		item * ptr = tableHash[index] ;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
			count++;
		}
		return count;
	}
}

int hashTable::HashFunction(string key)
{
	int hash = 0;
	for(int i = 0; i< (int)key.length(); i++)
	{
		hash = hash + (int)key[i];
	}
	hash = hash % tableSize;
	return hash;
}


hashTable::hashTable()
{
	for(int i = 0; i<tableSize ; i++)
	{
		tableHash[i] = new item() ;
		tableHash[i]->drink = "empty";
		tableHash[i]->name = "empty";
		tableHash[i]->next = NULL;
	}
}

void hashTable::AddItem(string name, string drink)
{
	int index = HashFunction(name);

	if(tableHash[index] == NULL)
	{
		tableHash[index]->name = name;
		tableHash[index]->drink = drink;
	}
	else
	{
		item * ptr = tableHash[index];
		item * n = new item();
		n->name = name;
		n->drink = drink;
		n->next = NULL;

		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = n;
	}
}

int main()
{
	hashTable hash;
	cout<<hash.HashFunction("Paul");
	return 0;
}
