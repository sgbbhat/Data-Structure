//============================================================================
// Name        : ReducedString.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	string s1;
	string result = "";
	map<char, int> m;
	map<char, int>::iterator it;

	cout << "Insert the string to be reduced : " << endl;
	cin >> s1;
	unsigned i = 0 ;

	while(i < s1.length())
	{
		if(s1[i] == s1[i+1])
		{
			s1.erase(i, 2);
		}
		else
			i++;
	}
	cout<<"Result : "<< s1 <<endl;
	return 0;
}
