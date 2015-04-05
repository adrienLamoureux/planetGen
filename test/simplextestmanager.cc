#include "simplextestmanager.hh"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( SimplexTest, "simplexRegister" );

SimplexTestManager::SimplexTestManager()
{

}

SimplexTestManager::~SimplexTestManager()
{

}

int SimplexTestManager::SimplexTest()
{
	return test_unit("simplexRegister");
}
