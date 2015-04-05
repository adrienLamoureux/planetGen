/*
 * Implementations of planegenerator.hh
 */

#include "planegenerator.hh"


PlaneGenerator::~PlaneGenerator()
{
}

void PlaneGenerator::set_map(PlaneHeightMap *map)
{
	m_map = map;
}
