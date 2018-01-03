/*
 * CGraphicElement.cpp
 *
 *  Created on: 7 Nov 2013
 *      Author: mnl
 */

#include "CCoordinate.h"
#include <iostream>
#include <vector>
#include "CGraphicElement.h"

GraSys::CGraphicElement::CGraphicElement(string type, int numberOfCoordinates,
		string color) {
	m_type = type;
	m_color = color;
	m_numberCoordinates = numberOfCoordinates;
}

void GraSys::CGraphicElement::move(float xoffset, float yoffset) {
	for (std::vector<CCoordinate>::iterator it = m_coordinates.begin();
			it != m_coordinates.end(); it++) {
		float x, y;
		it.base()->getCartesian(x, y);
		x += xoffset;
		y += yoffset;
		it.base()->setCartesian(x, y);
	}
}

void GraSys::CGraphicElement::print() {
	cout << m_type << "(color: " << m_color << ") with coordinates: ";
	for (std::vector<CCoordinate>::iterator it = m_coordinates.begin();
			it != m_coordinates.end(); it++) {
		cout << "[" << it.base()->getX() << ", " << it.base()->getY() << "]";
		if (it - m_coordinates.begin() < m_numberCoordinates - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}

const GraSys::CCoordinate GraSys::CGraphicElement::getCoordinate(
		unsigned int index) {
	return m_coordinates.at(index);
}

GraSys::CGraphicElement::~CGraphicElement() {
}

std::string GraSys::CGraphicElement::getColor() {
	return m_color;
}

bool GraSys::CGraphicElement::operator ==(
		const GraSys::CGraphicElement& c) const {
	bool equal = true;
	if (m_type != c.m_type || m_color != c.m_color) {
		equal = false;
	} else {
		// same type, so same m_numberCoordinates
		std::vector<CCoordinate>::const_iterator itc = c.m_coordinates.begin();
		for (std::vector<CCoordinate>::const_iterator it =
				m_coordinates.begin(); it != m_coordinates.end(); it++) {
			if (it.base()->getX() != itc.base()->getX()
					|| it.base()->getY() != itc.base()->getY()) {
				equal = false;
			}
			itc++;
		}
	}

	return equal;
}
