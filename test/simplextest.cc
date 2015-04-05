#include "simplextest.hh"

void SimplexTest::setUp()
{	
	m_myGenerator = new PlaneNoiseGenerator();

	m_simplex = new SimplexNoise();
	
	m_width = 512;
	m_height = 256;	

	m_map1 = new PlaneHeightMap(m_width, m_height);	
	m_myGenerator->set_map(m_map1);
	m_myGenerator->set_module(m_simplex);
	m_myGenerator->generate();

	m_map2 = new PlaneHeightMap(m_width, m_height);
	m_myGenerator->set_map(m_map2);
	m_myGenerator->set_module(m_simplex);
	m_myGenerator->generate();
	
}

void SimplexTest::tearDown(void)
{
	delete m_simplex;
	
	delete m_map1;
	delete m_map2;
	
	delete m_myGenerator;
}

void SimplexTest::checking_maps()
{
	for(int x = 0; x < m_width; ++x)
		for(int y = 0; y < m_height; ++y)
			CPPUNIT_ASSERT(m_map1->get(x,y) == m_map2->get(x,y));	
}

void SimplexTest::testSameSimplexResult()
{
	this->checking_maps();
}
