/*
 * CPoiDatabase.h
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CWAYPOINTDATABASE_H_
#define CWAYPOINTDATABASE_H_

#include "CWaypoint.h"
#include <map>
#include <string>

/**
 * A class to store POIs
 */
class CWpDatabase {
public:
	/**
	 * Constructor creates a new database
	 */
	CWpDatabase();

	/**
	 * Adds a POI to the database
	 *
	 * @param type			The waypoint's type
	 * @param name			The waypoint's name
	 * @param description	The waypoint's description
	 * @param latitude		The waypoint's latitude
	 * @param longitude		The waypoint's longitude
	 */
	void addWp(CWaypoint const& wp);

	/**
	 * Searches the PoiDatabase for a waypoint by its name and returns a pointer to it
	 *
	 * @param name 	The name of the waypoint to be searched
	 *
	 * @return A pointer to the waypoint with the given name
	 */
	CWaypoint* getPointerToWp(std::string name);
private:
	/**
	 * A map to store all known waypoints
	 */
	std::map<std::string, CWaypoint> m_Waypoint;
};

#endif /* CWAYPOINTDATABASE_H_ */
