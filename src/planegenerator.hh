#ifndef PLANEGENERATOR_HH
#define PLANEGENERATOR_HH

#include "generator.hh"
#include "planeheightmap.hh"

/**
 * \class PlaneGenerator
 * \brief PlaneGenerator is a pure virtual class to generate the elevations of a
 *        planar heightmap.
 */
class PlaneGenerator : public Generator
{
public:

	/**
	 * \brief Destructs the PlaneGenerator
	 */
	virtual ~PlaneGenerator();

	/**
	 * \brief Set the destination heightmap which will contain the
	 *        elevations generated after a call to the generate() function.
	 * \param map The destination heightmap.
	 */
	void set_map(PlaneHeightMap *map);

protected:
	 PlaneHeightMap *m_map; /**< Destination heightmap. */
};

#endif /* PLANEGENERATOR_HH */
