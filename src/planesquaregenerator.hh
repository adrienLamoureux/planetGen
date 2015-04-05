#ifndef PLANESQUAREGENERATOR_H
#define PLANESQUAREGENERATOR_H

#include "planegenerator.hh"
#include "planesquareheightmap.hh"


class PlaneSquareGenerator : public PlaneGenerator
{
public:
	/**
	 * \brief Set the destination heightmap which will contain the
	 *        elevations generated after a call to the generate() function.
	 * \param map The destination heightmap.
	 */
	void set_map(PlaneSquareHeightMap *map);

protected:
	 PlaneSquareHeightMap *m_map; /**< Destination heightmap. */
};

#endif
