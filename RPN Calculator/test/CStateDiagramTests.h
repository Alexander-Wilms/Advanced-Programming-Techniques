/*
 * CStateDiagramTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CSTATEDIAGRAMTESTS_H_
#define CSTATEDIAGRAMTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../src/CLifoBuffer.h"

class CStateDiagramTests : public CppUnit::TestFixture {
private:
	CLifoBuffer* buffer;
public:

	void setUp() {
		buffer = new CLifoBuffer(5);
		CPPUNIT_ASSERT(buffer != 0);
	}

	void tearDown() {
		delete buffer;
	}

	void testEmpty_evPush_PartiallyFilled() {
		CPPUNIT_ASSERT(buffer != 0);

		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(1, getNoOfElementsOnTheStack());
	}

	void testEmpty_evPop_Empty() {
		CPPUNIT_ASSERT(buffer != 0);

		CFraction data;
		CPPUNIT_ASSERT_EQUAL(0, getNoOfElementsOnTheStack());
		CPPUNIT_ASSERT_EQUAL(false,buffer->pop(data));
		CPPUNIT_ASSERT_EQUAL(0, getNoOfElementsOnTheStack());
	}

	void testPartiallyFilled_evPush_PartiallyFilled() {
		CPPUNIT_ASSERT(buffer != 0);

		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));

		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));

		CPPUNIT_ASSERT_EQUAL(4, getNoOfElementsOnTheStack());
	}

	void testPartiallyFilled_evPush_Full() {
		CPPUNIT_ASSERT(buffer != 0);

		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));

		CPPUNIT_ASSERT_EQUAL(false, buffer->push(CFraction(1,2)));

		CPPUNIT_ASSERT_EQUAL(5, getNoOfElementsOnTheStack());
	}

	void testPartiallyFilled_evPop_Empty() {
		CPPUNIT_ASSERT(buffer != 0);

		buffer->push(CFraction(1,2));
		CFraction data;
		CPPUNIT_ASSERT_EQUAL(true,buffer->pop(data));
		CPPUNIT_ASSERT_EQUAL(0, getNoOfElementsOnTheStack());
	}

	void testPartiallyFilled_evPop_PartiallyFilled() {
		CPPUNIT_ASSERT(buffer != 0);

		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));

		CFraction data;
		CPPUNIT_ASSERT_EQUAL(true, buffer->pop(data));

		CPPUNIT_ASSERT_EQUAL(2, getNoOfElementsOnTheStack());
	}

	void testFull_evPush_Full() {
		CPPUNIT_ASSERT(buffer != 0);

		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));

		CPPUNIT_ASSERT_EQUAL(false, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(5, getNoOfElementsOnTheStack());
	}


	void testFull_evPop_PartiallyFilled() {
		CPPUNIT_ASSERT(buffer != 0);

		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));
		CPPUNIT_ASSERT_EQUAL(true, buffer->push(CFraction(1,2)));

		CFraction data;
		CPPUNIT_ASSERT_EQUAL(true, buffer->pop(data));
		CPPUNIT_ASSERT_EQUAL(4, getNoOfElementsOnTheStack());
	}


	int getNoOfElementsOnTheStack() {
		int numberOfPossiblePushes = 0;

		for(int i = 0; i < 5; i++) {
			if(buffer->push(CFraction(1,2))) {
				numberOfPossiblePushes++;
			}
		}

		CFraction data;
		for(int i = 0; i < numberOfPossiblePushes; i++) {
			buffer->pop(data);
		}

		return 5 - numberOfPossiblePushes;
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("State Diagram Tests");

		suite->addTest(new CppUnit::TestCaller<CStateDiagramTests>("Empty evPush PartiallyFilled", &CStateDiagramTests::testEmpty_evPush_PartiallyFilled));
		suite->addTest(new CppUnit::TestCaller<CStateDiagramTests>("Empty evPop Empty", &CStateDiagramTests::testEmpty_evPop_Empty));

		suite->addTest(new CppUnit::TestCaller<CStateDiagramTests>("PartiallyFilled evPush PartiallyFilled", &CStateDiagramTests::testPartiallyFilled_evPush_PartiallyFilled));
		suite->addTest(new CppUnit::TestCaller<CStateDiagramTests>("PartiallyFilled evPush Full", &CStateDiagramTests::testPartiallyFilled_evPush_Full));
		suite->addTest(new CppUnit::TestCaller<CStateDiagramTests>("PartiallyFilled evPop Empty", &CStateDiagramTests::testPartiallyFilled_evPop_Empty));
		suite->addTest(new CppUnit::TestCaller<CStateDiagramTests>("PartiallyFilled evPop PartiallyFilled", &CStateDiagramTests::testPartiallyFilled_evPop_PartiallyFilled));

		suite->addTest(new CppUnit::TestCaller<CStateDiagramTests>("Full evPush Full", &CStateDiagramTests::testFull_evPush_Full));
		suite->addTest(new CppUnit::TestCaller<CStateDiagramTests>("Full evPop PartiallyFilled", &CStateDiagramTests::testFull_evPop_PartiallyFilled));

		return suite;
	}
};

#endif /* CSTATEDIAGRAMTESTS_H_ */
