//============================================================================
// Name        : iofStream.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream mystream;
	mystream.open("//home//shreeganesh//Documents//C++//Data-Structure//iofStream//example.txt");
	mystream<<"Testing iostream"<<endl;
	return 0;
}
