#ifndef PLANESQUAREHEIGHTMAP_HH
#define PLANESQUAREHEIGHTMAP_HH

#include "utils/data3D.hh"
#include "heightmapimpl.hh"

/**
 * \class PlaneSquareHeightMap
 * \brief This class implements a square planar HeightMap.
 */
class PlaneSquareHeightMap : public HeightMapImpl
{
public :
	/**
	 * \brief Constructs a PlaneSquareHeightMap.
	 * \param width The number of sides in width.
	 * \param height The number of sides in height.
	 * \param squareSize (facultative : default = 9) The number of pixels of a square. Have to be odd. If it isn't, the lower will be used.
	 */
	PlaneSquareHeightMap(int width, int height, int squareSize = 9);

	/**
	 * \brief Destructs a PlaneSquareHeightMap.
	 */
	virtual ~PlaneSquareHeightMap();

	/**
	 * \brief Get an array containing all the vertex.
	 * \return Returns all the vertex as an Array2D of double.
	 */
	virtual Array2D< double > get_vertex();

	/**
	 * \brief Get an array containing all the sides (a side is the numbers of its 4 vertex : the first vertex is the number 1).
	 * \return Returns all the sides as an vector.
	 */
	virtual std::vector< std::vector< int > > get_sides();

	/**
	 * \brief Get the size of a square in pixels.
	 * \return Returns the size of a square.
	 */
	int get_squareSize() const;

protected :

	/**
	 * \brief Computes the corresponding side from a given heightmap's point
	 * \param x The x heightmap's coordinate of the point
	 * \param y The y heightmap's coordinate of the point
	 * \return Return the corresponding side as a Side
	 */
	virtual Side<Data2D<int> > *_computes_side(int x, int y);

	/**
	 * \brief Computes the center of a square face
	 * \param s The face
	 * \retur Return the coordinates of the center of the square defined by its diagonal
	 */
	virtual Data2D<int> *_computes_center(Side<Data2D<int> > *s) const;

	/**
	 * \brief Computes the average of a vector's values (doubles).
	 * \param data to averaging.
	 * \return Return the average as double.
	 */
	virtual double _average(std::vector< double > *data);

	/**
	 * \brief Computes the height of a vertex.
	 * \param i The width index of the vertex.
	 * \param j The height index of the vertex.
	 * \return Return the height as double.
	 */
	virtual double _compute_a_vertex(int i, int j);

	int m_squareSize; /**< size of a square >*/
};

#endif /* PLANEHEIGHTMAP_HH */

