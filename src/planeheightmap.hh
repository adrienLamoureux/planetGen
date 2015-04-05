#ifndef PLANEHEIGHTMAP_HH
#define PLANEHEIGHTMAP_HH

#include "utils/array2d.hh"
#include "heightmap.hh"

/**
 * \class PlaneHeightMap
 * \brief This class implements a planar HeightMap.
 */
class PlaneHeightMap : public HeightMap
{
public:
	/**
	 * \brief Constructs a PlaneHeightMap.
	 */
	PlaneHeightMap(int width, int height);

	/**
	 * \brief Destructs the PlaneHeightMap.
	 */
	virtual ~PlaneHeightMap();

	/**
	 * \brief Get the width of the HeightMap
	 * \return Returns the width of the HeightMap.
	 */
	virtual int get_width() const;

	/**
	 * \brief Get the height of the HeightMap
	 * \return Returns the height of the HeightMap.
	 */
	virtual int get_height() const;

	/**
	 * \brief Set the elevation of a given point.
	 * \param x The x coordinate of the point.
	 * \param y The y coordinate of the point.
	 * \param value The elevation to store as a double.
	 */
	virtual void set(int x, int y, double value);

	/**
	 * \brief Get the elevation of a given point.
	 * \param x The x coordinate of the point.
	 * \param y The y coordinate of the point.
	 * \return Returns the elevation of the point as a double.
	 */
	virtual double get(int x, int y) const;

	/**
	 * \brief Return a reference to the elevation of a given point.
	 * \param x The x coordinate of the point.
	 * \param y The y coordinate of the point.
	 * \return Return a reference to the elevation of the point as a double.
	 */
	virtual double & at(int x, int y);

	/**
	 * \brief Return a constant reference to the elevation of a given point.
	 * \param x The x coordinate of the point.
	 * \param y The y coordinate of the point.
	 * \return Return a reference to the elevation of the point as a double.
	 */
	virtual const double & at(int x, int y) const;

protected:
	Array2D<double> *m_deleg; /**< Array to store the elevations */
};

#endif /* PLANEHEIGHTMAP_HH */
