/*
 * CJsonPersistence.cpp
 *
 *  Created on: 26.12.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CJsonPersistence.h"

CJsonPersistence::CJsonPersistence() :
		m_currentIndentation(0) {
	// TODO Auto-generated constructor stub

}

CJsonPersistence::~CJsonPersistence() {
	// TODO Auto-generated destructor stub
}

void CJsonPersistence::setMediaName(std::string name) {
	mediaName = name;
}

bool CJsonPersistence::writeData(const CWpDatabase& waypointDb,
		const CPoiDatabase& poiDb) {
	std::ofstream file;
	m_currentIndentation = 0;

	// first write all POIs into a file
	file.open(mediaName + ".json");
	if (file.is_open()) {
		file << "{" << std::endl;
		m_currentIndentation++;
		printDB(file, waypointDb);
		printDB(file, poiDb);
		file << "}" << std::endl;
		file.close();
		return true;
	} else {
		std::cout << "ERROR in CJsonStorage::writeData(): Couldn't open file "
				<< mediaName << ".json" << std::endl;
		return false;
	}

	return false;
}

void CJsonPersistence::indent(std::ofstream& file) {
	for (unsigned int i = 0; i < m_currentIndentation - 1; i++) {
		file << "\t";
	}
}

bool CJsonPersistence::printEntry(std::ofstream& file, const CWaypoint* wp) {
	m_currentIndentation++;

	indent(file);
	file << "{" << std::endl;

	printKeyValue("name", wp->getName(), file);
	file << "," << std::endl;
	printKeyValue("latitude", wp->getLatitude(), file);
	file << "," << std::endl;
	printKeyValue("longitude", wp->getLongitude(), file);

	// check if this waypoint is also a POI
	const CPOI* p_poi = dynamic_cast<const CPOI*>(wp);

	if (p_poi != nullptr) {
		file << "," << std::endl;
		printKeyValue("type", p_poi->getTypeAsString(), file);
		file << "," << std::endl;
		printKeyValue("description", p_poi->getDescription(), file);
	}

	file << std::endl;

	indent(file);
	file << "}";

	m_currentIndentation--;

	return true;
}

bool CJsonPersistence::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,
		CPersistentStorage::MergeMode mode) {
	return false;
}
