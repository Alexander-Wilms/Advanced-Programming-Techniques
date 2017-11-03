/*
 * main.cpp
 *
 *  Created on: 03.11.2017
 *      Author: awilms
 */

#include "CLifoBuffer.h"
#include "CFraction.h"
#include <iostream>

int main(void) {
	CLifoBuffer lifoBuffer(5);
	lifoBuffer.push(CFraction(1,2));
	lifoBuffer.push(CFraction(3,4));
	lifoBuffer.push(CFraction(5,6));
	lifoBuffer.print();
	CFraction storage;
	lifoBuffer.pop(storage);
	lifoBuffer.pop(storage);
	lifoBuffer.pop(storage);
	lifoBuffer.print();
	return 0;
}
