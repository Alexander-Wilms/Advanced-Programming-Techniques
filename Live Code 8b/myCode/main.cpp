// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>
#include <string>

using namespace std;

#include "Coordinate.h"
#include "CMatrix.h"

//We want to write a function which returns the max out of 2 numbers

int myMax(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

float myMax(float a, float b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//Moving towards our first templated function

//typedef int T;

template<typename T>
T myMaxtemplate(T a, T b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main (void)
{
    // TODO: Fügen Sie ab hier Ihren Programmcode ein
	cout << "week9b gestarted." << endl << endl;

	string a = "abc";
	string b = "xyz";

	cout << myMaxtemplate(a,b) << endl;


	Coordinate<string> c1("One","Two");
	Coordinate<int> c2(2,2);
	Coordinate<string> c3;

	//Testing default behaviour
	//c3.print();

	//c1.print();

	cout << "couting...." << c1 << endl;

	//Coordinate c3;
	//c3=myMaxtemplate(c1, c2);

	//cout << myMaxtemplate(c1,c2) << endl;

	CMatrix<Coordinate, float> myMatrix1(3,3);

	return 0;
}
