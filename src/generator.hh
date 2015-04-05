#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "heightmap.hh"

/**
 * \class Generator
 * \brief Generator is a pure virtual class to generate the elevations of a
 *        terrain.
 */
class Generator
{
public:
	/**
	 * \brief Generate elevations of a terrain.
	 */
	virtual void generate() = 0;

	/**
	 * \brief Generate elevations for a given area of a  heightmap. An
	 *        area is represented by its lower and upper x coordinates and
	 *        its lower and upper y coordinates.
	 * \param x1 The lower x coordinate of the area.
	 * \param y1 The lower y coordinate of the area.
	 * \param x2 The upper x coordinate of the area.
	 * \param y2 The upper y coordinate of the area.
	 */
	virtual void generate_area(int x1, int y1, int x2, int y2) = 0;
};

#endif /* GENERATOR_HH */
