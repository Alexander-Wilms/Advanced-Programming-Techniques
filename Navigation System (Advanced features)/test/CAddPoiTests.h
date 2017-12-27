/*
 * CLoadTests.h
 *
 *  Created on: 27.12.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef TEST_CADDPOITESTS_H_
#define TEST_CADDPOITESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../myCode/CRoute.h"
#include "../myCode/CPoiDatabase.h"
#include "../myCode/CWpDatabase.h"
#include <vector>

class CAddPoiTests : public CppUnit::TestFixture {
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

	void testAddPOISuccessful() {
		m_route->addWaypoint("Darmstadt");
		m_route->addPoi("Mensa HDA", "Darmstadt");
		std::vector<const CWaypoint*> routeVector = m_route->getRoute();
		CPPUNIT_ASSERT_EQUAL(2, (int) routeVector.size());
	}


	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests");
		suite->addTest(new CppUnit::TestCaller<CAddPoiTests>("Add POI", &CAddPoiTests::testAddPOISuccessful));
		return suite;
	}

};

#endif /* TEST_CADDPOITESTS_H_ */
