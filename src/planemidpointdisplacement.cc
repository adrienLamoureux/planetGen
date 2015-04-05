#include <cstdlib>
#include <ctime>
#include "planemidpointdisplacement.hh"

PlaneMidpointDisplacement::PlaneMidpointDisplacement(double amplitude,
						     double persistence,
						     int seed)
{
	m_amplitude = amplitude;
	m_persistence = persistence;
	m_seed = seed;
}

PlaneMidpointDisplacement::~PlaneMidpointDisplacement()
{
	
}

void PlaneMidpointDisplacement::set_amplitude(double amplitude)
{
	m_amplitude = amplitude;
}

double PlaneMidpointDisplacement::get_amplitude() const
{
	return m_amplitude;
}

void PlaneMidpointDisplacement::set_persistence(double persistence)
{
	m_persistence = persistence;
}

double PlaneMidpointDisplacement::get_persistence() const
{
	return m_persistence;
}

void PlaneMidpointDisplacement::set_seed(int seed)
{
	m_seed = seed;
}

int PlaneMidpointDisplacement::get_seed() const
{
	return m_seed;
}

void PlaneMidpointDisplacement::generate()
{
	generate_area(0, 0, m_map->get_width() - 1, m_map->get_height() -1);
}

inline void PlaneMidpointDisplacement::middle_point_step(int x, int y,
							 int offset,
							 double range)
{
	double error = (rand() / (double) RAND_MAX * -2 + 1) * range;

	double average = (m_map->get(x - offset, y - offset) +
			  m_map->get(x + offset, y - offset) +
			  m_map->get(x - offset, y + offset) +
			  m_map->get(x + offset, y + offset)) / 4.0;

	m_map->set(x, y, average + error);
}

inline void PlaneMidpointDisplacement::horizontal_side_step(int x, int y,
							    int offset)
{
	double average = (m_map->get(x - offset, y) +
			  m_map->get(x + offset, y)) / 2.0;

	m_map->set(x, y, average);
}

inline void PlaneMidpointDisplacement::vertical_side_step(int x, int y,
							  int offset)
{
	double average = (m_map->get(x, y - offset) +
			  m_map->get(x, y + offset)) / 2.0;

	m_map->set(x, y, average);
}


void PlaneMidpointDisplacement::generate_area(int x1, int y1, int x2, int y2)
{
	srand(m_seed);

	int offset = (x2 - x1) / 2;
	double range = m_amplitude;

	/* Set the first four corners. */

	m_map->set(x1, y1, (rand() / (double) RAND_MAX * -2 + 1) * range);
	m_map->set(x1, y2, (rand() / (double) RAND_MAX * -2 + 1) * range);
	m_map->set(x2, y1, (rand() / (double) RAND_MAX * -2 + 1) * range);
	m_map->set(x2, y2, (rand() / (double) RAND_MAX * -2 + 1) * range);


	while (offset > 0) {
		bool oddy = false;

		for (int y = y1; y <= y2; y += offset, oddy = !oddy) {
			bool oddx = false;

			for (int x = x1; x <= x2; x += offset, oddx = !oddx) {

				/* If this is a middle point. */

				if (oddx && oddy)
					middle_point_step(x, y, offset, range);

				/* If this is a vertical side. */

				if (!oddx && oddy)
					vertical_side_step(x, y, offset);

				/* If this is a horizontal side. */

				if (!oddy && oddx)
					horizontal_side_step(x, y, offset);
			}
		}

		range *= m_persistence;
		offset /= 2;
	}
}
