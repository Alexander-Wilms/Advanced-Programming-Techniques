/*
 * CCSVStorage.cpp
 *
 *  Created on: 03.12.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CCsvPersistence.h"

#include <algorithm>
#include <iostream>

CCsvPersistence::CCsvPersistence() :
	m_delimiter(";")
{
}

CCsvPersistence::~CCsvPersistence() {
}

void CCsvPersistence::setMediaName(std::string name) {
	/**
	 * Note: mediaName is not the file name!
	 * The file names are:
	 * - <mediaName>-wp.csv
	 * - <mediaName>-poi.csv
	 */
	mediaName = name;
}

bool CCsvPersistence::writeData(const CWpDatabase& waypointDb,
		const CPoiDatabase& poiDb) {
	std::ofstream file;
	const std::map<std::string, CWaypoint> pWaypointMap = waypointDb.getDB();
	const std::map<std::string, CPOI> pPOIMap = poiDb.getDB();

	// first write all POIs into a file
	file.open(mediaName + "-poi.csv");
	if(file.is_open()) {
		for (std::map<std::string,CPOI>::const_iterator it = pPOIMap.begin(); it != pPOIMap.end(); it++) {
			file << it->second.getTypeAsString() << ";" << it->second.getName() << ";" << it->second.getDescription() << ";" << it->second.getLatitude() << ";" << it->second.getLongitude() << std::endl;
		}
		file.close();
	} else {
		std::cout << "ERROR in CCSVStorage::writeData(): Couldn't open file " << mediaName << "-poi.csv" << std::endl;
		return false;
	}

	// then write all waypoints into a file
	file.open(mediaName + "-wp.csv");
	if(file.is_open()) {
		for (std::map<std::string,CWaypoint>::const_iterator it = pWaypointMap.begin(); it != pWaypointMap.end(); it++) {
			file << it->second.getName() << ";" << it->second.getLatitude() << ";" << it->second.getLongitude() << std::endl;
		}
		file.close();
	} else {
		std::cout << "ERROR in CCSVStorage::writeData(): Couldn't open file " << mediaName << "-wp.csv" << std::endl;
		return false;
	}

	return true;
}

bool CCsvPersistence::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,
		CPersistentStorage::MergeMode mode) {
	if(mode == REPLACE) {
		waypointDb.clearDb();
		poiDb.clearDb();
	}

	std::ifstream file;
	ParseStatus status;

	// first read all POIs from the file
	std::string line, remainingLine, type, name, description, tmp, superfluousField;
	t_poi POItype;
	double latitude, longitude;
	unsigned int lineNumber = 0;
	file.open(mediaName + "-poi.csv");
	if(file.is_open()) {
		while(!file.eof()){
			lineNumber++;

			// first read the entire line, since there's no easy way to peek
			std::getline(file,line,'\n');
			// empty line or EOF, nothing to do either way
			if(line == "\n" || file.eof()) { continue; }
			remainingLine = line;

			printError(status = checkNoOfFields(line, 5), lineNumber, line);
			if (status != OK) { continue; }

			printError(status = extractType(remainingLine, POItype), lineNumber, line);
			if (status != OK) { continue; }

			printError(status = extractName(remainingLine, name), lineNumber, line);
			if (status != OK) { continue; }

			printError(status = extractDescription(remainingLine, description), lineNumber, line);
			if (status != OK) { continue; }

			printError(status = extractLatitude(remainingLine, latitude), lineNumber, line);
			if (status != OK) { continue; }

			printError(status = extractLongitude(remainingLine, longitude), lineNumber, line);
			if (status != OK) { continue; }

			if(poiDb.getPointerToElement(name) == nullptr) {
				poiDb.addElement(CPOI(POItype, name, description, latitude, longitude));
				std::cout << "INFO in CCSVStorage::readData(): Added POI '" << name << "'" << std::endl;
			}
		}
		file.close();
	} else {
		std::cout << "ERROR in CCSVStorage::readData(): Couldn't open file " << mediaName << "-poi.csv" << std::endl;
		return false;
	}

	// then read all waypoints from the file
	lineNumber = 0;
	file.open(mediaName + "-wp.csv");
	if(file.is_open()) {
		while(!file.eof()){
			lineNumber++;

			// first read the entire line, since there's no easy way to peek
			std::getline(file,line,'\n');
			// empty line or EOF, nothing to do either way
			if(line == "\n" || file.eof()) { continue; }
			remainingLine = line;

			printError(status = checkNoOfFields(line, 3), lineNumber, line);
			if (status != OK) { continue; }

			printError(status = extractName(remainingLine, name), lineNumber, line);
			if (status != OK) { continue; }

			printError(status = extractLatitude(remainingLine, latitude), lineNumber, line);
			if (status != OK) { continue; }

			printError(status = extractLongitude(remainingLine, longitude), lineNumber, line);
			if (status != OK) { continue; }

			if(waypointDb.getPointerToElement(name) == nullptr) {
				waypointDb.addElement(CWaypoint(name, latitude, longitude));
				std::cout << "INFO in CCSVStorage::readData(): Added waypoint '" << name << "'" << std::endl;
			}
		}
		file.close();
	} else {
		std::cout << "ERROR in CCSVStorage::readData(): Couldn't open file " << mediaName << "-wp.csv" << std::endl;
		return false;
	}

	return true;
}

void CCsvPersistence::printError(ParseStatus status, unsigned int lineNumber,
		std::string lineContent) {

	if(status != OK) {
		std::cout << "ERROR: ";

		switch(status) {
		case ERR_TOO_FEW_FIELDS:
			std::cout << "too few fields";
			break;
		case ERR_TOO_MANY_FIELDS:
			std::cout << "too many fields";
			break;
		case ERR_TEXT_INSTEAD_OF_NUMBER:
			std::cout << "text where a number is expected";
			break;
		case ERR_COMMA_INSTEAD_OF_POINT:
			std::cout << "comma instead of point";
			break;
		case ERR_EMPTY_FIELD_TYPE:
			std::cout << "empty field 'type'";
			break;
		case ERR_EMPTY_FIELD_NAME:
			std::cout << "empty field 'name'";
			break;
		case ERR_EMPTY_FIELD_DESCRIPTION:
			std::cout << "empty field 'description'";
			break;
		case ERR_EMPTY_FIELD_LATITUDE:
			std::cout << "empty field 'latitude'";
			break;
		case ERR_EMPTY_FIELD_LONGITUDE:
			std::cout << "empty field 'longitude'";
			break;
		case ERR_COULDNT_PARSE_LONGITUDE:
			std::cout << "couldn't parse longitude";
			break;
		case ERR_COULDNT_PARSE_LATITUDE:
			std::cout << "couldn't parse latitude";
			break;
		case ERR_UNKNOWN_POI_TYPE:
			std::cout << "unknown POI type";
			break;
		case ERR_TOO_MANY_POINTS:
			std::cout << "too many points";
			break;
		case OK:
			;
		}

		std::cout << " in line " << lineNumber << ": " << lineContent << std::endl;
	}
}

std::string CCsvPersistence::getDigits(const std::string& source) {
	std::string returnValue;
	for(unsigned int i = 0; i < source.size(); i++) {
		if('0' <= (char) source.at(i) && (char) source.at(i) <= '9') {
			returnValue.append(source,i,1);
		}
	}
	return returnValue;
}

CCsvPersistence::ParseStatus CCsvPersistence::checkNoOfFields(const std::string& line,
		unsigned int expectedNo) const {
	unsigned int count = std::count(line.begin(), line.end(), ';');
	if(count < expectedNo-1) {
		return ERR_TOO_FEW_FIELDS;
	} else if (count > expectedNo-1){
		return ERR_TOO_MANY_FIELDS;
	}

	return OK;
}

CCsvPersistence::ParseStatus CCsvPersistence::extractLongitude(std::string& remainingLine, double& longitudeParsed) {
	std::string longitude = remainingLine.substr(0, remainingLine.find(m_delimiter));
	remainingLine = remainingLine.substr(remainingLine.find(m_delimiter)+1, remainingLine.size());
	if(longitude == "") {
		return ERR_EMPTY_FIELD_LONGITUDE;
	} else {
		if(longitude.find(',') == std::string::npos) {
			// http://www.cplusplus.com/forum/beginner/48769/
			if(longitude.find_first_not_of("0123456789.") == std::string::npos) {
				if(std::count(longitude.begin(), longitude.end(), '.') <= 1) {
					try {
						longitudeParsed = std::stod(longitude);
					} catch (const std::invalid_argument& ia) {
						return ERR_COULDNT_PARSE_LONGITUDE;
					}
				} else {
					return ERR_TOO_MANY_POINTS;
				}
			} else {
				return ERR_TEXT_INSTEAD_OF_NUMBER;
			}
		} else {
			return ERR_COMMA_INSTEAD_OF_POINT;
		}
	}

	return OK;
}

CCsvPersistence::ParseStatus CCsvPersistence::extractLatitude(std::string& remainingLine, double& latitudeParsed) {
	std::string longitude = remainingLine.substr(0, remainingLine.find(m_delimiter));
	remainingLine = remainingLine.substr(remainingLine.find(m_delimiter)+1, remainingLine.size());
	if(longitude == "") {
		return ERR_EMPTY_FIELD_LATITUDE;
	} else {
		if(longitude.find(',') == std::string::npos) {
			// http://www.cplusplus.com/forum/beginner/48769/
			if(longitude.find_first_not_of("0123456789.") == std::string::npos) {
				if(std::count(longitude.begin(), longitude.end(), '.') <= 1) {
					try {
						latitudeParsed = std::stod(longitude);
					} catch (const std::invalid_argument& ia) {
						return ERR_COULDNT_PARSE_LONGITUDE;
					}
				} else {
					return ERR_TOO_MANY_POINTS;
				}
			} else {
				return ERR_TEXT_INSTEAD_OF_NUMBER;
			}
		} else {
			return ERR_COMMA_INSTEAD_OF_POINT;
		}
	}

	return OK;
}

CCsvPersistence::ParseStatus CCsvPersistence::extractName(std::string& remainingLine, std::string& nameParsed) {
	std::string name = remainingLine.substr(0, remainingLine.find(m_delimiter));
	remainingLine = remainingLine.substr(remainingLine.find(m_delimiter)+1, remainingLine.size());
	if(name == "") {
		return ERR_EMPTY_FIELD_NAME;
	}
	nameParsed = name;

	return OK;
}

CCsvPersistence::ParseStatus CCsvPersistence::extractDescription(std::string& remainingLine,
		std::string& descriptionParsed) {
	std::string description = remainingLine.substr(0, remainingLine.find(m_delimiter));
	remainingLine = remainingLine.substr(remainingLine.find(m_delimiter)+1, remainingLine.size());
	if(description == "") {
		return ERR_EMPTY_FIELD_DESCRIPTION;
	}
	descriptionParsed = description;

	return OK;
}

CCsvPersistence::ParseStatus CCsvPersistence::extractType(std::string& remainingLine,
		t_poi& typeParsed) {
	// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	std::string type = remainingLine.substr(0, remainingLine.find(m_delimiter));
	remainingLine = remainingLine.substr(remainingLine.find(m_delimiter)+1, remainingLine.size());
	if(type == "") {
		return ERR_EMPTY_FIELD_TYPE;
	} else {
		if(type == "RESTAURANT") {
			typeParsed = RESTAURANT;
		} else if(type == "TOURISTIC") {
			typeParsed = TOURISTIC;
		} else if(type == "GASSTATION") {
			typeParsed = GASSTATION;
		} else if(type == "UNIVERSITY") {
			typeParsed = UNIVERSITY;
		} else if(type == "SIGHTSEEING") {
			typeParsed = SIGHTSEEING;
		} else {
			return ERR_UNKNOWN_POI_TYPE;
		}
	}

	return OK;
}
