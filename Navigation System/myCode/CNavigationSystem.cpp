/*
 * CNavigationSystem.cpp
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CNavigationSystem.h"

#include <iostream>
#include <string>
#include "CRoute.h"

CNavigationSystem::CNavigationSystem() :
		m_route(10, 10), m_PoiDatabase() {
}

void CNavigationSystem::run() {
	m_route.connectToPoiDatabase(&m_PoiDatabase);
	addPOIsToDatabase();
	enterRoute();
	printRoute();
	printDistanceCurPosNextPoi();
}

void CNavigationSystem::enterRoute() {
	m_route.addWaypoint(CWaypoint("Amsterdam", 52.370197222222, 4.8904444444444));
	m_route.addWaypoint(CWaypoint("Darmstadt", 49.872833, 8.651222));
	m_route.addWaypoint(CWaypoint("Berlin", 52.518611, 13.408333));

	m_route.addPoi("Mensa HDA");
	m_route.addPoi("Sitte");
	m_route.addPoi("Something not in the pool");
}

void CNavigationSystem::printRoute() {
	m_route.print();
}

void CNavigationSystem::addPOIsToDatabase() {
	m_PoiDatabase.addPoi(RESTAURANT, "Mensa HDA", "The best Mensa in the world",
			10, 20);
	m_PoiDatabase.addPoi(RESTAURANT, "Sitte", "More expensive but also good",
			11, 22);
}

void CNavigationSystem::printDistanceCurPosNextPoi() {
	CWaypoint currPos = m_GPSSensor.getCurrentPosition();
	// create a variable to store the nearest POI
	CPOI nextPoi;

	double distance = m_route.getDistanceNextPoi(currPos, nextPoi);
	std::cout << "Distance to next POI = " << distance << std::endl;
	nextPoi.print();
}
