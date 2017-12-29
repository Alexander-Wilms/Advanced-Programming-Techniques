/*
 * CWpDatabase.h
 *
 *  Created on: 26.12.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef MYCODE_CWPDATABASE_H_
#define MYCODE_CWPDATABASE_H_

#include "CDatabase.h"
#include "CWaypoint.h"

class CWpDatabase: public CDatabase<std::string, CWaypoint> {
public:
	CWpDatabase();
	virtual ~CWpDatabase();
};

#endif /* MYCODE_CWPDATABASE_H_ */
