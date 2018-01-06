/*
 * CTextParseInputTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CPLANEBOUNDINGBOXTESTS_H_
#define CPLANEBOUNDINGBOXTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../myCode/CCircle.h"
#include "../myCode/CPlane.h"
#include "../myCode/CRectangle.h"
#include "../myCode/CTriangle.h"

class CPlaneBoundingBoxTests: public CppUnit::TestFixture {
private:

public:

	void setUp() {
	}

	void tearDown() {
	}

	void testRectangle() {
		GraSys::CRectangle<float> rectangle("green", GraSys::CCoordinate<float>(-1,-2), GraSys::CCoordinate<float>(3,4));
		GraSys::CPlane<float> plane;
		plane.addElement(rectangle);
		GraSys::CRectangle<float> boundingBox = plane.boundingBox("", "");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(-1,-2), GraSys::CCoordinate<float>(3,4)), boundingBox);
	}

	void testCircle() {
		GraSys::CCircle<float> circle("blue", GraSys::CCoordinate<float>(37,42), 7);
		GraSys::CPlane<float> plane;
		plane.addElement(circle);
		GraSys::CRectangle<float> boundingBox = plane.boundingBox("CCircle", "blue");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(30,35), GraSys::CCoordinate<float>(44,49)), boundingBox);
	}

	void testTriangle() {
		GraSys::CTriangle<float> triangle("orange", GraSys::CCoordinate<float>(0,0), GraSys::CCoordinate<float>(10,0), GraSys::CCoordinate<float>(5,5));
		GraSys::CPlane<float> plane;
		plane.addElement(triangle);
		GraSys::CRectangle<float> boundingBox = plane.boundingBox("", "orange");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(0,0), GraSys::CCoordinate<float>(10,5)), boundingBox);
	}

	void testAllTypesAllColors() {
		GraSys::CPlane<float> plane;
		GraSys::CRectangle<float> boundingBox;

		GraSys::CRectangle<float> rectangle("red", GraSys::CCoordinate<float>(0,0), GraSys::CCoordinate<float>(2,2));
		plane.addElement(rectangle);

		GraSys::CCircle<float> circle("white" , GraSys::CCoordinate<float>(9,1), 1);
		plane.addElement(circle);

		GraSys::CTriangle<float> triangle("blue", GraSys::CCoordinate<float>(8,8), GraSys::CCoordinate<float>(10,8), GraSys::CCoordinate<float>(9,10));
		plane.addElement(triangle);

		// all types, all colors
		boundingBox = plane.boundingBox("", "");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(0,0), GraSys::CCoordinate<float>(10,10)), boundingBox);

		// rectangle, all colors
		boundingBox = plane.boundingBox("CRectangle", "");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(0,0), GraSys::CCoordinate<float>(2,2)), boundingBox);
		// rectangles, red
		boundingBox = plane.boundingBox("CRectangle", "red");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(0,0), GraSys::CCoordinate<float>(2,2)), boundingBox);
		// rectangles, white
		boundingBox = plane.boundingBox("CRectangle", "white");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(0,0), GraSys::CCoordinate<float>(0,0)), boundingBox);

		// circles, all colors
		boundingBox = plane.boundingBox("CCircle", "");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(8,0), GraSys::CCoordinate<float>(10,2)), boundingBox);
		// circles, white
		boundingBox = plane.boundingBox("CCircle", "white");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(8,0), GraSys::CCoordinate<float>(10,2)), boundingBox);
		// circles, blue
		boundingBox = plane.boundingBox("CCircle", "blue");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(0,0), GraSys::CCoordinate<float>(0,0)), boundingBox);

		// triangles, all colors
		boundingBox = plane.boundingBox("CTriangle", "");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(8,8), GraSys::CCoordinate<float>(10,10)), boundingBox);
		// triangles, blue
		boundingBox = plane.boundingBox("CTriangle", "blue");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(8,8), GraSys::CCoordinate<float>(10,10)), boundingBox);
		// triangles, red
		boundingBox = plane.boundingBox("CTriangle", "red");
		CPPUNIT_ASSERT_EQUAL(GraSys::CRectangle<float>("black", GraSys::CCoordinate<float>(0,0), GraSys::CCoordinate<float>(0,0)), boundingBox);
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("CTriangle::move() Tests");

		suite->addTest(new CppUnit::TestCaller<CPlaneBoundingBoxTests>("Move triangle", &CPlaneBoundingBoxTests::testRectangle));
		suite->addTest(new CppUnit::TestCaller<CPlaneBoundingBoxTests>("Move triangle", &CPlaneBoundingBoxTests::testCircle));
		suite->addTest(new CppUnit::TestCaller<CPlaneBoundingBoxTests>("Move triangle", &CPlaneBoundingBoxTests::testTriangle));
		suite->addTest(new CppUnit::TestCaller<CPlaneBoundingBoxTests>("Move triangle", &CPlaneBoundingBoxTests::testAllTypesAllColors));

		return suite;
	}
};

#endif /* CPLANEBOUNDINGBOXTESTS_H_ */
