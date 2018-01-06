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
template<typename T>
class CCoordinate
{
private:
	T m_x;
	T m_y;

public:
	CCoordinate<T> operator+ (const CCoordinate<T>& c) {
		CCoordinate result (m_x + c.m_x, m_y + c.m_y);
		return result;
	}

	template<class Y>
	friend ostream& operator<< (ostream& out, const GraSys::CCoordinate<Y>& c);
	bool operator== (const GraSys::CCoordinate<T>& c) const {
		return (getX() == c.getX() && getY() == c.getY());
	}

	enum t_quadrant { Q1, Q2, Q3, Q4 };

	CCoordinate(T initialX = 0, T initialY = 0) {
	//	cout << "Initializing object at " << this << endl;
		m_x = initialX;
		m_y = initialY;
	}

	CCoordinate(t_quadrant quadrant) {
		switch(quadrant) {
		case Q1:
			m_x = 1;
			m_y = 1;
			break;
		case Q2:
			m_x = -1;
			m_y = 1;
			break;
		case Q3:
			m_x = -1;
			m_y = -1;
			break;
		case Q4:
			m_x = 1;
			m_y = -1;
			break;
		}
	}

	CCoordinate(const CCoordinate& orig) {
	//	cout << "Initializing object (copy) at " << this << endl;
		m_x = orig.m_x;
		m_y = orig.m_y;
	}
	~CCoordinate() {
		//	cout << "Destructing object at " << this << endl;
	}

	void setCartesian(T x, T y) {
		m_x = x;
		m_y = y;
	}

	void getCartesian(T& x, T& y) {
		x = m_x;
		y = m_y;
	}

	void move(T x, T y) {
		m_x += x;
		m_y += y;
	}

	T getX() const {
		return m_x;
	}

	T getY() const {
		return m_y;
	}
};

template<class T>
ostream& operator<< (ostream& out, const GraSys::CCoordinate<T>& c) {
	out << "[" << c.m_x << ", " << c.m_y << "]";
	return out;
}


}



#endif /* CCOORDINATE_H_ */
