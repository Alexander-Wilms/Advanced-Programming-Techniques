// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>

using namespace std;

#include "CComplex.h"
#include "CComplexSet.h"


int main (void)
{

	cout << "Some overloaded methods, operators and other funny stuff..." << endl << endl;

	CComplex c1(1,1);
	CComplex c2(2,2);

	CComplex c3(CComplex::ONE);

	CComplex c4;

	c4 = c1 + c2;
	//Same line as the one before
	c4 = c1.operator+(c2);

	//We are brave
	c4 = c2 + CComplex(1,0);

	c4 = 1 + c2;

	//This will come later
	//c4 = operator+(c1,c2);

	cout << "Test " <<  c4 << endl;

	c4 += 123;
	cout << "Another Test " <<  c4 << endl;

	cout << "Let's play with some STL containers " << endl;

	CComplexSet cs;
	cs.addElement(c1);
	cs.addElement(c2);
	cs.addElement(c3);
	cs.addElement(c4);

	cs.print();

	cs.saveToFile("complex.txt");

	return 0;
}
