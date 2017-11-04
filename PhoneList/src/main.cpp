/*
 * main.cpp
 *
 *  Created on: 04.11.2017
 *      Author: awilms
 */

#include "CPhoneList.h"

int main(void) {
	CSimpleList simpleList;
	simpleList.loadFromFile("input.txt");
	simpleList.print();

	CPhoneList phoneList;
	phoneList.readAndTransformSimpleList(simpleList);
	phoneList.print();

	return 0;
}
