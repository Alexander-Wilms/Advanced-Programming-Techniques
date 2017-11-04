/*
 * CSimpleListElement.h
 *
 *  Created on: 04.11.2017
 *      Author: awilms
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
	long long m_number;
	std::string m_name;
};

#endif /* CSIMPLELISTELEMENT_H_ */
