/*
 * CGraphicElement.h
 *
 *  Created on: 7 Nov 2013
 *      Author: mnl
 */

#ifndef CGRAPHICELEMENT_H_
#define CGRAPHICELEMENT_H_

#include <string>
#include <vector>
#include "CCoordinate.h"

namespace GraSys {
class CGraphicElement
{
private:

protected:
	string m_type;
	string m_color;
	int m_numberCoordinates;
	std::vector<CCoordinate> m_coordinates;

public:
	CGraphicElement(string type = "Rectangle", int numberOfCoordinates = 4, string color = "black");
	virtual ~CGraphicElement();
	void move (float xoffset, float yoffset);
	void print();
	std::string getColor();
	const CCoordinate getCoordinate(unsigned int index);
	bool operator== (const CGraphicElement& c) const;
	friend std::ostream& operator<<(std::ostream& out, const CGraphicElement& g);
	virtual std::string getTypeName();
};
}

#endif /* CGRAPHICELEMENT_H_ */
