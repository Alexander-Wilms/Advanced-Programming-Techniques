/*
 * CTextParseInputTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CTRIANGLEMOVETESTS_H_
#define CTRIANGLEMOVETESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../myCode/CTriangle.h"

class CTriangleMoveTests: public CppUnit::TestFixture {
private:

public:

	void setUp() {
	}

	void tearDown() {
	}

	void testMoving() {
		GraSys::CCoordinate trianglecorner1(0, 0);
		GraSys::CCoordinate trianglecorner2(3, 7);
		GraSys::CCoordinate trianglecorner3(37, 42);
		GraSys::CTriangle triangle("blue", trianglecorner1, trianglecorner2,
				trianglecorner3);
		triangle.move(1, 2);

		CPPUNIT_ASSERT_EQUAL(GraSys::CCoordinate(1, 2), triangle.getCoordinate(0));
		CPPUNIT_ASSERT_EQUAL(GraSys::CCoordinate(4, 9), triangle.getCoordinate(1));
		CPPUNIT_ASSERT_EQUAL(GraSys::CCoordinate(38, 44), triangle.getCoordinate(2));
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("CTriangle::move() Tests");

		suite->addTest(new CppUnit::TestCaller<CTriangleMoveTests>("Move triangle", &CTriangleMoveTests::testMoving));

		return suite;
	}
};

#endif /* CTRIANGLEMOVETESTS_H_ */
