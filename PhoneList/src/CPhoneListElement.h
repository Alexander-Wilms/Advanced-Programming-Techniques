/*
 * CPhoneListElement.h
 *
 *  Created on: 04.11.2017
 *      Author: awilms
 */

#ifndef CPHONELISTELEMENT_H_
#define CPHONELISTELEMENT_H_

#include <string>
#include <vector>

class CPhoneListElement {
public:
	CPhoneListElement(std::string name, unsigned long long number);
	std::string getName();
	int getNumber(int index);
	void addNumber(unsigned long long number);
	bool numberInList(unsigned long long number);
private:
	std::vector<unsigned long long> m_number;
	std::string m_name;
};

#endif /* CPHONELISTELEMENT_H_ */
