/*
 * Implementations of planeSquareHeighmap.hh
 */

#include "planesquareheightmap.hh"


PlaneSquareHeightMap::PlaneSquareHeightMap(int width, int height, int squareSize)
{
	m_squareSize = (squareSize % 2 != 0) ? squareSize : squareSize - 1; // if squareSize is even, use the lower odd
	m_width = width;
	m_height = height;
	m_hm = new Array2D<double>(m_width, m_height);
}

PlaneSquareHeightMap::~PlaneSquareHeightMap()
{
	m_hm->~Array2D<double>();
}

Array2D< double > PlaneSquareHeightMap::PlaneSquareHeightMap::get_vertex()
{
	Array2D< double > *vertex = new Array2D< double >(m_width + 1, m_height + 1);
	
	for(int j = 0; j < (int)vertex->get_height(); ++j)
		for(int i = 0; i < (int)vertex->get_width(); ++i) {
			vertex->set(i, j, _compute_a_vertex(i, j));
		}
		
	return *vertex;
}

std::vector< std::vector< int > > PlaneSquareHeightMap::get_sides()
{
	std::vector< std::vector< int > > *sides = new std::vector< std::vector< int > >(0);

	int cpt_first = 1;

	for(int i = 0; i < (m_width + 1) * (m_height + 1); ++i) {
		std::vector< int > *a_side= new std::vector< int >(0);
		if(cpt_first % (m_width + 1) == 0) {
			++cpt_first;
			continue;
		}
		if(cpt_first > m_width + (m_height * (m_height - 1)))
		   break;

		a_side->push_back(cpt_first + 1);
		a_side->push_back(cpt_first);
		a_side->push_back(cpt_first + m_width + 1);
		a_side->push_back(cpt_first + m_width + 2);
		++cpt_first;

		sides->push_back(*a_side);
	}

	return *sides;
}

int PlaneSquareHeightMap::get_squareSize() const
{
	return m_squareSize;
}

Side<Data2D<int> > *PlaneSquareHeightMap::_computes_side(int x, int y)
{
	Data2D<int> *p1 = new Data2D<int>(x * m_squareSize, y * m_squareSize);
	Data2D<int> *p2 = new Data2D<int>(x * m_squareSize + m_squareSize, y * m_squareSize);
	Data2D<int> *p3 = new Data2D<int>(x * m_squareSize, y * m_squareSize + m_squareSize);
	Data2D<int> *p4 = new Data2D<int>(x * m_squareSize + m_squareSize, y * m_squareSize + m_squareSize);

	std::vector<Data2D<int> > *tmp = new std::vector<Data2D<int> >(0);
	tmp->push_back(*p1);
	tmp->push_back(*p2);
	tmp->push_back(*p3);
	tmp->push_back(*p4);
	Side<Data2D<int> > *s = new Side<Data2D<int> >(4, tmp);

	return s;
}

Data2D<int> *PlaneSquareHeightMap::_computes_center(Side<Data2D<int> >* s) const
{
	Data2D<int> init = s->get_a_vertex(0); // top left vertex
	Data2D<int> end = s->get_a_vertex(3); // bottom right vertex

	Data2D<int> *tmp = new Data2D<int>((init.x + end.x) / 2, (init.y + end.y) / 2);

	return tmp;
}

double PlaneSquareHeightMap::_average(std::vector< double > *data)
{
	double ave = 0;

	for(unsigned i = 0; i < data->size(); ++i)
		ave += data->at(i);

	return ave / data->size();
}

double PlaneSquareHeightMap::_compute_a_vertex(int i, int j)
{
	std::vector< double > *neigh = new std::vector< double > (0);
	if(i > 0 && j > 0)
		neigh->push_back(m_hm->get(i - 1, j - 1));
	if(i > 0 && j < (int)m_hm->get_height())
		neigh->push_back(m_hm->get(i - 1, j));
	if(j > 0 && i < (int)m_hm->get_width())
		neigh->push_back(m_hm->get(i, j - 1));
	if(i < (int)m_hm->get_width() && j < (int)m_hm->get_height())
		neigh->push_back(m_hm->get(i, j));
	
	return _average(neigh);
}
