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

	std::cout << "Enter name: ";
	std::cin >> name;

	std::cout << "Enter latitude: ";
	std::cin >> latitude;

	std::cout << "Enter longitude: ";
	std::cin >> longitude;

	CWaypoint returnValue(name, latitude, longitude);
	return returnValue;
}

CGPSSensor::~CGPSSensor() {
	// TODO Auto-generated destructor stub
}

