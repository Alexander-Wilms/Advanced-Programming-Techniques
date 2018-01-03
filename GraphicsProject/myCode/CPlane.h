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
#include <vector>

namespace GraSys {
class CPlane
{
private:
	std::vector<CGraphicElement> m_shapes;

public:
	bool addElement (CGraphicElement& element);

	/**
	 * Return the bounding box for all elements on the plane that match
	 * the given criteria.
	 *
	 * @param type take only shapes with the given type into account
	 * (use all shapes if type == "").
	 * @param color take only shapes with the given color into account
	 * (use all shapes if color == "").
	 */
	CRectangle boundingBox(string type = "", string color = "");

	void printScreen ();
};
}

#endif /* CPLANE_H_ */
