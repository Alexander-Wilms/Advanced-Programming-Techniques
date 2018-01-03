/*
 * CCoordinate.h
 *
 *  Created on: 05.11.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CCOORDINATE_H_
#define CCOORDINATE_H_

#include <ostream>

class CCoordinate {
public:
	CCoordinate(int x = 0, int y = 0);
	friend bool operator<(CCoordinate& l, CCoordinate& r);
	friend bool operator>(CCoordinate& l, CCoordinate& r);
	friend std::ostream& operator <<(std::ostream& out, CCoordinate& c);
private:
	int m_x;
	int m_y;
};

#endif /* CCOORDINATE_H_ */
