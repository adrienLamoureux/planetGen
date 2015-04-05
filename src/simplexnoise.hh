#ifndef SIMPLEXNOISE_HH
#define SIMPLEXNOISE_HH

#include <noise/noise.h>
#include <iostream>
#include <vector>
#include "utils/data3D.hh"
#include "noisebase.hh"

#define GRADIENTDIMENTION 3
#define GRADIENTSIZE 12

#define SKEWCOEFF 1/3.f
#define UNSKEWCOEFF 1/6.f
#define CONTRIBUTIONFACTOR 0.5f
#define THIRDCORNEROFFSET 2.0f
#define LASTCORNEROFFSET 1.0f
#define LASTCORNEROFFSETF 3.0f
#define THREEDFACTOR 32.0f

/**
 * \class SimplexNoise
 * \brief Class inherited from NoiseBase. It has to execute SimplexNoise3D algorithm. This algorithms has been inspired from http://staffwww.itn.liu.se/~stegu/simplexnoise/simplexnoise.pdf
 */
class SimplexNoise : public NoiseBase
{
public:
	/**
	 * \brief Default Constructor
	 */
	SimplexNoise();
	/**	
	 * Constructor which call the default one and set a randomization
	 * \param seed The seed for the random generator
	 */
	SimplexNoise(unsigned int seed);
	/**
	 * \brief Default Destructor
	 */
	virtual ~SimplexNoise();

	/**
	 * \brief Returns the number of source modules required by this noise module
	 * \return The number of source modules
	 */
	 virtual int GetSourceModuleCount() const;
	/**
	 * \brief Faster than using (int)Math.floor(x).
	 * \param x The value to use.
	 * \return The output value.
	 */
	int fastfloor(double x) const;
	/**
	 * \brief Generates an output value given the coordinates of the specified input value.
	 * \param x The x coordinate of the input value.
	 * \param y The y coordinate of the input value.
	 * \param z The z coordinate of the input value.
	 * \return The output value.
	 */
	 virtual double GetValue(double x, double y, double z) const;

protected:
	/**
	 * \brief Called to initialise data of the two Constructors
	 */
	void initializeConstructor();
	/**
	 * \brief Generates a set of data for simplexNoise
	 * \param x The x coordinate of the input value.
	 * \param y The y coordinate of the input value.
	 * \param z The z coordinate of the input value.
	 * \param skewedData Input data multiplied by the skewCoeff
	 * \param unSkewedData Unskewed data of the cell origin back to (x,y,z) space
	 * \param unSkewedToDataOrigin The (x,y,z) distances from the cell origin
	 */
	void initializeCubeData(double x, double y, double z, Data3D<int> *skewedData, Data3D<double> *unSkewedData, Data3D<double> *unSkewedToDataOrigin) const;
        /**
	 * \brief Generates offset depending on the initialized values
	 * \param unSkewedToDataOrigin The (x,y,z) distances from the cell origin
	 * \param offset_s Offsets for the second corner and third corner of simplex space
	 * \param offset_d Offsets of all corners in (x,y,z) data
	 */
	void buildOffset(Data3D<double> *unSkewedToDataOrigin, std::vector< Data3D<int> > *offset_s, std::vector< Data3D<double> > *offset_d) const;
        /**
	 * \brief Select random values from a permutation table
	 * \param skewedData Input data multiplied by the skewCoeff
	 * \param perm Values which cames from the simplex permutation table
	 * \param offset_s Offsets for the second corner and third corner of simplex space
	 */
	void selectPermutationValue(Data3D<int> *skewedData, std::vector<int> *perm, std::vector< Data3D<int> > *offset_s) const;
        /**
	 * \brief Calculate contribution depending on the offset vector
	 * \param contr Contribution of each corner
	 * \param offset_d Offsets of all corners in (x,y,z) data
	 */
	void calculateContribution(std::vector<double> *contr, std::vector< Data3D<double> > *offset_d) const;
        /**
	 * \brief Compute the height of the input data
	 * \param contr Contribution of each corner
	 * \param perm Values which cames from the simplex permutation table
	 * \param offset_d Offsets of all corners in (x,y,z) data
	 * \return The sum of the four data obtained by gradient and contribution
	 */
	double finalValue(std::vector<double> *contr, std::vector<int> *perm, std::vector< Data3D<double> > *offset_d) const;

private:	
	double m_grad3[GRADIENTSIZE][GRADIENTDIMENTION]; /**< Gradient to use */
};
#endif /* SIMPLEXNOISE_HH */
