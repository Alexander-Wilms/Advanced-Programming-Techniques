/*
 * CComplexSet.cpp
 *
 *  Created on: 20.11.2017
 *      Author: Fromm
 */

#include "CComplexSet.h"

#include <iostream>
#include <fstream>

using namespace std;

CComplexSet::CComplexSet()
{
	// TODO Auto-generated constructor stub

}

void CComplexSet::addElement(const CComplex& data)
{
	m_data.push_back(data);
}

void CComplexSet::print()
{
	vector<CComplex>::const_iterator it;

	for (it = m_data.begin(); it != m_data.end(); ++it)
	{
		cout << "Data: " << (*it) << endl;
	}
}

void CComplexSet::saveToFile(std::string filename)
{
	//Our file object
	fstream file;

	//Let's open the file and start storing the data at the first position
	file.open(filename.c_str(), fstream::out);
	file.seekg(0);


	//Iterate through the array and "print" the element into the file
	vector<CComplex>::const_iterator it;

	for (it = m_data.begin(); it != m_data.end(); ++it)
	{
		file << "Data: " << (*it) << endl;
	}

	//Close the file at the end of the day
	file.close();

}
