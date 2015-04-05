#ifndef NOISEBASE_HH
#define NOISEBASE_HH

#include <noise/noise.h>
#include <noise/module/modulebase.h>
#include <noise/module/module.h>

#define NBPOSSIBILITY 256
#define NBPERMUTATIONITER 20
#define AFACTOR 16807
#define CFACTOR 0
#define MFACTOR 2147483647

/**
 * \class NoiseBase
 * \brief Class inherited from noise::module::Module provided by LibNoise. It have to give some common method for additional noises.  
 */
class NoiseBase : public noise::module::Module 
{
public:
	/**
	 * \brief Default constructor which call the Module constructor of LibNoise
	 * \param GetSourceModuleCount The number of source Module used by the child class
	 */
	NoiseBase(int GetSourceModuleCount);
	/**
	 * \brief Default Destructor
	 */
	virtual ~NoiseBase();

	/**
	 * \brief Returns the number of source modules required by this noise module
	 * \return The number of source modules
	 */
	virtual int GetSourceModuleCount() const = 0;
	/**
	 * \brief Generates an output value given the coordinates of the specified input value.
	 * \param x The x coordinate of the input value.
	 * \param y The y coordinate of the input value.
	 * \param z The z coordinate of the input value.
	 * \return The output value.
	 */
	virtual double GetValue(double x, double y, double z) const = 0;
	/**
	 * \brief Give a seed value for noise generation algorithm
	 * \param seed The seed value
	 */
	virtual void set_seed(unsigned int seed);
	/**
	 * \brief Doing permutations on an array
	 */
	virtual void randomize_permutationTable();
	/**
	 * \brief The simplest pseudo-random generators are linear congruential generators where : 
	 n(x+1) = n(x) * A + C modulo M with suitably chosen values of A, C and M.
	 * \return The output value randomly generated
	 */
	virtual unsigned int getValue_linearRandomGenerator();

protected:
	unsigned int m_A, m_C, m_M; /**< The factor for linear randomization */
        unsigned int m_seedCopy, m_secondSeed; /**< Result of random with the seed */
	unsigned int m_seed; /**< The seed for random */
	unsigned int m_permutationTable[NBPOSSIBILITY*2]; /**< The permutation Table to random */
};


#endif /* NOISEBASE_HH */
