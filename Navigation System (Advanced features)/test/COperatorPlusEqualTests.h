/*
 * CLoadTests.h
 *
 *  Created on: 27.12.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef TEST_COPERATORPLUSEQUALTESTS_H_
#define TEST_COPERATORPLUSEQUALTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

class COperatorPlusEqualTests : public CppUnit::TestFixture {
private:
	CRoute* m_route;
	CPoiDatabase poiDatabase;
	CWpDatabase wpDatabase;
public:

	void setUp() {
		m_route = new CRoute();

		poiDatabase.addElement(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world",	10, 20));
		poiDatabase.addElement(CPOI(SIGHTSEEING, "Darmstadt", "Worth a visit", 50, 9));
		wpDatabase.addElement(CWaypoint("Darmstadt", 49.872833, 8.651222));
		wpDatabase.addElement(CWaypoint("Berlin", 52.518611, 13.408333));



	}

	void tearDown() {
		delete m_route;
	}

	void testWpDatabaseNullPointer() {
		m_route->connectToPoiDatabase(&poiDatabase);
		*m_route += "Mensa HDA";
		std::vector<const CWaypoint*> routeVector = m_route->getRoute();
		CPPUNIT_ASSERT_EQUAL(0, (int) routeVector.size());
	}

	void testPoiDatabaseNullPointer() {
		m_route->connectToWpDatabase(&wpDatabase);
		*m_route += "Darmstadt";
		std::vector<const CWaypoint*> routeVector = m_route->getRoute();
		CPPUNIT_ASSERT_EQUAL(0, (int) routeVector.size());
	}

	void testAddWaypointSuccessfullyAndPOISuccessfully() {
		m_route->connectToWpDatabase(&wpDatabase);
		m_route->connectToPoiDatabase(&poiDatabase);
		*m_route += "Darmstadt";
		std::vector<const CWaypoint*> routeVector = m_route->getRoute();
		CPPUNIT_ASSERT_EQUAL(2, (int) routeVector.size());
	}

	void testAddWaypointSuccessfullyAndPOIUnsuccessfully() {
		m_route->connectToWpDatabase(&wpDatabase);
		m_route->connectToPoiDatabase(&poiDatabase);
		*m_route += "Berlin";
		std::vector<const CWaypoint*> routeVector = m_route->getRoute();
		CPPUNIT_ASSERT_EQUAL(1, (int) routeVector.size());
	}

	void testAddWaypointUnsuccessfullyAndPOISuccessfully() {
		m_route->connectToWpDatabase(&wpDatabase);
		m_route->connectToPoiDatabase(&poiDatabase);
		*m_route += "Mensa HDA";
		std::vector<const CWaypoint*> routeVector = m_route->getRoute();
		CPPUNIT_ASSERT_EQUAL(1, (int) routeVector.size());
	}

	void testAddWaypointUnsuccessfullyAndPOIUnsuccessfully() {
		m_route->connectToWpDatabase(&wpDatabase);
		m_route->connectToPoiDatabase(&poiDatabase);
		*m_route += "Timbuktu";
		std::vector<const CWaypoint*> routeVector = m_route->getRoute();
		CPPUNIT_ASSERT_EQUAL(0, (int) routeVector.size());
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests");

		suite->addTest(new CppUnit::TestCaller<COperatorPlusEqualTests>("Load Existing", &COperatorPlusEqualTests::testWpDatabaseNullPointer));
		suite->addTest(new CppUnit::TestCaller<COperatorPlusEqualTests>("Load Missing", &COperatorPlusEqualTests::testPoiDatabaseNullPointer));
		suite->addTest(new CppUnit::TestCaller<COperatorPlusEqualTests>("Load Missing", &COperatorPlusEqualTests::testAddWaypointSuccessfullyAndPOISuccessfully));
		suite->addTest(new CppUnit::TestCaller<COperatorPlusEqualTests>("Load Missing", &COperatorPlusEqualTests::testAddWaypointSuccessfullyAndPOIUnsuccessfully));
		suite->addTest(new CppUnit::TestCaller<COperatorPlusEqualTests>("Load Missing", &COperatorPlusEqualTests::testAddWaypointUnsuccessfullyAndPOISuccessfully));
		suite->addTest(new CppUnit::TestCaller<COperatorPlusEqualTests>("Load Missing", &COperatorPlusEqualTests::testAddWaypointUnsuccessfullyAndPOIUnsuccessfully));

		return suite;
	}

};

#endif /* TEST_COPERATORPLUSEQUALTESTS_H_ */
