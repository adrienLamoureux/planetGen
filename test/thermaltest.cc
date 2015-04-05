#include "thermaltest.hh"

void ThermalTest::setUp()
{	
	m_myGenerator = new PlaneNoiseGenerator();
	
	m_thermal = new ThermalErosion();

	m_simplex = new SimplexNoise();
	
	m_midpoint = new PlaneMidpointDisplacement();

	m_diamond = new PlaneDiamondSquare();
	
	m_perlin = new noise::module::Perlin();

	m_width = 513;
	m_height = 513;	
}

void ThermalTest::tearDown(void)
{
	delete m_midpoint;
	delete m_diamond;
	delete m_simplex;
	delete m_perlin;

	delete m_thermal;
	
	delete m_map1;
	delete m_map2;
	
	delete m_myGenerator;
}

void ThermalTest::buildMidpointDisplacement()
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

void ThermalTest::buildDiamondSquare()
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

void ThermalTest::buildSimplexNoise()
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

void ThermalTest::buildPerlinNoise()
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

void ThermalTest::build_thermal()
{
	m_thermal->set_map(m_map1);
	m_thermal->generate();
	m_thermal->set_map(m_map2);
	m_thermal->generate();	

	this->checking_maps();
}

void ThermalTest::checking_maps()
{
	for(int x = 0; x < m_width; ++x)
		for(int y = 0; y < m_height; ++y)
			CPPUNIT_ASSERT(m_map1->get(x,y) == m_map2->get(x,y));	
}

void ThermalTest::testSameThermalPerlinResult()
{
	this->buildPerlinNoise();
	this->build_thermal();
}

void ThermalTest::testSameThermalSimplexResult()
{
	this->buildSimplexNoise();
	this->build_thermal();
}

void ThermalTest::testSameThermalMidpointResult()
{
	this->buildMidpointDisplacement();
	this->build_thermal();
}

void ThermalTest::testSameThermalDiamondResult()
{
	this->buildDiamondSquare();
	this->build_thermal();
}
