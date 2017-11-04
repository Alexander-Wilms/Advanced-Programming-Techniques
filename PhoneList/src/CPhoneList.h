/*
 * CPhoneList.h
 *
 *  Created on: 04.11.2017
 *      Author: awilms
 */

#ifndef CPHONELIST_H_
#define CPHONELIST_H_

#include "CSimpleList.h"
#include "CPhoneListElement.h"
#include <vector>

class CPhoneList {
public:
	CPhoneList();
	void readAndTransformSimpleList(CSimpleList& simpleList);
	void saveListToFile(std::string filename);
	void print();
private:
	bool nameExists(std::string name, int& pos);
	std::string numberDoubled(std::string, unsigned long long number);
	std::vector<CPhoneListElement> m_list;
};

#endif /* CPHONELIST_H_ */
