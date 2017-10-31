/*
 * CGPSSensor.h
 *
 *  Created on: 19.10.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CGPSSENSOR_H_
#define CGPSSENSOR_H_

#include "CWaypoint.h"

/**
 * This class represents a GPS sensor.
 * It can be used to request a coordinate (as a CWaypoint) via the CLI
 */
class CGPSSensor {
public:
	CGPSSensor();
	CWaypoint getCurrentPosition();
};

#endif /* CGPSSENSOR_H_ */
