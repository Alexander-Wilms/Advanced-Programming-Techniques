/*
 * CJsonPersistence.cpp
 *
 *  Created on: 26.12.2017
 *      Author: awilms
 */

#include "CJsonPersistence.h"

CJsonPersistence::CJsonPersistence() {
	// TODO Auto-generated constructor stub

}

CJsonPersistence::~CJsonPersistence() {
	// TODO Auto-generated destructor stub
}

void CJsonPersistence::setMediaName(std::string name) {
	mediaName = name;
}

bool CJsonPersistence::writeData(const CDatabase<std::string, CWaypoint>& waypointDb,
		const CDatabase<std::string, CPOI>& poiDb) {
	std::ofstream file;

	// first write all POIs into a file
	file.open(mediaName + ".txt");
	if(file.is_open()) {
		file << "{";
		printDB(file, waypointDb);
		const CDatabase<std::string, CWaypoint>* p_PoiDatabase = dynamic_cast<const CDatabase<std::string, CWaypoint>*>(&poiDb);
		printDB(file, *p_PoiDatabase);
		file << "}";
		file.close();
		return true;
	} else {
		std::cout << "ERROR in CJsonStorage::writeData(): Couldn't open file " << mediaName << ".txt" << std::endl;
		return false;
	}

	return false;
}



bool CJsonPersistence::printDB(std::ofstream& file, const CDatabase<std::string, CWaypoint>& p_db) {
	// CDatabase needs to be polymorphic -> requires a virtual destructor

	if(dynamic_cast<const CDatabase<std::string, CPOI>*>(&p_db) != nullptr) {
		// it's a database of POIs
		file << "\"pois\": [";
	} else {
		file << "\"waypoints\": [";
	}

	const std::map<std::string, CWaypoint> DbMap = p_db.getDB();

	for(std::map<std::string, CWaypoint>::const_iterator it = DbMap.begin(); it != DbMap.end(); it++) {
		printWaypoint(file, &(it->second));
	}

	file << "]";

	return true;
}

bool CJsonPersistence::printWaypoint(std::ofstream& file, const CWaypoint* wp) {
	file << "{";

	file << "\t";

	printKeyValue("name", wp->getName(), file);
	printKeyValue("latitude", wp->getLatitude(), file);
	printKeyValue("longitude", wp->getLongitude(), file);


	const CPOI* p_poi = dynamic_cast<const CPOI*>(wp);

	if(p_poi != nullptr) {
		printKeyValue("type", p_poi->getTypeAsString(), file);
		printKeyValue("description", p_poi->getDescription(), file);
	}

	file << "}";

	return true;
}

/**
 * when we're passing 'file' by value instead of by reference, the compilation error occurs:
 *
 * error: use of deleted function ‘std::basic_ofstream<_CharT, _Traits>::basic_ofstream(
 * const std::basic_ofstream<_CharT, _Traits>&) [with _CharT = char; _Traits = std::char_traits<char>]’
 */
bool CJsonPersistence::printKeyValue(std::string key, std::string value, std::ofstream& file) {
	file << "\"" << key << "\": \"" << value << "\"";
	return true;
}

bool CJsonPersistence::printKeyValue(std::string key, double value, std::ofstream& file) {
	return printKeyValue(key, std::to_string(value), file);
}

bool CJsonPersistence::readData() {
	return false;
}
