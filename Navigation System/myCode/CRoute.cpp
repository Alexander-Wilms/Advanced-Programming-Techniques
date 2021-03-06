/*
 * CRoute.cpp
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CRoute.h"
#include "CPOI.h"

#include <iostream>

CRoute::CRoute(unsigned int maxWp, unsigned int maxPoi) {
	m_maxWp = maxWp;
	m_maxPoi = maxPoi;

	m_pPoiDatabase = nullptr;

	/**
	 * allocate the dynamic arrays to store waypoints and POIs
	 *
	 * m_pWaypoint initially contains CWaypoints object constructed
	 * using the default arguments.
	 *
	 * m_pPOI initially contains undefined values
	 */
	// check against 0
	m_pWaypoint = new CWaypoint[maxWp];
	m_pPoi = new CPOI*[maxPoi];

	std::fill(m_pPoi, m_pPoi+maxPoi, nullptr);

	m_nextPoi = 0;
	m_nextWp = 0;
}

CRoute::CRoute(const CRoute& origin) {
	m_maxWp = origin.m_maxWp;
	m_maxPoi = origin.m_maxPoi;

	m_pPoiDatabase = origin.m_pPoiDatabase;

	m_nextPoi = origin.m_nextPoi;
	m_nextWp = origin.m_nextWp;

	// cppcheck complained that the value of pointer 'm_pWaypoint',
	// which points to allocated memory, is copied
	// in copy constructor instead of allocating new memory. Therefore,
	// now I'm allocating new memory and manually copying the values into
	// the new array
	m_pWaypoint = new CWaypoint[m_maxWp];
	m_pPoi = new CPOI*[m_maxPoi];

	// copy the CWaypoint and CPOI* array contents
	std::copy(origin.m_pWaypoint, origin.m_pWaypoint+m_maxWp, m_pWaypoint);
	std::copy(origin.m_pPoi, origin.m_pPoi+m_maxPoi, m_pPoi);
}

CRoute::~CRoute() {
	delete[] m_pWaypoint;
	delete[] m_pPoi;
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

void CRoute::addWaypoint(CWaypoint const& wp) {
	m_pWaypoint[m_nextWp] = wp;
	m_nextWp++;
}

void CRoute::addPoi(std::string namePoi) {
	// search for POI in database
	// if one was found, add it to the route

	// Only access POI database if it exists
	if (m_pPoiDatabase != nullptr) {
			// check array bounds
			if(m_nextPoi < 10) {
				// Don't store null pointers
				if (m_pPoiDatabase->getPointerToPoi(namePoi) != nullptr) {
				m_pPoi[m_nextPoi] = m_pPoiDatabase->getPointerToPoi(namePoi);
				m_nextPoi++;
			} else {
				std::cout << "ERROR in CRoute::addPoi(): Tried store null pointer"
						<< std::endl;
			}
		}
	} else {
		std::cout
				<< "ERROR in CRoute::addPoi(): Tried to dereference null pointer" << std::endl
				<< "Did you forget to connect to a CPoiDatabase?" << std::endl;
	}
}

double CRoute::getDistanceNextPoi(const CWaypoint& wp, CPOI& poi) {
	double returnValue = -1;
	bool firstPOI = true;

	if(m_pPoi == nullptr) {
		std::cout << "ERROR in CRoute::getDistanceNextPoi(): m_pPoi is a null pointer" << std::endl;
	}

	// iterate over all POIs of the route
	for (unsigned int j = 0; j < m_nextPoi; j++) {
		// Don't dereference null pointers
		if (m_pPoi[j] != nullptr) {
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

void CRoute::print() {
	std::cout << "Our Route has " << m_nextWp << " Waypoints and " << m_nextPoi
			<< " Points of Interest" << std::endl;

	// Print all waypoints of the route in the format deg mm ss
	for (unsigned int i = 0; i < m_nextWp; i++) {
		// m_pWaypoint[i] is identical to *(m_pWaypoint+i)
		if(m_pWaypoint+i != nullptr) {
			m_pWaypoint[i].print(MMSS);
		}
	}

	// Print all POIs of the route
	for (unsigned int j = 0; j < m_nextPoi; j++) {
		// Don't dereference null pointers
		if (m_pPoi[j] != nullptr) {
			m_pPoi[j]->print();
		} else {
			std::cout
					<< "ERROR in CRoute::print(): Tried to dereference null pointer"
					<< std::endl;
		}
	}
}
