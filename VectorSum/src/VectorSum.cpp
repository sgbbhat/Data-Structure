//============================================================================
// Name        : VectorSum.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    int sum = 0;
    cout<<"No of items in the list : "<<endl;
    cin >> n;
    vector<int> arr(n);
    vector<int>::iterator it;
    for(int arr_i = 0;arr_i < n;arr_i++)
    {
    	cout<<"Enter the element "<<arr_i<<endl;
    	cin >> arr[arr_i];
    }

    for(it = arr.begin() ; it != arr.end(); it++)
    {
    	sum = sum + *it;
    }

    cout<<sum;

    return 0;
}
