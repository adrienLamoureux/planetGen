#include "heightmapimpl.hh"


HeightMapImpl::~HeightMapImpl()
{

}

int HeightMapImpl::get_width() const
{
	return m_width;
}

int HeightMapImpl::get_height() const
{
	return m_height;
}

double & HeightMapImpl::at(int x, int y)
{
	return m_hm->at(x, y);
}

const double & HeightMapImpl::at(int x, int y) const
{
	return m_hm->at(x, y);
}

double HeightMapImpl::get(int x, int y) const
{
	return m_hm->get(x, y);
}

void HeightMapImpl::set(int x, int y, double value)
{
	m_hm->set(x, y, value);
}

Array2D< double > HeightMapImpl::get_hm()
{
	Array2D<double> tmp = *m_hm;
	return tmp;
}
