/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CCIRCLE.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CCIRCLE_H
#define CCIRCLE_H

#include <string>

#include "CGraphicObject.h"


class CCircle : public CGraphicObject {
private:
    unsigned int m_radius;
public:

    CCircle(std::string name, unsigned int radius = 0, CCoordinate const& center = CCoordinate(0,0));

    /**
     * Specialised print for the circle
     */
    void print();

};
/********************
**  CLASS END
*********************/
#endif /* CCIRCLE_H */
