// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>		// Header f�r die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>

using namespace std;

#include "CMatrix.h"

int main (void)
{
    // TODO: F�gen Sie ab hier Ihren Programmcode ein
	cout << "Matrix started." << endl << endl;

	CMatrix m1(3,3,UNIT);
	m1.print();

	CMatrix m2 = m1;
	m2.print();


	return 0;
}
