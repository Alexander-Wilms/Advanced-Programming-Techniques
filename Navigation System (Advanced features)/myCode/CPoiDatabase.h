/*
 * CPoiDatabase.h
 *
 *  Created on: 26.12.2017
 *      Author: awilms
 */

#ifndef MYCODE_CPOIDATABASE_H_
#define MYCODE_CPOIDATABASE_H_

#include "CDatabase.h"
#include "CPOI.h"

class CPoiDatabase: public CDatabase<std::string, CPOI> {
public:
	CPoiDatabase();
	virtual ~CPoiDatabase();
};

#endif /* MYCODE_CPOIDATABASE_H_ */
