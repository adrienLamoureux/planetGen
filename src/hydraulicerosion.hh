#ifndef HYDRAULICEROSION_HH
#define HYDRAULICEROSION_HH

#include "erosiongenerator.hh"
#include "utils/array2d.hh"

/**
 * \class HydraulicErosion
 * \brief HydraulicErosion implements erosion generator
 */
class HydraulicErosion : public ErosionGenerator
{
public:
	/**
	 * \brief Default Constructor
	 */
	HydraulicErosion();

	/**
	 * \brief Default Destructor
	 */
	virtual ~HydraulicErosion();

	/**
	 * \brief Generate elevations of the heightmap.
	 */
	virtual void generate();

	/**
	 * \brief Generate elevations for a given area of a  heightmap. An
	 *        area is represented by its lower and upper x coordinates and
	 *        its lower and upper y coordinates.
	 * \param x1 The lower x coordinate of the area.
	 * \param y1 The lower y coordinate of the area.
	 * \param x2 The upper x coordinate of the area.
	 * \param y2 The upper y coordinate of the area.
	 */
	void generate_area(int x1, int y1, int x2, int y2);

        /**
	 * \brief Setter for the rain amount.
	 * \param value Input value
	 */
	void set_rain_amount(double value);

        /**
	 * \brief Setter for the solubility.
	 * \param value Input value
	 */
	void set_solubility(double value);

        /**
	 * \brief Setter for the evaporation.
	 * \param value Input value
	 */
	void set_evaporation(double value);

	/**
	 * \brief Setter for the capacity.
	 * \param value Input value
	 */
	void set_capacity(double value);

private:
	/**
	 * \brief Simulation of Rain Processing.
	 */
	void rain_pass(int x1, int y1, int x2, int y2);

	/**
	 * \brief Simulation of Erosion Processing.
	 */
	void erosion_pass(int x1, int y1, int x2, int y2);

        /**
	 * \brief Change the pixel value of the heightMap depending on the current
	          height and the water map.
	 */
	void movement_pass(int x1, int y1, int x2, int y2);

        /**
	 * \brief Simulation of Evaporation and Deposition Processing.
	 */
	void evaporation_pass(int x1, int y1, int x2, int y2);

	/**
	 * \brief Compute local variation because of hydraulic erosion on a pixel.
	 * \param x The x coordinate of the current pixel
	 * \param y The y coordinate of the current pixel
	 */
	void local_variation(int x, int y, int x1, int y1);

	Array2D<double> *m_water_map; /**< map for water level >*/
	double m_rain_amount; /**< amount of rain on a point >*/
	double m_solubility; /**< erosion of a sediment >*/
	double m_evaporation; /**< evaporation of water >*/
	double m_capacity; /**< holding water of a sediment >*/
};

#endif /* HYDRAULICEROSION_HH */
