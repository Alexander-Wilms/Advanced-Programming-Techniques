/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/

// System Headers

#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#define DELIMINATOR ";"

// Own Headers

#include "CString.h"
using namespace myIO;

#include "CRecord.h"

namespace APT {

CRecord::CRecord()
{
    m_phone = 0;
    m_adress = "NoAdress";
    m_name = "NoName";
}

CRecord::CRecord(string name, string adress, int phone)
{
    m_phone = phone;
    m_adress = adress;
    m_name = name;
}

CRecord::CRecord(string s)
{
	//Convert the data based on the provided string
	fromString(CString(s));
}

CRecord::CRecord(const CRecord& orig)
{
	m_name = orig.m_name;
	m_phone = orig.m_phone;
	m_adress = orig.m_adress;
}

int CRecord::getPhone() const {
	return m_phone;
}

string CRecord::toString()
{
	string str;
	str = m_name+DELIMINATOR+m_adress+DELIMINATOR+CString2::int2String(m_phone);
	return str; 
}

void CRecord::fromString(string s)
{
	//TODO Error handling must be added
	m_name = CString2::cutLeft(s,DELIMINATOR);
	m_adress = CString2::cutLeft(s,DELIMINATOR);
	m_phone = CString2::string2Int(s);
}

bool CRecord::operator< (const CRecord ref) const {
	return m_name < ref.m_name;
}

} // namespace
