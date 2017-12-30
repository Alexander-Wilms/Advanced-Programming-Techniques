

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


void CCoordinate::set(int x, int y)
{
	if (x >= 0 && x <= 100 )
	{
		m_x = x;
	}
	else
	{
		m_x = 0;
		cout << "Read the spec you dummy" << endl;
	}

	if (y >= 0 && y <= 100 )
	{
		m_y = y;
	}
	else
	{
		m_y = 0;
		cout << "Read the spec you dummy" << endl;
	}


}
