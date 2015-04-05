#ifndef BLENDER3DIO_HH
#define BLENDER3DIO_HH

#include <string>
#include <vector>
#include <fstream>
#include <utils/array2d.hh>


class Blender3Dio
{
public :
	/**
	 * \brief Write a vertex array as a file readable by blender3D.
	 * \param vertex The vertex array as a double Array2D.
	 * \param out The sides as a vector.
	 * \param out The output file.
	 */
	static void write(Array2D<double> *vertex, std::vector< std::vector< int > > *sides, std::string out);
};


#endif // BLENDER3DIO_HH
