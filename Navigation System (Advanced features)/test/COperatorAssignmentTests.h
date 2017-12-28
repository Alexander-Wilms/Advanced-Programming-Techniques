/*
 * CLoadTests.h
 *
 *  Created on: 27.12.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef TEST_COPERATOREQUALTESTS_H_
#define TEST_COPERATOREQUALTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

class COperatorAssignmentTests : public CppUnit::TestFixture {
private:
	CRoute* m_route_1;
	CRoute* m_route_2;
	CPoiDatabase poiDatabase;
	CWpDatabase wpDatabase;
public:

	void setUp() {
		m_route_1 = new CRoute();
		m_route_2 = new CRoute();

		poiDatabase.addElement(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world",	10, 20));
		wpDatabase.addElement(CWaypoint("Darmstadt", 49.872833, 8.651222));
		wpDatabase.addElement(CWaypoint("Berlin", 52.518611, 13.408333));

		m_route_1->connectToPoiDatabase(&poiDatabase);
		m_route_1->connectToWpDatabase(&wpDatabase);
		m_route_2->connectToPoiDatabase(&poiDatabase);
		m_route_2->connectToWpDatabase(&wpDatabase);

		m_route_1->addWaypoint("Darmstadt");
		m_route_1->addWaypoint("Berlin");
		m_route_1->addPoi("Mensa HDA", "Darmstadt");

		m_route_2->addWaypoint("Darmstadt");
		m_route_2->addWaypoint("Berlin");
	}

	void tearDown() {
		delete m_route_1;
		delete m_route_2;
	}

	void testAssignment() {
		*m_route_1 = *m_route_2;
		std::vector<const CWaypoint*> route1Vector = m_route_1->getRoute();
		std::vector<const CWaypoint*> route2Vector = m_route_2->getRoute();
		CPPUNIT_ASSERT_EQUAL((int) route1Vector.size(), (int) route2Vector.size());
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests");

		suite->addTest(new CppUnit::TestCaller<COperatorAssignmentTests>("Test the assignment operator", &COperatorAssignmentTests::testAssignment));

		return suite;
	}

};

#endif /* TEST_COPERATOREQUALTESTS_H_ */
