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
	std::cout << "CPoiDatabase::CPoiDatabase()" << std::endl;
}

void CPoiDatabase::addPoi(CPOI const& poi) {

	m_POI.insert(std::pair<std::string,CPOI>(poi.getName(), poi));

}

CPOI* CPoiDatabase::getPointerToPoi(std::string name) {
	std::cout << "CPoiDatabase::getPointerToPoi()" << std::endl;
	CPOI* returnValue = nullptr;

	std::map<std::string,CPOI>::iterator it = m_POI.find(name);

	if(it == m_POI.end()) {
		std::cout << "ERROR in CPoiDatabase::getPointerToPoi(): Could not find POI " << name << std::endl;
		returnValue = nullptr;
	} else {
		returnValue = &(it->second);
	}

	std::cout << "CPoiDatabase::getPointerToPoi() returns " << returnValue << std::endl;
	return returnValue;
}
