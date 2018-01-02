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

#include "CCircle.h"
#include "CTriangle.h"
#include "CRectangle.h"


class CDatabase {
    private:
	unsigned int m_size;
	unsigned int m_nextFreeTriangle;
    /**@link aggregationByValue
     * @clientCardinality 1
     * @supplierCardinality 0..**/
    CCircle* m_circle;
     /**@link aggregationByValue
     * @clientCardinality 1
     * @supplierCardinality 0..**/
    CTriangle* m_triangle;
    /**@link aggregationByValue
     * @clientCardinality 1
     * @supplierCardinality 0..**/


    //Same story for the other objects...


    CRectangle* m_rectangle;
public:

    CDatabase(unsigned int size = 10);

    void print();

    bool addElement(CTriangle const& t);

    CTriangle* getAdressOfTriangle(std::string name);
};
/********************
**  CLASS END
*********************/
#endif /* CDATABASE_H */
