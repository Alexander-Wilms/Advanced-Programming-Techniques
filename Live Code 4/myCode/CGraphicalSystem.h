/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CGRAPHICALSYSTEM.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CGRAPHICALSYSTEM_H
#define CGRAPHICALSYSTEM_H

//Todo: Check if we really need all includes here
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CScreen.h"
#include "CDatabase.h"


class CGraphicalSystem {
private:
    /**@link aggregationByValue*/
    CDatabase m_database;
    /**@link aggregationByValue*/
    CScreen m_screen;
public:

    CGraphicalSystem();

    void print();
};
/********************
**  CLASS END
*********************/
#endif /* CGRAPHICALSYSTEM_H */
