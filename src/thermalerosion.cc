/*
 * Implementations of thermalerosion.hh
 */

#include "thermalerosion.hh"
#include <limits>

ThermalErosion::ThermalErosion() : ErosionGenerator()
{
}

ThermalErosion::~ThermalErosion()
{
}

void ThermalErosion::local_variation(int x, int y)
{
	int lowest_x, lowest_y;
	double talus = 4.0f / m_map->get_width();
	double max_diff = -std::numeric_limits<double>::max();
	double current_height = m_map->at(x,y);

	for (int i = -1; i < 2; i += 2) {
		for (int j = -1; j < 2; j += 2) {
			double current_diff = current_height -
				m_map->at(x + i, y + j);

			if (current_diff > max_diff) {
				max_diff = current_diff;
				lowest_x = i;
				lowest_y = j;
			}
		}
	}

	if (max_diff > talus) {
		double new_height = current_height - max_diff / 2.0f;
		m_map->at(x , y) =  new_height;
		m_map->at(x + lowest_x, y + lowest_y) = new_height;
	}
}

void ThermalErosion::generate()
{
	generate_area(0, 0, m_map->get_width() - 1, m_map->get_height() - 1);
}

void ThermalErosion::generate_area(int x1, int y1, int x2, int y2)
{
	for (int i = 0; i < m_nb_iterations; i++) {
		for (int x = x1 + 1; x < x2; x++) {
			for (int y = y1 + 1; y < y2; y++) {
				local_variation(x, y);
			}
		}
	}
}
