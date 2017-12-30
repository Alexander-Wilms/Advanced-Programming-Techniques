/*
 * main.cpp
 *
 *  Created on: 11.09.2012
 *      Author: Michael
 */

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

#include "CLoadExisting.h"
#include "CLoadTests.h"
#include "CSelectionTests.h"

using namespace CppUnit;
using namespace APTTest;

int main (int argc, char* argv[]) {

	TextUi::TestRunner runner;
	//runner.addTest( new CLoadExisting() );

	runner.addTest( CLoadTests::suite() );
	runner.addTest( CSelectionTests::suite() );
	runner.run();

	return 0;
}
