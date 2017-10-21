/*
 * CRoute.cpp
 *
 *  Created on: 20.10.2017
 *      Author: awilms
 */

#include "CRoute.h"
#include "CPOI.h"
#include <iostream>

CRoute::CRoute(unsigned int maxWp, unsigned int maxPoi) {
	m_maxWp = maxWp;
	m_maxPoi = maxPoi;

	m_pPoiDatabase = NULL;

	m_pWaypoint = new CWaypoint[maxWp];
	m_pPoi = new CPOI*[maxPoi];

	m_nextPoi = 0;
	m_nextWp = 0;
}

// copy constructor
CRoute::CRoute(const CRoute& origin) {
	m_maxWp = origin.m_maxWp;
	m_maxPoi = origin.m_maxPoi;

	m_pPoiDatabase = origin.m_pPoiDatabase;

	m_pWaypoint = origin.m_pWaypoint;
	m_pPoi = origin.m_pPoi;

	m_nextPoi = origin.m_nextPoi;
	m_nextWp = origin.m_nextWp;
}

CRoute::~CRoute() {
	delete [] m_pWaypoint;
	delete [] m_pPoi;
}

void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB = NULL) {
	m_pPoiDatabase = pPoiDB;
}

void CRoute::addWaypoint(std::string namePoi) {
	double latitude;
	double longitude;

	std::cout << "Enter latitude:" << std::endl;
	std::cin >> latitude;
	std::cout << "Enter longitude:" << std::endl;
	std::cin >> longitude;

	m_pWaypoint[m_nextWp] = CWaypoint(namePoi, latitude, longitude);
	m_nextWp++;
}

void CRoute::addPoi(std::string namePoi) {
	CPOI* Poi = NULL;
	Poi = m_pPoiDatabase->getPointerToPoi(namePoi);
	if(Poi != NULL) {
		m_pPoi[m_nextPoi] = m_pPoiDatabase->getPointerToPoi(namePoi);
		m_nextPoi++;
	}
}

double CRoute::getDistanceNextPoi(const CWaypoint& wp, CPOI& poi) {
	return wp.calculateDistance(poi);
}

double CRoute::getDistanceNextPoi(const CWaypoint& wp) {
	double returnValue = -1;
	CPOI nextPoi;

	for(unsigned int j = 0; j < m_nextPoi; j++) {
		if (returnValue == -1) {
			returnValue = wp.calculateDistance((CWaypoint) *m_pPoi[j]);
			nextPoi = *m_pPoi[j];
		} else if (wp.calculateDistance((CWaypoint) *m_pPoi[j]) < returnValue) {
			returnValue = wp.calculateDistance((CWaypoint) *m_pPoi[j]);
			nextPoi = *m_pPoi[j];
		}
	}

	std::cout << "Distance to next POI = " << returnValue << std::endl;
	nextPoi.print();
	return returnValue;
}

void CRoute::print() {
	std::cout << "Our Route has " <<  m_nextWp << " Waypoints and " << m_nextPoi << " Points of Interest" << std::endl;

	for(unsigned int i = 0; i < m_nextWp; i++) {
		m_pWaypoint[i].print(MMSS);
	}

	for(unsigned int j = 0; j < m_nextPoi; j++) {
		m_pPoi[j]->print();
	}
}
