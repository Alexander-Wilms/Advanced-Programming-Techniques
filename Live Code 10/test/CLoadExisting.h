/*
 * CLoadExisting.h
 *
 *  Created on: 15.09.2012
 *      Author: mnl
 */

#ifndef CLOADEXISTING_H_
#define CLOADEXISTING_H_

#include <string>
#include <cppunit/TestCase.h>

#include "../myCode/CAddressDB.h"
using namespace APT;

namespace APTTest {

/**
 * This class implements a single test case for loading the database
 * content from a file. It inherits from TestCase and overloads the method
 * runTest().
 */
class CLoadExisting: public CppUnit::TestCase {
public:
	CLoadExisting() : TestCase("Load existing") {
	}

	void runTest() {
		CAddressDB* adb = new CAddressDB("AddressDB.txt");
		CPPUNIT_ASSERT(adb->loadFromFile());
		delete adb;
	}
};

} /* namespace Test */
#endif /* CLOADEXISTING_H_ */
