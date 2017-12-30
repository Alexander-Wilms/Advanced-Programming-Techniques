/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CADRESSDATABASE.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CADRESSDATABASE_H
#define CADRESSDATABASE_H
#include "CStorage.h"
#include "CFormat.h"
#include "CFileIO.h"
#include "CExport.h"
class CAdressDatabase {
private:
    /**@link aggregationByValue
     * @clientCardinality 1
     * @supplierCardinality 1*/
    CStorage m_storage;
    /**@link aggregationByValue*/
    CExport lnkCExport;
public:

    void writeToFile();

    void readFromFile();

    void print();
};
/********************
**  CLASS END
*********************/
#endif /* CADRESSDATABASE_H */
