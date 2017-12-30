/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CWAYPOINT.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CWAYPOINT_H
#define CWAYPOINT_H

#include <string>

using namespace std;

class CWaypoint {
private:
    double m_lattitude;
    double m_longitude;
    string m_name;
public:

    void getStringRepresentation();
};
/********************
**  CLASS END
*********************/
#endif /* CWAYPOINT_H */
