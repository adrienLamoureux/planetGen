#ifndef SIDE_HH
#define SIDE_HH

#include <vector>
#include "utils/data2D.hh"

template <typename T>
class Side
{
public :
	/**
	 * \brief Constructs a Side
	 * \param n_vertex The number of vertex of the side
	 */
	Side(int n_vertex);

	/**
	 * \brief Constructs a Side
	 * \param n_vertex The number of vertex of the side
	 * \param vertex The vertex as a template
	 */
	Side(int n_vertex, std::vector< T > *vertex);

	/**
	 * \brief Destructs a Side
	 */
	~Side();

	/**
	 * \brief Get one vertex of the Side
	 *	\param The vertex index (have to be between 0 and m_n_vertex - 1 : first is top left then reading from left to right and from top to bottom)
	 * \return Returns the vertex of the Side as a template.
	 */
	T get_a_vertex(int i) const;

	/**
	 * \brief Get the vertex of the Side
	 * \return Returns the vertex of the Side as a template.
	 */
	std::vector<T> get_vertex() const;

	/**
	 * \brief Get the number of vertex of the Side
	 * \return Returns number of vertex as an integer.
	 */
	int get_n_vertex() const;

	/**
	 * \brief Set all the vertex of a Side
	 * \param vertex the vector containing all the vertex of a Side
	 */
	void set_vertex(std::vector<T> *vertex);

	/**
	 * \brief Set the vertex which the index is specified
	 * \param vertex The vertex to add
	 * \param i (facultative : default = 0) The vertex' index (have to be between 0 and m_n_vertex - 1 : first is top left then reading from left to right and from top to bottom)
	 */
	void set_a_vertex(T *vertex, int i = 0);


protected :
	int m_n_vertex;
	std::vector< T > *m_vertex;
};

#include "side.ii"

#endif /* SIDE_HH */
