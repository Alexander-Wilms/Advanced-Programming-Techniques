/*
 * CComplexSet.h
 *
 *  Created on: 20.11.2017
 *      Author: Fromm
 */

#ifndef CCOMPLEXSET_H_
#define CCOMPLEXSET_H_

#include "CComplex.h"
#include <vector>
#include <string>

class CComplexSet
{
private:
	std::vector<CComplex> m_data;
public:

	CComplexSet();

	void addElement(CComplex const& data);
	void print();

	void saveToFile(std::string filename);
};

#endif /* CCOMPLEXSET_H_ */
