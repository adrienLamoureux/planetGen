/*
 * Implementations of erosiongenerator.hh
 */

#include "erosiongenerator.hh"

const int default_nb_iterations = 4;

ErosionGenerator::ErosionGenerator()
{
	m_map = NULL;
	m_nb_iterations = default_nb_iterations;
}

ErosionGenerator::~ErosionGenerator()
{
}

void ErosionGenerator::set_map(HeightMap *map)
{
	m_map = map;
}

void ErosionGenerator::set_nb_iterations(int nb)
{
	m_nb_iterations = nb;
}
