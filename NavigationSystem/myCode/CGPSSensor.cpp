/*
 * CGPSSensor.cpp
 *
 *  Created on: 19.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CGPSSensor.h"
#include "CWaypoint.h"

#include <climits>
#include <iostream>
#include <string>

CGPSSensor::CGPSSensor() {
}

/**
 * Simulates reading the GPS coordinate
 *
 * @return The entered coordinate
 */
CWaypoint CGPSSensor::getCurrentPosition() {
	double latitude, longitude;

	std::cout << "GPS Sensor" << std::endl;

	// input validation
	std::cout << "\tEnter latitude: ";
	while (!(std::cin >> latitude)) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout
				<< "ERROR in CGPSSensor::getCurrentPosition(): Input could not be parsed"
				<< std::endl << "\tEnter latitude: ";
	}
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	std::cout << "\tEnter longitude: ";
	while (!(std::cin >> longitude)) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout
				<< "ERROR in CGPSSensor::getCurrentPosition(): Input could not be parsed"
				<< std::endl << "\tEnter longitude: ";
	}
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	CWaypoint returnValue("GPS coordinate", latitude, longitude);
	return returnValue;
}
