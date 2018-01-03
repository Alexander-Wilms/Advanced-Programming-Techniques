/*
 * CSimpleList.h
 *
 *  Created on: 04.11.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CSIMPLELIST_H_
#define CSIMPLELIST_H_

#include "CSimpleListElement.h"
#include <string>
#include <vector>

class CSimpleList {
public:
	void loadFromFile(std::string filename);
	CSimpleList();
	int size();
	long long getNumber(int pos);
	std::string getName(int pos);
	void print();
private:
	void addNameAndNumber(std::string name, long long number);
	std::string trim(const std::string& source, const std::string& t);
	std::string getDigits(const std::string& source);
	std::vector<CSimpleListElement> m_list;
};

#endif /* CSIMPLELIST_H_ */
