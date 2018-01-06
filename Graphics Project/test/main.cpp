#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
// https://stackoverflow.com/questions/13210248/cppunit-creating-a-simple-test
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TextOutputter.h>

#include "CCircleMoveTests.h"
#include "CCircleConstructorTests.h"
#include "CCoordinateMoveTests.h"
#include "CPlaneBoundingBoxTests.h"
#include "CRectangleMoveTests.h"
#include "CTriangleMoveTests.h"

/**
 * To view the generated *.gcda coverage data file,
 * the gcov Eclipse plugin needs to be installed
 */
int main (int argc, char* argv[]) {
	// Eclipse in-built indexer is worse than useless:
	// https://stackoverflow.com/a/10081040/2278742

	// https://schneide.wordpress.com/2009/04/14/structuring-cppunit-tests/

	CppUnit::TestResult controller;
	CppUnit::TestResultCollector result;
	controller.addListener ( &result );
	CppUnit::TextUi::TestRunner runner;

//	runner.addTest( CCircleMoveTests::suite() );
//	runner.addTest( CCircleConstructorTests::suite() );
//	runner.addTest( CCoordinateMoveTests::suite() );
	runner.addTest( CPlaneBoundingBoxTests::suite() );
//	runner.addTest( CRectangleMoveTests::suite() );
//	runner.addTest( CTriangleMoveTests::suite() );

	runner.setOutputter(new CppUnit::TextOutputter(&runner.result(), std::cout));

	return runner.run ("", false, true, false) ? 0 : 1;
}
