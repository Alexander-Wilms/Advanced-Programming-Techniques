/*
 * CPhoneListElement.h
 *
 *  Created on: 04.11.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CPHONELISTELEMENT_H_
#define CPHONELISTELEMENT_H_

#include <string>
#include <vector>

class CPhoneListElement {
public:
	CPhoneListElement(std::string name, long long number);
	std::string getName();
	int getNoNumber();
	long long getNumber(int index);
	void addNumber(long long number);
	bool numberInList(long long number);
private:
	std::vector<long long> m_number;
	std::string m_name;
};

#endif /* CPHONELISTELEMENT_H_ */
