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

		wpDatabase.addElement(CWaypoint("Darmstadt", 49.872833, 8.651222));
		wpDatabase.addElement(CWaypoint("Berlin", 52.518611, 13.408333));

		m_route->connectToPoiDatabase(&poiDatabase);
		m_route->connectToWpDatabase(&wpDatabase);
	}

	void tearDown() {
		delete m_route;
	}

	static CppUnit::TestSuite* suite() {
	CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests");

//	suite->addTest(new CppUnit::TestCaller<COperatorPlusEqualTests>("Load Existing", &COperatorPlusEqualTests::testLoadExisting));
//	suite->addTest(new CppUnit::TestCaller<COperatorPlusEqualTests>("Load Missing", &COperatorPlusEqualTests::testLoadMissing));

	return suite;
	}

};

#endif /* TEST_COPERATORPLUSEQUALTESTS_H_ */
