/*
 * CJsonPersistence.cpp
 *
 *  Created on: 26.12.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CJsonPersistence.h"
#include "CJsonScanner.h"
#include <algorithm>

//#define DEBUG

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
		file << "," << std::endl;
		printDB(file, poiDb);
		file << std::endl;
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
	if(mode == REPLACE) {
		waypointDb.clearDb();
		poiDb.clearDb();
	}

	std::ifstream file;

	file.open(mediaName + ".json");
	if(file.is_open()) {
		APT::CJsonToken* token = new APT::CJsonToken(APT::CJsonToken::TokenType::BEGIN_OBJECT);
		APT::CJsonScanner jsonScanner(file);
		APT::CJsonToken::TokenType event;
		stateType state = WAITING_FOR_FIRST_TOKEN;
		std::string currentAttributeName;
		std::string currentDB;

		// variables to keep track if object contains all necessary attributes
		bool parsingComplete = false;
		bool nameParsed = false;
		bool latitudeParsed = false;
		bool longitudeParsed = false;
		bool typeParsed = false;
		bool descriptionParsed = false;

		// variables to temporarily store attributes
		std::string name;
		double latitude;
		double longitude;
		t_poi type;
		std::string description;

		/**
		 * ensure that we don't end up in an infinite loop when
		 * - there's no next token, but parsing is not complete OR
		 * - the JSON is incomplete and the parser is still expecting more tokens
		 */
		while((token = jsonScanner.nextToken()) && !parsingComplete) {
			event = token->getType();


			std::string stateTypeStrings[] = {
					"WAITING_FOR_FIRST_TOKEN",
					"WAITING_FOR_DB_NAME",
					"WAITING_FOR_DB_BEGIN",
					"WAITING_FOR_ARRAY_BEGIN",
					"WAITING_FOR_OBJECT_BEGIN",
					"WAITING_FOR_ATTRIBUTE_NAME",
					"WAITING_FOR_NAME_SEPARATOR",
					"WAITING_FOR_VALUE",
					"WAITING_FOR_ATTRIBUTE_SEPARATOR_OR_END_OF_OBJECT",
					"WAITING_FOR_OBJECT_SEPARATOR_OR_END_OF_ARRAY",
					"WAITING_FOR_ARRAY_SEPARATOR_OR_END_OF_FILE"
			};

			std::string eventTypeStrings[] = {
					"BEGIN_OBJECT",
					"END_OBJECT",
					"BEGIN_ARRAY",
					"END_ARRAY",
					"NAME_SEPARATOR",
					"VALUE_SEPARATOR",
					"STRING",
					"NUMBER",
					"BOOL",
					"JSON_NULL"
			};

#ifdef DEBUG
			std::cout << std::endl << "state: " << stateTypeStrings[state] << std::endl;
			std::cout << "event: " << eventTypeStrings[event] << std::endl;
#endif

			switch(state) {
				case WAITING_FOR_FIRST_TOKEN:
					switch(event) {
						case APT::CJsonToken::TokenType::BEGIN_OBJECT:
							state = WAITING_FOR_DB_NAME;
							break;
						default:
							std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
							return false;
					}
					break;
				case WAITING_FOR_DB_NAME:
					switch(event) {
						case APT::CJsonToken::TokenType::STRING:
							currentDB = ((APT::CJsonValueToken<APT::CJsonToken::STRING,std::string>*)token)->getValue();
							state = WAITING_FOR_DB_BEGIN;
							break;
						default:
							std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
							return false;
					}
					break;
				case WAITING_FOR_DB_BEGIN:
					switch(event) {
						case APT::CJsonToken::TokenType::NAME_SEPARATOR:
							state = WAITING_FOR_ARRAY_BEGIN;
							break;
						default:
							std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
							return false;
					}
					break;
				case WAITING_FOR_ARRAY_BEGIN:
					switch(event) {
						case APT::CJsonToken::TokenType::BEGIN_ARRAY:
							state = WAITING_FOR_OBJECT_BEGIN;
							break;
						default:
							std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
							return false;
					}
					break;
				case WAITING_FOR_OBJECT_BEGIN:
					switch(event) {
						case APT::CJsonToken::TokenType::BEGIN_OBJECT:
							parsingComplete = false;
							nameParsed = false;
							latitudeParsed = false;
							longitudeParsed = false;
							typeParsed = false;
							descriptionParsed = false;
							state = WAITING_FOR_ATTRIBUTE_NAME;
							break;
						default:
							std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
							return false;
					}
					break;
				case WAITING_FOR_ATTRIBUTE_NAME:
					switch(event) {
						case APT::CJsonToken::TokenType::STRING:
							currentAttributeName = ((APT::CJsonValueToken<APT::CJsonToken::STRING,std::string>*)token)->getValue();
#ifdef DEBUG
							std::cout << "attribute name: \"" << currentAttributeName << "\"" << std::endl;
#endif
							state = WAITING_FOR_NAME_SEPARATOR;
							break;
						default:
							std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
							return false;
					}
					break;
				case WAITING_FOR_NAME_SEPARATOR:
					switch(event) {
						case APT::CJsonToken::TokenType::NAME_SEPARATOR:
							state = WAITING_FOR_VALUE;
							break;
						default:
							std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
							return false;
					}
					break;
				case WAITING_FOR_VALUE:
					switch(event) {
						case APT::CJsonToken::TokenType::STRING:
							if(currentAttributeName == "name") {
								name = ((APT::CJsonValueToken<APT::CJsonToken::STRING,std::string>*)token)->getValue();
#ifdef DEBUG
								std::cout << "attribute value: >" << name << "<" << std::endl;
#endif
								nameParsed = true;
							} else if(currentAttributeName == "type") {
								std::string typeString = ((APT::CJsonValueToken<APT::CJsonToken::STRING,std::string>*)token)->getValue();
								std::transform(typeString.begin(), typeString.end(),typeString.begin(), ::toupper);
#ifdef DEBUG
								std::cout << "attribute value: >" << typeString << "<" << std::endl;
#endif

								if(typeString == "") {
									std::cout << "empty poi type" << std::endl;
								} else {
									if(typeString == "RESTAURANT") {
										type = RESTAURANT;
									} else if(typeString == "TOURISTIC") {
										type = TOURISTIC;
									} else if(typeString == "GASSTATION") {
										type = GASSTATION;
									} else if(typeString == "UNIVERSITY") {
										type = UNIVERSITY;
									} else if(typeString == "SIGHTSEEING") {
										type = SIGHTSEEING;
									} else {
										std::cout << "unknown POI type" << std::endl;
									}
								}
								typeParsed = true;
							} else if(currentAttributeName == "description") {
								description = ((APT::CJsonValueToken<APT::CJsonToken::STRING,std::string>*)token)->getValue();
#ifdef DEBUG
								std::cout << "attribute value: >" << description << "<" << std::endl;
#endif
								descriptionParsed = true;
							} else {
								std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << " for attribute \"" << currentAttributeName << "\"" << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
								return false;
							}
							state = WAITING_FOR_ATTRIBUTE_SEPARATOR_OR_END_OF_OBJECT;
							break;
						case APT::CJsonToken::TokenType::NUMBER:
							if(currentAttributeName == "latitude") {
								latitude = ((APT::CJsonValueToken<APT::CJsonToken::NUMBER,double>*)token)->getValue();
#ifdef DEBUG
								std::cout << "attribute value: >" << latitude << "<" << std::endl;
#endif
								latitudeParsed = true;
							} else if(currentAttributeName == "longitude") {
								longitude = ((APT::CJsonValueToken<APT::CJsonToken::NUMBER,double>*)token)->getValue();
#ifdef DEBUG
								std::cout << "attribute value: >" << longitude << "<" << std::endl;
#endif
								longitudeParsed = true;
							} else {
								std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << " for attribute \"" << currentAttributeName << "\"" << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
								return false;
							}
							state = WAITING_FOR_ATTRIBUTE_SEPARATOR_OR_END_OF_OBJECT;
							break;
						default:
							std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
							return false;
					}
					break;
				case WAITING_FOR_ATTRIBUTE_SEPARATOR_OR_END_OF_OBJECT:
					switch(event){
						case APT::CJsonToken::TokenType::VALUE_SEPARATOR:
							state = WAITING_FOR_ATTRIBUTE_NAME;
							break;
						case APT::CJsonToken::TokenType::END_OBJECT:
							std::cout << "currentDB: " << currentDB << std::endl;
							if(currentDB == "waypoints") {
								if(nameParsed && latitudeParsed && longitudeParsed) {
									// add waypoint to waypoint DB
									std::cout << "found a waypoint" << std::endl;
									if(waypointDb.getPointerToElement(name) == nullptr) {
										waypointDb.addElement(CWaypoint(name, latitude, longitude));
#ifdef DEBUG
										std::cout << "INFO in CJsonPersistence::readData(): Added waypoint '" << name << "'" << std::endl;
#endif
									} else {
#ifdef DEBUG
										std::cout << "INFO in CJsonPersistence::readData(): Waypoint '" << name << "' already exists in DB" << std::endl;
#endif
									}

								} else {
									std::cout << "ERROR in CJsonPersistence::readData(): Waypoint has too few attributes in line " << jsonScanner.scannedLine() << std::endl;
									return false;
								}
							} else if(currentDB == "pois") {
								if(nameParsed && latitudeParsed && longitudeParsed && typeParsed && descriptionParsed) {
									// add waypoint to POI DB
									std::cout << "found a poi" << std::endl;
									poiDb.addElement(CPOI(type, name, description, latitude, longitude));
									if(poiDb.getPointerToElement(name) == nullptr) {
										poiDb.addElement(CPOI(type, name, description, latitude, longitude));
#ifdef DEBUG
										std::cout << "INFO in CJSONStorage::readData(): Added POI '" << name << "'" << std::endl;
#endif
									} else {
#ifdef DEBUG
										std::cout << "INFO in CJsonPersistence::readData(): POI '" << name << "'  already exists in DB" << std::endl;
#endif
									}
								} else {
									std::cout << "ERROR in CJsonPersistence::readData(): POI has too few attributes in line " << jsonScanner.scannedLine() << std::endl;
									return false;
								}
							}
							state = WAITING_FOR_OBJECT_SEPARATOR_OR_END_OF_ARRAY;
							break;
						default:
							std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
							return false;
					}
					break;
				case WAITING_FOR_OBJECT_SEPARATOR_OR_END_OF_ARRAY:
					switch(event){
						case APT::CJsonToken::TokenType::END_ARRAY:
							state = WAITING_FOR_ARRAY_SEPARATOR_OR_END_OF_FILE;
							break;
						case APT::CJsonToken::TokenType::VALUE_SEPARATOR:
							state = WAITING_FOR_OBJECT_BEGIN;
							break;
						default:
							std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
							return false;
					}
					break;
				case WAITING_FOR_ARRAY_SEPARATOR_OR_END_OF_FILE:
					switch(event){
						case APT::CJsonToken::TokenType::END_OBJECT:
							parsingComplete = true;
							break;
						case APT::CJsonToken::TokenType::VALUE_SEPARATOR:
							state = WAITING_FOR_DB_NAME;
							break;
						default:
							std::cout << "ERROR in CJsonPersistence::readData(): Did not expect event " << eventTypeStrings[event] << " in state " << stateTypeStrings[state] << std::endl << "Token ignored in line " << jsonScanner.scannedLine() << std::endl;
							return false;
					}

			}
		}
	}
	file.close();
	return false;
}
