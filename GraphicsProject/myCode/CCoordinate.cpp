/*
 * CCoordinate.cpp
 *
 *  Created on: 17.10.2013
 *      Author: mnl
 */

#include <iostream>
using namespace std;

#include "CCoordinate.h"

GraSys::CCoordinate::CCoordinate(float initialX, float initialY) {
//	cout << "Initializing object at " << this << endl;
	m_x = initialX;
	m_y = initialY;
}

GraSys::CCoordinate::CCoordinate(t_quadrant quadrant)
{
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

GraSys::CCoordinate::CCoordinate(const CCoordinate& orig)
{
//	cout << "Initializing object (copy) at " << this << endl;
	m_x = orig.m_x;
	m_y = orig.m_y;
}

GraSys::CCoordinate::~CCoordinate()
{
//	cout << "Destructing object at " << this << endl;
}

void GraSys::CCoordinate::setCartesian(float x, float y)
{
	m_x = x;
	m_y = y;
}

float GraSys::CCoordinate::getX() const {
	return m_x;
}

void GraSys::CCoordinate::move(float x, float y) {
	m_x += x;
	m_y += y;
}

bool GraSys::CCoordinate::operator ==(const GraSys::CCoordinate& c) const {
	return (this->getX() == c.getX() && this->getY() == c.getY());
}

float GraSys::CCoordinate::getY() const
{
	return m_y;
}

void GraSys::CCoordinate::getCartesian(float& x, float& y) {
	cout << "Address of parameter x: " << &x << endl;
	x = m_x;
	y = m_y;
}

GraSys::CCoordinate GraSys::operator+ (const CCoordinate& c1, const CCoordinate& c2) {
	CCoordinate result (c1.m_x + c2.m_x, c1.m_y + c2.m_y);
	return result;
}

ostream& GraSys::operator<< (ostream& out, const CCoordinate& c) {
	out << c.m_x << " " << c.m_y;
	return out;
}

