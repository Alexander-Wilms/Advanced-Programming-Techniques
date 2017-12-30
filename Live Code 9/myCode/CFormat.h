/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CFORMAT.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CFORMAT_H
#define CFORMAT_H

using namespace std;

#include "CFileIO.h"
#include <string>

class CFormat {
public:

    void translateFromFormat();

    void translateToFormat(string s);
};
/********************
**  CLASS END
*********************/
#endif /* CFORMAT_H */
