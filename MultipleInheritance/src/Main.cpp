//============================================================================
// Name        : MultipleInheritance.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class shape
{
protected:
	int width;
	int height;

public:
	void setwidth(int w)
	{
		width = w;
	}

	void setheight(int h)
	{
		height = h;
	}
};

class paintcost
{
public:
	int getcost(int area)
	{
		return area * 70;
	}
};

class Rectangle:public shape, public paintcost
{
public:
	int getarea()
	{
		return (width * height);
	}
};

int main() {
	Rectangle Rect;
	int area, cost;
	Rect.setwidth(5);
	Rect.setheight(7);

	area = Rect.getarea();
	cost = Rect.getcost(area);
	cout<<"Area of the rectangle = "<<area<<endl;
	cout<<"Cost to paint the rectangle = "<<cost<<endl;

	return 0;
}
