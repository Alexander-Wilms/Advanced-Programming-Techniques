/*
 * CElementPrintTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CELEMENTPRINTTESTS_H_
#define CELEMENTPRINTTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../src/CElement.h"
#include "../src/CText.h"

class CElementPrintTests: public CppUnit::TestFixture {
private:
	CElement* element;
public:

	void setUp() {
		element = new CElement();
	}

	void tearDown() {
		delete element;
	}

	void testPrintingWithText() {
		std::string input = "<top>\n <nested>some "
				"data</nested>\n more data\n</top>";
		std::string tag;
		unsigned int parsePosition = 0;
		CPPUNIT_ASSERT_EQUAL(true, element->parseInput(input, parsePosition));
		CPPUNIT_ASSERT_NO_THROW(element->print(3));
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Boundary Values Tests");

		suite->addTest(new CppUnit::TestCaller<CElementPrintTests>("Parsing very simple input", &CElementPrintTests::testPrintingWithText));

		return suite;
	}
};

#endif /* CELEMENTPRINTTESTS_H_ */
