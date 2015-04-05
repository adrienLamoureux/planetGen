#include <heightmapexporter.hh>
#include <terragenexporter.hh>
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

	HeightMapExporter *myExporter = new TerragenExporter();
	myExporter->write("perlin.ter", *map);

	delete myExporter;
	delete myGenerator;
	delete map;

	return 0;
}
