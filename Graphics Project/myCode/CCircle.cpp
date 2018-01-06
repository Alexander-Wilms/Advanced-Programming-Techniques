/*
 * CCircle.cpp
 *
 *  Created on: 7 Nov 2013
 *      Author: mnl
 */

#include <iostream>
using namespace std;
#include "CCircle.h"

GraSys::CCircle::CCircle(std::string color, const CCoordinate& center, double radius) :
		CGraphicElement("CCircle", 1, color), m_radius(radius) {
	m_coordinates.push_back(center);
}


double GraSys::CCircle::getRadius() {
	return m_radius;
}

void GraSys::CCircle::print() {
	cout << "Circle with center: [" << m_coordinates[0].getX()
			<< ", " << m_coordinates[0].getY() << "] and radius = " << m_radius << endl;

}

GraSys::CCircle::~CCircle() {
}

void GraSys::CCircle::setRadius(double radius) {
	m_radius = radius;
}

void GraSys::CCircle::setCenter(const CCoordinate& center) {
	m_coordinates.at(0) = center;
}

bool GraSys::CCircle::operator== (const CCircle& c) const {
	// call operator of base class and compare additional member
	return m_radius == c.m_radius && (CGraphicElement) *this == (CGraphicElement) c;
}
