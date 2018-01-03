/*
 * CScreen.cpp
 *
 *  Created on: 21 Nov 2013
 *      Author: mnl
 */

#include "CCircle.h"
#include "CPlane.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CGraphicElement.h"

#include <iostream>

#define DEBUG

bool GraSys::CPlane::addElement(CGraphicElement& element) {
	m_shapes.push_back((CGraphicElement) element);
	return true;
}

void GraSys::CPlane::printScreen() {
	for (std::vector<CGraphicElement>::iterator it = m_shapes.begin();
			it != m_shapes.end(); it++) {
		it.base()->print();
	}
}

GraSys::CRectangle GraSys::CPlane::boundingBox(string type, string color) {
	float min_x = 0, min_y = 0, max_x = 0, max_y = 0;
	std::vector<float> x, y;
	bool allTypes = false, allColors = false;

	if (type == "") {
#ifdef DEBUG
		std::cout << "boundingBox: allTypes = true" << std::endl;
#endif
		allTypes = true;
	} else {
#ifdef DEBUG
		std::cout << "boundingBox: " << type << std::endl;
#endif
	}

	if (color == "") {
		std::cout << "boundingBox: allColors = true" << std::endl;
		allColors = true;
	} else {
#ifdef DEBUG
		std::cout << "boundingBox: " << color << std::endl;
#endif
	}

#ifdef DEBUG
	int number = m_shapes.size();
	std::cout << "CPlane contains " << number << " objects" << std::endl;
#endif

	// iterate over all shapes of the plane
	for (std::vector<CGraphicElement>::iterator itshape = m_shapes.begin();
			itshape != m_shapes.end(); itshape++) {
		if (allTypes || type == "CCircle") {
			CCircle* pcircle = dynamic_cast<CCircle*>(itshape.base());
			if (pcircle != 0) {
#ifdef DEBUG
				std::cout << "CCircle" << color << std::endl;
#endif
				if (allColors || color == pcircle->getColor()) {
					// this doesn't work
					// GraSys::CCoordinate center = circle->getCoordinate(0);
					GraSys::CCoordinate center;
					center = pcircle->getCoordinate(0);
					double radius = pcircle->getRadius();
					x.push_back(center.getX() + radius);
					x.push_back(center.getX() - radius);
					y.push_back(center.getY() + radius);
					y.push_back(center.getY() - radius);
				}
			} else {
#ifdef DEBUG
	std::cout << "Couldn't cast to CCircle" << std::endl;
#endif
			}
		}

		if (allTypes || type == "CRectangle") {
			CRectangle* prectangle = dynamic_cast<CRectangle*>(itshape.base());
			if (prectangle != 0) {
#ifdef DEBUG
				std::cout << "CRectangle" << color << std::endl;
#endif
				if (allColors || color == prectangle->getColor()) {
					for (int i = 0; i < 2; i++) {
						CCoordinate coordinate;
						coordinate = prectangle->getCoordinate(i);
						x.push_back(coordinate.getX());
						y.push_back(coordinate.getY());
					}
				}
			} else {
#ifdef DEBUG
	std::cout << "Couldn't cast to CRectangle" << std::endl;
#endif
			}
		}

		if (allTypes || type == "CTriangle") {
			CTriangle* ptriangle = dynamic_cast<CTriangle*>(*itshape);
			if (ptriangle != 0) {
#ifdef DEBUG
				std::cout << "CTriangle" << color << std::endl;
#endif
				if (allColors || color == ptriangle->getColor()) {
					for (int i = 0; i < 3; i++) {
						CCoordinate coordinate;
						coordinate = ptriangle->getCoordinate(i);
						x.push_back(coordinate.getX());
						y.push_back(coordinate.getY());
					}
				}
			} else {
#ifdef DEBUG
	std::cout << "Couldn't cast to CTriangle" << std::endl;
#endif
			}
		}

		// iterate over all coordinates of the shape
		bool firstloop = true;
		std::vector<float>::iterator ity = y.begin();
		for (std::vector<float>::iterator itx = x.begin(); itx != x.end();
				itx++) {
			if (firstloop) {
				min_x = *itx;
				max_x = *itx;
				min_y = *ity;
				max_y = *ity;
			} else {
				if (*itx < min_x) {
					min_x = *itx.base();
				} else if (*itx > max_x) {
					max_x = *itx;
				}

				if (*ity < min_y) {
					min_y = *ity;
				} else if (*ity > max_y) {
					max_y = *ity;
				}
			}
			ity++;
		}
	}

	CCoordinate corner1(min_x, min_y);
	CCoordinate corner2(max_x, max_y);
	CRectangle boundingBox("black", corner1, corner2);

	return boundingBox;
}
