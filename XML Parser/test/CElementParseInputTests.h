/*
 * CElementParseInputTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CELEMENTPARSEINPUTTEXTTESTS_H_
#define CELEMENTPARSEINPUTTEXTTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../src/CElement.h"
#include "../src/CText.h"

class CElementParseInputTests: public CppUnit::TestFixture {
private:
	CElement* element;
public:

	void setUp() {
		element = new CElement();
	}

	void tearDown() {
		delete element;
	}

	void testParsingVerySimpleInput() {
		std::string input = "<nested>some data</nested>";
		std::string tag;
		unsigned int parsePosition = 0;
		CPPUNIT_ASSERT_EQUAL(true, element->parseInput(input, parsePosition));
		CPPUNIT_ASSERT_EQUAL(std::string("nested"), element->m_tag);
		CPPUNIT_ASSERT_EQUAL(std::string("some data"), ((CText*) element->m_content[0])->m_text);
		CPPUNIT_ASSERT_EQUAL((unsigned int) input.length(), parsePosition);
	}

	void testParsingComplexInput() {
		std::string input = "<top>\n <nested>some "
				"data</nested>\n more data\n</top>";
		std::string tag;
		unsigned int parsePosition = 0;
		CPPUNIT_ASSERT_EQUAL(true, element->parseInput(input, parsePosition));
		CPPUNIT_ASSERT_EQUAL(std::string("top"), element->m_tag);
		CPPUNIT_ASSERT_EQUAL(std::string("\n "), ((CText*) element->m_content[0])->m_text);
		CPPUNIT_ASSERT_EQUAL(std::string("nested"), ((CElement*) element->m_content[1])->m_tag);
		CPPUNIT_ASSERT_EQUAL(std::string("some data"), ((CText*)((CElement*)((CText*) element->m_content[1]))->m_content[0])->m_text);
		CPPUNIT_ASSERT_EQUAL(std::string("\n more data\n"), ((CText*) element->m_content[2])->m_text);
		CPPUNIT_ASSERT_EQUAL((unsigned int) input.length(), parsePosition);
	}

	void testParsingVeryComplexInput() {
		std::string input = "<level1>"
								"<level2>"
									"<level3>"
										"<level4>"
											"<level5_1>"
											"</level5_1>"
											"<level5_2>"
											"</level5_2>"
										"</level4>"
									"</level3>"
								"</level2>"
							"</level1>";
		std::string tag;
		unsigned int parsePosition = 0;
		CPPUNIT_ASSERT_EQUAL(true, element->parseInput(input, parsePosition));
		element->print(0);
		CPPUNIT_ASSERT_EQUAL(std::string("level1"), element->m_tag);
		CPPUNIT_ASSERT_EQUAL(std::string("level2"), ((CElement*) element->m_content[0])->m_tag);
		CPPUNIT_ASSERT_EQUAL(std::string("level3"), ((CElement*) ((CElement*) element->m_content[0])->m_content[0])->m_tag);
		CPPUNIT_ASSERT_EQUAL(std::string("level4"), ((CElement*) ((CElement*) ((CElement*) element->m_content[0])->m_content[0])->m_content[0])->m_tag);
		CPPUNIT_ASSERT_EQUAL(std::string("level5_1"), ((CElement*) ((CElement*) ((CElement*) ((CElement*) element->m_content[0])->m_content[0])->m_content[0])->m_content[0])->m_tag);
		CPPUNIT_ASSERT_EQUAL(std::string("level5_2"), ((CElement*) ((CElement*) ((CElement*) ((CElement*) element->m_content[0])->m_content[0])->m_content[0])->m_content[1])->m_tag);
	}

	void testParsingLegalTags() {
		unsigned int parsePosition = 0;
		CPPUNIT_ASSERT_EQUAL(true, element->parseInput("<Sample></Sample>", parsePosition));
		parsePosition = 0;
		CPPUNIT_ASSERT_EQUAL(true, element->parseInput("<Item1to3></Item1to3>", parsePosition));
		parsePosition = 0;
		CPPUNIT_ASSERT_EQUAL(true, element->parseInput("<point-or-square></point-or-square>", parsePosition));
	}

	void testParsingIllegalTags() {
		unsigned int parsePosition = 0;
		CPPUNIT_ASSERT_EQUAL(false, element->parseInput("<-not.good></-not.good>", parsePosition));
		parsePosition = 0;
		CPPUNIT_ASSERT_EQUAL(false, element->parseInput("<not:good></not:good>", parsePosition));
	}

	void testParsingValidCharacters() {
		unsigned int parsePosition = 0;
		// https://stackoverflow.com/questions/2444447/string-that-contains-all-ascii-characters
		CPPUNIT_ASSERT_EQUAL(true, element->parseInput("<top> \t\n!\"#$%&\'()*+,-./0123456789:;=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~</top>", parsePosition));
		// < is missing from input
	}

	void testParsingInvalidCharacters() {
		unsigned int parsePosition = 0;
		// https://stackoverflow.com/questions/2444447/string-that-contains-all-ascii-characters
		CPPUNIT_ASSERT_EQUAL(false, element->parseInput("<top>ä \t\n!\"#$%&\'()*+,-./0123456789:;=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~</top>", parsePosition));
		//                                                    |
		//                                           invalid text character
	}

	void testParsingOpeningAngledBracketInText() {
		unsigned int parsePosition = 0;
		// https://stackoverflow.com/questions/2444447/string-that-contains-all-ascii-characters
		CPPUNIT_ASSERT_EQUAL(false, element->parseInput("<top><</top>", parsePosition));
		//                                                    |
		//                                           invalid text character
	}

	void testMismatchingOuterOpeningAndClosingTags(){
		unsigned int parsePosition = 0;
		CPPUNIT_ASSERT_EQUAL(false, element->parseInput("<top></end>", parsePosition));
	}

	void testMismatchingInnerOpeningAndClosingTags(){
		unsigned int parsePosition = 0;
		CPPUNIT_ASSERT_EQUAL(false, element->parseInput("<top><open></close></top>", parsePosition));
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Boundary Values Tests");

		suite->addTest(new CppUnit::TestCaller<CElementParseInputTests>("Parsing very simple input", &CElementParseInputTests::testParsingVerySimpleInput));
		suite->addTest(new CppUnit::TestCaller<CElementParseInputTests>("Parsing complex input", &CElementParseInputTests::testParsingComplexInput));
		suite->addTest(new CppUnit::TestCaller<CElementParseInputTests>("Parsing very complex input", &CElementParseInputTests::testParsingVeryComplexInput));
		suite->addTest(new CppUnit::TestCaller<CElementParseInputTests>("Parsing legal tags", &CElementParseInputTests::testParsingLegalTags));
		suite->addTest(new CppUnit::TestCaller<CElementParseInputTests>("Parsing illegal tags", &CElementParseInputTests::testParsingIllegalTags));
		suite->addTest(new CppUnit::TestCaller<CElementParseInputTests>("Parsing valid characters", &CElementParseInputTests::testParsingValidCharacters));
		suite->addTest(new CppUnit::TestCaller<CElementParseInputTests>("Parsing invalid characters", &CElementParseInputTests::testParsingInvalidCharacters));
		suite->addTest(new CppUnit::TestCaller<CElementParseInputTests>("Parsing invalid characters", &CElementParseInputTests::testParsingOpeningAngledBracketInText));
		suite->addTest(new CppUnit::TestCaller<CElementParseInputTests>("Parsing invalid characters", &CElementParseInputTests::testMismatchingOuterOpeningAndClosingTags));
		suite->addTest(new CppUnit::TestCaller<CElementParseInputTests>("Parsing invalid characters", &CElementParseInputTests::testMismatchingInnerOpeningAndClosingTags));

		return suite;
	}
};

#endif /* CELEMENTPARSEINPUTTEXTTESTS_H_ */
