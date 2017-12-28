/*
 * CLoadTests.h
 *
 *  Created on: 27.12.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef TEST_CADDWAYPOINTTESTS_H_
#define TEST_CADDWAYPOINTTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

class CAddWaypointTests : public CppUnit::TestFixture {
private:
	CRoute* m_route;
	CPoiDatabase poiDatabase;
	CWpDatabase wpDatabase;
public:

	void setUp() {
		m_route = new CRoute();

		poiDatabase.addElement(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world",	10, 20));

		wpDatabase.addElement(CWaypoint("Darmstadt", 49.872833, 8.651222));
		wpDatabase.addElement(CWaypoint("Berlin", 52.518611, 13.408333));

		m_route->connectToPoiDatabase(&poiDatabase);
		m_route->connectToWpDatabase(&wpDatabase);
	}

	void tearDown() {
		delete m_route;
	}

	void testAddWaypointSuccess() {
		m_route->addWaypoint("Darmstadt");
		std::vector<const CWaypoint*> routeVector = m_route->getRoute();
		CPPUNIT_ASSERT_EQUAL(1, (int) routeVector.size());
	}

	void testAddWaypointFailure() {
		m_route->addWaypoint("Timbuktu");
		std::vector<const CWaypoint*> routeVector = m_route->getRoute();
		CPPUNIT_ASSERT_EQUAL(0, (int) routeVector.size());
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests");

		suite->addTest(new CppUnit::TestCaller<CAddWaypointTests>("Successfully add a waypoint", &CAddWaypointTests::testAddWaypointSuccess));
		suite->addTest(new CppUnit::TestCaller<CAddWaypointTests>("Fail to add a missing waypoint", &CAddWaypointTests::testAddWaypointFailure));

		return suite;
	}

};

#endif /* TEST_CADDWAYPOINTTESTS_H_ */
