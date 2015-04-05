#include "midpointdisplacementtest.hh"

void MidpointDisplacementTest::setUp()
{	
	m_midpoint = new PlaneMidpointDisplacement();
	
	m_width = 513;
	m_height = 513;	
}

void MidpointDisplacementTest::tearDown(void)
{
	delete m_midpoint;
	
	delete m_map1;
	delete m_map2;
}

void MidpointDisplacementTest::buildMidpoint()
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
}

void MidpointDisplacementTest::checking_maps()
{
	for(int x = 0; x < m_width; ++x)
		for(int y = 0; y < m_height; ++y)
			CPPUNIT_ASSERT(m_map1->get(x,y) == m_map2->get(x,y));	
}

void MidpointDisplacementTest::testSameMidpointDisplacementResult()
{
	this->buildMidpoint();
	this->checking_maps();
}
