#ifndef HEIGHTMAP_HH
#define HEIGHTMAP_HH

/**
 * \class HeightMap
 * \brief HeightMap is a pure virtual class to store the elevation of each
 *        point on a terrain. It defines the common ways to access and set the
          elevations on a terrain.
 */
class HeightMap
{
public:
	/**
	 * \brief Get the width of the HeightMap
	 * \return Returns the width of the HeightMap.
	 */
	virtual int get_width() const = 0;

	/**
	 * \brief Get the height of the HeightMap
	 * \return Returns the height of the HeightMap.
	 */
	virtual int get_height() const = 0;

	/**
	 * \brief Set the elevation of a given point.
	 * \param x The x coordinate of the point.
	 * \param y The y coordinate of the point.
	 * \param value The elevation to store as a double.
	 */
	virtual void set(int x, int y, double value) = 0;

	/**
	 * \brief Get the elevation of a given point.
	 * \param x The x coordinate of the point.
	 * \param y The y coordinate of the point.
	 * \return Returns the elevation of the point as a double.
	 */
	virtual double get(int x, int y) const = 0;

	/**
	 * \brief Return a reference to the elevation of a given point.
	 * \param x The x coordinate of the point.
	 * \param y The y coordinate of the point.
	 * \return Return a reference to the elevation of the point as a double.
	 */
	virtual double & at(int x, int y) = 0;

	/**
	 * \brief Return a constant reference to the elevation of a given point.
	 * \param x The x coordinate of the point.
	 * \param y The y coordinate of the point.
	 * \return Return a reference to the elevation of the point as a double.
	 */
	virtual const double & at(int x, int y) const = 0;
};

#endif /* HEIGHTMAP_HH */
