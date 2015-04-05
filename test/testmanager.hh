#ifndef TESTMANAGER_HH
#define TESTMANAGER_HH

#include <iostream>
#include <string>
#include <noise/noise.h>
#include <planeheightmap.hh>
#include <planenoisegenerator.hh>
#include <noisebase.hh>
#include <simplexnoise.hh>
#include <thermalerosion.hh>
#include <hydraulicerosion.hh>
#include <simplextest.hh>
#include <simplextestmanager.hh>
#include <thermaltestmanager.hh>
#include <hydraulictestmanager.hh>
#include <midpointdisplacementtestmanager.hh>
#include <diamondsquaretestmanager.hh>

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>

/**
 * \class TestManager 
 * \brief This class is used to simplify launching of Tests and provide a non-dependency between tests units.
 */
class TestManager
{
public :
	/**
	 * \brief Launch a simplex noise test.
	 * \return Result of a test.
	 */
	static int SimplexTest();
	/**
	 * \brief Launch a thermal erosion test.
	 * \return Result of a test.
	 */
	static int ThermalTest();
	/**
	 * \brief Launch a hydraulic erosion test.	 
	 * \return Result of a test.
	 */
	static int HydraulicTest();
	/**
	 * \brief Launch a midpoint displacement test.
	 * \return Result of a test.
	 */
	static int MidpointDisplacementTest();
	/**	 
	 * \brief Launch a diamond-square test.
	 * \return Result of a test.
	 */
	static int DiamondSquareTest();
};

#endif /* TESTMANAGER_HH */
