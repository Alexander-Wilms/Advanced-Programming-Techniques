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
typedef enum {RESTAURANT, TOURISTIC, GASSTATION, UNIVERSITY} t_poi;

/**
 * CPOI represents a Point Of Interest and inherits from CWaypoint
 */
class CPOI : public CWaypoint {
public:
	void print();
	explicit CPOI(t_poi type = RESTAURANT, std::string name = "defaultname", std::string description = "defaultdescription",
			double latitude = 37, double longitude = 42);
	void getAllDataByReference(std::string& name, double& latitude, double& longitude, t_poi& type, std::string& description);
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
