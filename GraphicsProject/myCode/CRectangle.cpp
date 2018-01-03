/*
 * CRectangle.cpp
 *
 *  Created on: 7 Nov 2013
 *      Author: mnl
 */

#include "CCoordinate.h"
#include "CRectangle.h"
#include <string>

GraSys::CRectangle::CRectangle(std::string color) : GraSys::CGraphicElement("Rectangle", 2, color) {
}

std::string GraSys::CRectangle::getTypeName()
{
	return "Rectangle";
}

GraSys::CRectangle::CRectangle(std::string color, const GraSys::CCoordinate& corner1,
		const GraSys::CCoordinate& corner2) {
	m_coordinates.push_back(corner1);
	m_coordinates.push_back(corner2);
}

GraSys::CRectangle::~CRectangle() {
}
