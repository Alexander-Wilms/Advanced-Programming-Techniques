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
	std::string slatitude, slongitude;
	double latitude, longitude;

	std::cout << "GPS Sensor" << std::endl;

	while(true){
		std::cout << "\tEnter latitude: ";
		std::cin >> slatitude;
		try {
			latitude = std::stod(slatitude);
			break;
		} catch(...) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "ERROR in CGPSSensor::getCurrentPosition(): Input could not be parsed" << std::endl;
		}
	}

	while(true){
		std::cout << "\tEnter longitude: ";
		std::cin >> slongitude;
		try {
			longitude = std::stod(slongitude);
			break;
		} catch(...) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "ERROR in CGPSSensor::getCurrentPosition(): Input could not be parsed" << std::endl;
		}
	}

	CWaypoint returnValue("GPS coordinate", latitude, longitude);
	return returnValue;
}
