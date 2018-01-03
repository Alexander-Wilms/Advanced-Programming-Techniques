/*
 * CCoordinate.h
 *
 *  Created on: 17.10.2013
 *      Author: mnl
 */

#ifndef CCOORDINATE_H_
#define CCOORDINATE_H_

#include <ostream>
using namespace std;

namespace GraSys {
class CCoordinate
{
	friend CCoordinate operator+ (const CCoordinate& c1, const CCoordinate& c2);
	friend ostream& operator<< (ostream& out, const CCoordinate& c);

private:
	float m_x;
	float m_y;

public:
	bool operator== (const GraSys::CCoordinate& c) const;
	enum t_quadrant { Q1, Q2, Q3, Q4 };

	CCoordinate(float initialX = 0, float initialY = 0);
	CCoordinate(t_quadrant quadrant);
	CCoordinate(const CCoordinate& orig);
	~CCoordinate();

	void setCartesian(float x, float y);
	void getCartesian(float& x, float& y);
	void move(float x, float y);

	float getX() const;
	float getY() const;
};

CCoordinate operator+ (const CCoordinate& c1, const CCoordinate& c2);
ostream& operator<< (ostream& out, const CCoordinate& c);
}

#endif /* CCOORDINATE_H_ */
