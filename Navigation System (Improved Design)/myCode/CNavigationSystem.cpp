/*
 * CNavigationSystem.cpp
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CNavigationSystem.h"

#include "CRoute.h"
#include "CCSVStorage.h"
#include "CPersistentStorage.h"
#include <iostream>
#include <string>

// #define SETUP_DBS

CNavigationSystem::CNavigationSystem() :
	m_route(),
	m_PoiDatabase(),
	m_WpDatabase() {
	 m_CSVStorage = CCSVStorage();
	 m_CSVStorage.setMediaName("navigationsystemdata");
}

void CNavigationSystem::run() {
	m_route.connectToPoiDatabase(&m_PoiDatabase);
	m_route.connectToWpDatabase(&m_WpDatabase);
#ifdef SETUP_DBS
	addPOIsAndWpsToDatabase();
	m_CSVStorage.writeData(m_WpDatabase, m_PoiDatabase);
#endif
	m_CSVStorage.readData(m_WpDatabase, m_PoiDatabase, CPersistentStorage::REPLACE);
	enterRoute();
	printRoute();
	printDistanceCurPosNextPoi();
	m_CSVStorage.writeData(m_WpDatabase, m_PoiDatabase);
}

void CNavigationSystem::enterRoute() {
	m_route.addWaypoint("Amsterdam");
	m_route.addWaypoint("Darmstadt");
	m_route.addWaypoint("Berlin");

	m_route.addPoi("Piet Friet", "Amsterdam");
	m_route.addPoi("Mensa HDA", "Darmstadt");
	m_route.addPoi("Sitte", "Darmstadt");
	m_route.addPoi("Something not in the pool", "Berlin");
}

void CNavigationSystem::printRoute() {
	m_route.print();
}

void CNavigationSystem::addPOIsAndWpsToDatabase() {
	CWaypoint Amsterdam("Amsterdam", 52.370197222222, 4.8904444444444);
	m_WpDatabase.addWp(Amsterdam);
	m_WpDatabase.addWp(CWaypoint("Darmstadt", 49.872833, 8.651222));
	m_WpDatabase.addWp(CWaypoint("Berlin", 52.518611, 13.408333));

	CPOI PietFriet(RESTAURANT, "Piet Friet", "1A Pommes Frites", 50, 5);
	m_PoiDatabase.addPoi(PietFriet);
	m_PoiDatabase.addPoi(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world", 10, 20));
	m_PoiDatabase.addPoi(CPOI(RESTAURANT, "Sitte", "More expensive but also good", 11, 22));
}

void CNavigationSystem::printDistanceCurPosNextPoi() {
	CWaypoint currPos = m_GPSSensor.getCurrentPosition();
	// create a variable to store the nearest POI
	CPOI nextPoi;

	double distance = m_route.getDistanceNextPoi(currPos, nextPoi);
	std::cout << "Distance to next POI = " << distance << std::endl;
	nextPoi.print();
}
