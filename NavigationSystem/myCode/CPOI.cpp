/*
 * CPOI.cpp
 *
 *  Created on: 19.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CPOI.h"

#include <iostream>

#include "CWaypoint.h"

/**
 * Creates a new POI with the given properties
 *
 * @param The POI's type
 * @param The POI's name
 * @param The POI's description
 * @param The POI's latitude
 * @param The POI's longitude
 */
CPOI::CPOI(t_poi type, std::string name, std::string description,
		double latitude, double longitude) : CWaypoint(name, latitude, longitude) {
	m_type = type;
	m_description = description;
}

/**
 * Returns a members of the POI by reference
 *
 * @param variable where to store the POI's name
 * @param variable where to store the POI's latitude
 * @param variable where to store the POI's longitude
 * @param variable where to store the POI's type
 * @param variable where to store the POI's description
 */
void CPOI::getAllDataByReference(std::string& name, double& latitude,
		double& longitude, t_poi& type, std::string& description) {
	name = m_name;
	latitude = m_latitude;
	longitude = m_longitude;
	type = m_type;
	description = m_description;
}

/**
 * Prints the properties of the POI
 */
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
	}
	std::cout << m_description << std::endl;
	/**
	 * call print() method of the superclass
	 */
	CWaypoint::print(MMSS);
}
