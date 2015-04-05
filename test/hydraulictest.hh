#ifndef HYDRAULICTEST_HH
#define HYDRAULICTEST_HH

#include <iostream>
#include <string>
#include <noise/noise.h>
#include <planeheightmap.hh>
#include <planenoisegenerator.hh>
#include <noisebase.hh>
#include <simplexnoise.hh>
#include <thermalerosion.hh>
#include <hydraulicerosion.hh>
#include <planemidpointdisplacement.hh>
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
 * \class HydraulicTest
 * \brief This class inherits from CppUnit::TextFixture.
 * It launches a suite of tests for hydraulic erosion algorithm.
 */
class HydraulicTest : public CppUnit::TestFixture 
{  
	CPPUNIT_TEST_SUITE(HydraulicTest);
	CPPUNIT_TEST(testSameHydraulicSimplexResult);
	CPPUNIT_TEST(testSameHydraulicPerlinResult);
	CPPUNIT_TEST(testSameHydraulicMidpointResult);
	CPPUNIT_TEST(testSameHydraulicDiamondResult);
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
	 * \brief Compare results of hydraulic erosion multiple iteration.
	 * The original heightmap is obtained by simplex noise algorithm. 
	 */
	void testSameHydraulicSimplexResult(void);
	/**
	 * \brief Compare results of hydraulic erosion multiple iteration.
	 * The original heightmap is obtained by perlin noise algorithm. 
	 */
	void testSameHydraulicPerlinResult(void);
	/**
	 * \brief Compare results of hydraulic erosion multiple iteration.
	 * The original heightmap is obtained by midpoint displacement algorithm. 
	 */
	void testSameHydraulicMidpointResult(void);
	/**
	 * \brief Compare results of hydraulic erosion multiple iteration.
	 * The original heightmap is obtained by diamond-square algorithm. 
	 */
	void testSameHydraulicDiamondResult(void);
	/**
	 * \brief Create the original heightmap based on diamond-square.
	 */
	void buildDiamondSquare();
        /**
	 * \brief Create the original heightmap based on midpoint displacement.
	 */
	void buildMidpointDisplacement();
        /**
	 * \brief Create the original heightmap based on simplex noise.
	 */	
	void buildSimplexNoise();
        /**
	 * \brief Create the original heightmap based on perlin noise.
	 */	
	void buildPerlinNoise();
        /**
	 * \brief Create the original heightmap based on hydraulic erosion.
	 */	
	void build_hydraulic();
        /**
	 * \brief Check that the heightmaps are equal 
	 * with the same generation method.
	 */	
	void checking_maps();

private:
	SimplexNoise *m_simplex; /**< A simplex noise object */
	PlaneMidpointDisplacement *m_midpoint; /**< A midpoint displacement object */
	PlaneDiamondSquare *m_diamond; /**< A diamond-square object */
	noise::module::Perlin *m_perlin; /**< A perlin noise object */
	HydraulicErosion *m_hydraulic; /**< A hydraulic erosion object */
	int m_width, m_height; /**< The width and height of each map */
	PlaneHeightMap *m_map1, *m_map2; /**< heightmap objects to compare */	
	PlaneNoiseGenerator *m_myGenerator; /**< A noise generator */
};

#endif /* HYDRAULICTEST_HH */
    
