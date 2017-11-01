/*
 * CPoiDatabase.h
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_

#include "CPOI.h"

/**
 * A class to store POIs
 */
class CPoiDatabase {
public:
	CPoiDatabase();
	void addPoi(t_poi type, std::string name, std::string description, double latitude, double longitude);
	CPOI* getPointerToPoi(std::string name);
private:
	/**
	 * A fixed-size array to store all known POIs
	 */
	CPOI m_POI[10];

	/**
	 * The number of POIs stored in this instance
	 */
	int m_noPoi;
};

#endif /* CPOIDATABASE_H_ */
