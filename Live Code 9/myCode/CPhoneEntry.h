/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPHONEENTRY.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CPHONEENTRY_H
#define CPHONEENTRY_H

#include <string>

using namespace std;

class CPhoneEntry {
private:
    unsigned int m_number;
    string m_name;
public:

    void getStringRepresentation();
};
/********************
**  CLASS END
*********************/
#endif /* CPHONEENTRY_H */
