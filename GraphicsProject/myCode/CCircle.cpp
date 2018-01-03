/*
 * CCircle.cpp
 *
 *  Created on: 7 Nov 2013
 *      Author: mnl
 */

#include <iostream>
using namespace std;
#include "CCircle.h"

GraSys::CCircle::CCircle(std::string color, const CCoordinate& center, double radius) : CGraphicElement("Circle", 1, color), m_radius(radius) {
	m_coordinates.push_back(center);
}

string GraSys::CCircle::getTypeName() {
	return "CCircle";
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
