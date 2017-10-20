/*
 * CPoiDatabase.cpp
 *
 *  Created on: 20.10.2017
 *      Author: awilms
 */

#include "CPoiDatabase.h"
#include "CPOI.h"

CPoiDatabase::CPoiDatabase() {
	m_noPoi = 0;
}

void CPoiDatabase::addPoi(t_poi type, std::string name, std::string description,
		double latitude, double longitude) {
	if(m_noPoi < 10) {
		m_POI[m_noPoi] = CPOI(type, name, description, latitude, longitude);
		m_noPoi++;
	}
}

CPOI* CPoiDatabase::getPointerToPoi(std::string name) {
	for(int i = 0; i < m_noPoi; i++) {
		if(m_POI[i].getName() == name) {
			return &m_POI[i];
		}
	}
}