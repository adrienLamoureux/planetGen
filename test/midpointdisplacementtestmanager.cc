#include "midpointdisplacementtestmanager.hh"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( MidpointDisplacementTest, "midpointRegister" );

MidpointDisplacementTestManager::MidpointDisplacementTestManager()
{

}

MidpointDisplacementTestManager::~MidpointDisplacementTestManager()
{

}

int MidpointDisplacementTestManager::MidpointTest()
{
	return test_unit("midpointRegister");
}
