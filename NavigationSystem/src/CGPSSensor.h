/*
 * CGPSSensor.h
 *
 *  Created on: 19.10.2017
 *      Author: awilms
 */

#ifndef CGPSSENSOR_H_
#define CGPSSENSOR_H_

#include "CWaypoint.h"

class CGPSSensor {
public:
	CGPSSensor();
	CWaypoint getCurrentPosition();
};

#endif /* CGPSSENSOR_H_ */
