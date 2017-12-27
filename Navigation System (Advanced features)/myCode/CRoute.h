/*
 * CRoute.h
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CROUTE_H_
#define CROUTE_H_

#include "CPOI.h"
#include "CPoiDatabase.h"
#include "CWpDatabase.h"
#include <list>
#include <string>
#include <vector>

class CRoute {
public:
	/**
	 * CRoute constructor
	 */
	CRoute();

	~CRoute();

	/**
	 * Copy constructor
	 *
	 * @param origin 	A reference to an existing CRoute instance
	 */
	CRoute(const CRoute& origin);

	/**
	 * Connects the route object to a POI database
	 *
	 * @param pPoiDB A pointer to a PoiDatabase
	 */
	void connectToPoiDatabase(CPoiDatabase* pPoiDB);

	/**
	 * Connects the route object to a POI database
	 *
	 * @param pPoiDB A pointer to a PoiDatabase
	 */
	void connectToWpDatabase(CWpDatabase* pWpDB);

	/**
	 * Adds a waypoint to the route
	 *
	 * @param namePoi 	The name of the wayoint to add
	 */
	void addWaypoint(std::string name);

	/**
	 * Adds a POI to the route
	 *
	 * @param namePoi 	The name of the POI to add
	 */
	void addPoi(std::string namePoi, std::string afterWp);

	/**
	 * Finds the nearest POI to the given waypoint and returns the distance
	 *
	 * @param wp 	Reference to a waypoint
	 * @param poi 	Reference to a POI, which is used to store the next POI
	 *
	 * @return The distance
	 */
	double getDistanceNextPoi(const CWaypoint& wp, CPOI& poi);

	/**
	 * Print all waypoints and POIs of the route
	 */
	void print();

	/**
	 * Appends POI with the given name to the route
	 */
	CRoute& operator +=(std::string name);

	/**
	 * Assigns another route to this instance
	 */
	CRoute& operator= (const CRoute& r);

	/**
	 * Adds 2 routes by concatenating the content, if they are connected to
	 * the same waypoint and POI database. If not, an error message is shown
	 * and an empty route is returned
	 */
	CRoute& operator+ (const CRoute& r);

	const std::vector<const CWaypoint*> getRoute();

private:
	std::list<CWaypoint*> m_route;

	/**
	 * A pointer to an existing POI database
	 */
	CPoiDatabase* m_pPoiDatabase;

	/**
	 * A pointer to an existing waypoint database
	 */
	CWpDatabase* m_pWpDatabase;
};

#endif /* CROUTE_H_ */
