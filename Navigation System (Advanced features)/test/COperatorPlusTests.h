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
	CRoute* m_route;
public:

	void setUp() {
		m_route = new CRoute();
		CPoiDatabase poiDatabase;
		poiDatabase.addElement(CPOI(RESTAURANT, "Mensa HDA", "The best Mensa in the world",
				10, 20));
		CWpDatabase wpDatabase;
		wpDatabase.addElement(CWaypoint("Darmstadt", 49.872833, 8.651222));
		wpDatabase.addElement(CWaypoint("Berlin", 52.518611, 13.408333));

		m_route->connectToPoiDatabase(&poiDatabase);
		m_route->connectToWpDatabase(&wpDatabase);
	}

	void tearDown() {
		delete m_route;
	}

//	static CppUnit::TestSuite* suite() {
//		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests");
//
//		suite->addTest(new CppUnit::TestCaller<CLoadTests>("Load Existing", &CLoadTests::testLoadExisting));
//		return suite;
//	}

};

#endif /* TEST_COPERATORPLUSTESTS_H_ */
