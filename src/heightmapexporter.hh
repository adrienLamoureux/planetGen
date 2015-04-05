#ifndef HEIGHTMAPCONVERTER_HH
#define HEIGHTMAPCONVERTER_HH

#include <iostream>
#include "heightmap.hh"

/**
 * \class HeightMapConverter
 * \brief HeightMapConverter is a pure virtual class to export a heightmap. It
 *        defines the common ways to export a heightmap.
 */
class HeightMapExporter
{
public:
	/**
	 * \brief Export a heightmap to a file.
	 * \param filename The name of the file in wich the heightmap will be
	 *        exported.
	 * \param map The heightmap to export.
	 */
	virtual void write(const std::string &filename, const HeightMap &map) = 0;
};

#endif /* HEIGHTMAPCONVERTER_HH */
