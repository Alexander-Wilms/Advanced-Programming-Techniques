/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CSCREEN.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CSCREEN_H
#define CSCREEN_H

#include <string>

#include "CDatabase.h"
#include "CTriangle.h"

class CScreen {
private:
	unsigned int m_size;
	unsigned int m_nextFreeTriangle;
    /**@link aggregation
     * @clientCardinality 1
     * @supplierCardinality 0..**/
	CTriangle** m_pTriangle;
    CDatabase* m_pDatabase;


public:

    CScreen (unsigned int size = 10);

    void connect(CDatabase* db);

    bool addElement(std::string name);

    void print();
};
/********************
**  CLASS END
*********************/
#endif /* CSCREEN_H */
