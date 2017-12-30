/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CEXPORT.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CEXPORT_H
#define CEXPORT_H
#include "CFileIO.h"
class CStorage;
class CFormat;
class CExport {
private:
    /**@link aggregationByValue*/
    CFileIO lnkCFileIO;
    /**@link aggregationByValue
     * @clientCardinality 1
     * @supplierCardinality 1*/
    CFormat* m_pFormat;
    CStorage * lnkCStorage;
};
/********************
**  CLASS END
*********************/
#endif /* CEXPORT_H */
