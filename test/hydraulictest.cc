#include "hydraulictest.hh"

void HydraulicTest::setUp()
{	
	m_myGenerator = new PlaneNoiseGenerator();
	
	m_hydraulic = new HydraulicErosion();

	m_simplex = new SimplexNoise();

	m_midpoint = new PlaneMidpointDisplacement();

	m_diamond = new PlaneDiamondSquare();
	
	m_perlin = new noise::module::Perlin();

	m_width = 513;
	m_height = 513;	
}

void HydraulicTest::tearDown(void)
{	
        delete m_midpoint;
	delete m_diamond;
	delete m_simplex;
	delete m_perlin;

	delete m_hydraulic;
	
	delete m_map1;
	delete m_map2;
	
	delete m_myGenerator;
}

void HydraulicTest::buildMidpointDisplacement()
{	
        double w = log(m_width-1)/log(2);
	double h = log(m_height-1)/log(2);
	CPPUNIT_ASSERT(h == (int)h);	
	CPPUNIT_ASSERT(w == (int)w);
	
	m_map1 = new PlaneHeightMap(m_width, m_height);
	m_midpoint->set_map(m_map1);
	m_midpoint->generate();

	m_map2 = new PlaneHeightMap(m_width, m_height);
	m_midpoint->set_map(m_map2);
	m_midpoint->generate();

	this->checking_maps();
}

void HydraulicTest::buildDiamondSquare()
{	
        double w = log(m_width-1)/log(2);
	double h = log(m_height-1)/log(2);
	CPPUNIT_ASSERT(h == (int)h);
	CPPUNIT_ASSERT(w == (int)w);

	m_map1 = new PlaneHeightMap(m_width, m_height);
	m_diamond->set_map(m_map1);
	m_diamond->generate();

	m_map2 = new PlaneHeightMap(m_width, m_height);
	m_diamond->set_map(m_map2);
	m_diamond->generate();	

	this->checking_maps();
}

void HydraulicTest::buildSimplexNoise()
{
	m_map1 = new PlaneHeightMap(m_width, m_height);	
	m_myGenerator->set_map(m_map1);
	m_myGenerator->set_module(m_simplex);
	m_myGenerator->generate();

	m_map2 = new PlaneHeightMap(m_width, m_height);
	m_myGenerator->set_map(m_map2);
	m_myGenerator->set_module(m_simplex);
	m_myGenerator->generate();

	this->checking_maps();
}

void HydraulicTest::buildPerlinNoise()
{
	m_map1 = new PlaneHeightMap(m_width, m_height);	
	m_myGenerator->set_map(m_map1);
	m_myGenerator->set_module(m_perlin);
	m_myGenerator->generate();

	m_map2 = new PlaneHeightMap(m_width, m_height);
	m_myGenerator->set_map(m_map2);
	m_myGenerator->set_module(m_perlin);
	m_myGenerator->generate();	

	this->checking_maps();
}

void HydraulicTest::build_hydraulic()
{
	m_hydraulic->set_map(m_map1);
	m_hydraulic->generate();
	m_hydraulic->set_map(m_map2);
	m_hydraulic->generate();

	this->checking_maps();
}

void HydraulicTest::checking_maps()
{
	for(int x = 0; x < m_width; ++x)
		for(int y = 0; y < m_height; ++y)
			CPPUNIT_ASSERT(m_map1->get(x,y) == m_map2->get(x,y));	
}

void HydraulicTest::testSameHydraulicPerlinResult()
{
	this->buildPerlinNoise();
	this->build_hydraulic();
}

void HydraulicTest::testSameHydraulicSimplexResult()
{
	this->buildSimplexNoise();
	this->build_hydraulic();
}
void HydraulicTest::testSameHydraulicMidpointResult()
{
	this->buildMidpointDisplacement();
	this->build_hydraulic();
}

void HydraulicTest::testSameHydraulicDiamondResult()
{
	this->buildDiamondSquare();
	this->build_hydraulic();
}
