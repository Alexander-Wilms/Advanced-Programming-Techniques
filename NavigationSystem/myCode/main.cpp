/*
 * NavigationSystem.cpp
 *
 *  Created on: 19.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include <iostream>
#include "CNavigationSystem.h"
#include "CWaypoint.h"

int main() {
	CWaypoint amsterdam("Amsterdam", 52.370197222222, 4.8904444444444);
	CWaypoint darmstadt("Darmstadt", 49.872833, 8.651222);
	std::cout << "Constructor" << std::endl << "===========" << std::endl;
	CWaypoint berlin("Berlin", 52.518611, 13.408333);
	CWaypoint tokio("Tokio", 35.683889, 139.774444);
	// no brackets, otherwise it's interpreted as a
	// function declaration
	CWaypoint newWaypoint;

	std::cout << std::endl << "print method" << std::endl << "============"
			<< std::endl;
	berlin.print(DEGREE);
	berlin.print(MMSS);

	std::cout << std::endl << "getter methods" << std::endl << "=============="
			<< std::endl;
	std::cout << "berlin.getName(): " << berlin.getName() << std::endl;
	std::cout << "berlin.getLatitude(): " << berlin.getLatitude() << std::endl;
	std::cout << "berlin.getLongitude(): " << berlin.getLongitude()
			<< std::endl;

	std::string name;
	double longitude, latitude;
	tokio.getAllDataByReference(name, latitude, longitude);
	std::cout << "content of local variable \"name\": " << name << std::endl;
	std::cout << "address of local variable \"name\": " << &name << std::endl;
	std::cout << "content of local variable \"latitude\": " << latitude
			<< std::endl;
	std::cout << "address of local variable \"latitude\": " << &latitude
			<< std::endl;
	std::cout << "content of local variable \"longitude\": " << longitude
			<< std::endl;
	std::cout << "address of local variable \"longitude\": " << &longitude
			<< std::endl;
	// Finding: pass by reference results in the variables having the same addresses

	std::cout << std::endl << "and a first real method" << std::endl
			<< "=======================" << std::endl;
	std::cout << "Distance between Amsterdam and Berlin: "
			<< amsterdam.calculateDistance(berlin) << std::endl;
	std::cout << "Distance between Berlin and Tokio: "
			<< berlin.calculateDistance(tokio) << std::endl;

	CNavigationSystem navigationSystem = CNavigationSystem();
	navigationSystem.run();

	std::cout << std::endl << "Test CRoute's copy constructor" << std::endl
			<< "==============================" << std::endl;

	CPoiDatabase poiDatabase;
	poiDatabase.addPoi(RESTAURANT, "Mensa HDA", "The best Mensa in the world",
			10, 20);
	CRoute* proute1 = new CRoute(10, 10);
	proute1->connectToPoiDatabase(&poiDatabase);
	proute1->addPoi("Mensa HDA");
	proute1->print();

	CRoute route2 = *proute1; // calls the copy constructor
	delete proute1;
	// route2 still has access to its associated member variables
	route2.print();

	return 0;
}
