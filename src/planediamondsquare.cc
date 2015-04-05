#include <cstdlib>
#include <ctime>
#include "planediamondsquare.hh"

PlaneDiamondSquare::PlaneDiamondSquare(double amplitude, double persistence,
				       int seed)
{
	m_amplitude = amplitude;
	m_persistence = persistence;
	m_seed = seed;
}

PlaneDiamondSquare::~PlaneDiamondSquare()
{
	
}

void PlaneDiamondSquare::set_amplitude(double amplitude)
{
	m_amplitude = amplitude;
}

double PlaneDiamondSquare::get_amplitude() const
{
	return m_amplitude;
}

void PlaneDiamondSquare::set_persistence(double persistence)
{
	m_persistence = persistence;
}

double PlaneDiamondSquare::get_persistence() const
{
	return m_persistence;
}

void PlaneDiamondSquare::set_seed(int seed)
{
	m_seed = seed;
}

int PlaneDiamondSquare::get_seed() const
{
	return m_seed;
}

void PlaneDiamondSquare::generate()
{
	generate_area(0, 0, m_map->get_width() - 1, m_map->get_height() -1);
}

inline void PlaneDiamondSquare::square_step(int x1, int y1, int x2, int y2,
					    double offset, double range)
{
	int x;
	int y;

	for (y = y1 + offset; y <= y2; y += 2 * offset) {
		for (x = x1 + offset; x <= x2; x += 2 * offset) {
			double error = (rand() / (double) RAND_MAX * -2 + 1) * range;

			double average = (m_map->get(x - offset, y - offset) +
					  m_map->get(x + offset, y - offset) +
					  m_map->get(x + offset, y + offset) +
					  m_map->get(x - offset, y + offset))
				/ 4.0;

			m_map->set(x, y, average + error);
		}
	}
}

inline void PlaneDiamondSquare::diamond_step(int x1, int y1, int x2, int y2,
					     double offset, double range)
{
	bool oddy = false;

	for (int y = y1; y <= y2; y += offset, oddy = !oddy) {
		bool oddx = false;

		for (int x = x1; x <= x2; x += offset, oddx = !oddx) {

			/* If this is a side. */
			if (oddx != oddy) {

				double error = (rand() / (double) RAND_MAX * -2 + 1) * range;
				double average = 0;

				if (x==x1)
					average += m_map->get(x2 - offset, y);
				else
					average += m_map->get(x - offset, y);

				if (x==x2)
					average += m_map->get(offset, y);
				else
					average += m_map->get(x + offset, y);

				if (y==y1)
					average += m_map->get(x, y2 - offset);
				else
					average += m_map->get(x, y - offset);

				if (y==y2)
					average += m_map->get(x, offset);
				else
					average += m_map->get(x, y + offset);

				average /= 4.0;

				m_map->set(x, y, average + error);
			}
		}
	}
}

void PlaneDiamondSquare::generate_area(int x1, int y1, int x2, int y2)
{
	srand(m_seed);

	int offset = (x2 - x1) / 2;
	double range = m_amplitude;

	/* Set the first four corners. */
	m_map->set(x1, y1, rand() / (double) RAND_MAX * -2 + 1);
	m_map->set(x1, y2, rand() / (double) RAND_MAX * -2 + 1);
	m_map->set(x2, y1, rand() / (double) RAND_MAX * -2 + 1);
	m_map->set(x2, y2, rand() / (double) RAND_MAX * -2 + 1);

	while (offset > 0) {
		square_step(x1, y1, x2, y2, offset, range);

		diamond_step(x1, y1, x2, y2, offset, range);

		range *= m_persistence;
		offset /= 2;
	}
}
