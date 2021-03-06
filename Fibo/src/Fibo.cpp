//============================================================================
// Name        : Fibo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int fibo_rec(int n)
{
	if(n <= 1)
		return n;
	else
		return fibo_rec(n-1) + fibo_rec(n-2);
}

int fibo_dynprog(int n)
{
	int f[n+1];
	int i;

	f[0] = 0;
	f[1] = 1;

	for(i=2; i <= n ; i++)
	{
		f[i] = f[i-1] + f[i-2];
	}

	return f[n];
}

int main()
{
	cout << fibo_rec(6)<<endl;
	cout << fibo_dynprog(6)<<endl;

	return 0;
}
