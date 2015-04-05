#ifndef PIXMAPEXPORTER_HH
#define PIXMAPEXPORTER_HH

#include <iostream>
#include "heightmapexporter.hh"

/**
 * \class PixmapExporter
 * \brief PixmapExporter implements a HeightMapExporter for the pixmap format.
 */
class PixmapExporter : public HeightMapExporter
{
public:
	/**
	 * \brief Construct a PixmapExporter
	 */
	PixmapExporter();

	/**
	 * \brief Destruct a PixmapExporter
	 */
	virtual ~PixmapExporter();

	/**
	 * \brief Export a heightmap to a file.
	 * \param filename The name of the file in wich the heightmap will be
	 *        exported.
	 * \param map The heightmap to export.
	 */
	virtual void write(const std::string &filename, const HeightMap &map);

	static const std::string magic_number; /**< Magic number needed for
						  building .pgm file. */

	static const int max_gray_value; /**< Maximum gray value used in the
					    .pgm file. */

private:
	/**
	 * \brief Find the minimum and maximum values from a given heightmap.
	 * \param map The heightmap.
	 */
	void get_min_max_values(const HeightMap& map);

	/**
	 * \brief Get the value mapped to the range we need to store an
	 *        elevation in pixmap format.
	 * \param v The value to be mapped.
	 */
	int get_mapped_value(double v) const;

	double m_min_value; /**< The minimum value of the current heightmap. */
	double m_max_value; /**< The maximum value of the current heightmap. */
};

#endif /* PIXMAPEXPORTER_HH */
