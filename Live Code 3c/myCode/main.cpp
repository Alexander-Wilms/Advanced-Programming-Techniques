// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>		// Header f�r die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>

using namespace std;

#include "CMatrix.h"
#include "CCoordinate.h"


int main (void)
{
    // TODO: F�gen Sie ab hier Ihren Programmcode ein
	cout << "Matrix started." << endl << endl;

	cout << "Matrix M1: " << endl;
	CMatrix m1(3,3,UNIT);
	m1.print();

	return 0;
}
