/*
 * CJsonPersistence.h
 *
 *  Created on: 26.12.2017
 *      Author: awilms
 */

#ifndef MYCODE_CJSONPERSISTENCE_H_
#define MYCODE_CJSONPERSISTENCE_H_

#include "CPersistentStorage.h"
#include "CWpDatabase.h"
#include "CPoiDatabase.h"
#include <fstream>
#include <string>

class CJsonPersistence: public CPersistentStorage {
private:
	/**
	 * base name of the database files
	 * The file names are:
	 * - <mediaName>-wp.txt
	 * - <mediaName>-poi.txt
	 */
	std::string mediaName;

	unsigned int m_currentIndentation;

	void indent(std::ofstream& file);
public:
	CJsonPersistence();
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

		void setMediaName(std::string name);

		bool printKeyValue(std::string key, std::string value, std::ofstream& file);

		bool printKeyValue(std::string key, double value, std::ofstream& file);

		bool printArray(std::ofstream& file, CWaypoint* wp);

		bool printWaypoint(std::ofstream& file, const CWaypoint* wp);

		bool printWpDB(std::ofstream& file, const CWpDatabase& wpdb);

		bool printPoiDB(std::ofstream& file, const CPoiDatabase& poidb);

};

#endif /* MYCODE_CJSONPERSISTENCE_H_ */
