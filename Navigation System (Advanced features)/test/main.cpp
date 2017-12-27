#include "CAddPoiTests.h"
#include "CAddWaypointTests.h"
#include "CConnectToPoiDatabaseTests.h"
#include "CConnectToWpDatabaseTests.h"
#include "CGetDistanceNextPoiTests.h"
#include "COperatorEqualTests.h"
#include "COperatorPlusEqualTests.h"
#include "COperatorPlusTests.h"

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
// https://stackoverflow.com/questions/13210248/cppunit-creating-a-simple-test
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/XmlOutputter.h>


int main (int argc, char* argv[]) {
	// Eclipse in-built indexer is worse than useless:
	// https://stackoverflow.com/a/10081040/2278742
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( CAddPoiTests::suite() );
	CppUnit::TestResult controller;
	runner.run(controller);
	return 0;
}
