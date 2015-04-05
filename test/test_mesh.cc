#include <heightmapexporter.hh>
#include <pixmapexporter.hh>
#include <noise/noise.h>
#include <planesquarenoisegenerator.hh>
#include <planesquareheightmap.hh>
#include <blender3dio.hh>
#include <utils/array2d.hh>


int main()
{
	const int width = 512;
	const int height = 256;
	srand(time(NULL));
	
	PlaneSquareHeightMap *map1 = new PlaneSquareHeightMap(width, height, 9);
	
	noise::module::Perlin myModule;
	
	PlaneSquareNoiseGenerator *myGenerator = new PlaneSquareNoiseGenerator();
	myGenerator->set_map(map1);
	myGenerator->set_module(&myModule);
	myGenerator->generate();
	
	if(map1->get_squareSize() != 9) // constructor
		return -1;
	
	if(map1->get_width() != width) // get_width()
		return -1;
	
	if(map1->get_height() != height) // get_width()
		return -1;
	
	double value;
	Array2D<double> *test_hm = new Array2D<double>(map1->get_width(), map1->get_height());
	
	for(int j = 0; j < map1->get_height(); ++j)
		for(int i = 0; i < map1->get_width(); ++i) {
			value = (double)((rand() % (101)) / 100);
			test_hm->set(i, j, value);
			map1->set(i, j, value);
		}
	
	for(int j = 0; j < map1->get_height(); ++j)
		for(int i = 0; i < map1->get_width(); ++i) {
			if(map1->get(i, j) != test_hm->get(i, j)) // set() + get()
				return -1;
		}
	
	PlaneSquareHeightMap *map2 = new PlaneSquareHeightMap(width, height, 12);

	myGenerator->set_map(map2);
	myGenerator->set_module(&myModule);
	myGenerator->set_bounds(0.0, 0.0, 4.0, 4.0);
	myGenerator->generate_area(0, 0, 255, 255);
	
	myGenerator->set_bounds(4.0, 0.0, 8.0, 4.0);
	myGenerator->generate_area(256, 0, 511, 255);
	
	if(map2->get_squareSize() != 11) // constructor
		return -1;
	
	Array2D<double> vertex = map2->get_vertex(); // get_vertex()
	double total = 0;
	int cpt = 0;
	
	for(int j = 0; j < (int)vertex.get_height(); ++j) {
		for(int i = 0; i < (int)vertex.get_width();++i) {
			if(i > 0 && j < map2->get_height()) {
				total += map2->get(i - 1, j);
				++cpt;
			}
			if(i > 0 && j > 0) {
				total += map2->get(i - 1, j - 1);
				++cpt;
			}
			if(j > 0 && i < map2->get_width()) {
				total += map2->get(i, j - 1);
				++cpt;
			}
			if(i < map2->get_width() && j < map2->get_height()) {
				total += map2->get(i, j);
				++cpt;
			}
			
			if(vertex.get(i, j) - (double)(total / cpt) > 0.00001)
				return -1;
			
			total = 0;
			cpt = 0;
			
		}
	}
	
	if((int)vertex.get_width() != map2->get_width() + 1) // vertex width
		return -1;
	if((int)vertex.get_height() != map2->get_height() + 1) // vertex height
		return -1;
		
		
	PlaneSquareHeightMap *map3 = new PlaneSquareHeightMap(4, 5);
		
	for(int j = 0; j < map3->get_height(); ++j)
		for(int i = 0; i < map3->get_width(); ++i)
			map3->set(i, j, 1);
	
	Array2D< double > v2 = map2->get_vertex();
	std::vector< std::vector< int > > s2 = map2->get_sides();
	Blender3Dio::write(&v2, &s2, "test_obj_2");
		

	PixmapExporter *myExporter = new PixmapExporter();
	myExporter->write("test_hm_3.pgm", *map1);
	myExporter->write("test_hm_4.pgm", *map2);
		
	delete myExporter;
	delete myGenerator;
	delete map1;
	delete map2;
	delete test_hm;
		
		
	return 0;
}
