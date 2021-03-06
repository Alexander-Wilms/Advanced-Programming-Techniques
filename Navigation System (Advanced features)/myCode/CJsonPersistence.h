/*
 * CJsonPersistence.h
 *
 *  Created on: 26.12.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef MYCODE_CJSONPERSISTENCE_H_
#define MYCODE_CJSONPERSISTENCE_H_

#include "CPersistentStorage.h"
#include "CWpDatabase.h"
#include "CPoiDatabase.h"
#include <fstream>
#include <string>
#include <type_traits>

class CJsonPersistence: public CPersistentStorage {
private:

	/**
	 * Enum that contains all possible states the parser can
	 * be in
	 */
	enum stateType {
		WAITING_FOR_FIRST_TOKEN,
		WAITING_FOR_DB_NAME,
		WAITING_FOR_DB_BEGIN,
		WAITING_FOR_ARRAY_BEGIN,
		WAITING_FOR_OBJECT_BEGIN,
		WAITING_FOR_ATTRIBUTE_NAME,
		WAITING_FOR_NAME_SEPARATOR,
		WAITING_FOR_VALUE,
		WAITING_FOR_ATTRIBUTE_SEPARATOR_OR_END_OF_OBJECT,
		WAITING_FOR_OBJECT_SEPARATOR_OR_END_OF_ARRAY,
		WAITING_FOR_ARRAY_SEPARATOR_OR_END_OF_FILE
	};

	/**
	 * Base name of the database file
	 */
	std::string mediaName;

	/**
	 * Store the current level of indentation
	 */
	unsigned int m_currentIndentation;

	/**
	 * Print as many tabs as m_currentIndentation specifies
	 */
	void indent(std::ofstream& file);
public:
	/**
	 * Constructor
	 */
	CJsonPersistence();

	/**
	 * Destructor
	 */
	~CJsonPersistence();

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
	bool readData(CWpDatabase& waypointDb,
			CPoiDatabase& poiDb,
			CPersistentStorage::MergeMode mode);

	/**
	 * Write the data to the persistent storage.
	 *
	 * @param waypointDb the data base with way points
	 * @param poiDb the database with points of interest
	 * @return true if the data could be saved successfully
	 */
	bool writeData(const CWpDatabase& waypointDb, const CPoiDatabase& poiDb);

	/*
	 * Set the base name of the database file
	 */
	void setMediaName(std::string name);

	/**
	 * Print a key value pair, where the value is either
	 * a string or a number to the provided file
	 *
	 * @param key The attribute name
	 * @param value The attribute value
	 * @param file The file stream
	 */
	template<class T>
	bool printKeyValue(std::string key, T value, std::ofstream& file);

	/**
	 * Print the fields of a CWaypoint or CPOI to a file
	 *
	 * @param file The file stream
	 * @param wp The waypoint or POI
	 */
	bool printEntry(std::ofstream& file, const CWaypoint* wp);

	/**
	 * Print the contents of the database, which may contain CWaypoints or CPOIs
	 *
	 * @paramm file The file stream
	 * @param wpdb The database
	 */
	template<class T>
	bool printDB(std::ofstream& file, const CDatabase<std::string, T>& wpdb);
};

template<class T>
inline bool CJsonPersistence::printDB(std::ofstream& file, const CDatabase<std::string, T>& wpdb) {
	m_currentIndentation++;

	indent(file);
	if(std::is_same<T, CWaypoint>::value) {
		// it's a database of waypoints
		file << "\"waypoints\": [" << std::endl;
	} else if(std::is_same<T, CPOI>::value) {
		// it's a database of POIs
		file << "\"pois\": [" << std::endl;
	}

	const std::map<std::string, T> DbMap = wpdb.getDB();
	int NoOfEntries = DbMap.size();

	// https://stackoverflow.com/questions/5719842/what-is-wrong-with-my-usage-of-c-standard-librarys-find
	for (typename std::map<std::string, T>::const_iterator it = DbMap.begin(); it != DbMap.end(); it++) {
		printEntry(file, &(it->second));
		NoOfEntries--;
		if (NoOfEntries != 0) {
			file << ",";
		}

		file << std::endl;
	}

	indent(file);
	file << "]";

	m_currentIndentation--;

	return true;
}

template<class T>
inline bool CJsonPersistence::printKeyValue(std::string key, T value,
		std::ofstream& file) {
	indent(file);
	file << "\"" << key << "\": ";
	if(std::is_same<T, std::string>::value) {
		file << "\"" << value << "\"";
	}else if(std::is_same<T, double>::value) {
		file << value;
	}
	return true;
}

#endif /* MYCODE_CJSONPERSISTENCE_H_ */
