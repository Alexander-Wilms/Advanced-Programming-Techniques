/*
 * NavigationSystem.cpp
 *
 *  Created on: 19.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CPersistentStorage.h"
#include "CNavigationSystem.h"
#include "CWaypoint.h"
#include "CCsvPersistence.h"
#include "CJsonPersistence.h"
#include <iostream>

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

	std::cout << std::endl << "Test CRoute's operator+= and addPoi" << std::endl
				               << "==============================" << std::endl;


	CPoiDatabase poiDatabase;
	poiDatabase.addElement(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world",
			10, 20));
	CWpDatabase wpDatabase;
	wpDatabase.addElement(CWaypoint("Darmstadt", 49.872833, 8.651222));
	wpDatabase.addElement(CWaypoint("Berlin", 52.518611, 13.408333));
	CRoute* proute1 = new CRoute();
	proute1->connectToPoiDatabase(&poiDatabase);
	proute1->connectToWpDatabase(&wpDatabase);
	std::cout << "TEST: Adding POI should fail if the corresponding waypoint doesn't exist:" << std::endl;
	proute1->addPoi("Mensa HDA", "doesn't exist");
	proute1->print();

	std::cout << "TEST: Adding POI should fail if the corresponding waypoint doesn't exist:" << std::endl;
	proute1->addPoi("Mensa HDA", "Darmstadt");
	proute1->print();

	std::cout << "TEST: Adding the previously missing waypoint:" << std::endl;
	(*proute1) += "Darmstadt";
	proute1->print();

	std::cout << "TEST: Adding another waypoint:" << std::endl;
	(*proute1) += "Berlin";
	proute1->print();

	std::cout << "TEST: Now, adding the POI after waypoint 'Darmstadt' should succeed:" << std::endl;
	proute1->addPoi("Mensa HDA", "Darmstadt");
	proute1->print();

	std::cout << std::endl << "Test CRoute's copy constructor" << std::endl
				           << "==============================" << std::endl;
	CRoute route2 = *proute1; // calls the copy constructor
	proute1->print();
	delete proute1;
	std::cout << "TEST: If the copy constructor works, the following route is the same as above and thus still has access to it's member variables:" << std::endl;
	route2.print();

	std::cout << std::endl << "Test CRoute's assignment operator" << std::endl
				           << "=================================" << std::endl;
	CRoute route3;
	route3 = route2;
	std::cout << "TEST: The original route:" << std::endl;
	route2.print();
	std::cout << "TEST: If the overloaded assignment operator works, the following route is the same as above:" << std::endl;
	route3.print();

	std::cout << std::endl << "Test CRoute's operator+" << std::endl
				           << "=================================" << std::endl;
	std::cout << "TEST: Adding two routes using the same databases should work:" << std::endl;
	route2 = route2 + route3;
	std::cout << "TEST: The sum of two routes with the same databases:" << std::endl;
	route2.print();
	CRoute route4;
	CPoiDatabase poiDatabaseOperatorPlus;
	poiDatabaseOperatorPlus.addElement(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world",
				10, 20));
	CWpDatabase wpDatabaseOperatorPlus;
	wpDatabase.addElement(CWaypoint("Darmstadt", 49.872833, 8.651222));
	route4.connectToPoiDatabase(&poiDatabaseOperatorPlus);
	route4.connectToWpDatabase(&wpDatabaseOperatorPlus);
	std::cout << "TEST: Adding two routes using the same databases shouldn't work:" << std::endl;
	CRoute routetest = route2 + route4;
	std::cout << "TEST: The sum of two routes with different databases should be an empty route:" << std::endl;

	std::cout << std::endl << "Test writing the DBs to CSV files" << std::endl
			               << "=============================" << std::endl;
	CPoiDatabase poiDatabaseCVSWriteTest;
	poiDatabaseCVSWriteTest.addElement(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world", 49.866934, 8.637911));
	poiDatabaseCVSWriteTest.addElement(CPOI(SIGHTSEEING, "Berlin", "Berlin City Center", 52.51, 13.4));
	CWpDatabase wpDatabaseCVSWriteTest;
	wpDatabaseCVSWriteTest.addElement(CWaypoint("Amsterdam", 52.3731, 4.8922));
	wpDatabaseCVSWriteTest.addElement(CWaypoint("Darmstadt", 49.872833, 8.651222));
	CCsvPersistence myCVSStorage;
	myCVSStorage.setMediaName("test-export");
	myCVSStorage.writeData(wpDatabaseCVSWriteTest, poiDatabaseCVSWriteTest);
	std::cout << "TEST: Check if the files 'test-export-poi/wp.csv' have the expected content" << std::endl;

	std::cout << std::endl << "Test reading DBs from CSV files and writing it back" << std::endl
	          	           << "===============================================" << std::endl;
	CWpDatabase wpDatabaseCVSReadTest;
	CPoiDatabase poiDatabaseCVSReadTest;
	CCsvPersistence myCVSStorageReadTest;
	myCVSStorageReadTest.setMediaName("test-export");
	myCVSStorageReadTest.readData(wpDatabaseCVSReadTest, poiDatabaseCVSReadTest, CPersistentStorage::REPLACE);
	myCVSStorageReadTest.setMediaName("test-export-import-export");
	myCVSStorageReadTest.writeData(wpDatabaseCVSReadTest, poiDatabaseCVSReadTest);
	std::cout << "TEST: Check if the 'test-export-import-export-poi/wp.csv' files have the same content as the 'test-export-poi/wp.csv' files" << std::endl;

	std::cout << std::endl << "CSV: Error handling" << std::endl
	          	  	  	   << "==============" << std::endl;
	CWpDatabase wpDatabaseCVSReadErrorsTest;
	CPoiDatabase poiDatabaseCVSReadErrorsTest;
	CCsvPersistence myCVSStorageReadErrorsTest;
	myCVSStorageReadErrorsTest.setMediaName("test-errors-import");
	myCVSStorageReadErrorsTest.readData(wpDatabaseCVSReadErrorsTest, poiDatabaseCVSReadErrorsTest, CPersistentStorage::REPLACE);
	myCVSStorageReadErrorsTest.setMediaName("test-errors-import-export");
	myCVSStorageReadErrorsTest.writeData(wpDatabaseCVSReadErrorsTest, poiDatabaseCVSReadErrorsTest);

	std::cout << std::endl << "Test writing the DBs to JSON files" << std::endl
				               << "=============================" << std::endl;
	CPoiDatabase poiDatabaseJSONWriteTest;
	CWpDatabase wpDatabaseJSONWriteTest;
	CJsonPersistence myJSONStorage;


	myJSONStorage.setMediaName("test-export-empty-waypoints-empty-pois");
	myJSONStorage.writeData(wpDatabaseJSONWriteTest, poiDatabaseJSONWriteTest);

	wpDatabaseJSONWriteTest.addElement(CWaypoint("Amsterdam", 52.3731, 4.8922));
	wpDatabaseJSONWriteTest.addElement(CWaypoint("Darmstadt", 49.872833, 8.651222));


	myJSONStorage.setMediaName("test-export-empty-pois");
	myJSONStorage.writeData(wpDatabaseJSONWriteTest, poiDatabaseJSONWriteTest);

	poiDatabaseJSONWriteTest.addElement(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world", 49.866934, 8.637911));
	poiDatabaseJSONWriteTest.addElement(CPOI(SIGHTSEEING, "Berlin", "Berlin City Center", 52.51, 13.4));

	myJSONStorage.setMediaName("test-export");
	myJSONStorage.writeData(wpDatabaseJSONWriteTest, poiDatabaseJSONWriteTest);
	std::cout << "TEST: Check if the file 'test-export.json' has the expected content" << std::endl;

	std::cout << std::endl << "Test reading the DBs from JSON files and writing them back" << std::endl
					               << "=============================" << std::endl;
	CWpDatabase wpDatabaseJSONReadTest;
	CPoiDatabase poiDatabaseJSONReadTest;
	CJsonPersistence myJSONStorageReadTest;
	myJSONStorageReadTest.setMediaName("test-export");
	myJSONStorageReadTest.readData(wpDatabaseJSONReadTest, poiDatabaseJSONReadTest, CPersistentStorage::REPLACE);
	myJSONStorageReadTest.setMediaName("test-export-import-export");
	myJSONStorageReadTest.writeData(wpDatabaseJSONReadTest, poiDatabaseJSONReadTest);
	std::cout << "TEST: Check if the 'test-export.json' file has the same content as the 'test-export-import-export.json' file" << std::endl;

	std::cout << std::endl << "Test reading the DBs from JSON files and writing them back" << std::endl
					               << "=============================" << std::endl;
	CWpDatabase wpDatabaseJSONReadOrderTest;
	CPoiDatabase poiDatabaseJSONReadOrderTest;
	CJsonPersistence myJSONStorageReadOrderTest;
	myJSONStorageReadOrderTest.setMediaName("test-import-order");
	myJSONStorageReadOrderTest.readData(wpDatabaseJSONReadOrderTest, poiDatabaseJSONReadOrderTest, CPersistentStorage::REPLACE);
	myJSONStorageReadOrderTest.setMediaName("test-import-order-export");
	myJSONStorageReadOrderTest.writeData(wpDatabaseJSONReadOrderTest, poiDatabaseJSONReadOrderTest);
	std::cout << "TEST: Check if the 'test-import-order-export.json' file has the same content as the 'test-import-order.json' file" << std::endl;

	std::cout << std::endl << "Test reading the DBs from invalid JSON files and writing them back" << std::endl
					               << "=============================" << std::endl;
	CWpDatabase wpDatabaseJSONReadInvalidTest;
	CPoiDatabase poiDatabaseJSONReadInvalidTest;
	CJsonPersistence myJSONStorageReadInvalidTest;
	myJSONStorageReadInvalidTest.setMediaName("test-import-error-handling");
	myJSONStorageReadInvalidTest.readData(wpDatabaseJSONReadInvalidTest, poiDatabaseJSONReadInvalidTest, CPersistentStorage::REPLACE);
	myJSONStorageReadInvalidTest.setMediaName("test-import-error-handling-export");
	myJSONStorageReadInvalidTest.writeData(wpDatabaseJSONReadInvalidTest, poiDatabaseJSONReadInvalidTest);
	std::cout << "TEST: Check if the 'test-import-error-handling.json' file has the same content as the 'test-import-error-handling-export.json' file" << std::endl;

	return 0;
}
