/*
 * CRoute.h
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CROUTE_H_
#define CROUTE_H_

#include <string>
#include "CPOI.h"
#include "CPoiDatabase.h"

class CRoute {
public:
	/**
	 * CRoute constructor
	 *
	 * @param maxWp 	maximum number of waypoints
	 * @param maxPoi 	maximum number of POIs
	 */
	CRoute(unsigned int maxWp, unsigned int maxPoi);

	/**
	 * Copy constructor
	 *
	 * @param origin 	A reference to an existing CRoute instance
	 */
	CRoute(const CRoute& origin);

	/**
	 * CRoute destructor deletes the dynamic arrays
	 */
	~CRoute();

	/**
	 * Connects the route object to a POI database
	 *
	 * @param pPoiDB A pointer to a PoiDatabase
	 */
	void connectToPoiDatabase(CPoiDatabase* pPoiDB);

	/**
	 * Adds a waypoint to the route
	 *
	 * @param namePoi 	The name of the wayoint to add
	 */
	void addWaypoint(CWaypoint const& wp);

	/**
	 * Adds a POI to the route
	 *
	 * @param namePoi 	The name of the POI to add
	 */
	void addPoi(std::string namePoi);

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
private:
	/**
	 * A pointer to a dynamic array storing all waypoints
	 * of the route
	 */
	CWaypoint* m_pWaypoint;

	/**
	 * The maximum number waypoints that can bes stored
	 * as part of this route
	 */
	unsigned int m_maxWp;

	/**
	 * The index of the next waypoint to store
	 */
	unsigned int m_nextWp;

	/**
	 * A pointer to a pointer to a POI
	 * Used for the dynamic array containing pointers to
	 * CPOI instances stored in the CPoiDatabase instance
	 */
	CPOI** m_pPoi;

	/**
	* The maximum number POIs that can bes stored
	* as part of this route
	*/
	unsigned int m_maxPoi;

	/**
	 * The index of the next POI to store
	 */
	unsigned int m_nextPoi;

	/**
	 * A pointer to an existing POI database
	 */
	CPoiDatabase* m_pPoiDatabase;
};

#endif /* CROUTE_H_ */
