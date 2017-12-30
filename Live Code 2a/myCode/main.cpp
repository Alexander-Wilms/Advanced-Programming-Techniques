// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>

#include "CCoordinate.h"
#include "CTriangle.h"

using namespace std;




int main (void)
{
    // TODO: Fügen Sie ab hier Ihren Programmcode ein
	cout << "Playing around with some classes" << endl << endl;

	cout << endl << "Testing a coordinate" << endl;
	CCoordinate c1;
	c1.print();


	return 0;

	cout << endl << "Testing a triangle" << endl;

	CTriangle myTriangle;

	//Some testcases
	if (myTriangle.set(2,1000,2))
	{
		cout << "Set coordinate 0" << endl;
	}
	else
	{
		cout << "Error in setting coordinate 0" << endl;
	}
	myTriangle.set(1,10,20);
	myTriangle.set(2,30,40);

	myTriangle.print();


	return 0;
}
