

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CTRIANGLE.CPP
* Author          :
* Description     :
*
*
****************************************************************************/


//System Include Files
#include <iostream>
using namespace std;

//Own Include Files
#include "CTriangle.h"
#include "CCoordinate.h"

//Method Implementations

void CTriangle::print()
{
	for (int i = 0; i < 3; i++)
	{
		m_coordinate[i].print();
	}
}

bool CTriangle::set(int index, int x, int y)
{
	//Let's first check the valid index
	if (index < 0 || index >= 3)
	{
		//Error condition
		cout << "ERROR [Triangle]: wrong index" << endl;
		return false;
	}
	else
	{
		//all ok
	}

	return m_coordinate[index].set(x, y);


}
