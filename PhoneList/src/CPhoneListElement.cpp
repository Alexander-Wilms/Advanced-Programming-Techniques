/*
 * CPhoneListElement.cpp
 *
 *  Created on: 04.11.2017
 *      Author: awilms
 */

#include "CPhoneListElement.h"

CPhoneListElement::CPhoneListElement(std::string name, unsigned long long number) :
m_name(name)
{
	m_number.push_back(number);
}

std::string CPhoneListElement::getName() {
	return m_name;
}

int CPhoneListElement::getNumber(int index) {
	return m_number.at(index);
}

void CPhoneListElement::addNumber(unsigned long long number) {
	m_number.push_back(number);
}

bool CPhoneListElement::numberInList(unsigned long long number) {
	bool numberInList = false;

	for(std::vector<unsigned long long>::iterator it = m_number.begin(); it != m_number.end(); it++) {
		if(*it.base() == number) {
			numberInList = true;
		}
	}

	return numberInList;
}
