/*
 * CSimpleList.cpp
 *
 *  Created on: 04.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CSimpleList.h"
#include "CSimpleListElement.h"
#include <iostream>
#include <fstream>
#include <string>

void CSimpleList::loadFromFile(std::string filename) {
	std::string line, name, number;
	std::ifstream file;
	long long numberParsed;
	file.open(filename);
	if(file.is_open()) {
		while(!file.eof()){
			name = "";
			number = "";
			std::getline(file,name,';');
			name = trim(name, ";");
			name = trim(name, "\n");
			std::getline(file,number);
			if(number != "") {
				numberParsed = std::stoull(getDigits(number));
			} else {
				numberParsed = -1;
			}
			addNameAndNumber(name, numberParsed);
		}
		file.close();
	}
}

CSimpleList::CSimpleList() {

}

int CSimpleList::size() {
	return m_list.size();
}

long long CSimpleList::getNumber(int pos) {
	return m_list.at(pos).getNumber();
}

std::string CSimpleList::getName(int pos) {
	return m_list.at(pos).getName();
}

void CSimpleList::print() {
	for(std::vector<CSimpleListElement>::iterator it = m_list.begin(); it != m_list.end(); it++) {
		std::cout << it.base()->getName() << "; " << it.base()->getNumber() << std::endl;
	}
}

void CSimpleList::addNameAndNumber(std::string name, long long number) {
	CSimpleListElement simpleListElement(name, number);
	m_list.push_back(simpleListElement);
}

std::string CSimpleList::trim(const std::string& source, const std::string& t) {
	std::string returnValue;
	if(source.substr(source.size()-1, 1) == t) {
		returnValue.append(source, 0, source.size()-1);
		return returnValue;
	}
	return source;
}

std::string CSimpleList::getDigits(const std::string& source) {
	std::string returnValue;

	for(int i = 0; i < source.size(); i++) {
		if('0' <= (char) source.at(i) && (char) source.at(i) <= '9') {
			returnValue.append(source,i,1);
		}
	}
	return returnValue;
}
