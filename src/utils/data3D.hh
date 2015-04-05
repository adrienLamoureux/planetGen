#ifndef DATA3D_HH
#define DATA3D_HH

#include <iostream>

template <class T>
class Data3D
{
public:
	Data3D();
	~Data3D();

	void affiche() const;

	T x;
	T y;
	T z;
};

#include "data3D.ii"

#endif /* DATA3D_HH */
