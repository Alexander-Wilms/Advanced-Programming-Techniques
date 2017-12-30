/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CMATRIX.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CMATRIX_H
#define CMATRIX_H

#include "CCoordinate.h"

enum matrixInit_t{ZERO, ONE, UNIT, INDEX};

typedef CCoordinate matrixdata_t;


//Note
//This header is not fully commented, check the coordinate class for examples....
class CMatrix {
private:
    /**
     * @link aggregationByValue
     * @supplierCardinality 1..*
     * @clientCardinality 1 
     */
    matrixdata_t* m_pData;

    unsigned short m_noColumns;
    unsigned short m_noRows;

    static int m_count;
public:

    CMatrix(unsigned short noRows = 1, unsigned short noColumns = 1, matrixInit_t init = ONE);

    /**
     * Copy constructor, takes another object of the same class for initialisation
     */
    CMatrix(CMatrix const& origin);

    ~CMatrix();
    //Const here means: The method will not modify the object
    //The method can be used for const objects
    void print() const;

    bool set(unsigned short row, unsigned short column, matrixdata_t value);



private:
    unsigned int getIndex(unsigned short row, unsigned short column) const;


};
/********************
**  CLASS END
*********************/
#endif /* CMATRIX_H */
