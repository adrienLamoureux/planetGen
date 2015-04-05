/*
 * Implementations of bitmapexporter.hh
 */

#include "bitmapexporter.hh"
#include "utils/bitmap_image.hpp"


BitmapExporter::BitmapExporter()
{
	m_min_value = 0.0;
	m_max_value = 0.0;
}

BitmapExporter::~BitmapExporter()
{
}

void BitmapExporter::write(const std::string &filename, const HeightMap &map)
{
	int height = map.get_height();
	int width  = map.get_width();
	bitmap_image image(width, height);

	get_min_max_values(map);

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			double value = (map.at(x,y) - m_min_value) * 255 /
				(m_max_value - m_min_value);

			image.set_pixel(x, y, value, value, value);
		}
	}

	image.save_image(filename);
}

void BitmapExporter::get_min_max_values(const HeightMap &map)
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

void read(const std::string &filename, HeightMap &map)
{
	bitmap_image image(filename);

	if (!image)
	{
		printf("Error - Failed to open: input.bmp\n");
		return ;
	}

	unsigned char red;
	unsigned char green;
	unsigned char blue;

	unsigned int height = image.height();
	unsigned int width  = image.width();

	for (std::size_t y = 0; y < height ;++y)
	{
		for (std::size_t x = 0; x < width; ++x)
		{
			image.get_pixel(x,y,red,green,blue);
			map.set(x,y,red);
		}
	}
	return ;
}
