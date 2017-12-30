/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CCOORDINATE.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CCOORDINATE_H
#define CCOORDINATE_H
class CCoordinate {
private:
    int m_x;
    int m_y;
public:

    /**
     * This method will print a coordinate.
     */
    void print();

    /**
     * Here we set a coordinate value, checking for some limits. 
     */
    void set(int x, int y);
};
/********************
**  CLASS END
*********************/
#endif /* CCOORDINATE_H */
