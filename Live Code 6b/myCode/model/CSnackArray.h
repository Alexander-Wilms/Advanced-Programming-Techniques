/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CSNACKARRAY.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CSNACKARRAY_H
#define CSNACKARRAY_H
class CSnack;
class CSnackArray {
private:
    CSnack * m_snack;
    int m_number;
public:

    void deliverSnack();

    void getNumberOfSnacks();

    float getPrice();
};
/********************
**  CLASS END
*********************/
#endif /* CSNACKARRAY_H */
