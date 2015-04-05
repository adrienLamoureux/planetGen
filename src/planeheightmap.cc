/*
 * Implementations of planeheighmap.hh
 */

#include "planeheightmap.hh"

PlaneHeightMap::PlaneHeightMap(int width, int height)
{
	m_deleg = new Array2D<double>(width, height);
}

PlaneHeightMap::~PlaneHeightMap()
{
	delete m_deleg;
}

int PlaneHeightMap::get_width() const
{
	return m_deleg->get_width();
}

int PlaneHeightMap::get_height() const
{
	return m_deleg->get_height();
}

void PlaneHeightMap::set(int x, int y, double value)
{
	m_deleg->set(x, y, value);
}

double PlaneHeightMap::get(int x, int y) const
{
	return m_deleg->get(x, y);
}

double & PlaneHeightMap::at(int x, int y)
{
	return m_deleg->at(x, y);
}

const double & PlaneHeightMap::at(int x, int y) const
{
	return m_deleg->at(x, y);
}
