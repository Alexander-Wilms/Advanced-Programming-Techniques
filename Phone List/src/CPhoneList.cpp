/*
 * CPhoneList.cpp
 *
 *  Created on: 04.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CPhoneList.h"
#include <fstream>
#include <iostream>
#include <set>

CPhoneList::CPhoneList() {
}

void CPhoneList::readAndTransformSimpleList(CSimpleList& simpleList) {
	std::string name;
	unsigned long long number;
	for (int i = 0; i < simpleList.size(); i++) {
		name = simpleList.getName(i);
		number = simpleList.getNumber(i);

		int pos;
		if (nameExists(name, pos)) {
			m_list[pos].addNumber(number);
		} else {
			m_list.push_back(CPhoneListElement(name, number));
		}
	}
}

void CPhoneList::saveListToFile(std::string filename) {
	std::ofstream file;
	file.open(filename);
	if(file.is_open()) {
		for (std::vector<CPhoneListElement>::iterator it = m_list.begin();
				it != m_list.end(); it++) {

			file << it.base()->getName() << ";";

			for (int i = 0; i < it.base()->getNoNumber(); i++) {
				if (it.base()->getNumber(i) != -1) {
					file << " " << it.base()->getNumber(i);
					std::string nameOfOtherPerson = numberDoubled(
							it.base()->getName(), it.base()->getNumber(i));
					if (nameOfOtherPerson != "") {
						file << " (Conflict with " << nameOfOtherPerson << ")";
					}
				} else {
					file << " No number found" << std::endl;
				}
			}
			file << std::endl;
		}
		file.close();
	} else {
		std::cout << "ERROR: Couldn't open file " << filename << std::endl;
	}
}

void CPhoneList::print() {
	for (std::vector<CPhoneListElement>::iterator it = m_list.begin();
			it != m_list.end(); it++) {

		std::cout << it.base()->getName() << ";";

		for (int i = 0; i < it.base()->getNoNumber(); i++) {
			if (it.base()->getNumber(i) != -1) {
				std::cout << " " << it.base()->getNumber(i);
				std::string nameOfOtherPerson = numberDoubled(
						it.base()->getName(), it.base()->getNumber(i));
				if (nameOfOtherPerson != "") {
					std::cout << " (Conflict with " << nameOfOtherPerson << ")";
				}
			} else {
				std::cout << " No number found" << std::endl;
			}
		}
		std::cout << std::endl;
	}
}

bool CPhoneList::nameExists(std::string name, int& pos) {
	bool found = false;

	for (std::vector<CPhoneListElement>::iterator it = m_list.begin();
			it != m_list.end(); it++) {
		if (it.base()->getName() == name) {
			found = true;
			pos = it - m_list.begin();
		}
	}

	return found;
}

std::string CPhoneList::numberDoubled(std::string name, long long number) {
	std::string nameOfOtherPerson = "";

	// iterate over all entries
	for (std::vector<CPhoneListElement>::iterator it = m_list.begin();
			it != m_list.end(); it++) {
		// iterate over all associated phone numbers
		for (int i = 0; i < it.base()->getNoNumber(); i++) {
			if (it.base()->getNumber(i) == number
					&& it.base()->getName() != name) {
				nameOfOtherPerson = it.base()->getName();
			}
		}
	}

	return nameOfOtherPerson;
}
