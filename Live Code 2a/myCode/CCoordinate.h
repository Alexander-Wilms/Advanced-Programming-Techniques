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
	/**
	 * Range 0..100
	 * Special value: -1 in case of wrong initialisation
	 */
    int m_x;

	/**
	 * Range 0..100
	 * Special value: -1 in case of wrong initialisation
	 */
    int m_y;
    //char dummy[5]; simply for testing
public:

    /**
     * Our constructor, which will be called automatically
     * whenever an object is created
     * Please take the parameters x and y if they are provided
     * If the User is not providing parameters, take the default values 0 and 0
     * If the data is wrong, please set them to -1 and -1
     */
    CCoordinate(int x = 0, int y = 0);

    /**
     * Destructor
     */
    ~CCoordinate();

    /**
     * This method will print a coordinate.
     */
    void print();

    /**
     * Here we set a coordinate value, checking for some limits. 
     * IMPORTANT: whenever a function might throw an error, this error has to be
     * communicated to the caller, by return value, exception,..
     */
    bool set(int x, int y);
};
/********************
**  CLASS END
*********************/
#endif /* CCOORDINATE_H */
