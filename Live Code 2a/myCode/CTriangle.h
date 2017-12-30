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


#include "CCoordinate.h"
class CTriangle {
private:
    /**@link aggregation*/
    CCoordinate m_coordinate[3];

public:

    bool set(int index, int x, int y);
    void print();
};
/********************
**  CLASS END
*********************/
#endif /* CTRIANGLE_H */
