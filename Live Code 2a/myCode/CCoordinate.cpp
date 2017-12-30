

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CCOORDINATE.CPP
* Author          :
* Description     :
*
*
****************************************************************************/


//System Include Files
#include <iostream>
using namespace std;

//Own Include Files
#include "CCoordinate.h"


//Method Implementations

void CCoordinate::print()
{
	cout << "( " << m_x << ", " << m_y << ")";
}


bool CCoordinate::set(int x, int y)
{

	//Only if both values are correct, they will be set
	if ( (x >= 0 && x <= 100) &&
		 (y >= 0 && y <= 100) )
	{
		m_x = x;
		m_y = y;
	}
	else
	{
		cout << "Read the spec you dummy" << endl;
		return false;
	}

	return true;
}

CCoordinate::CCoordinate(int x, int y)
{
	cout << "Just created a coordinate at adress " << this << endl;

	//Disadvantage, no range check
	//m_x = x;
	//m_y = y;

	if (this->set(x,y) == false)
	{
		//Error, lets set the to -1 and -1
		m_x = -1;
		m_y = -1;
		cout << "ERROR in COORDINATE: range in constructor" << endl;
	}


}

CCoordinate::~CCoordinate()
{
	cout << "Just destroyed a coordinate at adress " << this << endl;
}
