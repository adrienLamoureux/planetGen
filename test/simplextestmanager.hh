#ifndef SIMPLEXTESTMANAGER_HH
#define SIMPLEXTESTMANAGER_HH

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
#include <concretetestmanager.hh>

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
 * \class DiamondSquareTestManager
 * \brief This class inherits from ConcreteTestManager. It has to add classes 
 * into the simplex noise register of cppunit for pipeline test.
 */
class SimplexTestManager : public ConcreteTestManager
{
public :
        /**
	 * \brief Default constructor of the class.
	 */
	SimplexTestManager();
	/**
	 * \brief Default destructor of the class.
	 */
	~SimplexTestManager();

        /**
	 * \brief Method to use the register test of cppunit
	 * \return Result of the simplex noise register test
	 */
	int SimplexTest();
};

#endif /* SIMPLEXTESTMANAGER */
