#include <erosiongenerator.hh>
#include <hydraulicerosion.hh>
#include <heightmapexporter.hh>
#include <pixmapexporter.hh>
#include <noise/noise.h>
#include <planeheightmap.hh>
#include <planenoisegenerator.hh>

int main()
{
	const int width = 512;
	const int height = 512;

	PlaneHeightMap *map = new PlaneHeightMap(width, height);
	PlaneNoiseGenerator *myGenerator = new PlaneNoiseGenerator();
	noise::module::Perlin myModule;

	myGenerator->set_map(map);
	myGenerator->set_module(&myModule);
	myGenerator->set_bounds(0.0, 0.0, 8.0, 8.0);
	myGenerator->generate();

	ErosionGenerator *myErosion = new HydraulicErosion();
	myErosion->set_map(map);
	myErosion->generate_area(128, 128, 384, 384);

	HeightMapExporter *myExporter = new PixmapExporter();
	myExporter->write("perlin_hydraulicerosion.pgm", *map);

	delete myExporter;
	delete myGenerator;
	delete myErosion;
	delete map;

	return 0;
}
