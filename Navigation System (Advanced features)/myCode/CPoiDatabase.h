/*
 * CPoiDatabase.h
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_

#include "CPOI.h"
#include <map>
#include <string>

/**
 * A class to store POIs
 */
class CPoiDatabase {
public:
	/**
	 * Constructor creates a new database
	 */
	CPoiDatabase();

	/**
	 * Adds a POI to the database
	 *
	 * @param type			The POI's type
	 * @param name			The POI's name
	 * @param description	The POI's description
	 * @param latitude		The POI's latitude
	 * @param longitude		The POI's longitude
	 */
	void addPoi(CPOI const& poi);

	/**
	 * Searches the PoiDatabase for a POI by its name and returns a pointer to it
	 *
	 * @param name 	The name of the POI to be searched
	 *
	 * @return A pointer to the POI with the given name
	 */
	CPOI* getPointerToPoi(std::string name);

	/**
	 * Returns a const pointer to the map
	 */
	const std::map<std::string, CPOI>& getDB() const;

	/**
	 * Deletes all elements of the database
	 */
	void clearDb();
private:
	/**
	 * A map to store all known POIs
	 */
	std::map<std::string, CPOI> m_POI;
};

#endif /* CPOIDATABASE_H_ */
