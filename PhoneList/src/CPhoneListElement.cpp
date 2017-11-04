/*
 * CPhoneListElement.cpp
 *
 *  Created on: 04.11.2017
 *      Author: awilms
 */

#include "CPhoneListElement.h"

CPhoneListElement::CPhoneListElement(std::string name, long long number) :
m_name(name)
{
	m_number.push_back(number);
}

std::string CPhoneListElement::getName() {
	return m_name;
}

long long CPhoneListElement::getNumber(int index) {
	return m_number.at(index);
}

void CPhoneListElement::addNumber(long long number) {
	m_number.push_back(number);
}

int CPhoneListElement::getNoNumber() {
	return m_number.size();
}


bool CPhoneListElement::numberInList(long long number) {
	for(std::vector<long long>::iterator it = m_number.begin(); it != m_number.end(); it++) {
		if(*it.base() == number) {
			return true;
		}
	}

	return false;
}
