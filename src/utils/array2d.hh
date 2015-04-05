#ifndef ARRAY2D_HH
#define ARRAY2D_HH

template <class T>
class Array2D
{
public:
	/**
	 * \brief Constructs an Array2D.
	 */
	Array2D(unsigned width, unsigned height);

	/**
	 * \brief Destructs the Array2D.
	 */
	~Array2D();

	/**
	 * \brief Get the width of the array.
	 * \return Returns the width of the array.
	 */
	unsigned get_width() const;

	/**
	 * \brief Get the height of the array.
	 * \return Returns the height of the array.
	 */
	unsigned get_height() const;

	/**
	 * \brief Set the element at the given position.
	 * \param x The x position of the element.
	 * \param y The y position of the element.
	 * \param value The value to store at the given position.
	 */
	void set(int x, int y, T value);

	/**
	 * \brief Get the element at the given position.
	 * \param x The x position of the element.
	 * \param y The y position of the element.
	 */
	T get(int x, int y) const;

	/**
	 * \brief Return a reference to the element at the given position.
	 * \param x The x position of the element.
	 * \param y The y position of the element.
	 * \return Return a reference to the element at the given position.
	 */
	T & at(int x, int y) const;

	/**
	 * \brief Display the array to standard output.
	 */
	void debug() const;

protected:
	unsigned m_width; /**< Width of the Array2D. */
	unsigned m_height; /**< Height of the Array2D */
	T *m_values; /**<  Array storing the elements of the Array2D */
};

#include "array2d.ii"

#endif /* ARRAY2D_HH */
