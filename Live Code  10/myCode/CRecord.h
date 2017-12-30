/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        :
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CRECORD_H
#define CRECORD_H

#include <string>
#include <iostream>

#include "CString.h"

namespace APT {

class CRecord {

friend std::ostream& operator<<(std::ostream& out, const CRecord& c)
{
	out << c.m_name << "\t" << c.m_adress << "\t" << c.m_phone;
	return out;
}

friend bool addressBefore(const CRecord& r1, const CRecord& r2);

private:
    int m_phone;
    std::string m_adress;
    std::string m_name;
public:

    CRecord();
	CRecord(std::string s);
	CRecord(const APT::CRecord& origin);
    CRecord(std::string name, std::string adress, int phone);

    int getPhone() const;

	std::string toString();

	void fromString(std::string s);

	bool operator< (const CRecord ref) const;
};
/********************
**  CLASS END
*********************/

} // namespace

#endif /* CRECORD_H */
