#ifndef MIDPOINTDISPLACEMENTTESTMANAGER_HH
#define MIDPOINTDISPLACEMENTTESTMANAGER_HH

#include "concretetestmanager.hh"
#include <midpointdisplacementtest.hh>

/**
 * \class MidpointDisplacementTestManager
 * \brief This class inherits from ConcreteTestManager. It has to add classes 
 * into the midpoint displacement register of cppunit for pipeline test.
 */
class MidpointDisplacementTestManager : public ConcreteTestManager
{
public :
	/**
	 * \brief Default constructor of the class.
	 */
	MidpointDisplacementTestManager();
	/**
	 * \brief Default destructor of the class.
	 */
	~MidpointDisplacementTestManager();
	/**
	 * \brief Method to use the register test of cppunit
	 * \return Result of the midpoint displacement register test
	 */
	int MidpointTest();
};

#endif /* MIDPOINTDISPLACEMENTTESTMANAGER_HH */
