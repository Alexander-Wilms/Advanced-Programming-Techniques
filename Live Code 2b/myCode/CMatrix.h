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

enum matrixInit_t{ZERO, ONE, UNIT, INDEX};

typedef int matrixdata_t;

class CMatrix {
private:
    matrixdata_t* m_pData;
    unsigned short m_noColumns;
    unsigned short m_noRows;
public:

    CMatrix(unsigned short noRows = 1, unsigned short noColumns = 1, matrixInit_t init = ONE);

    void print();

    ~CMatrix();

private:
    unsigned int getIndex(unsigned short row, unsigned short column);

};
/********************
**  CLASS END
*********************/
#endif /* CMATRIX_H */
