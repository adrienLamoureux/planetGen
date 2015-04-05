/*
 * Implementations of terragenexporter.hh
 */

#include <iostream>
#include <fstream>

#include "terragenexporter.hh"

static const int max_gray_value = 255;

TerragenExporter::TerragenExporter()
{
	m_min_value = 0.0;
	m_max_value = 0.0;
}

TerragenExporter::~TerragenExporter()
{
}

void TerragenExporter::get_min_max_values(const HeightMap &map)
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

int TerragenExporter::get_mapped_value(double v) const
{
	return (v - m_min_value) * max_gray_value / (m_max_value - m_min_value);
}

void TerragenExporter::write(const std::string &filename, const HeightMap &map)
{
	std::ofstream output;

	output.open(filename.c_str(), std::ios::out | std::ios::binary);

	int width = map.get_width();
	int height = map.get_height();
	int size = width < height ? width - 1 : height - 1;

	union short_to_2_bytes {
		short integer;
		char bytes[2];
	};

	union int_to_4_bytes {
		int integer;
		char bytes[4];
	};

	short_to_2_bytes two_bytes_size;
	short_to_2_bytes two_bytes_width;
	short_to_2_bytes two_bytes_height;
	short_to_2_bytes two_bytes_heightscale;

	two_bytes_size.integer = (short) size;
	two_bytes_width.integer = (short) width;
	two_bytes_height.integer = (short) height;
	two_bytes_heightscale.integer = (short) ((double) max_gray_value / (double) 30);
	/* Write the Terragen header. */
	output.write("TERRAGEN", 8);
	output.write("TERRAIN ", 8);
	output.write("SIZE", 4);
	output.write(two_bytes_size.bytes, 2);
	output.write("\0\0", 2);
	output.write("XPTS", 4);
	output.write(two_bytes_width.bytes, 2);
	output.write("\0\0", 2);
	output.write("YPTS", 4);
	output.write(two_bytes_height.bytes, 2);
	output.write("\0\0", 2);
	output.write("ALTW", 4);
	output.write(two_bytes_heightscale.bytes, 2);
	output.write("\0\0", 2);


	/* Get the minimum and maximum value of the current heightmap in order
	   to map each value to the range needed by the pgm format. */
	get_min_max_values(map);

	/* Write each elevation form the heightmap to the .ter file. */
	for (int y = 0; y < map.get_height(); y++) {
		for (int x = 0; x < map.get_width(); x++) {
			short_to_2_bytes elevation;
			elevation.integer = (short) get_mapped_value(map.get(x, y));
			output.write(elevation.bytes, 2);
		}
	}

	output.close();
}
