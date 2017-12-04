/*
 * CCSVStorage.cpp
 *
 *  Created on: 03.12.2017
 *      Author: awilms
 */

#include "CCSVStorage.h"
#include <iostream>

CCSVStorage::CCSVStorage() {
}

CCSVStorage::~CCSVStorage() {
}

void CCSVStorage::setMediaName(std::string name) {
	/**
	 * Note: mediaName is not the file name!
	 * The file names are:
	 * - <mediaName>-wp.txt
	 * - <mediaName>-poi.txt
	 */
	mediaName = name;
}

bool CCSVStorage::writeData(const CWpDatabase& waypointDb,
		const CPoiDatabase& poiDb) {
	std::ofstream file;
	const std::map<std::string, CWaypoint> pWaypointMap = waypointDb.getDB();
	const std::map<std::string, CPOI> pPOIMap = poiDb.getDB();

	// first write all POIs into a file
	file.open(mediaName + "-poi.txt");
	if(file.is_open()) {
		for (std::map<std::string,CPOI>::const_iterator it = pPOIMap.begin(); it != pPOIMap.end(); it++) {
			file << it->second.getTypeAsString() << ";" << it->second.getName() << ";" << it->second.getDescription() << ";" << it->second.getLatitude() << ";" << it->second.getLongitude() << std::endl;
		}
		file.close();
	} else {
		std::cout << "ERROR in CCSVStorage::writeData(): Couldn't open file " << mediaName << "-poi.txt" << std::endl;
	}

	// then write all waypoints into a file
	file.open(mediaName + "-wp.txt");
	if(file.is_open()) {
		for (std::map<std::string,CWaypoint>::const_iterator it = pWaypointMap.begin(); it != pWaypointMap.end(); it++) {
			file << it->second.getName() << ";" << it->second.getLatitude() << ";" << it->second.getLongitude() << std::endl;
		}
		file.close();
	} else {
		std::cout << "ERROR in CCSVStorage::writeData(): Couldn't open file " << mediaName << "-wp.txt" << std::endl;
	}

	return true;
}

bool CCSVStorage::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,
		CPersistentStorage::MergeMode enumMergeMode) {
	if(enumMergeMode == REPLACE) {
		waypointDb.clearDb();
		poiDb.clearDb();
	}

	std::ifstream file;
	std::string delimiter = ";";

	// first read all POIs from the file
	std::string line, remainingLine, type, name, description, latitude, longitude, tmp, superfluousField;
	t_poi typeParsed;
	double latitudeParsed, longitudeParsed;
	unsigned int lineNumber = 0;
	file.open(mediaName + "-poi.txt");
	if(file.is_open()) {
		while(!file.eof()){
			lineNumber++;
			line = "";
			type = "";
			name = "";
			description = "";
			latitude = "";
			longitude = "";

			// first read the entire line, since there's no easy way to peek
			std::getline(file,line,'\n');
			if(line == "\n" || file.eof()) {
				// empty line or EOF, nothing to do either way
				continue;
			}
			line = trim(line, "\n");
			remainingLine = line;

			// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
			type = remainingLine.substr(0, remainingLine.find(delimiter));
			remainingLine = remainingLine.substr(remainingLine.find(delimiter)+1, remainingLine.size());
			if(type == "") {
				printError(ERR_EMPTY_FIELD_TYPE, lineNumber, line);
				continue;
			} else {
				std::cout << "type: " << type << std::endl;
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
					printError(ERR_UNKNOWN_POI_TYPE, lineNumber, line);
				}
			}

			// if there are no more semicolons in the remaining line, there's too
			// few entries
			if(remainingLine.find(';') == std::string::npos) {
				printError(ERR_TOO_FEW_FIELDS, lineNumber, line);
				continue;
			}

			name = remainingLine.substr(0, remainingLine.find(delimiter));
			remainingLine = remainingLine.substr(remainingLine.find(delimiter)+1, remainingLine.size());
			std::cout << "name: " << name << std::endl;
			if(name == "") {
				printError(ERR_EMPTY_FIELD_NAME, lineNumber, line);
				continue;
			}

			// if there are no more semicolons in the remaining line, there's too
			// few entries
			if(remainingLine.find(';') == std::string::npos) {
				printError(ERR_TOO_FEW_FIELDS, lineNumber, line);
				continue;
			}

			description = remainingLine.substr(0, remainingLine.find(delimiter));
			remainingLine = remainingLine.substr(remainingLine.find(delimiter)+1, remainingLine.size());
			std::cout << "description: " << description << std::endl;
			if(description == "") {
				printError(ERR_EMPTY_FIELD_DESCRIPTION, lineNumber, line);
				continue;
			}

			// if there are no more semicolons in the remaining line, there's too
			// few entries
			if(remainingLine.find(';') == std::string::npos) {
				printError(ERR_TOO_FEW_FIELDS, lineNumber, line);
				continue;
			}

			latitude = remainingLine.substr(0, remainingLine.find(delimiter));
			remainingLine = remainingLine.substr(remainingLine.find(delimiter)+1, remainingLine.size());
			if(latitude == "") {
				printError(ERR_EMPTY_FIELD_LATITUDE, lineNumber, line);
				continue;
			} else {
				// http://www.cplusplus.com/reference/string/string/find/
				if(latitude.find(',') == std::string::npos) {
					try {
						std::cout << "latitude: " << latitude << std::endl;
						latitudeParsed = std::stod(latitude);
					} catch (const std::invalid_argument& ia) {
						printError(ERR_COULDNT_PARSE_LATITUDE, lineNumber, line);
						continue;
					}
				} else {
					printError(ERR_COMMA_INSTEAD_OF_POINT, lineNumber, line);
					continue;
				}
			}

			longitude = remainingLine.substr(0, remainingLine.find(delimiter));
			remainingLine = remainingLine.substr(remainingLine.find(delimiter)+1, remainingLine.size());
			if(longitude == "") {
				printError(ERR_EMPTY_FIELD_LONGITUDE, lineNumber, line);
				continue;
			} else {
				if(longitude.find(',') == std::string::npos) {
					try {
						std::cout << "longitude: " << longitude << std::endl;
						longitudeParsed = std::stod(longitude);
					} catch (const std::invalid_argument& ia) {
						printError(ERR_COULDNT_PARSE_LONGITUDE, lineNumber, line);
						continue;
					}
				} else {
					printError(ERR_COMMA_INSTEAD_OF_POINT, lineNumber, line);
					continue;
				}
			}

			if(remainingLine != longitude) {
				//std::cout << "<" << remainingLine << ">" << std::endl;
				printError(ERR_TOO_MANY_FIELDS, lineNumber, line);
				continue;
			}

			if(poiDb.getPointerToPoi(name) == nullptr) {
				poiDb.addPoi(CPOI(typeParsed, name, description, latitudeParsed, longitudeParsed));
			}
		}
		file.close();
	} else {
		std::cout << "ERROR in CCSVStorage::writeData(): Couldn't open file " << mediaName << "-poi.txt" << std::endl;
	}


	lineNumber = 0;
	// then read all waypoints from the file
	file.open(mediaName + "-wp.txt");



	file.close();

	return true;
}

void CCSVStorage::printError(ParseError problem, unsigned int lineNumber,
		std::string lineContent) {
	std::cout << "ERROR: ";

	switch(problem) {
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
	}

	std::cout << " in line " << lineNumber << ": " << lineContent << std::endl;
}

std::string CCSVStorage::trim(const std::string& source, const std::string& t) {
	std::string returnValue;
	if(source.size() > 1 && source.substr(source.size()-1, 1) == t) {
		returnValue.append(source, 0, source.size()-1);
		return returnValue;
	}
	return source;
}

std::string CCSVStorage::getDigits(const std::string& source) {
	std::string returnValue;

	for(unsigned int i = 0; i < source.size(); i++) {
		if('0' <= (char) source.at(i) && (char) source.at(i) <= '9') {
			returnValue.append(source,i,1);
		}
	}
	return returnValue;
}
