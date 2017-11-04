/*
 * CSimpleListElement.cpp
 *
 *  Created on: 04.11.2017
 *      Author: awilms
 */

#include "CSimpleListElement.h"

CSimpleListElement::CSimpleListElement(std::string name, long long number) :
	m_name(name), m_number(number)
{

}

std::string CSimpleListElement::getName() {
	return m_name;
}

long long CSimpleListElement::getNumber() {
	return m_number;
}
