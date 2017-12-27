/*
 * CLoadTests.h
 *
 *  Created on: 27.12.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef TEST_CGETDISTANCENEXTPOITESTS_H_
#define TEST_CGETDISTANCENEXTPOITESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

class CGetDistanceNextPoiTests : public CppUnit::TestFixture {
private:
	CRoute* m_route;
	CPoiDatabase poiDatabase;
	CWpDatabase wpDatabase;
public:

	void setUp() {
		m_route = new CRoute();

		poiDatabase.addElement(CPOI(SIGHTSEEING, "Berlin", "Berlin City Center", 52.51, 13.4));
		poiDatabase.addElement(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world",	50, 9));

		wpDatabase.addElement(CWaypoint("Berlin", 52.518611, 13.408333));
		wpDatabase.addElement(CWaypoint("Darmstadt", 49.872833, 8.651222));

		m_route->connectToWpDatabase(&wpDatabase);
	}

	void tearDown() {
		delete m_route;
	}

	void testPoiDatabaseNullPointer() {
		CPOI returnByReferenceValue;
		CWaypoint darmstadt("Darmstadt", 49.872833, 8.651222);
		CPPUNIT_ASSERT_EQUAL((double) -1, m_route->getDistanceNextPoi(darmstadt, returnByReferenceValue));
	}

	void testDistanceCalculation() {
		m_route->connectToPoiDatabase(&poiDatabase);
		CPOI returnByReferenceValue;
		CWaypoint darmstadt("Darmstadt", 49.872833, 8.651222);
		CPPUNIT_ASSERT_GREATER((double) 0, m_route->getDistanceNextPoi(darmstadt, returnByReferenceValue));
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests");

		suite->addTest(new CppUnit::TestCaller<CGetDistanceNextPoiTests>("Load Existing", &CGetDistanceNextPoiTests::testPoiDatabaseNullPointer));
		suite->addTest(new CppUnit::TestCaller<CGetDistanceNextPoiTests>("Load Existing", &CGetDistanceNextPoiTests::testDistanceCalculation));

		return suite;
	}

};

#endif /* TEST_CGETDISTANCENEXTPOITESTS_H_ */
