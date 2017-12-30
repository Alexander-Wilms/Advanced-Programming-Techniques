

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


//Own Include Files
#include "CTriangle.h"

//Method Implementations

CTriangle::CTriangle(std::string name, CCoordinate c1, CCoordinate c2, CCoordinate c3) : CGraphicObject("Triangle "+name, 3)
{
	set(0,c1);
	set(1,c2);
	set(2,c3);
}
