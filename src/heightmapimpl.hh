#ifndef HEIGHTMAPIMPL_HH
#define HEIGHTMAPIMPL_HH

#include "utils/side.hh"
#include "utils/array2d.hh"
#include "heightmap.hh"


/**
 * \class HeightMapImpl
 * \brief HeightMapImpl is a class to store the elevation of each
 *        point on a terrain. It defines the common ways to access and set the
          elevations on a terrain.
 */
class HeightMapImpl : public HeightMap
{
public:
	/**
	 * \brief Destruct the HeightMapImpl
	 */	
	virtual ~HeightMapImpl();

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

	/**
	 * \brief Get the complete heightmap
	 * \return Returns the heightmap as an Array2D.
	 */
	virtual Array2D< double > get_hm();

	/**
	 * \brief Get an array containing all the vertex.
	 * \return Returns all the vertex as an Array2D of double.
	 */
	virtual Array2D< double > get_vertex() = 0;

	/**
	 * \brief Get an array containing all the sides (a side is the numbers of its 4 vertex : the first vertex is the number 1).
	 * \return Returns all the sides as an vector.
	 */
	virtual std::vector< std::vector< int > > get_sides() = 0;
protected :

	int m_width; /**< HeightMap width >*/
	int m_height; /**< HeightMap height >*/
	Array2D<double> *m_hm; /**< heightmap >*/
};

#endif /* HEIGHTMAPIMPL_HH */
