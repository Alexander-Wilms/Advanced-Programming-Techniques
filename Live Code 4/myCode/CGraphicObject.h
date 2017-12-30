/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CGRAPHICOBJECT.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CGRAPHICOBJECT_H
#define CGRAPHICOBJECT_H

#include <string>

//Please do not open a namespace in a header file, because otherwise it will
//be opened by any file including this header
//using namespace std;

#include "CCoordinate.h"

class CGraphicObject {
private:

	/**
	 * The name will be used to identify the object
	 */
    std::string m_name;

    /**
     * The number of coordinates
     * Valid range: 0...whatever
     */
    unsigned int m_noCoordinates;

protected:
    /**@link aggregationByValue
     * @clientCardinality 1
     * @supplierCardinality 1..**/
    CCoordinate* m_pCoordinate;
public:

    /**
     * Constructor
     * @param unsigned short noCoordinates name of the object
     * @param unsigned short noCoordinates the number of coordinates needed for the object
     */
    CGraphicObject(std::string name = "Unnamed GraphicalObject", unsigned short noCoordinates = 1);


    /**
     * Will set a value
     * In case the coordiante will be out of range, the value will not change
     * @param signed short dx pixel movement in x direction
     * @param signed short dy pixel movement in y direction
     * return true if movement was successfull
     */
    bool set(unsigned short index, unsigned int short x, unsigned int short y);

    /**
     * Will set a value
     * In case the coordiante will be out of range, the value will not change
     * @param signed short dx pixel movement in x direction
     * @param signed short dy pixel movement in y direction
     * return true if movement was successfull
     */
    bool set(unsigned short index, CCoordinate const& c);

    /**
     * Will print a graphical object on the screen
     */
    void print();

    /**
     * Will move a coordinate as defined by the parameters
     * In case the coordiante will be out of range, the value will not change
     * @param signed short dx pixel movement in x direction
     * @param signed short dy pixel movement in y direction
     * return true if movement was successfull
     */
    bool move(signed short dx, signed short dy);

    //Will discusss this later...
    CGraphicObject& operator=(CGraphicObject const& origin);

    std::string getName();

};
/********************
**  CLASS END
*********************/
#endif /* CGRAPHICOBJECT_H */
