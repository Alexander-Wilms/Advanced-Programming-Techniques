/*
 * CUseCaseTests.h
 *
 *  Created on: 3.1.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef TEST_CUSECASETESTS_H_
#define TEST_CUSECASETESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../src/CLifoBuffer.h"

class CLifoBufferUseCaseTests : public CppUnit::TestFixture {
private:
	CLifoBuffer* buffer;
public:

	void setUp() {
		buffer = new CLifoBuffer(5);
	}

	void tearDown() {
		delete buffer;
	}

	void testPushingAndPoppingFractions() {
		CPPUNIT_ASSERT(buffer != 0);

		buffer->push(CFraction(1,2));
		buffer->push(CFraction(3,4));

		CFraction tmp;

		buffer->pop(tmp);
		// allow a delta of 1%
		CPPUNIT_ASSERT_DOUBLES_EQUAL(3./4, tmp.toDouble(),3/4/100);

		buffer->pop(tmp);
		// allow a delta of 1%
		CPPUNIT_ASSERT_DOUBLES_EQUAL(1./2, tmp.toDouble(),1/2/100);
	}

	void testPrinting() {
		CPPUNIT_ASSERT(buffer != 0);

		buffer->push(CFraction(1,2));
		buffer->push(CFraction(3,4));

		buffer->print();
	}

	static CppUnit::TestSuite* suite() {

		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Use Case Tests");

		suite->addTest(new CppUnit::TestCaller<CLifoBufferUseCaseTests>("Pushing and popping fractions", &CLifoBufferUseCaseTests::testPushingAndPoppingFractions));
		suite->addTest(new CppUnit::TestCaller<CLifoBufferUseCaseTests>("Printing", &CLifoBufferUseCaseTests::testPrinting));

		return suite;
	}
};

#endif /* TEST_CUSECASETESTS_H_ */
