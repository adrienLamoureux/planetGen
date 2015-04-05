#include "testmanager.hh"

int TestManager::SimplexTest()
{
	SimplexTestManager simplex;
	return simplex.SimplexTest();
}

int TestManager::ThermalTest()
{
	ThermalTestManager thermal;
	return thermal.ThermalTest();
}

int TestManager::HydraulicTest()
{
	HydraulicTestManager hydraulic;
	return hydraulic.HydraulicTest();
}

int TestManager::MidpointDisplacementTest()
{
	MidpointDisplacementTestManager midpoint;
	return midpoint.MidpointTest();
}

int TestManager::DiamondSquareTest()
{
	DiamondSquareTestManager diamond;
	return diamond.DiamondSquareTest();
}
