// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>		// Header für die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>

using namespace std;

#include "CMatrix.h"

void printaMatrix(CMatrix const& m)
{
	//ALthough set is not strictly modifying the object content, it is not declared as const
	//m.set(0,0,123);
	m.print();
}

void printMatrixByPointer(CMatrix const * const pm)
{
	pm->print();
}

int main (void)
{
    // TODO: Fügen Sie ab hier Ihren Programmcode ein
	cout << "Matrix started." << endl << endl;

	cout << "Matrix M1: " << endl;
	CMatrix m1(3,3,UNIT);
	m1.print();

	cout << "Calling a function" << endl;
	printaMatrix(m1);
	cout << "Returning from a function" << endl;

	cout << "Matrix M1 after function call: " << endl;
	m1.print();


	cout << "Matrix M2: " << endl;
	CMatrix m2 = m1;
	m2.set(2,2,22);
	m2.print();

	cout << "Matrix M1: " << endl;
	m1.print();

	cout << "A very optimistic story..." << endl;
	//Here, not the copy constructor but the assignment operator
	//(will be presented in a few lectures) has been used
	//As we did not implement this operator, again a shallo copy is used
	CMatrix m3;
	m3 = m2;
	m3.print();


	return 0;
}
