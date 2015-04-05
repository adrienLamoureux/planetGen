/*
 * Implementations of planenoisegenerator.hh
 */


#include "planenoisegenerator.hh"

PlaneNoiseGenerator::PlaneNoiseGenerator()
{
	m_module = NULL;
	m_x_lower = 0.0;
	m_z_lower = 0.0;
	m_x_upper = 0.0;
	m_z_upper = 0.0;
}

PlaneNoiseGenerator::~PlaneNoiseGenerator()
{
}

void PlaneNoiseGenerator::set_map(PlaneHeightMap *map)
{
	PlaneGenerator::set_map(map);

	set_bounds(0, 0, map->get_width() / 64.0, map->get_height() / 64.0);
}

void PlaneNoiseGenerator::set_bounds(float x_lower, float z_lower,
				     float x_upper, float z_upper)
{
	m_x_upper = x_upper;
	m_z_upper = z_upper;
	m_x_lower = x_lower;
	m_z_lower = z_lower;
}

void PlaneNoiseGenerator::generate()
{
	generate_area(0, 0, m_map->get_width() - 1, m_map->get_height() - 1);
}

void PlaneNoiseGenerator::generate_area(int x1, int y1, int x2, int y2)
{
	int width = x2 - x1 + 1;
	int height = y2 - y1 + 1;

	float x_extent = m_x_upper - m_x_lower;
	float z_extent = m_z_upper - m_z_lower;
	float x_delta  = x_extent / (float) width;
	float z_delta  = z_extent / (float) height;
	float x_cur    = m_x_lower;
	float z_cur    = m_z_lower;

	for (int x = x1; x <= x2; x++) {
		z_cur = m_z_lower;

		for (int z = y1; z <= y2; z++) {
			m_map->set(x, z, m_module->GetValue(x_cur, 0, z_cur));
			z_cur += z_delta;
		}

		x_cur += x_delta;
	}
}

void PlaneNoiseGenerator::set_module(noise::module::Module *module)
{
	m_module = module;
}
