/*
 * main.cpp
 *
 *  Created on: 04.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CPhoneList.h"
#include <iostream>

int main(void) {
	CSimpleList simpleList;
	simpleList.loadFromFile("input.txt");
	std::cout << "CSimpleList::print()" << std::endl
			  << "====================" << std::endl;
	simpleList.print();

	CPhoneList phoneList;
	phoneList.readAndTransformSimpleList(simpleList);
	std::cout << std::endl << "CPhoneList::print()" << std::endl
			  	  	  	   << "===================" << std::endl;
	phoneList.print();
	phoneList.saveListToFile("output.txt");

	return 0;
}
