#ifndef EROSIONGENERATOR_HH
#define EROSIONGENERATOR_HH

#include "planegenerator.hh"
#include "planeheightmap.hh"

/**
 * \class ErosionGenerator
 * \brief ErosionGenerator implements an erosion generator for a heightmap.
 *        For this generator, no needs to know what is the shape of the map.
 */
class ErosionGenerator : public Generator
{
public:
	/**
	 * \brief Default Constructor
	 */
	ErosionGenerator();
	/**
	 * \brief Default Destructor
	 */
	virtual ~ErosionGenerator();

	/**
	 * \brief Set the destination heightmap which will contain the
	 *        elevations generated after a call to the generate() function.
	 * \param map The destination heightmap.
	 */
	virtual void set_map(HeightMap *map);

	/**
	 * \brief Generate elevations of the planar heightmap.
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

	/**
	 * \brief Set the number of iterations for the erosion.
	 * \param nb The number of iterations.
	 */
	void set_nb_iterations(int nb);

protected:
	HeightMap *m_map;
	int m_nb_iterations; /**< number of iterations for the erosion >*/
};

#endif /* EROSIONGENERATOR_HH */
