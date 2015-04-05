/*
 * Implementations of hydraulicerosion.hh
 */

#include "hydraulicerosion.hh"
#include <limits>

const double default_rain_amount = 0.01;
const double default_solubility = 0.01;
const double default_evaporation = 0.9;
const double default_capacity = 0.01;

HydraulicErosion::HydraulicErosion() : ErosionGenerator()
{
	m_rain_amount = default_rain_amount;
	m_solubility = default_solubility;
	m_evaporation = default_evaporation;
	m_capacity = default_capacity;
}

HydraulicErosion::~HydraulicErosion()
{
}

void HydraulicErosion::set_rain_amount(double value)
{
	m_rain_amount = value;
}

void HydraulicErosion::set_solubility(double value)
{
	m_solubility = value;
}

void HydraulicErosion::set_evaporation(double value)
{
	m_evaporation = value;
}

void HydraulicErosion::set_capacity(double value)
{
	m_capacity = value;
}

void HydraulicErosion::rain_pass(int x1, int y1, int x2, int y2)
{
	for (int x = 0; x <= x2 - x1; x++) {
		for (int y = 0; y <= y2 - y1; y++) {
			m_water_map->at(x, y) += m_rain_amount;
		}
	}
}

void HydraulicErosion::erosion_pass(int x1, int y1, int x2, int y2)
{
	for (int x = x1; x <= x2; x++) {
		for (int y = y1; y <= y2; y++) {
			m_map->at(x, y) -= m_water_map->at(x - x1, y - y1) *
				m_solubility;
		}
	}
}

void HydraulicErosion::local_variation(int x, int y, int x1, int y1)
{
	int lowest_x, lowest_y;
	double current_height = m_map->at(x, y) + m_water_map->at(x - x1,
								  y - y1);
	double max_diff = -std::numeric_limits<double>::max();

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			double  cur_diff;

			cur_diff = current_height - m_map->at(x + i, y + j) -
				m_water_map->at(x - x1 + i, y - y1 + i);

			if (cur_diff > max_diff) {
				max_diff = cur_diff;

				lowest_x = i;
				lowest_y = j;
			}
		}
	}

	if (max_diff > 0.0) {
		if (m_water_map->at(x - x1, y - y1) < max_diff) {
			m_water_map->at(x - x1 + lowest_x, y - y1 + lowest_y) +=
				m_water_map->at(x - x1, y - y1);

			m_water_map->at(x - x1, y - y1) = 0.0;
		} else {
			m_water_map->at(x - x1 + lowest_x, y - y1 + lowest_y) +=
				max_diff / 2.0;

			m_water_map->at(x - x1, y - y1) -= max_diff / 2.0;
		}
	}
}

void HydraulicErosion::movement_pass(int x1, int y1, int x2, int y2)
{
	for (int x = x1 + 1; x < x2; x++) {
		for (int y = y1 + 1; y < y2; y++) {
			local_variation(x, y, x1, y1);
		}
	}
}

void HydraulicErosion::evaporation_pass(int x1, int y1, int x2, int y2)
{
	double  water_lost;

	for (int x = x1; x <= x2; x++) {
		for (int y = y1; y <= y2; y++) {
			water_lost = m_water_map->at(x - x1, y - y1) *
				m_evaporation;

			m_water_map->at(x - x1, y - y1) -= water_lost;

			m_map->at(x, y) += water_lost * m_capacity;
		}
	}
}

void HydraulicErosion::generate()
{
	generate_area(0, 0, m_map->get_width() - 1, m_map->get_height() - 1);
}

void HydraulicErosion::generate_area(int x1, int y1, int x2, int y2)
{
	m_water_map = new Array2D<double>(x2 - x1 + 1, y2 - y1 + 1);

	for (int x = 0; x <= x2 - x1; x++) {
		for (int y = 0; y <= y2 - y1; y++) {
			m_water_map->at(x, y) = 0;
		}
	}

	for (int i = 0; i < m_nb_iterations; i++) {
		rain_pass(x1, y1, x2, y2);
		erosion_pass(x1, y1, x2, y2);
		movement_pass(x1, y1, x2, y2);
		evaporation_pass(x1, y1, x2, y2);
	}
	delete m_water_map;
}
