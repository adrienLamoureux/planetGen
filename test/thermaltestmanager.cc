#include "thermaltestmanager.hh"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( ThermalTest, "thermalRegister" );

ThermalTestManager::ThermalTestManager()
{

}

ThermalTestManager::~ThermalTestManager()
{

}

int ThermalTestManager::ThermalTest()
{
	return test_unit("thermalRegister");
}
