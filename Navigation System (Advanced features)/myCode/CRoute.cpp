/*
 * CRoute.cpp
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CRoute.h"
#include "CPOI.h"

#include <iostream>

CRoute::CRoute() :
m_pPoiDatabase(nullptr),
m_pWpDatabase(nullptr)
{
}

CRoute::CRoute(const CRoute& origin) {
	m_pPoiDatabase = origin.m_pPoiDatabase;
	m_pWpDatabase = origin.m_pWpDatabase;
	m_route = origin.m_route;
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
	if (m_pWpDatabase != nullptr) {
		CWaypoint* wp = m_pWpDatabase->getPointerToElement(name);

		if (wp != nullptr) {
			// we found a POI with the given name in the PoiDatabase
			m_route.push_back(wp);
#ifdef DEBUG
			std::cout << "INFO in CRoute::addWaypoint(): Added waypoint '" << name << "'" << std::endl;
#endif
		} else {
			std::cout << "ERROR in CRoute:addPoi(): No waypoint with name '"
					<< name << "' found in m_pWpDatabase" << std::endl;
		}
	} else {
		std::cout
		<< "ERROR in CRoute::addWaypoint(): Tried to dereference null pointer"
		<< std::endl << "Did you forget to connect to a CWpDatabase?"
		<< std::endl;
	}
}

void CRoute::addPoi(std::string namePoi, std::string afterWp) {
	// search for POI in database
	// if one was found, add it to the route

	bool waypointFound = false;

	if (m_pPoiDatabase != nullptr) {
		// we're connected to a PoiDatabase
		CPOI* poi = m_pPoiDatabase->getPointerToElement(namePoi);

		if (poi != nullptr) {
			// we found a POI with the given name in the PoiDatabase

			// iterate over the route from the back until we've found a waypoint with a matching name
			for (std::list<CWaypoint*>::reverse_iterator rit = m_route.rbegin();
					rit != m_route.rend(); ++rit) { // ATTENTION: _increment_ reverse iterator
				// can afterWp also reference a POI?

				if ((*rit)->getName() == afterWp) {
					// we found a waypoint with the given name in the route
					m_route.insert(rit.base(), poi);
#ifdef DEBUG
					std::cout << "INFO in CRoute::addPoi(): Added POI '" << namePoi << "'" << std::endl;
#endif
					waypointFound = true;
					break;
				}
			}

			if (!waypointFound) {
				std::cout << "ERROR in CRoute:addPoi(): No waypoint with name '"
						<< afterWp << "' found in m_route" << std::endl;
			}
		} else {
			std::cout << "ERROR in CRoute:addPoi(): No POI with name '"
					<< namePoi << "' found in m_pPoiDatabase" << std::endl;
		}
	} else {
		std::cout
		<< "ERROR in CRoute::addPoi(): Tried to dereference null pointer"
		<< std::endl << "Did you forget to connect to a CPoiDatabase?"
		<< std::endl;
	}
}

double CRoute::getDistanceNextPoi(const CWaypoint& wp, CPOI& poi) {
	double returnValue = -1;
	bool firstPOI = true;

	if(m_pPoiDatabase == nullptr) {
		std::cout << "ERROR in CRoute::getDistanceNextPoi(): Tried to dereference CWaypoint* null pointer"
				<< std::endl;
		return -1;
	}

	for(std::map<std::string, CPOI>::const_iterator it = m_pPoiDatabase->getDB().begin(); it != m_pPoiDatabase->getDB().end(); ++it) {

		if (firstPOI == true) {
			// the first POI
			returnValue = wp.calculateDistance((CWaypoint) it->second);
			poi = (it->second);
			firstPOI = false;
		} else if (wp.calculateDistance((CWaypoint) it->second)
				< returnValue) {
			// found a POI that's even closer
			returnValue = wp.calculateDistance((CWaypoint) it->second);
			poi = (it->second);
		}
	}
	return returnValue;
}

void CRoute::print() {
	for (std::list<CWaypoint*>::iterator it = m_route.begin();
			it != m_route.end(); it++) {
		/**
		 * HINT:
		 * Error message: source type is not polymorphic ->
		 * base class needs a virtual function, e.g. the destructor
		 */
		CPOI* pPOI = dynamic_cast<CPOI*>(*it);
		if (pPOI != nullptr) {
			// it is indeed a POI
			std::cout << "POI " << *pPOI << std::endl;
		} else {

			/**
			 * all elements can be cast to CWaypoint*, but it's
			 * not necessary to print it if we already successfully
			 * cast it to CPOI*, otherwise we would print the element twice
			 */
			CWaypoint* pWp = dynamic_cast<CWaypoint*>(*it);
			if (pWp != nullptr) {
				// it is indeed a waypoint
				std::cout << "Waypoint " << *pWp << std::endl;
			} else {
				std::cout << "ERROR in CRoute::print(): Couldn't dynamic_cast to either CPOI* or CWaypoint*" << std::endl;
			}

		}
	}
}

CRoute& CRoute::operator+=(std::string name) {
	bool nothingFound = true;

	if (m_pWpDatabase != nullptr) {
		if (m_pPoiDatabase != nullptr) {
			CWaypoint* wp = m_pWpDatabase->getPointerToElement(name);
			CPOI* poi = m_pPoiDatabase->getPointerToElement(name);

			if (wp != nullptr) {
				// waypoint found
				m_route.push_back(wp);
				nothingFound = false;
			} else {
				std::cout << "WARNING in CRoute:operator+=(): No waypoint with name '"
						<< name << "' found in m_pWpDatabase" << std::endl;
			}

			if (poi != nullptr) {
				// POI found
				m_route.push_back(poi);
				nothingFound = false;
			} else {
				std::cout << "WARNING in CRoute:operator+=(): No POI with name '"
						<< name << "' found in m_pPoiDatabase" << std::endl;
			}

			if(nothingFound) {
				std::cout << "ERROR in CRoute:operator+=(): No POI or waypoint with name '"
						<< name << "' found in m_pPoiDatabase respectively m_pWpDatabase" << std::endl;
			}
		} else {
			std::cout
			<< "ERROR in CRoute::operator+=(): Tried to dereference null pointer"
			<< std::endl
			<< "Did you forget to connect to a CPoiDatabase?"
			<< std::endl;
		}
	} else {
		std::cout
		<< "ERROR in CRoute::operator+=(): Tried to dereference null pointer"
		<< std::endl << "Did you forget to connect to a CWpDatabase?"
		<< std::endl;
	}

	return *this;
}

CRoute& CRoute::operator=(const CRoute& r) {
	m_pPoiDatabase = r.m_pPoiDatabase;
	m_pWpDatabase = r.m_pWpDatabase;
	m_route = r.m_route;
	return *this;
}

CRoute& CRoute::operator+(const CRoute& r) {
	bool sameDatabases = false;

	if(m_pPoiDatabase == r.m_pPoiDatabase) {
		if(m_pWpDatabase == r.m_pWpDatabase) {
			sameDatabases = true;
			// https://stackoverflow.com/questions/1449703/how-to-append-a-listt-object-to-another
			m_route.insert(m_route.end(), r.m_route.begin(), r.m_route.end());
		} else {
			std::cout << "ERROR in CRoute::operator+(): Waypoint databases differ" << std::endl;
		}
	} else {
		std::cout << "ERROR in CRoute::operator+(): POI databases differ" << std::endl;
	}

	if(!sameDatabases) {
		m_route.clear();
	}

	return *this;
}

const std::vector<const CWaypoint*> CRoute::getRoute() {
	const std::vector<const CWaypoint*> returnValue{std::begin(m_route), std::end(m_route)};
	return returnValue;
}
