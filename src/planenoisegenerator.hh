#ifndef PLANENOISEGENERATOR_HH
#define PLANENOISEGENERATOR_HH

#include <noise/noise.h>
#include "planegenerator.hh"
#include "planeheightmap.hh"

/**
 * \class PlaneNoiseGenerator
 * \brief PlaneNoiseGenerator implements a noise generator for a planar
 *        heightmap. It uses a module from Libnoise (ie. noise::module::Module)
 *        to generate the noise values.
 */
class PlaneNoiseGenerator : public PlaneGenerator
{
public:
	/**
	 * \brief Construct a PlaneNoiseGenerator.
	 */
	PlaneNoiseGenerator();

	/**
	 * \brief Destruct a PlaneNoiseGenerator.
	 */
	virtual ~PlaneNoiseGenerator();

	/**
	 * \brief Set the destination heightmap which will contain the
	 *        elevations generated after a call to the generate() function.
	 * \param map The destination heightmap.
	 */
	virtual void set_map(PlaneHeightMap *map);

	/**
	 * \brief Set the boundaries of the planar height map.
	 * \param x_lower The lower x boundary of the planar heightmap.
	 * \param z_lower The lower z boundary of the planar heightmap.
	 * \param x_upper The upper x boundary of the planar heightmap.
	 * \param z_upper The upper z boundary of the planar heightmap.
	 */
	void set_bounds(float x_lower, float z_lower,
			float x_upper, float z_upper);

	/**
	 * \brief Generate elevations of the planar heightmap.
	 */
	virtual void generate();

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

	/**
	 * \brief Set the noise module used to generate the elevations.
	 * \param module The noise module.
	 */
	void set_module(noise::module::Module *module);

private:
	noise::module::Module *m_module; /**< noise module */
	float m_x_lower; /**< The lower x boundary of the planar heightmap. */
	float m_z_lower; /**< The lower z boundary of the planar heightmap. */
	float m_x_upper; /**< The upper x boundary of the planar heightmap. */
	float m_z_upper; /**< The upper z boundary of the planar heightmap. */
};

#endif /* PLANENOISEGENERATOR_HH_HH */
