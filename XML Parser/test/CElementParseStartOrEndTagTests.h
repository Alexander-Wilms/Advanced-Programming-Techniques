/*
 * CTextParseInputTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CRPNCALCULATOROPERATIONTESTS_H_
#define CRPNCALCULATOROPERATIONTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../src/CElement.h"

class CElementParseStartOrEndTagTests : public CppUnit::TestFixture {
private:
	CElement* element;
public:

	void setUp() {
		element = new CElement();
	}

	void tearDown() {
		delete element;
	}

	void testOpeningTag() {
		bool isStartTag;
		std::string tag;
		unsigned int parsePosition = 3;
		element->parseStartOrEndTag("...<Hi>...", parsePosition, isStartTag, tag);
		CPPUNIT_ASSERT_EQUAL(true, isStartTag);
		CPPUNIT_ASSERT_EQUAL(std::string("Hi"), tag);
		CPPUNIT_ASSERT_EQUAL(7, (int) parsePosition);
	}

	void testClosingTag() {
		bool isStartTag;
		std::string tag;
		unsigned int parsePosition = 3;
		element->parseStartOrEndTag("...</Hi>...", parsePosition, isStartTag, tag);
		CPPUNIT_ASSERT_EQUAL(false, isStartTag);
		CPPUNIT_ASSERT_EQUAL(std::string("Hi"), tag);
		CPPUNIT_ASSERT_EQUAL(8, (int) parsePosition);
	}

	void testPrintingElementWithoutChildren() {
		element->m_tag = "test";
		element->print(0);
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Boundary Values Tests");

		suite->addTest(new CppUnit::TestCaller<CElementParseStartOrEndTagTests>("Boundary value 1", &CElementParseStartOrEndTagTests::testOpeningTag));
		suite->addTest(new CppUnit::TestCaller<CElementParseStartOrEndTagTests>("Boundary value 1", &CElementParseStartOrEndTagTests::testClosingTag));
		suite->addTest(new CppUnit::TestCaller<CElementParseStartOrEndTagTests>("Boundary value 1", &CElementParseStartOrEndTagTests::testPrintingElementWithoutChildren));

		return suite;
	}
};

#endif /* CRPNCALCULATOROPERATIONTESTS_H_ */
