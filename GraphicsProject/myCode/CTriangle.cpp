/*
 * CTriangle.cpp
 *
 *  Created on: 7 Nov 2013
 *      Author: mnl
 */

#include <iostream>
#include "CTriangle.h"
#include "CGraphicElement.h"

GraSys::CTriangle::CTriangle(string color) : GraSys::CGraphicElement("Triangle", 3, color) {
	CCoordinate corner1(0,0);
	CCoordinate corner2(1,0);
	CCoordinate corner3(0,0.5);
	m_coordinates.push_back(corner1);
	m_coordinates.push_back(corner2);
	m_coordinates.push_back(corner3);
}

string GraSys::CTriangle::getTypeName()
{
	return "Triangle";
}

GraSys::CTriangle::~CTriangle() {
}

GraSys::CTriangle::CTriangle(string color, const CCoordinate& corner1,
		const CCoordinate& corner2, const CCoordinate& corner3) {
	m_coordinates.push_back(corner1);
	m_coordinates.push_back(corner2);
	m_coordinates.push_back(corner3);
}
