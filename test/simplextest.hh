#ifndef SIMPLEXTEST_HH
#define SIMPLEXTEST_HH

#include <iostream>
#include <string>
#include <noise/noise.h>
#include <planeheightmap.hh>
#include <planenoisegenerator.hh>
#include <noisebase.hh>
#include <simplexnoise.hh>
#include <thermalerosion.hh>
#include <hydraulicerosion.hh>

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

#include "simplexnoise.hh"

/**
 * \class SimplexTest
 * \brief This class inherits from CppUnit::TextFixture.
 * It launches a suite of tests for simplex test algorithm.
 */
class SimplexTest : public CppUnit::TestFixture 
{  
	CPPUNIT_TEST_SUITE(SimplexTest);
	CPPUNIT_TEST(testSameSimplexResult);
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
	 * \brief Compare results of simplex noise multiple iteration.
	 */
	void testSameSimplexResult(void);
        /**
	 * \brief Check that the heightmaps are equal 
	 * with the same generation method.
	 */
	void checking_maps();

private:
	SimplexNoise *m_simplex; /**< A simplex noise object */
	int m_width, m_height; /**< The width and height of each map */
	PlaneHeightMap *m_map1, *m_map2; /**< heightmap objects to compare */		
	PlaneNoiseGenerator *m_myGenerator; /**< A noise generator */
};

#endif /* SIMPLEXTEST_HH */
    
