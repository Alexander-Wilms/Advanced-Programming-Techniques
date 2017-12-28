/*
 * CLoadTests.h
 *
 *  Created on: 27.12.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef TEST_CCONNECTTOPOIDATABASETESTS_H_
#define TEST_CCONNECTTOPOIDATABASETESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

class CConnectToPoiDatabaseTests : public CppUnit::TestFixture {
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
	}

	void tearDown() {
		delete m_route;
	}

	void testConnectingToNullPointer() {
		m_route->connectToWpDatabase(&wpDatabase);
		m_route->connectToPoiDatabase(nullptr);
		m_route->addWaypoint("Darmstadt");
		m_route->addPoi("Mensa HDA", "Darmstadt");
		std::vector<const CWaypoint*> routeVector = m_route->getRoute();
		CPPUNIT_ASSERT_EQUAL(1, (int) routeVector.size());
	}

	void testConnectingToDatabase() {
		m_route->connectToWpDatabase(&wpDatabase);
		m_route->connectToPoiDatabase(&poiDatabase);
		m_route->addWaypoint("Darmstadt");
		m_route->addPoi("Mensa HDA", "Darmstadt");
		std::vector<const CWaypoint*> routeVector = m_route->getRoute();
		CPPUNIT_ASSERT_EQUAL(2, (int) routeVector.size());
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests");

		suite->addTest(new CppUnit::TestCaller<CConnectToPoiDatabaseTests>("Fail to connect to nullptr", &CConnectToPoiDatabaseTests::testConnectingToNullPointer));
		suite->addTest(new CppUnit::TestCaller<CConnectToPoiDatabaseTests>("Connect to POI DB", &CConnectToPoiDatabaseTests::testConnectingToDatabase));

		return suite;
	}
};

#endif /* TEST_CCONNECTTOPOIDATABASETESTS_H_ */
