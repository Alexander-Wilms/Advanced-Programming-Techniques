/*
 * CNavigationSystem.cpp
 *
 *  Created on: 20.10.2017
 *      Author: awilms
 */

#include "CNavigationSystem.h"
#include "CRoute.h"
#include <iostream>
#include <string>

CNavigationSystem::CNavigationSystem() : m_route(10,10) {
	m_PoiDatabase = CPoiDatabase();
}

void CNavigationSystem::run() {
	std::cout << "run()" << std::endl;
	m_route.connectToPoiDatabase(&m_PoiDatabase);
	addPOIsToDatabase();
	enterRoute();
	printRoute();
	printDistanceCurPosNextPoi();
}

void CNavigationSystem::enterRoute() {
	std::string input;

	std::string name;

	m_route.addWaypoint("Amsterdam");
	m_route.addWaypoint("Darmstadt");
	m_route.addWaypoint("Berlin");
	m_route.addPoi("Mensa HDA");
	m_route.addPoi("Sitte");
	m_route.addPoi("Something not in the pool");

//	bool done = false;
//	while(!done) {
//		std::cout << "Add some POIs and waypoints, or save route (p/w/s)" << std::endl;
//		std::cin >> input;
//
//		if(input == "p") {
//			std::cout << "Enter name:" << std::endl;
//			std::cin.ignore();
//			std::getline(std::cin, name);
//			m_route.addPoi(name);
//		} else if(input == "w") {
//			std::cout << "Enter name:" << std::endl;
//			std::cin.ignore();
//			std::getline(std::cin, name);
//			m_route.addWaypoint(name);
//		} else if(input == "s") {
//			done = true;
//		} else {
//			std::cout << "Error" << std::endl;
//		}
//	}
}

void CNavigationSystem::printRoute() {
	m_route.print();
}

void CNavigationSystem::addPOIsToDatabase() {
	m_PoiDatabase.addPoi(RESTAURANT, "Mensa HDA", "The best Mensa in the world", 10, 20);
	m_PoiDatabase.addPoi(RESTAURANT, "Sitte", "More expensive but also good", 11, 22);
}

void CNavigationSystem::printDistanceCurPosNextPoi() {
	CWaypoint currPos = m_GPSSensor.getCurrentPosition();
	m_route.getDistanceNextPoi(currPos);
}
