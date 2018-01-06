/*
 * CScreen.h
 *
 *  Created on: 21 Nov 2013
 *      Author: mnl
 */

#ifndef CPLANE_H_
#define CPLANE_H_

#include "CGraphicElement.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"
#include <vector>

namespace GraSys {
template<typename T>
class CPlane
{
private:
	std::vector<CGraphicElement<T>*> m_shapes;

public:
	bool addElement (CGraphicElement<T>& element) {
		m_shapes.push_back((CGraphicElement<T>*) &element);
		std::cout << "actual when adding: " << element.getColor() << std::endl;
		return true;
	}

	/**
	 * Return the bounding box for all elements on the plane that match
	 * the given criteria.
	 *
	 * @param type take only shapes with the given type into account
	 * (use all shapes if type == "").
	 *
	 * @param color take only shapes with the given color into account
	 * (use all shapes if color == "").
	 */
	CRectangle<T> boundingBox(string type = "", string color = "") {
		float min_x = 0, min_y = 0, max_x = 0, max_y = 0;
		std::vector<float> subBoundingBoxXValues, subBoundingBoxYValues;
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
	#ifdef DEBUG
			std::cout << "boundingBox: allColors = true" << std::endl;
	#endif
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

		bool couldntCastGraphicElement = true;

		// iterate over all shapes of the plane
		for (typename std::vector<CGraphicElement<T>*>::iterator itshape = m_shapes.begin(); itshape != m_shapes.end(); itshape++) {

			couldntCastGraphicElement = true;

			// try casting the shape to a circle
			if (allTypes || type == "CCircle") {
				CCircle<T>* pcircle = dynamic_cast<CCircle<T>*>(*itshape);
				if (pcircle != nullptr) {
					couldntCastGraphicElement = false;
	#ifdef DEBUG
					std::cout << "CCircle" << color << std::endl;
	#endif
					if (allColors || color == pcircle->getColor()) {
						GraSys::CCoordinate<T> center = pcircle->getCoordinate(0);
						double radius = pcircle->getRadius();
						subBoundingBoxXValues.push_back(center.getX() + radius);
						subBoundingBoxXValues.push_back(center.getX() - radius);
						subBoundingBoxYValues.push_back(center.getY() + radius);
						subBoundingBoxYValues.push_back(center.getY() - radius);
					}
				} else {
	#ifdef DEBUG
					std::cout << "Couldn't cast to CCircle" << std::endl;
	#endif
				}
			}

			if (allTypes || type == "CRectangle") { // try casting the shape to rectangle
				CRectangle<T>* prectangle = dynamic_cast<CRectangle<T>*>(*itshape);
				if (prectangle != nullptr) {
					couldntCastGraphicElement = false;
	#ifdef DEBUG
					std::cout << "CRectangle" << color << std::endl;
	#endif
					std::cout << "actual: " << prectangle->getColor() << std::endl;

					if (allColors || color == prectangle->getColor()) {
						for (int i = 0; i < 2; i++) {
							CCoordinate<T> coordinate;
							coordinate = prectangle->getCoordinate(i);
							subBoundingBoxXValues.push_back(coordinate.getX());
							subBoundingBoxYValues.push_back(coordinate.getY());
						}
					}
				} else {
	#ifdef DEBUG
					std::cout << "Couldn't cast to CRectangle" << std::endl;
	#endif
				}
			}

			if (allTypes || type == "CTriangle") { // try casting the shape to rectangle
				CTriangle<T>* ptriangle = dynamic_cast<CTriangle<T>*>(*itshape);
				if (ptriangle != nullptr) {
					couldntCastGraphicElement = false;
	#ifdef DEBUG
					std::cout << "CTriangle" << color << std::endl;
	#endif
					if (allColors || color == ptriangle->getColor()) {
						for (int i = 0; i < 3; i++) {
							CCoordinate<T> coordinate;
							coordinate = ptriangle->getCoordinate(i);
							subBoundingBoxXValues.push_back(coordinate.getX());
							subBoundingBoxYValues.push_back(coordinate.getY());
						}
					}
				} else {
	#ifdef DEBUG
					std::cout << "Couldn't cast to CTriangle" << std::endl;
	#endif
				}
			}

			if(couldntCastGraphicElement) {
				std::cout << "ERROR in GraSys::CPlane::boundingBox(): couldn't cast to any specific shape" << std::endl;
			}
		}

		// iterate over all coordinates of the shapes
		bool firstloop = true;
		std::vector<float>::iterator ity = subBoundingBoxYValues.begin();
		for (std::vector<float>::iterator itx = subBoundingBoxXValues.begin(); itx != subBoundingBoxXValues.end(); itx++) {
			if (firstloop) {
				min_x = *itx;
				max_x = *itx;
				min_y = *ity;
				max_y = *ity;
				firstloop = false;
			} else {
				if (*itx < min_x) {
					min_x = *itx;
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

		CCoordinate corner1(min_x, min_y);
		CCoordinate corner2(max_x, max_y);
		CRectangle boundingBox("black", corner1, corner2);

		return boundingBox;
	}

	void printScreen () {
		for (typename std::vector<CGraphicElement<T>*>::iterator it = m_shapes.begin();
				it != m_shapes.end(); it++) {
			std::cout << *it << std::endl;
		}
	}

	CPlane() {

	}
};
}

#endif /* CPLANE_H_ */
