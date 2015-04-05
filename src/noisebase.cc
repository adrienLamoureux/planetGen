#include "noisebase.hh"

NoiseBase::NoiseBase(int GetSourceModuleCount) : Module(GetSourceModuleCount)
{
	m_A = AFACTOR;
	m_C = CFACTOR;
	m_M = MFACTOR;
	m_seed = 0;
	m_secondSeed = 0;
	m_seedCopy = m_seed;
    
	/* Default initialization of permutation table */
	for(int i = 0; i < NBPOSSIBILITY*2 ; i++)
		m_permutationTable[i] = i & (NBPOSSIBILITY-1);
}

NoiseBase::~NoiseBase()
{
}

void NoiseBase::set_seed(unsigned int seed)
{
	m_seed = seed;
	m_seedCopy = m_seed;
}

unsigned int NoiseBase::getValue_linearRandomGenerator()
{
	m_secondSeed = m_A*m_seedCopy + m_C%m_M;
	m_seedCopy = m_secondSeed;
	return m_secondSeed;
}

void NoiseBase::randomize_permutationTable()
{
	int perm_value;
	unsigned int ncase;

	/* clean and add all of the possible values */
	for(unsigned int i = 0 ; i < NBPOSSIBILITY; ++i)
		m_permutationTable[i] = i;

	/* do it 20 times, it's a good comprise to gain random */
	for(unsigned int j = 0 ; j < NBPERMUTATIONITER; ++j)
		/* for each case of the permutation table, do a permutation with another case */
		for (unsigned int i = 0; i < NBPOSSIBILITY ; ++i) {
			/* selected case depending on the seed & the other constant parameters */
			ncase = this->getValue_linearRandomGenerator() & (NBPOSSIBILITY-1);
			perm_value = m_permutationTable[i];
			m_permutationTable[i] = m_permutationTable[ncase];
			m_permutationTable[ncase] = perm_value;
		}
	/* necessary step for permutation table */
	for(unsigned int i = NBPOSSIBILITY ; i < NBPOSSIBILITY*2; ++i)
		m_permutationTable[i] = m_permutationTable[i & (NBPOSSIBILITY-1)];
}
