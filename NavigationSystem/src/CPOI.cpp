/*
 * CPOI.cpp
 *
 *  Created on: 19.10.2017
 *      Author: awilms
 */

#include "CPOI.h"
#include <iostream>
#include "CWaypoint.h"

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
}

CPOI::CPOI(t_poi type, std::string name, std::string description,
		double latitude, double longitude) : CWaypoint(name, latitude, longitude) {

	m_type = type;
	m_description = description;
}

void CPOI::getAllDataByReference(std::string& name, double& latitude,
		double& longitude, t_poi& type, std::string& description) {
	name = m_name;
	latitude = m_latitude;
	longitude = m_longitude;
	type = m_type;
	description = m_description;
}
