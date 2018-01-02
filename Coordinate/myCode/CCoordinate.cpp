/*
 * CCoordinate.cpp
 *
 *  Created on: 22.10.2017
 *      Author: awilms
 */

#include "CCoordinate.h"
#include <iostream>
#include <cmath>

#define RAD2DEG 180/M_PI

CCoordinate::CCoordinate(float x, float y, float z) {
	m_x = x;
	m_y = y;
	m_z = z;

	std::cout << "Constructor generates object at " << this << std::endl;
	std::cout << "Value = <" << m_x << ", " << m_y << ", " << m_z << ">" << std::endl;
}

CCoordinate::~CCoordinate() {
	std::cout << "Destructor: The object's address: " << this << std::endl;
}

void CCoordinate::getCartesian(float& x, float& y, float& z) {
	x = m_x;
	y = m_y;
	z = m_z;
	// without call by reference, no values can be returned
}

void CCoordinate::setCartesian(float x, float y, float z) {
	m_x = x;
	m_y = y;
	m_z = z;
	// using call by reference doesn't change anything
}

void CCoordinate::add(CCoordinate& c) {
	m_x += c.m_x;
	m_y += c.m_y;
	m_z += c.m_z;
	// I need to access the arguments members
}

void CCoordinate::print(t_coordinate style) {
	float r, phi, z, theta;

	switch(style) {
	case CARTESIAN:
		std::cout << "Cartesian representation <x,y,z> = <" << m_x << ", " << m_y << ", " << m_z << ">" << std::endl;
		break;
	case CYLINDER:
		getCylinder(r, phi, z);
		std::cout << "Cylinder representation <r,phi,z> = <" << r << ", " << phi << ", " << z << ">" << std::endl;
		break;
	case POLAR:
		getPolar(r, phi, theta);
		std::cout << "Polar representation <r,phi,theta> = <" << r << ", " << phi << ", " << theta << ">" << std::endl;
	}
}

void CCoordinate::getPolar(float& r, float& phi, float& theta) {
	r = sqrt(m_x*m_x+m_y*m_y+m_z*m_z);

	if(m_y >= 0) {
		phi = acos(m_x/(sqrt(m_x*m_x+m_y*m_y)));
	} else if(m_y < 0) {
		phi = 2*M_PI-acos(m_x/sqrt(m_x*m_x+m_y*m_y));
	}

	theta = M_PI/2 - atan(m_z/(sqrt(m_x*m_x+m_y*m_y)));

	if(isnanf(phi) || isnanf(theta)) {
		std::cout << "WARNING: Undefined result. Setting all angles to 0" << std::endl;
		phi = 0;
		theta = 0;
	}

	phi *= RAD2DEG;
	theta *= RAD2DEG;

}

void CCoordinate::getCylinder(float& r, float& phi, float& h) {
	r = sqrt(m_x*m_x+m_y*m_y);

	if(m_x > 0) {
		phi = atan(m_y/m_x);
	} else if(m_x < 0 && m_y >= 0) {
		phi = atan(m_y/m_x)+M_PI;
	} else if(m_x < 0 && m_y < 0) {
		phi = atan(m_y/m_x)-M_PI;
	} else if(m_x == 0 && m_y > 0) {
		phi = M_PI/2;
	} else if(m_x == 0 && m_y < 0) {
		phi = M_PI/2;
	} else {
		std::cout << "WARNING: Undefined result. Setting phi to 0" << std::endl;
		phi = 0;
	}

	phi *= RAD2DEG;

	h = m_z;
}
