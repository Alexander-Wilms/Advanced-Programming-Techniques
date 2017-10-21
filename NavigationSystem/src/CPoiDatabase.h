/*
 * CPoiDatabase.h
 *
 *  Created on: 20.10.2017
 *      Author: awilms
 */

#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_

#include "CPOI.h"

class CPoiDatabase {
public:
	CPoiDatabase();
	void addPoi(t_poi type, std::string name, std::string description, double latitude, double longitude);
	CPOI* getPointerToPoi(std::string name);
private:
	CPOI* m_POI;
	int m_noPoi;
};

#endif /* CPOIDATABASE_H_ */
