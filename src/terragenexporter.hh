#ifndef TERRAGENEXPORTER_HH
#define TERRAGENEXPORTER_HH

#include <iostream>
#include "heightmapexporter.hh"


/**
 * \class TerragenExporter
 * \brief TerragenExporter implements a HeightMapExporter for the terragen
 *        format.
 */
class TerragenExporter : public HeightMapExporter
{
public:
	/**
	 * \brief Construct a TerragenExporter
	 */
	TerragenExporter();

	/**
	 * \brief Destruct a TerragenExporter
	 */
	virtual ~TerragenExporter();

	/**
	 * \brief Export a heightmap to a file.
	 * \param filename The name of the file in wich the heightmap will be
	 *        exported.
	 * \param map The heightmap to export.
	 */
	virtual void write(const std::string &filename, const HeightMap &map);

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

#endif /* TERRAGENEXPORTER_HH */
