// SGSE1-Labor
// CAddressDB.cpp

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien


#include <iostream>				
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

#include "CString.h"
using namespace myIO;

#include "CAddressDB.h"
#include "CRecord.h"

namespace APT {

CAddressDB::CAddressDB(string filename)
{
	//Initialise the attributes
	m_filename = filename;
}

CAddressDB::~CAddressDB()
{
}

const CRecord* CAddressDB::findByNumber(int phone) const {
	map<int, CRecord*>::const_iterator res = m_recordsByNumber.find(phone);
	if (res == m_recordsByNumber.end()) {
		return 0;
	}
	return res->second;
}


void CAddressDB::addRecord(const CRecord& c)
{
	m_records.push_back(c);
	m_recordsByNumber[c.getPhone()] = &m_records.back();
}

bool addressBefore(const CRecord& r1, const CRecord& r2)
{
	return r1.m_adress < r2.m_adress;
}

std::vector<CRecord> CAddressDB::select(t_print t, string filter)
{
	switch (t)
	{
	case ALL:
		return m_records;

	case SORTED: {
		vector<CRecord> sorted (m_records.begin(), m_records.end());
		sort(sorted.begin(), sorted.end());
		return sorted;
	}

	case SORTED_BY_ADDR: {
		vector<CRecord> sorted (m_records.begin(), m_records.end());
		sort(sorted.begin(), sorted.end(), addressBefore);
		return sorted;
	}

	case FILTER : {
		vector<CRecord> filtered;
		for (vector<CRecord>::iterator itr = m_records.begin();
			 itr < m_records.end(); itr++)
		{
			if (CString2::contains(itr->toString(), filter))
			{
				filtered.push_back(*itr);
			}
		}
		return filtered;
		break;
	}

	default:
		break;
	}
	return vector<CRecord>();
}

void CAddressDB::print(t_print t)
{
	string filter;

	cout << "================" << endl;
	vector<CRecord> recs;
	if (t == FILTER) {
		cout << "Please enter filter: ";
		cin >> filter;
		recs = select(t, filter);
	} else {
		recs = select(t);
	}
	for (vector<CRecord>::iterator itr = recs.begin();
			itr < recs.end(); itr++)
	{
		cout << *itr << endl;
	}
	cout << "================" << endl;
}

void CAddressDB::saveToFile()
{
	CFileIO myFile;

	myFile.openFile(m_filename,OUT);
	

	for (vector<CRecord>::iterator itr = m_records.begin();
		 itr < m_records.end(); itr++)
	{
		myFile.writeLine(itr->toString());
	}
	myFile.closeFile();

	cout << "....saved data to file" << endl;
}

bool CAddressDB::loadFromFile()
{
	string s;
	CFileIO myFile;

	if (!myFile.openFile(m_filename,IN)) {
		return false;
	}
	
	cout << "Reading from file: " << m_filename << endl;

	while (myFile.readLine(s))
	{
		//HACK nasty coding: addRecord is only executed if length > 0
		if (s.length() > 0)
		{
			addRecord(CRecord(s));
		}
		else
		{
			cout << ".";
		}
	}
	myFile.closeFile();
	cout << "finished" << endl;
	return true;
}

} // namespace
