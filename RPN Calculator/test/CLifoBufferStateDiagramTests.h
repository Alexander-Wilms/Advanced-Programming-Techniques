/*
 * CStateDiagramTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CLIFOBUFFERSTATEDIAGRAMTESTS_H_
#define CLIFOBUFFERSTATEDIAGRAMTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../src/CLifoBuffer.h"

class CLifoBufferStateDiagramTests : public CppUnit::TestFixture {
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

		suite->addTest(new CppUnit::TestCaller<CLifoBufferStateDiagramTests>("Empty evPush PartiallyFilled", &CLifoBufferStateDiagramTests::testEmpty_evPush_PartiallyFilled));
		suite->addTest(new CppUnit::TestCaller<CLifoBufferStateDiagramTests>("Empty evPop Empty", &CLifoBufferStateDiagramTests::testEmpty_evPop_Empty));

		suite->addTest(new CppUnit::TestCaller<CLifoBufferStateDiagramTests>("PartiallyFilled evPush PartiallyFilled", &CLifoBufferStateDiagramTests::testPartiallyFilled_evPush_PartiallyFilled));
		suite->addTest(new CppUnit::TestCaller<CLifoBufferStateDiagramTests>("PartiallyFilled evPush Full", &CLifoBufferStateDiagramTests::testPartiallyFilled_evPush_Full));
		suite->addTest(new CppUnit::TestCaller<CLifoBufferStateDiagramTests>("PartiallyFilled evPop Empty", &CLifoBufferStateDiagramTests::testPartiallyFilled_evPop_Empty));
		suite->addTest(new CppUnit::TestCaller<CLifoBufferStateDiagramTests>("PartiallyFilled evPop PartiallyFilled", &CLifoBufferStateDiagramTests::testPartiallyFilled_evPop_PartiallyFilled));

		suite->addTest(new CppUnit::TestCaller<CLifoBufferStateDiagramTests>("Full evPush Full", &CLifoBufferStateDiagramTests::testFull_evPush_Full));
		suite->addTest(new CppUnit::TestCaller<CLifoBufferStateDiagramTests>("Full evPop PartiallyFilled", &CLifoBufferStateDiagramTests::testFull_evPop_PartiallyFilled));

		return suite;
	}
};

#endif /* CLIFOBUFFERSTATEDIAGRAMTESTS_H_ */
