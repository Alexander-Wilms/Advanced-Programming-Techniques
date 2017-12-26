/*
 * CJsonPersistence.h
 *
 *  Created on: 26.12.2017
 *      Author: awilms
 */

#ifndef MYCODE_CJSONPERSISTENCE_H_
#define MYCODE_CJSONPERSISTENCE_H_

#include "CPersistentStorage.h"
#include "CDatabase.h"
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
public:
	CJsonPersistence();
	virtual ~CJsonPersistence();

	bool readData();

	/**
		* Write the data to the persistent storage.
		*
		* @param waypointDb the data base with way points
		* @param poiDb the database with points of interest
		* @return true if the data could be saved successfully
		*/
		bool writeData(const CDatabase<std::string, CWaypoint>& waypointDb, const CDatabase<std::string, CPOI>& poiDb);

		void setMediaName(std::string name);

		bool printKeyValue(std::string key, std::string value, std::ofstream& file);

		bool printKeyValue(std::string key, double value, std::ofstream& file);

		bool printArray(std::ofstream& file, CWaypoint* wp);

		bool printWaypoint(std::ofstream& file, const CWaypoint* wp);

		bool printDB(std::ofstream& file, const CDatabase<std::string, CWaypoint>& p_db);

};

#endif /* MYCODE_CJSONPERSISTENCE_H_ */
