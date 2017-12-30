// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>

#include "CCoordinate.h"

using namespace std;


typedef struct {
	int x;
	int y;
} coordinate_t;

typedef struct
{
	coordinate_t corner[3];
}triangle_t;


void TRIANGLE_print(triangle_t const * const pTriangle)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Corner: " << i+1 << " = (" << pTriangle->corner[i].x << ", " << pTriangle->corner[i].y << ")" << endl;

	}
}

int main (void)
{
    // TODO: Fügen Sie ab hier Ihren Programmcode ein
	cout << "Hello world" << endl << endl;

	//Bad hack for creating a triangle
	int x1, y1, x2, y2, x3, y3;

	//C-Style OO
	triangle_t myTriangle;
	myTriangle.corner[0].x =1;
	myTriangle.corner[0].y =1;
	myTriangle.corner[1].x =2;
	myTriangle.corner[1].y =2;
	myTriangle.corner[2].x =3;
	myTriangle.corner[2].y =3;
	TRIANGLE_print(&myTriangle);


	//Real C++ classes
	CCoordinate c1;
	//c1.m_x = 1;
	//c1.m_y = 1;
	c1.set(1,333);
	c1.print();

	CCoordinate c2;

	return 0;
}
