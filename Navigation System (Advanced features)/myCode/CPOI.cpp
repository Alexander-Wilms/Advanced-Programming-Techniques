/*
 * CPOI.cpp
 *
 *  Created on: 19.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CPOI.h"
#include "CWaypoint.h"

#include <iostream>

CPOI::CPOI(t_poi type, std::string name, std::string description,
		double latitude, double longitude) : CWaypoint(name, latitude, longitude),
		m_type(type),
		m_description(description) {
	// cppcheck: initialization via initialization list for performance reasons
}

void CPOI::getAllDataByReference(std::string& name, double& latitude,
		double& longitude, t_poi& type, std::string& description) {
	name = m_name;
	latitude = m_latitude;
	longitude = m_longitude;
	type = m_type;
	description = m_description;
}

void CPOI::print() {
	std::cout << "Point of Interest" << std::endl << "=================" << std::endl;
	std::cout << " of type ";
	switch(m_type) {
	case RESTAURANT:
		std::cout << "Restaurant: ";
		break;
	case TOURISTIC:
		std::cout << "Touristic: ";
		break;
	case GASSTATION:
		std::cout << "Gasstation: ";
		break;
	case UNIVERSITY:
		std::cout << "University: ";
		break;
	case SIGHTSEEING:
		std::cout << "Sightseeing: ";
	}
	std::cout << m_description << std::endl;
	// call print() method of the superclass
	CWaypoint::print(MMSS);
}

std::string CPOI::getTypeAsString() const {
	switch(m_type) {
	case RESTAURANT:
		return "Restaurant";
		break;
	case TOURISTIC:
		return "Touristic";
		break;
	case GASSTATION:
		return "Gasstation";
		break;
	case UNIVERSITY:
		return "University";
		break;
	case SIGHTSEEING:
		return "Sightseeing";
	}

	return "";
}

std::string CPOI::getDescription() const {
	return m_description;
}
