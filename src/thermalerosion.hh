#ifndef THERMALEROSION_HH
#define THERMALEROSION_HH

#include "erosiongenerator.hh"
#include "planeheightmap.hh"

/**
 * \class ThermalErosion
 * \brief ThermalErosion implements erosion generator
 */
class ThermalErosion : public ErosionGenerator
{
public:
	/**
	 * \brief Default Constructor
	 */
	ThermalErosion();
	/**
	 * \brief Default Destructor
	 */
	virtual ~ThermalErosion();
	/**
	 * \brief Generate elevations of the heightmap.
	 */
	virtual void generate();

	/**
	 * \brief Generate elevations for a given area of a  heightmap. An
	 *        area is represented by its lower and upper x coordinates and
	 *        its lower and upper y coordinates.
	 * \param x1 The lower x coordinate of the area.
	 * \param y1 The lower y coordinate of the area.
	 * \param x2 The upper x coordinate of the area.
	 * \param y2 The upper y coordinate of the area.
	 */
	void generate_area(int x1, int y1, int x2, int y2);

protected:
	/**
	 * \brief Compute local variation because of hydraulic erosion on a
	 *        pixel.
	 * \param x The x coordinate of the current pixel
	 * \param y The y coordinate of the current pixel
	 */
	void local_variation(int x, int y);
};

#endif /* THERMALEROSION_HH */
