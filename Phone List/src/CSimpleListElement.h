/*
 * CSimpleListElement.h
 *
 *  Created on: 04.11.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CSIMPLELISTELEMENT_H_
#define CSIMPLELISTELEMENT_H_

#include <string>

class CSimpleListElement {
public:
	CSimpleListElement(std::string name, long long number);
	std::string getName();
	long long getNumber();
private:
	std::string m_name;
	long long m_number;
};

#endif /* CSIMPLELISTELEMENT_H_ */
