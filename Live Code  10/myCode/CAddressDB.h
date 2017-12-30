/////////////////////////////////////////////////////////////////////////////
// SGSE1-Labor
// CAdress.h
//
// Das h-File kann auch leer bleiben, wenn es die Aufgabe nicht erfordert,
// ein h-File zu schreiben
//
// h-Files werden im Allgemeinen f�r die Modularisierung von Software ben�tigt
// durch h-Files ist es n�mlich m�glich, Prototypen von Funktionen oder 
// Klassendefinitionen auch in cpp-Files zu verwenden, in denen die Funktionen 
// oder Klassen nicht implementiert sind
//

// das folgende Kontrukt verhindert, dass der Inhalt von 
// h-Files mehrfach includiert wird
//
#ifndef CAddress_H
#define CAddress_H

#include <vector>
#include <map>

#include "CFileIO.h"
#include "CRecord.h"

enum t_print{ALL, FILTER, SORTED, SORTED_BY_ADDR};

namespace APT {

class CAddressDB
{

private:
	
	std::string m_filename;

    /**
     * @link aggregationByValue
     * @supplierCardinality 0..*
     * @clientCardinality 1
     */
    std::vector<APT::CRecord> m_records;

    std::map<int, APT::CRecord*> m_recordsByNumber;

    /**
     * @link association
     * @clientQualifier m_phone
     * @directed
     * @supplierCardinality 0..1
     * @clientCardinality 1*/
    CRecord lnkCRecord;
public:

    /**
     * Constructor 
     */
    CAddressDB(std::string filename);

    /**
     * Destructor 
     */
    ~CAddressDB();

    /**
     * Find a record, given the phone number.
     * Return 0 if not found, else a pointer to the record
     */
    const CRecord* findByNumber(int phone) const;

    /**
     * Select records for printing
     */
    std::vector<CRecord> select(t_print t, std::string filter = "");

    /**
     * Prints all record which match to "filter"
     */
    void print(t_print t);

    /**
     * Adds a record to the database 
     */
    void addRecord(const APT::CRecord& c);

    /**
     * Save all records to a file. 
     */
    void saveToFile();

    /**
     * Load records from file 
     */
    bool loadFromFile();

};

} // namespace
	
#endif
