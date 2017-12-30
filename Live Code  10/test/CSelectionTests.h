/*
 * CFilterTests.h
 *
 *  Created on: 16.09.2012
 *      Author: mnl
 */

#ifndef CFILTERTESTS_H_
#define CFILTERTESTS_H_


#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CAddressDB.h"
using namespace APT;

namespace APTTest {

/**
 * This class implements several test cases related to the selection method.
 * Each test case is implemented
 * as a method testXXX. The static method suite() returns a TestSuite
 * in which all tests are registered.
 */
class CSelectionTests: public CppUnit::TestFixture {
private:
	CAddressDB* adb;

public:

	void setUp() {
		adb = new CAddressDB("test/SelectionTestData1.txt");
		CPPUNIT_ASSERT(adb->loadFromFile());
	}

	void tearDown() {
		delete adb;
	}

	void testSelectAll() {
		CPPUNIT_ASSERT_EQUAL(3, (int)adb->select(ALL).size());
	}

	void testSelectNone() {
		CPPUNIT_ASSERT_EQUAL(0, (int)adb->select(FILTER, "_NOMATCH_").size());
	}

	void testSelectSome() {
		CPPUNIT_ASSERT_EQUAL(2, (int)adb->select(FILTER, "Hier").size());
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Selection Tests");

		suite->addTest(new CppUnit::TestCaller<CSelectionTests>
				 ("Select All", &CSelectionTests::testSelectAll));

		suite->addTest(new CppUnit::TestCaller<CSelectionTests>
				 ("Load Missing", &CSelectionTests::testSelectNone));

		suite->addTest(new CppUnit::TestCaller<CSelectionTests>
				 ("Load Missing", &CSelectionTests::testSelectSome));
		return suite;
	}
};

} /* namespace Test */


#endif /* CFILTERTESTS_H_ */
