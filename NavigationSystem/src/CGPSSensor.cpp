/*
 * CGPSSensor.cpp
 *
 *  Created on: 19.10.2017
 *      Author: awilms
 */

#include "CGPSSensor.h"
#include "CWaypoint.h"
#include <iostream>
#include <string>

CGPSSensor::CGPSSensor() {
	// TODO Auto-generated constructor stub

}

CWaypoint CGPSSensor::getCurrentPosition() {
	std::string name;
	double latitude, longitude;

	std::cout << "GPS Sensor" << std::endl;

	std::cout << "\tEnter latitude: ";
	std::cin >> latitude;

	std::cout << "\tEnter longitude: ";
	std::cin >> longitude;

	CWaypoint returnValue("GPS coordinate", latitude, longitude);
	return returnValue;
}
