//============================================================================
// Name        : DynamicArray.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

void print(int *p, int size)
{
	cout<<"Printing the content of an array"<<endl;
	for(int i=0; i< size; i++)
	{
		cout<<p[i]<<endl;
	}
}

int main()
{
	int * p ;
	int size;
	cout<<"Size of the array : "<<endl;
	cin>>size;
	p = new (nothrow) int [size] ;
	if (p == nullptr)
	{
	  cout<<"Error in allocation"<<endl;
	}
	else
	{
		for(int i=0; i<size; i++)
		{
			cout<<"Value of element "<<i+1<<": "<<endl;
			cin>>p[i];
		}
		print(p, size);
	}

	// Dynamic array increment
	int init_size = 2;
	int * ptrArray = new int[init_size];
	int j =0;
	int no_elements = 0;
	int test = 0;
	while(test < 4)
	{
		cout<<"Enter element to be added : "<<endl;
		cin>>ptrArray[j];
		j = j+1;
		no_elements = no_elements + 1;
		if(no_elements > init_size - 1)
		{
			init_size = init_size * 2;
			int * ptrArray_new = new int[init_size];
			memcpy(&ptrArray, &ptrArray_new , init_size/2);
			test ++ ;
		}
	}

	return 0;
}
