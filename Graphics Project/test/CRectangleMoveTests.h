/*
 * CTextParseInputTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CRECTANGLEMOVETESTS_H_
#define CRECTANGLEMOVETESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../myCode/CRectangle.h"

class CRectangleMoveTests: public CppUnit::TestFixture {
private:

public:

	void setUp() {
	}

	void tearDown() {
	}

	void testMoving() {
		GraSys::CCoordinate corner1(0, 0);
		GraSys::CCoordinate corner2(37, 42);
		GraSys::CRectangle rectangle("black", corner1, corner2);
		rectangle.move(1, 2);

		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle("black", GraSys::CCoordinate(1,2), GraSys::CCoordinate(38,44)), rectangle);
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("CRectangle::move() Tests");

		suite->addTest(new CppUnit::TestCaller<CRectangleMoveTests>("Move rectangle", &CRectangleMoveTests::testMoving));

		return suite;
	}
};

#endif /* CRECTANGLEMOVETESTS_H_ */
