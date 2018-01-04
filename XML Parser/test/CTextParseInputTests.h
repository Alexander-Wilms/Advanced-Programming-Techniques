/*
 * CTextParseInputTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CTEXTPARSEINPUTTEXTTESTS_H_
#define CTEXTPARSEINPUTTEXTTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../src/CText.h"

class CTextParseInputTests: public CppUnit::TestFixture {
private:
	CText* text;
public:

	void setUp() {
		text = new CText();
	}

	void tearDown() {
		delete text;
	}

	void testParsingInput() {
		std::string tag;
		unsigned int parsePosition = 0;
		CPPUNIT_ASSERT_EQUAL(true, text->parseInput("some data</nested>", parsePosition));
		CPPUNIT_ASSERT_EQUAL(std::string("some data"), text->m_text);
		CPPUNIT_ASSERT_EQUAL(9, (int) parsePosition);
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Boundary Values Tests");

		suite->addTest(new CppUnit::TestCaller<CTextParseInputTests>("Boundary value 1", &CTextParseInputTests::testParsingInput));

		return suite;
	}
};

#endif /* CTEXTPARSEINPUTTEXTTESTS_H_ */
