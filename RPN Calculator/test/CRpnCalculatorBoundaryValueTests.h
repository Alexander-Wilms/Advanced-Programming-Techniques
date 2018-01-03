/*
 * CRpnCalculatorBoundaryValuesTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CRPNCALCULATORBOUNDARYVALUETESTS_H_
#define CRPNCALCULATORBOUNDARYVALUETESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../src/CRpnCalculator.h"

class CRpnCalculatorBoundaryValueTests : public CppUnit::TestFixture {
private:
	CRpnCalculator* calculator;
public:

	void setUp() {
		calculator = new CRpnCalculator();
	}

	void tearDown() {
		delete calculator;
	}

	void testBoundaryValueZero() {
		testBoundaryValue(0);
	}

	void testBoundaryValueOne() {
		testBoundaryValue(1);
	}

	void testBoundaryValueTwo() {
		testBoundaryValue(2);
	}

	void testBoundaryValueNine() {
		testBoundaryValue(9);
	}

	void testBoundaryValueTen() {
		testBoundaryValue(10);
	}

	void testBoundaryValueEleven() {
		testBoundaryValue(11);
	}

	void testBoundaryValue(int noOfFractions) {

		for(int i = 1; i <= 2*2; i+=2) {
			calculator->pushValue(CFraction(i,i+1));
		}
		CFraction data;
		for(int i = 2*2; i >= 1; i-=2) {
			CPPUNIT_ASSERT_EQUAL(true, calculator->popResult(data));
			CPPUNIT_ASSERT_EQUAL(CFraction(i-1,i), data);
		}
		CPPUNIT_ASSERT_EQUAL(false, calculator->popResult(data));
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Boundary Values Tests");


		suite->addTest(new CppUnit::TestCaller<CRpnCalculatorBoundaryValueTests>("Boundary value 1", &CRpnCalculatorBoundaryValueTests::testBoundaryValueZero));
		suite->addTest(new CppUnit::TestCaller<CRpnCalculatorBoundaryValueTests>("Boundary value 1", &CRpnCalculatorBoundaryValueTests::testBoundaryValueOne));
		suite->addTest(new CppUnit::TestCaller<CRpnCalculatorBoundaryValueTests>("Boundary value 1", &CRpnCalculatorBoundaryValueTests::testBoundaryValueTwo));
		suite->addTest(new CppUnit::TestCaller<CRpnCalculatorBoundaryValueTests>("Boundary value 1", &CRpnCalculatorBoundaryValueTests::testBoundaryValueNine));
		suite->addTest(new CppUnit::TestCaller<CRpnCalculatorBoundaryValueTests>("Boundary value 1", &CRpnCalculatorBoundaryValueTests::testBoundaryValueTen));
		suite->addTest(new CppUnit::TestCaller<CRpnCalculatorBoundaryValueTests>("Boundary value 1", &CRpnCalculatorBoundaryValueTests::testBoundaryValueEleven));

		return suite;
	}
};

#endif /* CRPNCALCULATORBOUNDARYVALUETESTS_H_ */
