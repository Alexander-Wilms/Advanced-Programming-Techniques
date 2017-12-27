#include "CAddPoiTests.h"
#include "CAddWaypointTests.h"
#include "CConnectToPoiDatabaseTests.h"
#include "CConnectToWpDatabaseTests.h"
#include "CCopyConstructorTests.h"
#include "CGetDistanceNextPoiTests.h"
#include "COperatorPlusEqualTests.h"
#include "COperatorPlusTests.h"
#include "CPrintTests.h"

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
// https://stackoverflow.com/questions/13210248/cppunit-creating-a-simple-test
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/XmlOutputter.h>
#include "CCopyConstructorTests.h"
#include "COperatorAssignmentTests.h"

/**
 * To view the generated *.gcda coverage data file,
 * the gcov Eclipse plugin needs to be installed
 */
int main (int argc, char* argv[]) {
	// Eclipse in-built indexer is worse than useless:
	// https://stackoverflow.com/a/10081040/2278742
	CppUnit::TextUi::TestRunner runner;

	runner.addTest( CAddPoiTests::suite() );
	runner.addTest( CAddWaypointTests::suite() );
	runner.addTest( CConnectToPoiDatabaseTests::suite() );
	runner.addTest( CConnectToWpDatabaseTests::suite() );
	runner.addTest( CCopyConstructorTests::suite() );
	runner.addTest( CGetDistanceNextPoiTests::suite() );
	runner.addTest( COperatorAssignmentTests::suite() );
	runner.addTest( COperatorPlusEqualTests::suite() );
	runner.addTest( COperatorPlusTests::suite() );
	runner.addTest( CPrintTests::suite() );

	CppUnit::TestResult controller;
	runner.run(controller);
	return 0;
}
