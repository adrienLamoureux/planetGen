#ifndef DIAMONDSQUARETESTMANAGER_HH
#define DIAMONDSQUARETESTMANAGER_HH

#include "concretetestmanager.hh"
#include <diamondsquaretest.hh>

/**
 * \class DiamondSquareTestManager
 * \brief This class inherits from ConcreteTestManager. It has to add classes 
 * into the diamond-square register of cppunit for pipeline test.
 */
class DiamondSquareTestManager : public ConcreteTestManager
{
public :
	/**
	 * \brief Default constructor of the class.
	 */
	DiamondSquareTestManager();
	/**
	 * \brief Default destructor of the class.
	 */
	~DiamondSquareTestManager();
	
        /**
	 * \brief Method to use the register test of cppunit
	 * \return Result of the diamond-square register test
	 */
	int DiamondSquareTest();
};

#endif /* DIAMONDSQUARETESTMANAGER_HH */
