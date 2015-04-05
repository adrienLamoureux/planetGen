#ifndef PLANEMIDPOINTDISPLACEMENT_HH
#define PLANEMIDPOINTDISPLACEMENT_HH

#include "planegenerator.hh"

class PlaneMidpointDisplacement : public PlaneGenerator
{
public:
	/**
	 * \brief Constructs a PlaneMidpointDisplacement.
	 * \param amplitude The amplitude.
	 * \param persistence The persistence.
	 * \param seed The seed.
	 */
	PlaneMidpointDisplacement(double amplitude = m_default_amplitude,
				  double persistence = m_default_persistence,
				  int seed = m_default_seed);

	/**
	 * \brief Destructs a PlaneMidpointDisplacement.
	 */
	virtual ~PlaneMidpointDisplacement();

	/**
	 * \brief Set the amplitude
	 * \param amplitude The amplitude.
	 */
	void set_amplitude(double amplitude);

	/**
	 * \brief Get the amplitude
	 * \return Return the amplitude as a double.
	 */
	double get_amplitude() const;

	/**
	 * \brief Set the persistence.
	 * \param persistence The persistence.
	 * \return Return the persistence as a double.
	 */
	void set_persistence(double persistence);

 	/**
	 * \brief Get the persistence.
	 * \return Return the persistence as a double.
	 */
	double get_persistence() const;

	/**
	 * \brief Set the seed.
	 * \param seed The seed.
	 * \return Return the seed as an integer.
	 */
	void set_seed(int seed);

	/**
	 * \brief Get the seed.
	 * \return Return the seed as an integer.
	 */
	int get_seed() const;

	/**
	 * \brief Generate elevations of the planar heightmap.
	 */
	void generate();

	/**
	 * \brief Generate elevations for a given area of a planar heightmap. An
	 *        area is represented by its lower and upper x coordinates and its
	 *        lower and upper y coordinates.
	 * \param x1 The lower x coordinate of the area.
	 * \param y1 The lower y coordinate of the area.
	 * \param x2 The upper x coordinate of the area.
	 * \param y2 The upper y coordinate of the area.
	 */
	void generate_area(int x1, int y1, int x2, int y2);

private:
	inline void middle_point_step(int x, int y, int offset, double range);

	inline void horizontal_side_step(int x, int y, int offset);

	inline void vertical_side_step(int x, int y, int offset);

	static const double m_default_amplitude = 1;
	static const double m_default_persistence = 0.65;
	static const int m_default_seed = 1;

	double m_amplitude; /**< The amplitude. */
	double m_persistence; /**< The persistence. */
	unsigned int m_seed; /**< The seed. */
};

#endif /* PLANEMIDPOINTDISPLACEMENT_HH */
