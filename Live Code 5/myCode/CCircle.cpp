

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CCIRCLE.CPP
* Author          :
* Description     :
*
*
****************************************************************************/


//System Include Files
#include <iostream>
using namespace std;


//Own Include Files
#include "CCircle.h"

//Method Implementations



CCircle::CCircle(std::string name, unsigned int radius,
		const CCoordinate& center) : CGraphicObject(name, 1)
{
	m_radius = radius;
	set(0, center);
}

void CCircle::print()
{
	cout << endl<< endl<< "Specialised print for the circle" << endl;
	cout << "Radius: " << m_radius << endl;
	cout << "Center point: ";

	//This requires a protected scope
	m_pCoordinate[0].print();

	//Alternative approach, let's use the print method
	//CGraphicObject::print();
}
