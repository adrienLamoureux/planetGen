#include <heightmapexporter.hh>
#include <pixmapexporter.hh>
#include <planeheightmap.hh>
#include <planediamondsquare.hh>

int main()
{
	const int width = 513;
	const int height = 513;

	PlaneHeightMap *map = new PlaneHeightMap(width, height);

	PlaneDiamondSquare *myGenerator = new PlaneDiamondSquare();
	myGenerator->set_map(map);
	myGenerator->generate_area(128, 128, 385, 385);

	HeightMapExporter *myExporter = new PixmapExporter();
	myExporter->write("diamondsquare.pgm", *map);

	delete myExporter;
	delete myGenerator;
	delete map;

	return 0;
}
