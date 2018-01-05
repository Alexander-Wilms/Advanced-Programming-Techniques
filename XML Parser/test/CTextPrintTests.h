/*
 * CTextParseInputTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CTEXTPRINTTESTS_H_
#define CTEXTPRINTTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../src/CText.h"

class CTextPrintTests: public CppUnit::TestFixture {
private:
	CText* text;
public:

	void setUp() {
		text = new CText();
	}

	void tearDown() {
		delete text;
	}

	void testPrinting() {
		std::string tag;
		unsigned int parsePosition = 0;
		text->parseInput("some data</nested>", parsePosition);
		CPPUNIT_ASSERT_NO_THROW(text->print(0));
	}

	void testPrintingWithNewline() {
		std::string tag;
		unsigned int parsePosition = 0;
		text->parseInput("some data\n</nested>", parsePosition);
		CPPUNIT_ASSERT_NO_THROW(text->print(2));
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Boundary Values Tests");

		suite->addTest(new CppUnit::TestCaller<CTextPrintTests>("Parsing very simple input", &CTextPrintTests::testPrinting));
		suite->addTest(new CppUnit::TestCaller<CTextPrintTests>("Parsing very simple input", &CTextPrintTests::testPrintingWithNewline));

		return suite;
	}
};

#endif /* CTEXTPRINTTESTS_H_ */
