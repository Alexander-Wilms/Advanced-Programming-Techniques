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

	// first write all POIs into a file
	file.open(mediaName + ".json");
	if (file.is_open()) {
		file << "{" << std::endl;
		m_currentIndentation++;
		printWpDB(file, waypointDb);
		printPoiDB(file, poiDb);
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

bool CJsonPersistence::printWpDB(std::ofstream& file, const CWpDatabase& wpdb) {
	m_currentIndentation++;

	// it's a database of waypoints
	indent(file);
	file << "\"waypoints\": [" << std::endl;

	const std::map<std::string, CWaypoint> DbMap = wpdb.getDB();

	int NoOfWaypoints = DbMap.size();

	for (std::map<std::string, CWaypoint>::const_iterator it = DbMap.begin();
			it != DbMap.end(); it++) {
		printWaypoint(file, &(it->second));
		NoOfWaypoints--;
		if (NoOfWaypoints != 0) {
			file << ",";
		}

		file << std::endl;
	}

	indent(file);
	file << "]," << std::endl;

	m_currentIndentation--;

	return true;
}

bool CJsonPersistence::printPoiDB(std::ofstream& file,
		const CPoiDatabase& poidb) {
	m_currentIndentation++;

	// it's a database of POIs
	indent(file);
	file << "\"pois\": [" << std::endl;
	const std::map<std::string, CPOI> DbMap = poidb.getDB();
	int NoOfPois = DbMap.size();

	for (std::map<std::string, CPOI>::const_iterator it = DbMap.begin();
			it != DbMap.end(); it++) {
		printWaypoint(file, &(it->second));
		NoOfPois--;
		if (NoOfPois != 0) {
			file << ",";
		}

		file << std::endl;
	}

	indent(file);
	file << "]" << std::endl;

	m_currentIndentation--;

	return true;
}

bool CJsonPersistence::printWaypoint(std::ofstream& file, const CWaypoint* wp) {
	m_currentIndentation++;

	indent(file);
	file << "{" << std::endl;

	printKeyValue("name", wp->getName(), file);
	file << "," << std::endl;
	printKeyValue("latitude", wp->getLatitude(), file);
	file << "," << std::endl;
	printKeyValue("longitude", wp->getLongitude(), file);

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

/**
 * when we're passing 'file' by value instead of by reference, the compilation error occurs:
 *
 * error: use of deleted function ‘std::basic_ofstream<_CharT, _Traits>::basic_ofstream(
 * const std::basic_ofstream<_CharT, _Traits>&) [with _CharT = char; _Traits = std::char_traits<char>]’
 */
bool CJsonPersistence::printKeyValue(std::string key, std::string value,
		std::ofstream& file) {
	indent(file);
	file << "\t\"" << key << "\": \"" << value << "\"";
	return true;
}

bool CJsonPersistence::printKeyValue(std::string key, double value,
		std::ofstream& file) {
	return printKeyValue(key, std::to_string(value), file);
}

bool CJsonPersistence::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,
		CPersistentStorage::MergeMode mode) {
	return false;
}
