/*
 * CLoadTests.h
 *
 *  Created on: 27.12.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef TEST_COPERATORPLUSTESTS_H_
#define TEST_COPERATORPLUSTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../myCode/CRoute.h"

class COperatorPlusTests : public CppUnit::TestFixture {
private:
	CRoute m_route_original;
	CRoute m_route_sameWpDBdifferentPOIDB;
	CRoute m_route_differentWpDBsamePOIDB;
	CRoute m_route_differentWpDBdifferentPOIDB;
	CRoute m_route_sameWpDBsamePOIDB;
	CRoute m_routeResult;
public:

	void setUp() {
		CPoiDatabase poiDatabase_1;
		poiDatabase_1.addElement(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world", 10, 20));
		CWpDatabase wpDatabase_1;
		wpDatabase_1.addElement(CWaypoint("Darmstadt", 49.872833, 8.651222));
		wpDatabase_1.addElement(CWaypoint("Berlin", 52.518611, 13.408333));

		CPoiDatabase poiDatabase_2;
		poiDatabase_2.addElement(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world", 10, 20));
		CWpDatabase wpDatabase_2;
		wpDatabase_2.addElement(CWaypoint("Darmstadt", 49.872833, 8.651222));
		wpDatabase_2.addElement(CWaypoint("Berlin", 52.518611, 13.408333));

		m_route_original.connectToWpDatabase(&wpDatabase_1);
		m_route_original.connectToPoiDatabase(&poiDatabase_1);
		m_route_original.addWaypoint("Darmstadt");
		m_route_original.addWaypoint("Berlin");
		m_route_original.addPoi("Mensa HDA", "Darmstadt");

		m_route_sameWpDBsamePOIDB.connectToWpDatabase(&wpDatabase_1);
		m_route_sameWpDBsamePOIDB.connectToPoiDatabase(&poiDatabase_1);
		m_route_sameWpDBsamePOIDB.addWaypoint("Darmstadt");
		m_route_sameWpDBsamePOIDB.addPoi("Mensa HDA", "Darmstadt");

		m_route_sameWpDBdifferentPOIDB.connectToWpDatabase(&wpDatabase_1);
		m_route_sameWpDBdifferentPOIDB.connectToPoiDatabase(&poiDatabase_2);
		m_route_sameWpDBdifferentPOIDB.addWaypoint("Darmstadt");
		m_route_sameWpDBdifferentPOIDB.addPoi("Mensa HDA", "Darmstadt");

		m_route_differentWpDBsamePOIDB.connectToWpDatabase(&wpDatabase_2);
		m_route_differentWpDBsamePOIDB.connectToPoiDatabase(&poiDatabase_1);
		m_route_differentWpDBsamePOIDB.addWaypoint("Darmstadt");
		m_route_differentWpDBsamePOIDB.addPoi("Mensa HDA", "Darmstadt");

		m_route_differentWpDBdifferentPOIDB.connectToWpDatabase(&wpDatabase_2);
		m_route_differentWpDBdifferentPOIDB.connectToPoiDatabase(&poiDatabase_2);
		m_route_differentWpDBdifferentPOIDB.addWaypoint("Darmstadt");
		m_route_differentWpDBdifferentPOIDB.addPoi("Mensa HDA", "Darmstadt");
	}

	void tearDown() {
	}

	void addingRoutesWithSameDatabases() {
		m_routeResult = m_route_original + m_route_sameWpDBsamePOIDB;
		std::vector<const CWaypoint*> routeVector = m_routeResult.getRoute();
		CPPUNIT_ASSERT_EQUAL(5, (int) routeVector.size());
	}

	void addingRoutesWithDifferentWaypointDatabases() {
		m_routeResult = m_route_original + m_route_differentWpDBsamePOIDB;
		std::vector<const CWaypoint*> routeVector = m_routeResult.getRoute();
		CPPUNIT_ASSERT_EQUAL(0, (int) routeVector.size());
	}

	void addingRoutesWithDifferentPOIDatabases() {
		m_routeResult = m_route_original + m_route_sameWpDBdifferentPOIDB;
		std::vector<const CWaypoint*> routeVector = m_routeResult.getRoute();
		CPPUNIT_ASSERT_EQUAL(0, (int) routeVector.size());
	}

	void addingRoutesWithDifferentDatabases() {
		m_routeResult = m_route_original + m_route_differentWpDBdifferentPOIDB;
		std::vector<const CWaypoint*> routeVector = m_routeResult.getRoute();
		CPPUNIT_ASSERT_EQUAL(0, (int) routeVector.size());
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests");

		suite->addTest(new CppUnit::TestCaller<COperatorPlusTests>("Successfully add routes", &COperatorPlusTests::addingRoutesWithSameDatabases));
		suite->addTest(new CppUnit::TestCaller<COperatorPlusTests>("Fail to add routes due to different waypoint DBs", &COperatorPlusTests::addingRoutesWithDifferentWaypointDatabases));
		suite->addTest(new CppUnit::TestCaller<COperatorPlusTests>("Fail to add routes due to different POI DBs", &COperatorPlusTests::addingRoutesWithDifferentPOIDatabases));
		suite->addTest(new CppUnit::TestCaller<COperatorPlusTests>("Fail to add routes due to different waypoint and POI DBs", &COperatorPlusTests::addingRoutesWithDifferentDatabases));

		return suite;
	}
};

#endif /* TEST_COPERATORPLUSTESTS_H_ */
