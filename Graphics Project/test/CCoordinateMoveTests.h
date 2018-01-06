/*
 * CTextParseInputTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CCOORDINATEMOVETESTS_H_
#define CCOORDINATEMOVETESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../myCode/CCoordinate.h"

class CCoordinateMoveTests: public CppUnit::TestFixture {
private:
	GraSys::CCoordinate<float>* coord;
public:

	void setUp() {
		coord = new GraSys::CCoordinate<float>(37, 42);
	}

	void tearDown() {
		delete coord;
	}

	void testMoving() {
		coord->move(3, -2);

		CPPUNIT_ASSERT_EQUAL((float) 40, coord->getX());
		CPPUNIT_ASSERT_EQUAL((float) 40, coord->getX());
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("CCoordinate::move() Tests");

		suite->addTest(new CppUnit::TestCaller<CCoordinateMoveTests>("Move coordinate", &CCoordinateMoveTests::testMoving));

		return suite;
	}
};

#endif /* CCOORDINATEMOVETESTS_H_ */
