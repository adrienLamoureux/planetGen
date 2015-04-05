#ifndef DIAMONDSQUARETEST_HH
#define DIAMONDSQUARETEST_HH

#include <iostream>
#include <string>
#include <noise/noise.h>
#include <planeheightmap.hh>
#include <planediamondsquare.hh>

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
 * \class DiamondSquareTest
 * \brief This class inherits from CppUnit::TextFixture.
 * It launches a suite of tests for diamond-square algorithm.
 */
class DiamondSquareTest : public CppUnit::TestFixture 
{  
	CPPUNIT_TEST_SUITE(DiamondSquareTest);
	CPPUNIT_TEST(testSameDiamondSquareResult);
	CPPUNIT_TEST_SUITE_END();
	
public:
	/**
	 * \brief Method to initialize context for testing
	 */
	void setUp(void);
	/**
	 * \brief Method to clear context after testing
	 */
	void tearDown(void);

protected:
	/**
	 * \brief Compare results of diamond-square multiple iteration
	 */
	void testSameDiamondSquareResult(void);
	/**
	 * \brief Create the diamond-square objects for comparaison
	 */
	void buildDiamondSquare();
	/**
	 * \brief Check that the heightmaps are equal 
	 * with the same generation method.
	 */
	void checking_maps();

private:
	PlaneDiamondSquare *m_diamond; /**< A diamond-square object */
	int m_width, m_height; /**< The width and height of each map */
	PlaneHeightMap *m_map1, *m_map2; /**< heightmap objects to compare */	
};

#endif /* DIAMONDSQUARETEST_HH */
    
