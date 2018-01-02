/*
 * CPoiDatabase.cpp
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CPoiDatabase.h"
#include "CPOI.h"

#include <iostream>

CPoiDatabase::CPoiDatabase() {
	m_noPoi = 0;
}

void CPoiDatabase::addPoi(t_poi type, std::string name, std::string description,
		double latitude, double longitude) {
	if(m_noPoi < 10) {
		m_POI[m_noPoi] = CPOI(type, name, description, latitude, longitude);
		m_noPoi++;
	} else {
		std::cout << "ERROR in CPoiDatabase::addPoi(): Tried to add more than 10 POIs" << std::endl;
	}
}

CPOI* CPoiDatabase::getPointerToPoi(std::string name) {
	CPOI* returnValue = nullptr;

	for(int i = 0; i < m_noPoi; i++) {
		if(m_POI[i].getName() == name) {
			returnValue = &m_POI[i];
		}
	}

	if(returnValue == nullptr) {
		std::cout << "ERROR in CPoiDatabase::getPointerToPoi(): Could not find POI " << name << std::endl;
	}

	return returnValue;
}
