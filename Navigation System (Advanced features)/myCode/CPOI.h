/*
 * CPOI.h
 *
 *  Created on: 19.10.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CPOI_H_
#define CPOI_H_

#include <string>
#include "CWaypoint.h"

/**
 * Use an enum to make it easier to differentiate between the
 * POI types
 */
typedef enum {RESTAURANT, TOURISTIC, GASSTATION, UNIVERSITY, SIGHTSEEING} t_poi;

/**
 * CPOI represents a Point Of Interest and inherits from CWaypoint
 */
class CPOI : public CWaypoint {
public:
	/**
	 * Prints the properties of the POI
	 */
	void print();

	/**
	 * Creates a new POI with the given properties
	 *
	 * @param type			The POI's type
	 * @param name			The POI's name
	 * @param description	The POI's description
	 * @param latitude		The POI's latitude
	 * @param longitude		The POI's longitude
	 */
	explicit CPOI(t_poi type = RESTAURANT, std::string name = "defaultname", std::string description = "defaultdescription",
			double latitude = 37, double longitude = 42);

	/**
	 * Returns a members of the POI by reference
	 *
	 * @param name			variable where to store the POI's name
	 * @param latitude		variable where to store the POI's latitude
	 * @param longitude		variable where to store the POI's longitude
	 * @param type			variable where to store the POI's type
	 * @param description	variable where to store the POI's description
	 */
	void getAllDataByReference(std::string& name, double& latitude, double& longitude, t_poi& type, std::string& description);

	/**
	 * returns the POI's type as a string
	 */
	std::string getTypeAsString() const;

	/**
	 * returns the POI's description
	 */
	std::string getDescription() const;
private:
	/**
	 * Describes the type of POI of this instance
	 */
	t_poi m_type;

	/**
	 * A description of the POI
	 */
	std::string m_description;
};

#endif /* CPOI_H_ */
