#include <heightmapexporter.hh>
#include <pixmapexporter.hh>
#include <noise/noise.h>
#include <planeheightmap.hh>
#include <planenoisegenerator.hh>
#include <simplexnoise.hh>

int main()
{
	const int width = 512;
	const int height = 256;

	PlaneHeightMap *map = new PlaneHeightMap(width, height);
	PlaneNoiseGenerator *myGenerator = new PlaneNoiseGenerator();
	noise::module::Module *myModule = new SimplexNoise();

	myGenerator->set_map(map);
	myGenerator->set_module(myModule);
	myGenerator->set_bounds(0.0, 0.0, 4.0, 4.0);
	myGenerator->generate_area(0, 0, 255, 255);

	myGenerator->set_bounds(4.0, 0.0, 8.0, 4.0);
	myGenerator->generate_area(256, 0, 511, 255);

	HeightMapExporter *myExporter = new PixmapExporter();
	myExporter->write("simplexnoise.pgm", *map);

	delete myModule;
	delete myExporter;
	delete myGenerator;
	delete map;

	return 0;
}
