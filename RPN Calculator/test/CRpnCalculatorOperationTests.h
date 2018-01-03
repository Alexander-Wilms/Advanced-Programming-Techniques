/*
 * CRpnCalculatorOperationTests.h
 *
 *  Created on: 03.01.2018
 *      Author: Fabian Alexander Wilms
 */

#ifndef CRPNCALCULATOROPERATIONTESTS_H_
#define CRPNCALCULATOROPERATIONTESTS_H_

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestCaller.h"

#include "../src/CRpnCalculator.h"

class CRpnCalculatorOperationTests : public CppUnit::TestFixture {
private:
	CRpnCalculator* calculator;
public:

	void setUp() {
		calculator = new CRpnCalculator();
	}

	void tearDown() {
		delete calculator;
	}

	void testOperationAdd() {
		calculator->pushValue(CFraction(1,2));
		calculator->pushValue(CFraction(3,4));
		calculator->add();
		CFraction data;
		CPPUNIT_ASSERT_EQUAL(true, calculator->popResult(data));
		CPPUNIT_ASSERT_DOUBLES_EQUAL(1./2+3./4, data.toDouble(), (1./2+3./4)/100);
	}

	void testOperationSubstract() {
		calculator->pushValue(CFraction(1,2));
		calculator->pushValue(CFraction(3,4));
		calculator->substract();
		CFraction data;
		CPPUNIT_ASSERT_EQUAL(true, calculator->popResult(data));
		CPPUNIT_ASSERT_DOUBLES_EQUAL(1./2-3./4, data.toDouble(), abs((1./2-3./4)/100));
	}

	void testOperationMultiply() {
		calculator->pushValue(CFraction(1,2));
		calculator->pushValue(CFraction(3,4));
		calculator->multiply();
		CFraction data;
		CPPUNIT_ASSERT_EQUAL(true, calculator->popResult(data));
		CPPUNIT_ASSERT_DOUBLES_EQUAL(1./2*3./4, data.toDouble(), (1./2*3./4)/100);
	}

	void testOperationDivide() {
		calculator->pushValue(CFraction(1,2));
		calculator->pushValue(CFraction(3,4));
		calculator->divide();
		CFraction data;
		CPPUNIT_ASSERT_EQUAL(true, calculator->popResult(data));
		CPPUNIT_ASSERT_DOUBLES_EQUAL((1./2)/(3./4), data.toDouble(), ((1./2)/(3./4))/100);
	}

	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Boundary Values Tests");


		suite->addTest(new CppUnit::TestCaller<CRpnCalculatorOperationTests>("Boundary value 1", &CRpnCalculatorOperationTests::testOperationAdd));
		suite->addTest(new CppUnit::TestCaller<CRpnCalculatorOperationTests>("Boundary value 1", &CRpnCalculatorOperationTests::testOperationSubstract));
		suite->addTest(new CppUnit::TestCaller<CRpnCalculatorOperationTests>("Boundary value 1", &CRpnCalculatorOperationTests::testOperationMultiply));
		suite->addTest(new CppUnit::TestCaller<CRpnCalculatorOperationTests>("Boundary value 1", &CRpnCalculatorOperationTests::testOperationDivide));

		return suite;
	}
};

#endif /* CRPNCALCULATOROPERATIONTESTS_H_ */
