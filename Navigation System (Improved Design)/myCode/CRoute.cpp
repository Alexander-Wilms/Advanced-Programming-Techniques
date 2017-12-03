/*
 * CRoute.cpp
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CRoute.h"
#include "CPOI.h"

#include <iostream>

CRoute::CRoute() {
	std::cout << "CRoute::CRoute()" << std::endl;
	m_pPoiDatabase = nullptr;
	m_pWpDatabase = nullptr;
}

CRoute::CRoute(const CRoute& origin) {
	m_pPoiDatabase = origin.m_pPoiDatabase;
	m_pWpDatabase = origin.m_pWpDatabase;

	m_route = origin.m_route;
}

CRoute::~CRoute() {
}

void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB) {
	// Don't connect to null pointers
	if (pPoiDB != nullptr) {
		m_pPoiDatabase = pPoiDB;
	} else {
		std::cout
				<< "ERROR in CRoute::connectToPoiDatabase(): Pointer to PoiDB is a null pointer"
				<< std::endl;
	}
}

void CRoute::connectToWpDatabase(CWpDatabase* pWpDB) {
	// Don't connect to null pointers
	if (pWpDB != nullptr) {
		m_pWpDatabase = pWpDB;
	} else {
		std::cout
				<< "ERROR in CRoute::connectToWpDatabase(): Pointer to WpDB is a null pointer"
				<< std::endl;
	}
}

void CRoute::addWaypoint(std::string name) {
	std::cout << "CRoute::addWaypoint()" << std::endl;
	std::cout << "Pushing back: " << m_pWpDatabase->getPointerToWp(name) << std::endl;
	m_route.push_back(m_pWpDatabase->getPointerToWp(name));
}

void CRoute::addPoi(std::string namePoi, std::string afterWp) {
	std::cout << "CRoute::addPoi()" << std::endl;
	// search for POI in database
	// if one was found, add it to the route

	bool waypointFound = false;

	if (m_pPoiDatabase != nullptr) {
		// we're connected to a PoiDatabase
		CPOI* poi = m_pPoiDatabase->getPointerToPoi(namePoi);

		if (poi != nullptr) {
			// we found a POI with the given name in the PoiDatabase

			std::cout << "m_route contains " << m_route.size() << " elements" << std::endl;

			// iterate over the route from the back until we've found a waypoint with a matching name
			for(std::list<CWaypoint*>::reverse_iterator rit = m_route.rbegin(); rit != m_route.rend(); ++rit) { // ATTENTION: _increment_ reverse iterator
				// can afterWp also reference a POI?

				std::cout << "inside for loop" << std::endl;

				std::cout << "rit: " << *rit << std::endl;

				CWaypoint* debug = *rit.base();


				std::cout << (*rit)->getLatitude() << std::endl;

				(*rit)->print(1);


				std::cout << "after print" << std::endl;

				std::cout << "getName(): " << (*rit.base())->getName() << std::endl;

				//CWaypoint debug(*(*rit.base()));

				//std::cout << "after CWaypoint constructor" << std::endl;

				//std::cout << "getName(): " << debug.getName() << std::endl;


				if((*rit)->getName() == afterWp) {
					// we found a waypoint with the given name in the route
					m_route.insert(rit.base(), (CWaypoint*) poi);
					waypointFound = true;
				}
			}

			if(!waypointFound) {
				std::cout << "ERROR in CRoute:addPoi(): No waypoint with name " << afterWp << " found in m_route" << std::endl;
			}

		} else {
			std::cout << "ERROR in CRoute:addPoi(): No POI with name " << namePoi << " found in m_pPoiDatabase" << std::endl;
		}
	} else {
		std::cout << "ERROR in CRoute::addPoi(): Tried to dereference null pointer" << std::endl
				<< "Did you forget to connect to a CPoiDatabase?" << std::endl;
	}
}

double CRoute::getDistanceNextPoi(const CWaypoint& wp, CPOI& poi) {
	double returnValue = -1;
//	bool firstPOI = true;
//
//	if(m_pPoi == nullptr) {
//		std::cout << "ERROR in CRoute::getDistanceNextPoi(): m_pPoi is a null pointer" << std::endl;
//	}
//
//	// iterate over all POIs of the route
//	for (unsigned int j = 0; j < m_nextPoi; j++) {
//		// Don't dereference null pointers
//		if (m_pPoi[j] != nullptr) {
//			if (firstPOI == true) {
//				// the first POI
//				returnValue = wp.calculateDistance((CWaypoint) *m_pPoi[j]);
//				poi = *m_pPoi[j];
//				firstPOI = false;
//			} else if (wp.calculateDistance((CWaypoint) *m_pPoi[j])
//					< returnValue) {
//				// found a POI that's even closer
//				returnValue = wp.calculateDistance((CWaypoint) *m_pPoi[j]);
//				poi = *m_pPoi[j];
//			}
//		} else {
//			std::cout
//					<< "ERROR in CRoute::getDistanceNextPoi(): Tried to dereference null pointer"
//					<< std::endl;
//		}
//	}
//
	return returnValue;
}

void CRoute::print() {

	for(std::list<CWaypoint*>::iterator it = m_route.begin(); it != m_route.end(); it++) {
		// HINT:
		// source type is not polymorpic ->
		// base class needs a virtual function, e.g. the destructor
		CPOI* pPOI = dynamic_cast<CPOI*> (*it);
		if(pPOI != nullptr) {
			// it is indeed a POI
			std::cout << *pPOI << std::endl;
		}

		CWaypoint* pWp = dynamic_cast<CWaypoint*> (*it);
		if(pWp != nullptr) {
			// it is indeed a waypoint
			std::cout << *pWp << std::endl;
		}
	}
}

CRoute& CRoute::operator +=(std::string name) {

	CWaypoint* wp = m_pWpDatabase->getPointerToWp(name);

	CPOI* poi = m_pPoiDatabase->getPointerToPoi(name);

	if (wp != nullptr) {
		// waypoint found
		m_route.push_back(wp);
	}

	if (poi != nullptr) {
		// poi found
		m_route.push_back(poi);
	}

	return *this;
}

CRoute& CRoute::operator= (const CRoute& r) {
	m_pPoiDatabase = r.m_pPoiDatabase;
	m_pWpDatabase = r.m_pWpDatabase;
	m_route = r.m_route;
	return *this;
}
