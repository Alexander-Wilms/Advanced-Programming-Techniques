/*
 * CCoordinate.cpp
 *
 *  Created on: 05.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CCoordinate.h"
#include <cmath>

CCoordinate::CCoordinate(int x, int y) {
	m_x = x;
	m_y = y;
}

/*
 * https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading:
 *
 * The standard library’s algorithms (e.g. std::sort()) and types (e.g. std::map) will always only expect operator< to be present. However, the users of your type will expect all the other operators to be present, too, so if you define operator<, be sure to follow the third fundamental rule of operator overloading and also define all the other boolean comparison operators. The canonical way to implement them is this:
 *
 * inline bool operator==(const X& lhs, const X& rhs){    do actual comparison    }
 * inline bool operator!=(const X& lhs, const X& rhs){return !operator==(lhs,rhs);}
 * inline bool operator< (const X& lhs, const X& rhs){    do actual comparison    }
 * inline bool operator> (const X& lhs, const X& rhs){return  operator< (rhs,lhs);}
 * inline bool operator<=(const X& lhs, const X& rhs){return !operator> (lhs,rhs);}
 * inline bool operator>=(const X& lhs, const X& rhs){return !operator< (lhs,rhs);}
 */

bool operator<(CCoordinate& l, CCoordinate& r) {
	return std::sqrt((l.m_x^2)+(l.m_y^2)) < std::sqrt((r.m_x^2)+(r.m_y^2));
}

bool operator>(CCoordinate& l, CCoordinate& r) {
	return r < l;
}

std::ostream& operator <<(std::ostream& out, CCoordinate& c) {
	out << "(" << c.m_x << ", " << c.m_y << ")";
	return out;
}
