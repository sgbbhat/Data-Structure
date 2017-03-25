//============================================================================
// Name        : VirtualFunction.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Person
{
public:
	virtual ~Person()
	{
		cout<<"Person deleted"<<endl;
	}
	void virtual AboutMe()
	{
		cout<<"I am a person"<<endl;
	}
};

class student:public Person
{
public:
	~student()
	{
		cout<<"Student deleted"<<endl;
	}
	void AboutMe()
	{
		cout<<"I am a student"<<endl;
	}
};

int main() {

	Person * n2 = new student();
	n2->AboutMe();

	delete n2;

	return 0;
}
