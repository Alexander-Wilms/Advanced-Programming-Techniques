/*
 * NavigationSystem.cpp
 *
 *  Created on: 19.10.2017
 *      Author: awilms
 */

#include <iostream>
#include "CWaypoint.h"


int main() {
	CWaypoint amsterdam("Amsterdam", 52.370197222222, 4.8904444444444);
	CWaypoint darmstadt("Darmstadt", 49.872833, 8.651222);
	std::cout << "Constructor" << std::endl << "==========" << std::endl;
	CWaypoint berlin("Berlin", 52.518611, 13.408333);
	CWaypoint tokio("Tokio", 35.683889, 139.774444);
	CWaypoint newWaypoint();

	std::cout << std::endl << "print method" << std::endl << "==========" << std::endl;
	berlin.print(DEGREE);
	berlin.print(MMSS);

	std::cout << std::endl << "getter methods" << std::endl << "==============" << std::endl;
	std::cout << "berlin.getName(): "  << berlin.getName() << std::endl;
	std::cout << "berlin.getLatitude(): "  << berlin.getLatitude() << std::endl;
	std::cout << "berlin.getLongitude(): "  << berlin.getLongitude() << std::endl;

	std::string name;
	double longitude, latitude;
	tokio.getAllDataByReference(name, latitude, longitude);
	std::cout << "content of local variable \"name\": " << name << std::endl;
	std::cout << "address of local variable \"name\": " << &name << std::endl;
	std::cout << "content of local variable \"latitude\": " << latitude << std::endl;
	std::cout << "address of local variable \"latitude\": " << &latitude << std::endl;
	std::cout << "content of local variable \"longitude\": " << longitude << std::endl;
	std::cout << "address of local variable \"longitude\": " << &longitude << std::endl;
	// Finding: pass by reference results in the variables having the same addresses

	std::cout << std::endl << "and a first real method" << std::endl << "=======================" << std::endl;
	std::cout << "Distance between Amsterdam and Berlin: " << amsterdam.calculateDistance(berlin) << std::endl;
	std::cout << "Distance between Berlin and Tokio: " << berlin.calculateDistance(tokio) << std::endl;

	return 0;
}
