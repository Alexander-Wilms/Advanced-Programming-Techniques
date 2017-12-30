// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>
using namespace std;

#include "CGraphicObject.h"
#include "CTriangle.h"
#include "CCircle.h"
#include "CDatabase.h"

#include "CGraphicalSystem.h"

int main (void)
{

	cout << "week4 gestarted." << endl << endl;

#if 0
	cout << "Testing the grPHICAL OBJECT...."  <<endl;
	CGraphicObject go1("Graphic object 1", 3);
	go1.set(0,1,1);
	go1.set(1,2,2);
	go1.set(2,3,3);

	go1.print();

	cout << endl << "some error handling checks: index" << endl;
	go1.set(4,4,4);


	go1.print();

	cout << endl << "some error handling checks:value" << endl;
	go1.set(2,-100,0xffffffff);

	go1.print();
#endif

#if 0
	cout << "Testing a triangle" << endl;
	CTriangle t1("t1", CCoordinate(11,11), CCoordinate(22,22), CCoordinate(33,33));

	t1.print();

#endif

#if 0
	cout << "Testing a circle" << endl;
	CCircle c1("c1", 123, CCoordinate(1,2));

	c1.print();

#endif

#if 0
	cout << "Testing a database" << endl;

	CDatabase d1(10);
	d1.addElement(t1);
	d1.print();
#endif

	cout << "Testing the fullblown system...."  << endl;
	CGraphicalSystem g1;
	g1.print();

	return 0;
}
