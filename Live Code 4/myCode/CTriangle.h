/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CTRIANGLE.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include <string>
#include "CCoordinate.h"

#include "CGraphicObject.h"
class CTriangle : public CGraphicObject {
public:

    CTriangle(std::string name = "No Trinagle yet", CCoordinate c1 = CCoordinate(0,0), CCoordinate c2 = CCoordinate(0,0), CCoordinate c3 = CCoordinate(0,0));
};
/********************
**  CLASS END
*********************/
#endif /* CTRIANGLE_H */
