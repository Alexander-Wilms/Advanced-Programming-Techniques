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
	CRoute(unsigned int maxWp, unsigned int maxPoi);
	CRoute(const CRoute& origin);
	~CRoute();
	void connectToPoiDatabase(CPoiDatabase* pPoiDB);
	void addWaypoint(std::string namePoi);
	void addPoi(std::string namePoi);
	double getDistanceNextPoi(const CWaypoint& wp, CPOI& poi);
	double getDistanceNextPoi(const CWaypoint& wp);
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
