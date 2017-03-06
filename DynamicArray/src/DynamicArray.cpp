//============================================================================
// Name        : DynamicArray.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
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

	return 0;
}