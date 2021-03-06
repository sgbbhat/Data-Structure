//============================================================================
// Name        : RotateMatrix.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define N 4

void rotateMatrix_Anticlock(int mat[4][4])
{
    // Consider all squares one by one
    for (int x = 0; x < N / 2; x++)
    {
        // Consider elemet
        for (int y = x; y < N-x-1; y++)
        {
            // store current cell in temp variable
            int temp = mat[x][y];

            // move values from right to top
            mat[x][y] = mat[y][N-1-x];

            // move values from bottom to right
            mat[y][N-1-x] = mat[N-1-x][N-1-y];


            // move values from left to bottom
            mat[N-1-x][N-1-y] = mat[N-1-y][x];

            // assign temp to left
            cout<<"[N-1-y][x] : "<<mat[N-1-y][x]<<endl;

            mat[N-1-y][x] = temp;
        }
    }
}

void rotateMatrix_clock(int mat[4][4])
{
    // Consider all squares one by one
    for (int x = 0; x < N / 2; x++)
    {
        // Consider elemet
        for (int y = x; y < N-x-1; y++)
        {
            // store current cell in temp variable
            int temp = mat[x][y];

            // move values from left to top
            mat[x][y] = mat[N-1-y][x];

            // move values from bottom to left
            mat[N-1-y][x] = mat[N-1-x][N-1-y];

            // move values from right to bottom
            mat[N-1-x][N-1-y] = mat[y][N-1-x];

            mat[y][N-1-x] = temp;
        }
    }
}

int main() {
	int X[4][4] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

	cout<<"Before Rotate : "<<endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout<<X[i][j]<<" ";

		cout<<endl;
	}

	rotateMatrix_clock(X);

	cout<<"After Rotate : "<<endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout<<X[i][j]<<" ";

		cout<<endl;
	}

	return 0;
}
