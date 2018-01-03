/*
 * main.cpp
 *
 *  Created on: 22.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CCoordinate.h"
#include <iostream>

int main(void) {
	std::cout << "Constructor" << std::endl;
	std::cout << "===========" << std::endl;

	CCoordinate c1(4,4,2);
	CCoordinate c2;
	CCoordinate c3(-4);

	std::cout << "Printing" << std::endl;
	std::cout << "========" << std::endl;

	c1.print(CARTESIAN);
	c1.print(CYLINDER);
	c2.print(CYLINDER);

	c1.print(POLAR);
	c2.print(POLAR);
	c3.print(POLAR);

	std::cout << "Adding" << std::endl;
	std::cout << "======" << std::endl;

	c1.add(c3);

	/*
	 * work for add(CCoordinate c);
	 * doesn't work for work for add(CCoordinate& c);
	 * cannot bind non-const lvalue reference of type
	 * ‘CCoordinate&’ to an rvalue of type ‘CCoordinate’
	 */
	c2.add(CCoordinate(1,2,3));
	c1.print(CARTESIAN);
	c2.print(CARTESIAN);
}
