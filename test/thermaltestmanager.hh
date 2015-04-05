#ifndef THERMALTESTMANAGER_HH
#define THERMALTESTMANAGER_HH

#include "concretetestmanager.hh"
#include <thermaltest.hh>

/**
 * \class ThermalTestManager
 * \brief This class inherits from ConcreteTestManager. It has to add classes 
 * into the thermal erosion register of cppunit for pipeline test.
 */
class ThermalTestManager : public ConcreteTestManager
{
public :
	/**
	 * \brief Default constructor of the class.
	 */
	ThermalTestManager();
	/**
	 * \brief Default destructor of the class.
	 */
	~ThermalTestManager();
	/**
	 * \brief Method to use the register test of cppunit
	 * \return Result of the thermal erosion register test
	 */
	int ThermalTest();
};

#endif /* THERMALTESTMANAGER */
