/*
 * CRoute.cpp
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include <iostream>
#include "CPOI.h"
#include "CRoute.h"

/**
 * CRoute constructor
 *
 * @param maxWp 	maximum number of waypoints
 * @param maxPoi 	maximum number of POIs
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
 * @param origin 	A reference to an existing CRoute instance
 */
CRoute::CRoute(const CRoute& origin) {
	m_maxWp = origin.m_maxWp;
	m_maxPoi = origin.m_maxPoi;

	m_pPoiDatabase = origin.m_pPoiDatabase;

	m_nextPoi = origin.m_nextPoi;
	m_nextWp = origin.m_nextWp;

	// cppcheck complained that the value of pointer 'm_pWaypoint',
	// which points to allocated memory, is copied
	// in copy constructor instead of allocating new memory
	m_pWaypoint = new CWaypoint[m_maxWp];
	m_pPoi = new CPOI*[m_maxPoi];

	for (unsigned int i = 0; i < m_maxWp; i++) {
		m_pWaypoint[i] = origin.m_pWaypoint[i];
	}

	for (unsigned int j = 0; j < m_maxPoi; j++) {
		m_pPoi[j] = origin.m_pPoi[j];
	}
}

/**
 * CRoute destructor deletes the dynamic arrays
 */
CRoute::~CRoute() {
	delete[] m_pWaypoint;
	delete[] m_pPoi;
}

/**
 * Connects the route object to a POI database
 *
 * @param pPoiDB A pointer to a PoiDatabase
 */
void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB) {
	// Don't connect to null pointers
	if (pPoiDB != NULL) {
		m_pPoiDatabase = pPoiDB;
	} else {
		std::cout
				<< "ERROR in CRoute::connectToPoiDatabase(): Pointer to PoiDB is a null pointer"
				<< std::endl;
	}
}

/**
 * Adds a waypoint to the route
 *
 * @param namePoi 	The name of the wayoint to add
 */
void CRoute::addWaypoint(std::string namePoi) {
	std::string slatitude, slongitude;
	double latitude, longitude;

	std::cout << namePoi << ":" << std::endl;

	// input validation
	while(true){
		std::cout << "\tEnter latitude: ";
		std::cin >> slatitude;
		try {
			latitude = std::stod(slatitude);
			break;
		} catch(...) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "ERROR in CRoute::addWaypoint(): Input could not be parsed" << std::endl;
		}
	}

	while(true){
		std::cout << "\tEnter longitude: ";
		std::cin >> slongitude;
		try {
			longitude = std::stod(slongitude);
			break;
		} catch(...) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "ERROR in CRoute::addWaypoint(): Input could not be parsed" << std::endl;
		}
	}

	m_pWaypoint[m_nextWp] = CWaypoint(namePoi, latitude, longitude);
	m_nextWp++;
}

/**
 * Adds a POI to the route
 *
 * @param namePoi 	The name of the POI to add
 */
void CRoute::addPoi(std::string namePoi) {
	// search for POI in database
	// if one was found, add it to the route

	// Only access POI database if it exists
	if (m_pPoiDatabase != NULL) {
		// Don't store null pointers
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
 * Finds the nearest POI to the given waypoint and returns the distance
 *
 * @param wp 	Reference to a waypoint
 * @param poi 	Reference to a POI, which is used to store the next POI
 *
 * @return The distance
 */
double CRoute::getDistanceNextPoi(const CWaypoint& wp, CPOI& poi) {
	double returnValue = -1;
	bool firstPOI = true;

	// iterate over all POIs of the route
	for (unsigned int j = 0; j < m_nextPoi; j++) {
		// Don't dereference null pointers
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
			std::cout
					<< "ERROR in CRoute::getDistanceNextPoi(): Tried to dereference null pointer"
					<< std::endl;
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

	// Print all waypoints of the route in the format deg mm ss
	for (unsigned int i = 0; i < m_nextWp; i++) {
		m_pWaypoint[i].print(MMSS);
	}

	// Print all POIs of the route
	for (unsigned int j = 0; j < m_nextPoi; j++) {
		// Don't dereference null pointers
		if (m_pPoi[j] != NULL) {
			m_pPoi[j]->print();
		} else {
			std::cout
					<< "ERROR in CRoute::print(): Tried to dereference null pointer"
					<< std::endl;
		}
	}
}
