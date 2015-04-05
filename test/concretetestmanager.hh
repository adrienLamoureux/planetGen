#ifndef CONCRETETESTMANAGER_HH
#define CONCRETETESTMANAGER_HH

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
#include <iostream>

/**
 * \class ConcreteTestManager
 * \brief This class provide a method to launch tests depending on the register.
 */
class ConcreteTestManager
{
protected :
	/**
	 * \brief Method to launch cppunit tests
	 * \param registerName The register to use for suite tests
	 * \return The result of the register tests
	 */
        int test_unit(const std::string &registerName);
};



#endif /* CONCRETETESTMANAGER_HH */
