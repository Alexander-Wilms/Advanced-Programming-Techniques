/*
 * CCSVStorage.h
 *
 *  Created on: 03.12.2017
 *      Author: Fabian Alexander Wilms
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
	enum ParseStatus {
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
		ERR_COULDNT_PARSE_LATITUDE,
		ERR_TOO_MANY_POINTS,
		OK
	};

	/**
	 * Prints the specified error to the console
	 */
	void printError(CCSVStorage::ParseStatus problem, unsigned int lineNumber, std::string lineContent);

	std::string getDigits(const std::string& source);

private:
	/**
	 * base name of the database files
	 * The file names are:
	 * - <mediaName>-wp.txt
	 * - <mediaName>-poi.txt
	 */
	std::string mediaName;

	/**
	 * The character used to separate the fields
	 */
	std::string m_delimiter;

	/**
	 * Check if there are as many fields in this line as expected
	 *
	 * @param line The current line
	 * @param expectedNo The expected number of fields
	 *
	 * @return OK or an error
	 */
	ParseStatus checkNoOfFields(const std::string& line, unsigned int expectedNo) const;

	/**
	 * Extract the longitude from the remainder of the current line
	 *
	 * @param remainingLine The remainder of the current line
	 * @param longitudeParsed Variable to return the longitude by reference
	 *
	 * @return OK or an error
	 */
	ParseStatus extractLongitude(std::string& remainingLine, double& longitudeParsed);

	/**
	 * Extract the POI or waypoint latitude from the remainder of the current line
	 *
	 * @param remainingLine The remainder of the current line
	 * @param latitudeParsed Variable to return the latitude by reference
	 *
	 * @return OK or an error
	 */
	ParseStatus extractLatitude(std::string& remainingLine, double& latitudeParsed);

	/**
	 * Extract the name from the remainder of the current line
	 *
	 * @param remainingLine The remainder of the current line
	 * @param nameParsed Variable to return the name by reference
	 *
	 * @return OK or an error
	 */
	ParseStatus extractName(std::string& remainingLine, std::string& nameParsed);

	/**
	 * Extract the POI description from the remainder of the current line
	 *
	 * @param remainingLine The remainder of the current line
	 * @param descriptionParsed Variable to return the name by reference
	 *
	 * @return OK or an error
	 */
	ParseStatus extractDescription(std::string& remainingLine, std::string& descriptionParsed);

	/**
	 * Extract the POI type from the remainder of the current line
	 *
	 * @param remainingLine The remainder of the current Line
	 * @param typeParsed Variable to return the type by reference
	 *
	 * @returns OK or an error
	 */
	ParseStatus extractType(std::string& remainingLine, t_poi& typeParsed);

};

#endif /* MYCODE_CCSVSTORAGE_H_ */
