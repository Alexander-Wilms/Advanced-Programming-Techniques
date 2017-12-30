/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CDATABASE.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CDATABASE_H
#define CDATABASE_H

#include "CGraphicObject.h"

class CDatabase {
    private:
	unsigned int m_size;
	unsigned int m_nextFreeObject;
     /**@link aggregationByValue
     * @clientCardinality 1
     * @supplierCardinality 0..**/
    CGraphicObject** m_pObject;
    //Same story for the other objects...

public:

    CDatabase(unsigned int size = 10);

    ~CDatabase();

    void print();

    bool addElement(object_t type, std::string name);

    CGraphicObject* getAdressOfObject(std::string name);
};
/********************
**  CLASS END
*********************/
#endif /* CDATABASE_H */
