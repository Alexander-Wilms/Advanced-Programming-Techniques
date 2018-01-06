/*
 * CGraphicElement.h
 *
 *  Created on: 7 Nov 2013
 *      Author: mnl
 */

#ifndef CGRAPHICELEMENT_H_
#define CGRAPHICELEMENT_H_

#include <string>
#include <vector>
#include "CCoordinate.h"

namespace GraSys {
template<typename T>
class CGraphicElement
{
private:

protected:
	string m_type;
	string m_color;
	int m_numberCoordinates;
	std::vector<CCoordinate<T>> m_coordinates;

public:
	CGraphicElement(string type = "Rectangle", int numberOfCoordinates = 4, string color = "black") {
		m_type = type;
		m_color = color;
		m_numberCoordinates = numberOfCoordinates;
	}

	virtual ~CGraphicElement() {

	}

	void move (T xoffset, T yoffset) {
		typename std::vector<CCoordinate<T>>::iterator bla;
		for (typename std::vector<CCoordinate<T>  >::iterator it = m_coordinates.begin(); it != m_coordinates.end(); it++) {
			T x, y;
			it->getCartesian(x, y);
			x += xoffset;
			y += yoffset;
			it->setCartesian(x, y);
		}
	}

	void print() {
		std::cout << *this << std::endl;
	}

	std::string getColor() {
		return m_color;
	}

	const CCoordinate<T> getCoordinate(unsigned int index) {
		return m_coordinates.at(index);
	}

	bool operator== (const CGraphicElement<T>& c) const {
		bool equal = true;
		if (m_type != c.m_type || m_color != c.m_color) {
			// types and colors are not equal
			equal = false;
		} else {
			// same type, so same m_numberCoordinates
			typename std::vector<CCoordinate<T> >::const_iterator itc = c.m_coordinates.begin();
			for (typename std::vector<CCoordinate<T>>::const_iterator it =
					m_coordinates.begin(); it != m_coordinates.end(); it++) {
				if (it->getX() != itc->getX() || it->getY() != itc->getY()) {
					equal = false;
				}
				itc++;
			}
		}

		return equal;
	}

	// https://stackoverflow.com/questions/4039817/friend-declaration-declares-a-non-template-function
	template<typename Y>
	friend std::ostream& operator<< (std::ostream& out, const GraSys::CGraphicElement<Y>& g);

	virtual std::string getTypeName() {
		return m_type;
	}
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const GraSys::CGraphicElement<T>& g) {
	out << "[type: " << g.m_type << ", color: " << g.m_color << ", coordinates:";

	typename std::vector<GraSys::CCoordinate<T>>::const_iterator itc = g.m_coordinates.begin();
	for (typename std::vector<GraSys::CCoordinate<T>>::const_iterator it = g.m_coordinates.begin(); it != g.m_coordinates.end(); it++) {
		out << " " << *it;
	}

	out << "]";

	return out;
}


}



#endif /* CGRAPHICELEMENT_H_ */
