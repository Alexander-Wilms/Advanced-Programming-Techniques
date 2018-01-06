/*
 * CTextParseInputTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CCIRCLECONSTRUCTORTESTS_H_
#define CCIRCLECONSTRUCTORTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../myCode/CCircle.h"

class CCircleConstructorTests: public CppUnit::TestFixture {
private:

public:

	void setUp() {
	}

	void tearDown() {
	}

	void testNoArgument() {
		GraSys::CCircle circle;
		CPPUNIT_ASSERT_EQUAL(GraSys::CCircle("black", GraSys::CCoordinate(0,0), 0), circle);
	}

	void testOneArgument() {
		GraSys::CCircle circle("red");
		CPPUNIT_ASSERT_EQUAL(GraSys::CCircle("red", GraSys::CCoordinate(0,0), 0), circle);
	}

	void testTwoArguments() {
		GraSys::CCircle circle("red", GraSys::CCoordinate(1,2));
		CPPUNIT_ASSERT_EQUAL(GraSys::CCircle("red", GraSys::CCoordinate(1,2), 0), circle);
	}

	void testThreeArguments() {
		GraSys::CCircle circle("red", GraSys::CCoordinate(1,2), 3);
		CPPUNIT_ASSERT_EQUAL(GraSys::CCircle("red", GraSys::CCoordinate(1,2), 3), circle);
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("CCircle::CCircle() Tests");

		suite->addTest(new CppUnit::TestCaller<CCircleConstructorTests>("No argument", &CCircleConstructorTests::testNoArgument));
		suite->addTest(new CppUnit::TestCaller<CCircleConstructorTests>("One argument", &CCircleConstructorTests::testOneArgument));
		suite->addTest(new CppUnit::TestCaller<CCircleConstructorTests>("Two arguments", &CCircleConstructorTests::testTwoArguments));
		suite->addTest(new CppUnit::TestCaller<CCircleConstructorTests>("Three arguments", &CCircleConstructorTests::testThreeArguments));

		return suite;
	}
};

#endif /* CCIRCLECONSTRUCTORTESTS_H_ */
