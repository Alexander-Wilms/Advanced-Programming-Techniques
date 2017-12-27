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

class CLoadTests : public CppUnit::TestFixture {
public:
	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests");
		//suite->addTest(new CppUnit::TestCaller<CLoadTests>("Load Existing", &CLoadTests::testLoadExisting));
		return suite;
	}

};

#endif /* TEST_CCONNECTTOPOIDATABASETESTS_H_ */
