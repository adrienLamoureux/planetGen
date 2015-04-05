#ifndef BITMAPEXPORTER_HH
#define BITMAPEXPORTER_HH

#include "heightmapexporter.hh"

class BitmapExporter : public HeightMapExporter
{
public:
	/**
	 * \brief Construct a BitmapExporter
	 */
	BitmapExporter();

	/**
	 * \brief Destruct a BitmapExporter
	 */
	virtual ~BitmapExporter();

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
	void read(const std::string &filename, HeightMap &map);
	double m_min_value; /**< The minimum value of the current heightmap. */
	double m_max_value; /**< The maximum value of the current heightmap. */
};

#endif /* BITMAPEXPORTER_HH */
