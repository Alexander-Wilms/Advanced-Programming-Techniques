/*
 * CPoiDatabase.cpp
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include <iostream>
#include "CPOI.h"
#include "CPoiDatabase.h"

/**
 * Constructor creates a new database
 */
CPoiDatabase::CPoiDatabase() {
	m_noPoi = 0;
}

/**
 * Adds a POI to the database
 *
 * @param type			The POI's type
 * @param name			The POI's name
 * @param description	The POI's description
 * @param latitude		The POI's latitude
 * @param longitude		The POI's longitude
 */
void CPoiDatabase::addPoi(t_poi type, std::string name, std::string description,
		double latitude, double longitude) {
	if(m_noPoi < 10) {
		m_POI[m_noPoi] = CPOI(type, name, description, latitude, longitude);
		m_noPoi++;
	}
}

/**
 * Searches the PoiDatabase for a POI by its name and returns a pointer to it
 *
 * @param name 	The name of the POI to be searched
 *
 * @return A pointer to the POI with the given name
 */
CPOI* CPoiDatabase::getPointerToPoi(std::string name) {
	CPOI* returnValue = NULL;

	for(int i = 0; i < m_noPoi; i++) {
		if(m_POI[i].getName() == name) {
			returnValue = &m_POI[i];
		}
	}

	if(returnValue == NULL) {
		std::cout << "ERROR in CPoiDatabase::getPointerToPoi(): Could not find POI by name" << name << std::endl;
	}

	return returnValue;
}
