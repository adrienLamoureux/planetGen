#include "hydraulictestmanager.hh"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( HydraulicTest, "hydraulicRegister" );

HydraulicTestManager::HydraulicTestManager()
{

}

HydraulicTestManager::~HydraulicTestManager()
{

}

int HydraulicTestManager::HydraulicTest()
{
	return test_unit("hydraulicRegister");
}
