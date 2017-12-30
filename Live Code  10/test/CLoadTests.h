/*
 * CLoadTests.h
 *
 *  Created on: 15.09.2012
 *      Author: mnl
 */

#ifndef CLOADTESTS_H_
#define CLOADTESTS_H_

#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CAddressDB.h"
using namespace APT;

namespace APTTest {

/**
 * This class implements several test cases related to loading the
 * data for the database from a file. Each test case is implemented
 * as a method testXXX. The static method suite() returns a TestSuite
 * in which all tests are registered.
 */
class CLoadTests: public CppUnit::TestFixture {
public:

	void testLoadExisting() {
		CAddressDB* adb = new CAddressDB("AddressDB.txt");
		CPPUNIT_ASSERT(adb->loadFromFile());
		delete adb;
	}

	void testLoadMissing() {
		CAddressDB* adb = new CAddressDB("NonExistantDB.txt");
		CPPUNIT_ASSERT(!adb->loadFromFile());
		delete adb;
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests");

		suite->addTest(new CppUnit::TestCaller<CLoadTests>
				 ("Load Existing", &CLoadTests::testLoadExisting));

		suite->addTest(new CppUnit::TestCaller<CLoadTests>
				 ("Load Missing", &CLoadTests::testLoadMissing));

		return suite;
	}
};

} /* namespace Test */
#endif /* CLOADTESTS_H_ */
