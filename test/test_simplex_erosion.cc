#include <heightmapexporter.hh>
#include <pixmapexporter.hh>
#include <noise/noise.h>
#include <planeheightmap.hh>
#include <planenoisegenerator.hh>
#include <noisebase.hh>
#include <simplexnoise.hh>
#include <thermalerosion.hh>
#include <hydraulicerosion.hh>

#include <fstream>

#include "simplextest.hh"
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>

CPPUNIT_TEST_SUITE_REGISTRATION( SimplexTest );
	 
int main(int argc, char* argv[])
{
	// informs test-listener about testresults
	CPPUNIT_NS::TestResult testresult;
	 
	// register listener for collecting the test-results
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener (&collectedresults);
	 
	// register listener for per-test progress output
	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener (&progress);
	 
	// insert test-suite at test-runner by registry
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
	testrunner.run(testresult);
	 
	// output results in compiler-format
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
	compileroutputter.write ();

	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
/*
  void check_heightMap(const std::string &filename, PlaneHeightMap *map)
  {
  std::ofstream fichier(filename.c_str(), std::ios::out | std::ios::trunc);
  if(fichier)  // si l'ouverture a réussi
  {
  // instructions	
  for(int i = 0; i < map->get_width(); ++i)
  {
  for(int j = 0; j < map->get_height(); ++j)
  {
  fichier << map->get(i, j);
  fichier << "\n";
  }
  }
  fichier.close();  // on referme le fichier
  }
  else  // sinon
  std::cerr << "Erreur à l'ouverture !" << std::endl;
  }

  int main()
  {
  const int width = 512;
  const int height = 256;

  PlaneHeightMap *map1 = new PlaneHeightMap(width, height);

  noise::module::Perlin myModulePerlin;
  //noise::module::Module *myModule = new NoiseBase(0);
  //NoiseBase *n = new NoiseBase(0);	

  noise::module::Module *myModule = new SimplexNoise();

  PlaneNoiseGenerator *myGenerator = new PlaneNoiseGenerator();

  myGenerator->set_map(map1);
  myGenerator->set_module(myModule);
  myGenerator->generate();
  check_heightMap("test_check_simplex", map1);
  HeightMapConverter *myConverter = new PixmapConverter();
  myConverter->write("simplex.pgm", *map1);

  ErosionGenerator *thermal = new ThermalErosion();
  thermal->set_map(map1);
  thermal->generate();
  check_heightMap("test_check_simplex_erosionThermal", map1);
  myConverter = new PixmapConverter();
  myConverter->write("simplex_erosionThermal.pgm", *map1);	
  ErosionGenerator *hydraulic = new HydraulicErosion();
  hydraulic->set_map(map1);
  hydraulic->generate();
  check_heightMap("test_check_simplex_erosionThermalHydraulic", map1);
  myConverter = new PixmapConverter();
  myConverter->write("simplex_erosionThermalHydraulic.pgm", *map1);

  return 0;
  }
*/

