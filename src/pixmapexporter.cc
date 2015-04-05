/*
 * Implementations of pixmapexporter.hh
 */

#include <iostream>
#include <fstream>

#include "pixmapexporter.hh"

const std::string PixmapExporter::magic_number = "P2";
const int PixmapExporter::max_gray_value = 255;


PixmapExporter::PixmapExporter()
{
	m_min_value = 0;
	m_max_value = 0;
}

PixmapExporter::~PixmapExporter()
{
}

void PixmapExporter::get_min_max_values(const HeightMap &map)
{
	m_min_value = m_max_value = map.get(0, 0);

	for (int x = 0; x < map.get_width(); x++) {
		for (int z = 0; z < map.get_height(); z++) {
			double current_value = map.get(x, z);

			if (current_value < m_min_value)
				m_min_value = current_value;

			if (current_value > m_max_value)
				m_max_value = current_value;
		}
	}
}

int PixmapExporter::get_mapped_value(double v) const
{
	return (v - m_min_value) * max_gray_value / (m_max_value - m_min_value);
}

void PixmapExporter::write(const std::string &filename, const HeightMap &map)
{
	std::ofstream output;

	output.open(filename.c_str());

	/* Write the pgm header. */
	output << magic_number << " ";
	output << map.get_width() << " ";
	output << map.get_height() << " ";
	output << max_gray_value << " ";

	/* Get the minimum and maximum value of the current heightmap in order
	   to map each value to the range needed by the pgm format. */
	get_min_max_values(map);

	/* Write each elevation form the heightmap to the pgm file. */
	for (int z = 0; z < map.get_height(); z++) {
		for (int x = 0; x < map.get_width(); x++) {
			output << get_mapped_value(map.get(x, z)) << " ";
		}
	}

	output.close();
}
