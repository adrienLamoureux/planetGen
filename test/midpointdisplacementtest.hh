#ifndef MIDPOINTDISPLACEMENTTEST_HH
#define MIDPOINTDISPLACEMENTTEST_HH

#include <iostream>
#include <string>
#include <noise/noise.h>
#include <planeheightmap.hh>
#include <planemidpointdisplacement.hh>

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
 * \class MidpointDisplacementTest
 * \brief This class inherits from CppUnit::TextFixture.
 * It launches a suite of tests for midpoint displacement algorithm.
 */
class MidpointDisplacementTest : public CppUnit::TestFixture 
{  
	CPPUNIT_TEST_SUITE(MidpointDisplacementTest);
	CPPUNIT_TEST(testSameMidpointDisplacementResult);
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
	 * \brief Compare results of midpoint displacement multiple iteration.
	 */
	void testSameMidpointDisplacementResult(void);
	 /**
	 * \brief Create the heightmap based on midpoint displacement.
	 */
	void buildMidpoint();
        /**
	 * \brief Check that the heightmaps are equal 
	 * with the same generation method.
	 */	
	void checking_maps();

private:
	PlaneMidpointDisplacement *m_midpoint; /**< A midpoint displacement object */
	int m_width, m_height; /**< The width and height of each map */
	PlaneHeightMap *m_map1, *m_map2; /**< heightmap objects to compare */		
};

#endif /* MIDPOINTDISPLACEMENTTEST_HH */
    
