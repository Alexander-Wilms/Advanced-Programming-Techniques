/*
 * CGPSSensor.cpp
 *
 *  Created on: 19.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CGPSSensor.h"
#include "CWaypoint.h"

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
	std::string slatitude, slongitude;
	double latitude, longitude;

	std::cout << "GPS Sensor" << std::endl;

	// input validation
	while(true){
		std::cout << "\tEnter latitude: ";
		std::cin >> slatitude;
		// try to parse string
		try {
			latitude = std::stod(slatitude);
			break;
		} catch(...) { // catch all exceptions
			std::cin.clear();
			std::cin.ignore();
			std::cout << "ERROR in CGPSSensor::getCurrentPosition(): Input could not be parsed" << std::endl;
		}
	}

	while(true){
		std::cout << "\tEnter longitude: ";
		std::cin >> slongitude;
		// try to parse string
		try {
			longitude = std::stod(slongitude);
			break;
		} catch(...) { // catch all exceptions
			std::cin.clear();
			std::cin.ignore();
			std::cout << "ERROR in CGPSSensor::getCurrentPosition(): Input could not be parsed" << std::endl;
		}
	}

	CWaypoint returnValue("GPS coordinate", latitude, longitude);
	return returnValue;
}
