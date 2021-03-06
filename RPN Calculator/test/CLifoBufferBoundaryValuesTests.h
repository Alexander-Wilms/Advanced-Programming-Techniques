/*
 * CBoundaryValuesTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CLIFOBUFFERBOUNDARYVALUESTESTS_H_
#define CLIFOBUFFERBOUNDARYVALUESTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../src/CLifoBuffer.h"

class CLifoBufferBoundaryValueTests : public CppUnit::TestFixture {
private:
	CLifoBuffer* buffer;
public:

	void setUp() {

	}

	void tearDown() {
		delete buffer;
	}

	void testBoundaryValueOne() {
		buffer = new CLifoBuffer(1);
		CPPUNIT_ASSERT(buffer != 0);
		// outside allowed range -> set to 5
		CPPUNIT_ASSERT_EQUAL(5, getStackSize());
	}

	void testBoundaryValueTwo() {
		buffer = new CLifoBuffer(2);
		CPPUNIT_ASSERT(buffer != 0);
		CPPUNIT_ASSERT_EQUAL(2, getStackSize());
	}

	void testBoundaryValueThree() {
		buffer = new CLifoBuffer(3);
		CPPUNIT_ASSERT(buffer != 0);
		CPPUNIT_ASSERT_EQUAL(3, getStackSize());
	}

	void testBoundaryValueNine() {
		buffer = new CLifoBuffer(9);
		CPPUNIT_ASSERT(buffer != 0);
		CPPUNIT_ASSERT_EQUAL(9, getStackSize());
	}

	void testBoundaryValueTen() {
		buffer = new CLifoBuffer(10);
		CPPUNIT_ASSERT(buffer != 0);
		CPPUNIT_ASSERT_EQUAL(10, getStackSize());
	}

	void testBoundaryValueEleven() {
		buffer = new CLifoBuffer(11);
		CPPUNIT_ASSERT(buffer != 0);
		// outside allowed range -> set to 5
		CPPUNIT_ASSERT_EQUAL(5, getStackSize());
	}

	int getStackSize() {
		int numberOfPossiblePushes = 0;

		// max no of pushes we try is 11
		for(int i = 0; i < 11; i++) {
			if(buffer->push(CFraction(1,2))) {
				numberOfPossiblePushes++;
			}
		}

		CFraction data;
		for(int i = 0; i < numberOfPossiblePushes; i++) {
			buffer->pop(data);
		}

		return numberOfPossiblePushes;
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Boundary Values Tests");

		suite->addTest(new CppUnit::TestCaller<CLifoBufferBoundaryValueTests>("Boundary value 1", &CLifoBufferBoundaryValueTests::testBoundaryValueOne));
		suite->addTest(new CppUnit::TestCaller<CLifoBufferBoundaryValueTests>("Boundary value 2", &CLifoBufferBoundaryValueTests::testBoundaryValueTwo));
		suite->addTest(new CppUnit::TestCaller<CLifoBufferBoundaryValueTests>("Boundary value 3", &CLifoBufferBoundaryValueTests::testBoundaryValueThree));
		suite->addTest(new CppUnit::TestCaller<CLifoBufferBoundaryValueTests>("Boundary value 9", &CLifoBufferBoundaryValueTests::testBoundaryValueNine));
		suite->addTest(new CppUnit::TestCaller<CLifoBufferBoundaryValueTests>("Boundary value 10", &CLifoBufferBoundaryValueTests::testBoundaryValueTen));
		suite->addTest(new CppUnit::TestCaller<CLifoBufferBoundaryValueTests>("Boundary value 11", &CLifoBufferBoundaryValueTests::testBoundaryValueEleven));

		return suite;
	}
};

#endif /* CLIFOBUFFERBOUNDARYVALUESTESTS_H_ */
