/*
 * CGPSSensor.cpp
 *
 *  Created on: 19.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include <iostream>
#include <string>
#include "CGPSSensor.h"
#include "CWaypoint.h"

CGPSSensor::CGPSSensor() {
	// TODO Auto-generated constructor stub

}

/**
 * Simulates reading the GPS coordinate
 *
 * @return The entered coordinate
 */
CWaypoint CGPSSensor::getCurrentPosition() {
	double latitude, longitude;

	std::cout << "GPS Sensor" << std::endl;

	std::cout << "\tEnter latitude: ";
	std::cin >> latitude;

	std::cout << "\tEnter longitude: ";
	std::cin >> longitude;

	CWaypoint returnValue("GPS coordinate", latitude, longitude);
	return returnValue;
}
