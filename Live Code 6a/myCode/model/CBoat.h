/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CBOAT.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CBOAT_H
#define CBOAT_H
#include "CPerson.h"
#include "CSailor.h"
#include "CCaptain.h"
class CBoat {
private:
    int m_speed;
    int m_course;
    int m_maxSpeed;
    /**@link aggregation
     * @supplierCardinality 1..**/
    CPerson lnkCPerson;
public:

    void command();

    void sail();

    void leaveBoat();

    void enterBoat();
};
/********************
**  CLASS END
*********************/
#endif /* CBOAT_H */
