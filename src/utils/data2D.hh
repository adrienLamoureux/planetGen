#ifndef DATA2D_HH
#define DATA2D_HH

#include <iostream>

template <typename T>
class Data2D
{
public:
	Data2D();
	Data2D(T c_x, T c_y);
	~Data2D();

	void affiche() const;

	T x;
	T y;
};

#include "data2D.ii"

#endif /* DATA2D_HH */

