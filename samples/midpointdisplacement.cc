#include <heightmapexporter.hh>
#include <pixmapexporter.hh>
#include <planeheightmap.hh>
#include <planemidpointdisplacement.hh>

int main()
{
	const int width = 513;
	const int height = 513;

	PlaneHeightMap *map = new PlaneHeightMap(width, height);

	PlaneMidpointDisplacement *myGenerator = new PlaneMidpointDisplacement();
	myGenerator->set_map(map);
	myGenerator->generate_area(128, 128, 385, 385);

	HeightMapExporter *myExporter = new PixmapExporter();
	myExporter->write("midpointdisplacement.pgm", *map);

	delete myExporter;
	delete myGenerator;
	delete map;

	return 0;
}
