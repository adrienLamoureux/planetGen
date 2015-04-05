#include <blender3dio.hh>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <clocale>


void Blender3Dio::write(Array2D<double>* vertex, std::vector< std::vector< int > > *sides, std::string out)
{
	std::string out_name = out + ".obj";
	std::ofstream fl(out_name.c_str());

	if(!fl)
	{
		std::cerr << "Output file error. Interrupt." << std::endl;
		exit(-1);
	}

	fl << "# Blender v2.69 (sub 0) OBJ File: ''" << std::endl << "# www.blender.org" << std::endl << "mtllib " << out << ".mtl" << std::endl << "o " << out << std::endl;

	// vertex	
	for(unsigned j = 0; j < vertex->get_height(); ++j)
		for(unsigned i = 0; i < vertex->get_width(); ++i)
			fl << "v " << i << " " << j << " " << vertex->get(i, j) << std::endl;
	////

	fl << "usemtl None" << std::endl << "s off" << std::endl;

	// sides
	for(unsigned i = 0; i < sides->size(); ++i)
		fl << "f " << sides->at(i).at(0) << " " << sides->at(i).at(1) << " " << sides->at(i).at(2) << " " << sides->at(i).at(3) << std::endl;
	////
	
	fl.close();
}
