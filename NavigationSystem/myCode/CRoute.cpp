/*
 * CRoute.cpp
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CRoute.h"

#include <iostream>
#include "CPOI.h"

/**
 * CRoute constructor
 *
 * @param maximum number of waypoints
 * @param maximum number of POIs
 */
CRoute::CRoute(unsigned int maxWp, unsigned int maxPoi) {
	m_maxWp = maxWp;
	m_maxPoi = maxPoi;

	m_pPoiDatabase = NULL;

	/**
	 * allocate the dynamic arrays to store waypoints and POIs
	 */
	m_pWaypoint = new CWaypoint[maxWp];
	m_pPoi = new CPOI*[maxPoi];

	m_nextPoi = 0;
	m_nextWp = 0;
}

/**
 * Copy constructor
 *
 * @param A reference to an existing CRoute instance
 */
CRoute::CRoute(const CRoute& origin) {
	m_maxWp = origin.m_maxWp;
	m_maxPoi = origin.m_maxPoi;

	m_pPoiDatabase = origin.m_pPoiDatabase;

	m_pWaypoint = origin.m_pWaypoint;
	m_pPoi = origin.m_pPoi;

	m_nextPoi = origin.m_nextPoi;
	m_nextWp = origin.m_nextWp;
}

/**
 * CRoute destructor deletes the dynamic arrays
 */
CRoute::~CRoute() {
	delete[] m_pWaypoint;
	delete[] m_pPoi;
}

/**
 * Connects to a POI database
 *
 * @param A pointer to a PoiDatabase
 */
void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB = NULL) {
	/**
	 * Don't add null pointers
	 */
	if (pPoiDB != NULL) {
		m_pPoiDatabase = pPoiDB;
	} else {
		std::cout << "ERROR in CRoute::connectToPoiDatabase(): Pointer to PoiDB is a null pointer" << std::endl;
	}
}

/**
 * Adds a waypoint to the route
 *
 * @param The name of the wayoint to add
 */
void CRoute::addWaypoint(std::string namePoi) {
	double latitude;
	double longitude;

	std::cout << namePoi << ":" << std::endl;
	std::cout << "Enter latitude:" << std::endl;
	std::cin >> latitude;
	std::cout << "Enter longitude:" << std::endl;
	std::cin >> longitude;

	m_pWaypoint[m_nextWp] = CWaypoint(namePoi, latitude, longitude);
	m_nextWp++;
}

/**
 * Adds a POI to the route
 *
 * @param The name of the POI to add
 */
void CRoute::addPoi(std::string namePoi) {
	// search for POI in database
	// if one was found, add it to the route
	/**
	 * Don't store null pointers
	 */
	if (m_pPoiDatabase != NULL) {
		if (m_pPoiDatabase->getPointerToPoi(namePoi) != NULL) {
			m_pPoi[m_nextPoi] = m_pPoiDatabase->getPointerToPoi(namePoi);
			m_nextPoi++;
		} else {
			std::cout << "ERROR in CRoute::addPoi(): Tried store null pointer"
					<< std::endl;
		}
	} else {
		std::cout
				<< "ERROR in CRoute::addPoi(): Tried to dereference null pointer"
				<< std::endl;
	}
}

/**
 * Calculates the distance between a waypoint and a POI
 *
 * @param Reference to a waypoint
 * @param Reference to a POI
 *
 * @return The distance
 */
double CRoute::getDistanceNextPoi(const CWaypoint& wp, CPOI& poi) {
	double returnValue = -1;
	bool firstPOI = true;

	/**
	 * iterate over all POIs of the route
	 */
	for (unsigned int j = 0; j < m_nextPoi; j++) {
		/**
		 *  Don't dereference null pointers
		 */
		if (m_pPoi[j] != NULL) {
			if (firstPOI == true) {
				// the first POI
				returnValue = wp.calculateDistance((CWaypoint) *m_pPoi[j]);
				poi = *m_pPoi[j];
				firstPOI = false;
			} else if (wp.calculateDistance((CWaypoint) *m_pPoi[j])
					< returnValue) {
				// found a POI that's even closer
				returnValue = wp.calculateDistance((CWaypoint) *m_pPoi[j]);
				poi = *m_pPoi[j];
			}
		} else {
			std::cout << "ERROR in CRoute::getDistanceNextPoi(): Tried to dereference null pointer" << std::endl;
		}
	}

	return returnValue;
}

/**
 * Print all waypoints and POIs of the route
 */
void CRoute::print() {
	std::cout << "Our Route has " << m_nextWp << " Waypoints and " << m_nextPoi
			<< " Points of Interest" << std::endl;

	/**
	 * Print all waypoints of the route in the format deg mm ss
	 */
	for (unsigned int i = 0; i < m_nextWp; i++) {
		m_pWaypoint[i].print(MMSS);
	}

	/**
	 * Print all POIs of the route
	 */
	for (unsigned int j = 0; j < m_nextPoi; j++) {
		/**
		 *  Don't dereference null pointers
		 */
		if (m_pPoi[j] != NULL) {
			m_pPoi[j]->print();
		} else {
			std::cout << "ERROR in CRoute::print(): Tried to dereference null pointer" << std::endl;
		}
	}
}
