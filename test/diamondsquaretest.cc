#include "diamondsquaretest.hh"

void DiamondSquareTest::setUp()
{	
	m_diamond = new PlaneDiamondSquare();
	
	m_width = 513;
	m_height = 513;	
}

void DiamondSquareTest::tearDown(void)
{
	delete m_diamond;
	
	delete m_map1;
	delete m_map2;
}

void DiamondSquareTest::buildDiamondSquare()
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
}

void DiamondSquareTest::checking_maps()
{
	for(int x = 0; x < m_width; ++x)
		for(int y = 0; y < m_height; ++y)
			CPPUNIT_ASSERT(m_map1->get(x,y) == m_map2->get(x,y));	
}

void DiamondSquareTest::testSameDiamondSquareResult()
{
	this->buildDiamondSquare();
	this->checking_maps();
}
