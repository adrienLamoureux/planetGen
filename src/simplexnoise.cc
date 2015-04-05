#include "simplexnoise.hh"

SimplexNoise::SimplexNoise() : NoiseBase(0)
{
	this->initializeConstructor();
}

SimplexNoise::SimplexNoise(unsigned int seed) : NoiseBase(0)
{
	this->initializeConstructor();
	set_seed(seed);
	randomize_permutationTable();
}

void SimplexNoise::initializeConstructor()
{
	float grad3Temp[][GRADIENTDIMENTION] = {
		{1.f,1.f,0.f},
		{-1.f,1.f,0.f},
		{1.f,-1.f,0.f},
		{-1.f,-1.f,0.f},

		{1.f,0.f,1.f},
		{-1.f,0.f,1.f},
		{1.f,0.f,-1.f},
		{-1.f,0.f,-1.f},

		{0.f,1.f,1.f},
		{0.f,-1.f,1.f},
		{0.f,1.f,-1.f},
		{0.f,-1.f,-1.f}
	};

	for(int i = 0 ; i < GRADIENTSIZE; ++i)
		for(int j = 0 ; j < GRADIENTDIMENTION; ++j)
			m_grad3[i][j] = grad3Temp[i][j];	
}

SimplexNoise::~SimplexNoise()
{
}

int SimplexNoise::GetSourceModuleCount() const
{
	return 0;
}

int SimplexNoise::fastfloor(double x) const
{
	return x>=0 ? (int)x : (int)x-1;
}

void SimplexNoise::initializeCubeData(double x, double y, double z, Data3D<int> *skewedData, Data3D<double> *unSkewedData, Data3D<double> *unSkewedToDataOrigin) const
{
	double sum = (x + y + z) * SKEWCOEFF;

	skewedData->x = this->fastfloor(sum+x);
	skewedData->y = this->fastfloor(y+sum);
	skewedData->z = this->fastfloor(z+sum);
	
	sum = (skewedData->x + skewedData->y + skewedData->z) * UNSKEWCOEFF;
    	unSkewedData->x = skewedData->x - sum;
    	unSkewedData->y = skewedData->y - sum;
    	unSkewedData->z = skewedData->z - sum;
	
	unSkewedToDataOrigin->x = x-unSkewedData->x;
	unSkewedToDataOrigin->y = y-unSkewedData->y;
	unSkewedToDataOrigin->z = z-unSkewedData->z;
}

void SimplexNoise::buildOffset(Data3D<double> *unSkewedToDataOrigin, std::vector< Data3D<int> > *offset_s, std::vector< Data3D<double> > *offset_d) const
{
	if(unSkewedToDataOrigin->x >= unSkewedToDataOrigin->y) {
		if(unSkewedToDataOrigin->y >= unSkewedToDataOrigin->z) {
			offset_s->at(0).x = 1;
		  	offset_s->at(0).y = 0;
  	          	offset_s->at(0).z = 0;
            	  	offset_s->at(1).x = 1;
            	  	offset_s->at(1).y = 1;
            	  	offset_s->at(1).z = 0;
		} else if(unSkewedToDataOrigin->x >= unSkewedToDataOrigin->z) {
            		offset_s->at(0).x = 1;
			offset_s->at(0).y = 0;
			offset_s->at(0).z = 0;
			offset_s->at(1).x = 1;
			offset_s->at(1).y = 0;
			offset_s->at(1).z = 1;
        	} else {
            		offset_s->at(0).x = 0;
            		offset_s->at(0).y = 0;
            		offset_s->at(0).z = 1;
            		offset_s->at(1).x = 1;
            		offset_s->at(1).y = 0;
            		offset_s->at(1).z = 1;
        	}
      	} else {
		if(unSkewedToDataOrigin->y < unSkewedToDataOrigin->z) {
            		offset_s->at(0).x = 0;
            		offset_s->at(0).y = 0;
            		offset_s->at(0).z = 1;
            		offset_s->at(1).x = 0;
            		offset_s->at(1).y = 1;
            		offset_s->at(1).z = 1;
        	} else if(unSkewedToDataOrigin->x < unSkewedToDataOrigin->z) {
           		offset_s->at(0).x = 0;
            		offset_s->at(0).y = 1;
            		offset_s->at(0).z = 0;
            		offset_s->at(1).x = 0;
            		offset_s->at(1).y = 1;
            		offset_s->at(1).z = 1;
        	} else {
            		offset_s->at(0).x = 0;
            		offset_s->at(0).y = 1;
            		offset_s->at(0).z = 0;
            		offset_s->at(1).x = 1;
            		offset_s->at(1).y = 1;
            		offset_s->at(1).z = 0;
        	}
	}

	offset_d->at(0) = *unSkewedToDataOrigin;

	offset_d->at(1).x = offset_d->at(0).x - offset_s->at(0).x + UNSKEWCOEFF;
	offset_d->at(1).y = offset_d->at(0).y - offset_s->at(0).y + UNSKEWCOEFF;
	offset_d->at(1).z = offset_d->at(0).z - offset_s->at(0).z + UNSKEWCOEFF;

	offset_d->at(2).x = offset_d->at(0).x - offset_s->at(1).x + THIRDCORNEROFFSET*UNSKEWCOEFF;
	offset_d->at(2).y = offset_d->at(0).y - offset_s->at(1).y + THIRDCORNEROFFSET*UNSKEWCOEFF;
	offset_d->at(2).z = offset_d->at(0).z - offset_s->at(1).z + THIRDCORNEROFFSET*UNSKEWCOEFF;

	offset_d->at(3).x = offset_d->at(0).x - LASTCORNEROFFSET + LASTCORNEROFFSETF*UNSKEWCOEFF;
	offset_d->at(3).y = offset_d->at(0).y - LASTCORNEROFFSET + LASTCORNEROFFSETF*UNSKEWCOEFF;
	offset_d->at(3).z = offset_d->at(0).z - LASTCORNEROFFSET + LASTCORNEROFFSETF*UNSKEWCOEFF;
}

void SimplexNoise::selectPermutationValue(Data3D<int> *skewedData, std::vector<int> *perm, std::vector< Data3D<int> > *offset_s) const
{
	int ii = skewedData->x & (NBPOSSIBILITY-1);
	int jj = skewedData->y & (NBPOSSIBILITY-1);
	int kk = skewedData->z & (NBPOSSIBILITY-1);
	
	perm->at(0) = m_permutationTable[ii + m_permutationTable[jj + m_permutationTable[kk ]]] % GRADIENTSIZE;
	perm->at(1) = m_permutationTable[ii + offset_s->at(0).x + m_permutationTable[jj + offset_s->at(0).y + m_permutationTable[kk + offset_s->at(0).z]]] % GRADIENTSIZE;
	perm->at(2) = m_permutationTable[ii + offset_s->at(1).x + m_permutationTable[jj + offset_s->at(1).y + m_permutationTable[kk + offset_s->at(1).z]]] % GRADIENTSIZE;
	perm->at(3) = m_permutationTable[ii + 1 + m_permutationTable[jj + 1 + m_permutationTable[kk + 1 ]]] % GRADIENTSIZE;	
}

void SimplexNoise::calculateContribution(std::vector<double> *contr, std::vector< Data3D<double> > *offset_d) const
{
	contr->at(0) = CONTRIBUTIONFACTOR - offset_d->at(0).x * offset_d->at(0).x - offset_d->at(0).y * offset_d->at(0).y - offset_d->at(0).z * offset_d->at(0).z;
	contr->at(1) = CONTRIBUTIONFACTOR - offset_d->at(1).x * offset_d->at(1).x - offset_d->at(1).y * offset_d->at(1).y - offset_d->at(1).z * offset_d->at(1).z;
	contr->at(2) = CONTRIBUTIONFACTOR - offset_d->at(2).x * offset_d->at(2).x - offset_d->at(2).y * offset_d->at(2).y - offset_d->at(2).z * offset_d->at(2).z;
	contr->at(3) = CONTRIBUTIONFACTOR - offset_d->at(3).x * offset_d->at(3).x - offset_d->at(3).y * offset_d->at(3).y - offset_d->at(3).z * offset_d->at(3).z;
}

double SimplexNoise::finalValue(std::vector<double> *contr, std::vector<int> *perm, std::vector< Data3D<double> > *offset_d) const
{
	double n1,n2,n3,n4;
	if(contr->at(0) < 0)
		n1 = 0;
	else
		n1 = contr->at(0)*contr->at(0)*contr->at(0)*contr->at(0)*(m_grad3[perm->at(0)][0] * offset_d->at(0).x + m_grad3[perm->at(0)][1] * offset_d->at(0).y + m_grad3[perm->at(0)][2] * offset_d->at(0).z);
	if(contr->at(1) < 0)
		n2 = 0;
	else
		n2 = contr->at(1)*contr->at(1)*contr->at(1)*contr->at(1)*(m_grad3[perm->at(1)][0] * offset_d->at(1).x + m_grad3[perm->at(1)][1] * offset_d->at(1).y + m_grad3[perm->at(1)][2] * offset_d->at(1).z);
	if(contr->at(2) < 0)
		n3 = 0;
	else
		n3 = contr->at(2)*contr->at(2)*contr->at(2)*contr->at(2)*(m_grad3[perm->at(2)][0] * offset_d->at(2).x + m_grad3[perm->at(2)][1] * offset_d->at(2).y + m_grad3[perm->at(2)][2] * offset_d->at(2).z);
	if(contr->at(3) < 0)
		n4 = 0;
	else
		n4 = contr->at(3)*contr->at(3)*contr->at(3)*contr->at(3)*(m_grad3[perm->at(3)][0] * offset_d->at(3).x + m_grad3[perm->at(3)][1] * offset_d->at(3).y + m_grad3[perm->at(3)][2] * offset_d->at(3).z);
	return (n1+n2+n3+n4)*THREEDFACTOR;
}

double SimplexNoise::GetValue(double x, double y, double z) const
{  
	std::vector<double> *contr = new std::vector<double>(4);
	std::vector<int> *perm = new std::vector<int>(4);	
	Data3D<int> *skewedData = new Data3D<int>();
	Data3D<double> *unSkewedData = new Data3D<double>();
	Data3D<double> *unSkewedToDataOrigin = new Data3D<double>();
	std::vector< Data3D<int> > *offset_s = new std::vector< Data3D<int> >(2);
	std::vector< Data3D<double> > *offset_d = new std::vector< Data3D<double> >(4);	
	initializeCubeData(x, y, z, skewedData, unSkewedData,unSkewedToDataOrigin);
	buildOffset(unSkewedToDataOrigin, offset_s, offset_d);
	selectPermutationValue(skewedData, perm, offset_s);
	calculateContribution(contr, offset_d);
	double value = finalValue(contr, perm, offset_d);
	delete contr;
	delete perm;
	delete skewedData;
	delete unSkewedData;
	delete unSkewedToDataOrigin;
	delete offset_s;
	delete offset_d;
	return value;
	//return 0.0;
}
