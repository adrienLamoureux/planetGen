#ifndef HYDRAULICTESTMANAGER_HH
#define HYDRAULICTESTMANAGER_HH

#include "concretetestmanager.hh"
#include <hydraulictest.hh>

/**
 * \class HydraulicTestManager
 * \brief This class inherits from ConcreteTestManager. It has to add classes 
 * into the hydraulic erosion register of cppunit for pipeline test.
 */
class HydraulicTestManager : public ConcreteTestManager
{
public :
	/**
	 * \brief Default constructor of the class.
	 */
	HydraulicTestManager();
	/**
	 * \brief Default destructor of the class.
	 */
	~HydraulicTestManager();

        /**
	 * \brief Method to use the register test of cppunit
	 * \return Result of the hydraulic erosion register test
	 */
	int HydraulicTest();
};

#endif /* HYDRAULICTESTMANAGER_HH */
