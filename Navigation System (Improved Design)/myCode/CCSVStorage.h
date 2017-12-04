/*
 * CCSVStorage.h
 *
 *  Created on: 03.12.2017
 *      Author: awilms
 */

#ifndef MYCODE_CCSVSTORAGE_H_
#define MYCODE_CCSVSTORAGE_H_

#include "CPersistentStorage.h"
#include "CPoiDatabase.h"
#include "CWpDatabase.h"
#include <fstream>
#include <string>

class CCSVStorage: public CPersistentStorage {
public:
	CCSVStorage();

	~CCSVStorage();

	/**
	* Set the name of the media to be used for persistent storage.
	* The exact interpretation of the name depends on the implementation
	* of the component.
	*
	* @param name the media to be used
	*/
	void setMediaName(std::string name);

	/**
	* Write the data to the persistent storage.
	*
	* @param waypointDb the data base with way points
	* @param poiDb the database with points of interest
	* @return true if the data could be saved successfully
	*/
	bool writeData(const CWpDatabase& waypointDb, const CPoiDatabase& poiDb);

	/**
	* Fill the databases with the data from persistent storage. If
	* merge mode is MERGE, the content in the persistent storage
	* will be merged with any content already existing in the data
	* bases. If merge mode is REPLACE, already existing content
	* will be removed before inserting the content from the persistent
	* storage.
	*
	* @param waypointDb the the data base with way points
	* @param poiDb the database with points of interest
	* @param mode the merge mode
	* @return true if the data could be read successfully
	*/
	bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb, CPersistentStorage::MergeMode mode);


	/**
	 * The type of error detected while parsing the CSV file
	 */
	enum ParseError {
		ERR_TOO_FEW_FIELDS,
		ERR_TOO_MANY_FIELDS,
		ERR_TEXT_INSTEAD_OF_NUMBER,
		ERR_COMMA_INSTEAD_OF_POINT,
		ERR_EMPTY_FIELD_NAME,
		ERR_EMPTY_FIELD_TYPE,
		ERR_EMPTY_FIELD_DESCRIPTION,
		ERR_EMPTY_FIELD_LATITUDE,
		ERR_EMPTY_FIELD_LONGITUDE,
		ERR_UNKNOWN_POI_TYPE,
		ERR_COULDNT_PARSE_LONGITUDE,
		ERR_COULDNT_PARSE_LATITUDE
	};

	/**
	 * Prints the specified error to the console
	 */
	void printError(ParseError problem, unsigned int lineNumber, std::string lineContent);

	std::string getDigits(const std::string& source);

private:
	std::string mediaName;

	std::string trim(const std::string& source, const std::string& t);
};

#endif /* MYCODE_CCSVSTORAGE_H_ */
