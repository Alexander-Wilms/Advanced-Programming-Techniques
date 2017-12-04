/*
 * NavigationSystem.cpp
 *
 *  Created on: 19.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CCSVStorage.h"
#include "CPersistentStorage.h"
#include "CNavigationSystem.h"
#include "CWaypoint.h"
#include <iostream>

int main() {
//	CWaypoint amsterdam("Amsterdam", 52.370197222222, 4.8904444444444);
//	CWaypoint darmstadt("Darmstadt", 49.872833, 8.651222);
//	std::cout << "Constructor" << std::endl << "===========" << std::endl;
//	CWaypoint berlin("Berlin", 52.518611, 13.408333);
//	CWaypoint tokio("Tokio", 35.683889, 139.774444);
//	// no brackets, otherwise it's interpreted as a
//	// function declaration
//	CWaypoint newWaypoint;
//
//	std::cout << std::endl << "print method" << std::endl << "============"
//			<< std::endl;
//	berlin.print(DEGREE);
//	berlin.print(MMSS);
//
//	std::cout << std::endl << "getter methods" << std::endl << "=============="
//			<< std::endl;
//	std::cout << "berlin.getName(): " << berlin.getName() << std::endl;
//	std::cout << "berlin.getLatitude(): " << berlin.getLatitude() << std::endl;
//	std::cout << "berlin.getLongitude(): " << berlin.getLongitude()
//			<< std::endl;
//
//	std::string name;
//	double longitude, latitude;
//	tokio.getAllDataByReference(name, latitude, longitude);
//	std::cout << "content of local variable \"name\": " << name << std::endl;
//	std::cout << "address of local variable \"name\": " << &name << std::endl;
//	std::cout << "content of local variable \"latitude\": " << latitude
//			<< std::endl;
//	std::cout << "address of local variable \"latitude\": " << &latitude
//			<< std::endl;
//	std::cout << "content of local variable \"longitude\": " << longitude
//			<< std::endl;
//	std::cout << "address of local variable \"longitude\": " << &longitude
//			<< std::endl;
//	// Finding: pass by reference results in the variables having the same addresses
//
//	std::cout << std::endl << "and a first real method" << std::endl
//			<< "=======================" << std::endl;
//	std::cout << "Distance between Amsterdam and Berlin: "
//			<< amsterdam.calculateDistance(berlin) << std::endl;
//	std::cout << "Distance between Berlin and Tokio: "
//			<< berlin.calculateDistance(tokio) << std::endl;
//
//	CNavigationSystem navigationSystem = CNavigationSystem();
//	navigationSystem.run();
//
//	std::cout << std::endl << "Test CRoute's copy constructor" << std::endl
//			<< "==============================" << std::endl;

	CPoiDatabase poiDatabase;
	poiDatabase.addPoi(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world",
			10, 20));
	CWpDatabase wpDatabase;
	wpDatabase.addWp(CWaypoint("Darmstadt", 49.872833, 8.651222));
	CRoute* proute1 = new CRoute();
	proute1->connectToPoiDatabase(&poiDatabase);
	proute1->connectToWpDatabase(&wpDatabase);
	proute1->addPoi("Mensa HDA", "doesn't exist");
	proute1->print();

	(*proute1) += "Darmstadt";
	proute1->print();

	proute1->addPoi("Mensa HDA", "Darmstadt");
	proute1->print();

	CRoute route2 = *proute1; // calls the copy constructor
	delete proute1;
	// route2 still has access to its associated member variables
	route2.print();

	std::cout << std::endl << "Test CRoute's assignment operator" << std::endl
				           << "=================================" << std::endl;

	CRoute route3;
	route3 = route2;
	route3.print();

	std::cout << "Test writing the DBs to files" << std::endl
			  << "=============================" << std::endl;
//	CPoiDatabase poiDatabaseCVSWriteTest;
//	poiDatabaseCVSWriteTest.addPoi(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world", 49.866934, 8.637911));
//	poiDatabaseCVSWriteTest.addPoi(CPOI(SIGHTSEEING, "Berlin", "Berlin City Center", 52.51, 13.4));
//	CWpDatabase wpDatabaseCVSWriteTest;
//	wpDatabaseCVSWriteTest.addWp(CWaypoint("Amsterdam", 52.3731, 4.8922));
//	wpDatabaseCVSWriteTest.addWp(CWaypoint("Darmstadt", 49.872833, 8.651222));
//	CCSVStorage myCVSStorage;
//	myCVSStorage.setMediaName("test-export");
//	myCVSStorage.writeData(wpDatabaseCVSWriteTest, poiDatabaseCVSWriteTest);

//	std::cout << "Test reading Dbs from files" << std::endl
//	          << "===========================" << std::endl;
//	CWpDatabase wpDatabaseCVSReadTest;
//	CPoiDatabase poiDatabaseCVSReadTest;
//	CCSVStorage myCVSStorageReadTest;
//	myCVSStorageReadTest.setMediaName("test-export");
//	myCVSStorageReadTest.readData(wpDatabaseCVSReadTest, poiDatabaseCVSReadTest, CPersistentStorage::REPLACE);
//	myCVSStorageReadTest.setMediaName("test-export-import-export");
//	myCVSStorageReadTest.writeData(wpDatabaseCVSReadTest, poiDatabaseCVSReadTest);

	std::cout << "Error handling" << std::endl
	          << "==============" << std::endl;
	CWpDatabase wpDatabaseCVSReadErrorsTest;
	CPoiDatabase poiDatabaseCVSReadErrorsTest;
	CCSVStorage myCVSStorageReadErrorsTest;
	myCVSStorageReadErrorsTest.setMediaName("test-errors-import");
	myCVSStorageReadErrorsTest.readData(wpDatabaseCVSReadErrorsTest, poiDatabaseCVSReadErrorsTest, CPersistentStorage::REPLACE);
	myCVSStorageReadErrorsTest.setMediaName("test-errors-import-export");
	myCVSStorageReadErrorsTest.writeData(wpDatabaseCVSReadErrorsTest, poiDatabaseCVSReadErrorsTest);

	return 0;
}
