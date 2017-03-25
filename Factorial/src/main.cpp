//============================================================================
// Name        : Factorial.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int fact_rec(int n)
{
	if(n == 1)
		return 1;
	else
		return n * fact_rec(n - 1);
}

int fact_dyn(int n)
{
	int f[n+1];
	int i;

	f[0] = 1;

	for(i = 1; i <= n; i++)
	{
		f[i] = i * f[i-1];
	}

	return f[n];

}

int main() {
	cout << fact_rec(5) << endl;
	cout << fact_dyn(5) << endl;

	return 0;
}
