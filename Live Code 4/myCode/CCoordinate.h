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

/**
 * A coordinate object represents a pair of values, x and y. 
 */
class CCoordinate {
private:
    /**
     * The x coordinate value 
     */
    int m_x;
    /**
     * The y coordinate value 
     */
    int m_y;
public:

    /**
     * The Constructor
     * @param int x Inital x value, default  0
     * @param int y initial y value, default 0 
     */
    CCoordinate(int x = 0, int y = 0);
    /**
     * This method will print a coordinate.
     * @param void
     * @return void
     */
    void print();

    /**
     * Set a coordinate value
     * @param int x Inital x value, default  0, range 0..100
     * @param int y initial y value, default 0, range 0..100
     * @return bool, true if value has been in range, false if value has not been in range
     */
    bool set(int x, int y);
};
/********************
**  CLASS END
*********************/
#endif /* CCOORDINATE_H */
