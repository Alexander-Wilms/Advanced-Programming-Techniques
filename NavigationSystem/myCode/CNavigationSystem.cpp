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

/**
 * Constructor of CNavigationSystem
 *
 * calls the constructor of the member m_route, otherwise
 * a constructor CRoute::CRoute() without arguments is required
 *
 * m_PoiDatabase() is initialized like this, since cppcheck suggested it for performance reasons
 */
CNavigationSystem::CNavigationSystem() :
		m_route(10, 10),  m_PoiDatabase() {
}

/**
 * Starts the navigation system
 */
void CNavigationSystem::run() {
	m_route.connectToPoiDatabase(&m_PoiDatabase);
	addPOIsToDatabase();
	enterRoute();
	printRoute();
	printDistanceCurPosNextPoi();
}

/**
 * Allows the user to enter coordinates for waypoints and POIs of the given route
 */
void CNavigationSystem::enterRoute() {
	m_route.addWaypoint("Amsterdam");
	m_route.addWaypoint("Darmstadt");
	m_route.addWaypoint("Berlin");
	m_route.addPoi("Mensa HDA");
	m_route.addPoi("Sitte");
	m_route.addPoi("Something not in the pool");
}

/**
 * Prints all waypoints and POIs of the route
 */
void CNavigationSystem::printRoute() {
	m_route.print();
}

/**
 * Add the given POIs to the POI database
 */
void CNavigationSystem::addPOIsToDatabase() {
	m_PoiDatabase.addPoi(RESTAURANT, "Mensa HDA", "The best Mensa in the world",
			10, 20);
	m_PoiDatabase.addPoi(RESTAURANT, "Sitte", "More expensive but also good",
			11, 22);
}

/**
 * Requests the current location from the GPS sensor and prints the
 * distance to the next POI of the route
 */
void CNavigationSystem::printDistanceCurPosNextPoi() {
	CWaypoint currPos = m_GPSSensor.getCurrentPosition();
	/**
	 * create a variable to store the nearest POI
	 */
	CPOI nextPoi;
	double distance = m_route.getDistanceNextPoi(currPos, nextPoi);
	std::cout << "Distance to next POI = " << distance << std::endl;
	nextPoi.print();
}
