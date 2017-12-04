/*
 * CWpDatabase.cpp
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CWpDatabase.h"
#include "CWaypoint.h"

#include <iostream>
#include <string>

CWpDatabase::CWpDatabase() : m_Waypoint() {
}

void CWpDatabase::addWp(CWaypoint const& wp) {
		m_Waypoint.insert(std::pair<std::string,CWaypoint>(wp.getName(), wp));

}

CWaypoint* CWpDatabase::getPointerToWp(std::string name) {
	CWaypoint* returnValue = nullptr;

	std::map<std::string,CWaypoint>::iterator it = m_Waypoint.find(name);

	if(it == m_Waypoint.end()) {
		// nothing found
		std::cout << "ERROR in CWpDatabase::getPointerToWp(): Could not find waypoint '" << name << "'" << std::endl;
		returnValue = nullptr;
	} else {
		returnValue = &(it->second);
	}

	return returnValue;
}

const std::map<std::string, CWaypoint>& CWpDatabase::getDB() const {
	return m_Waypoint;
}

void CWpDatabase::clearDb() {
	m_Waypoint.clear();
}
