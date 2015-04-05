#include "diamondsquaretestmanager.hh"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( DiamondSquareTest, "diamondRegister" );

DiamondSquareTestManager::DiamondSquareTestManager()
{

}

DiamondSquareTestManager::~DiamondSquareTestManager()
{

}

int DiamondSquareTestManager::DiamondSquareTest()
{
	return test_unit("diamondRegister");
}
