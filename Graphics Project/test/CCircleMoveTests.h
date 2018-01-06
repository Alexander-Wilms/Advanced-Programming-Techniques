/*
 * CTextParseInputTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CCIRCLEMOVETESTS_H_
#define CCIRCLEMOVETESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../myCode/CCircle.h"

class CCircleMoveTests: public CppUnit::TestFixture {
private:

public:

	void setUp() {
	}

	void tearDown() {
	}

	void testMoving() {
		GraSys::CCoordinate center(3, 7);
		GraSys::CCircle circle("blue", center, 3);
		circle.move(1, 2);

		CPPUNIT_ASSERT_EQUAL(GraSys::CCoordinate(4, 9), circle.getCoordinate(0));
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("CCircle::move() Tests");

		suite->addTest(new CppUnit::TestCaller<CCircleMoveTests>("Move circle", &CCircleMoveTests::testMoving));

		return suite;
	}
};

#endif /* CCIRCLEMOVETESTS_H_ */
