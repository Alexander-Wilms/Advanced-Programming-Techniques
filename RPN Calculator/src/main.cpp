/*
 * main.cpp
 *
 *  Created on: 03.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CLifoBuffer.h"
#include "CFraction.h"
#include "CRpnCalculator.h"
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

	CRpnCalculator calculator;
	calculator.pushValue(CFraction(5,2));
	calculator.pushValue(CFraction(6,5));
	calculator.multiply();
	calculator.pushValue(CFraction(1,2));
	calculator.add();
	calculator.pushValue(CFraction(1,3));
	calculator.substract();
	calculator.pushValue(CFraction(5,1));
	calculator.pushValue(CFraction(1,6));
	calculator.add();
	calculator.pushValue(CFraction(11,4));
	calculator.add();
	calculator.divide();
	calculator.popResult(storage);
	std::cout << "expected value: 0.4" << std::endl;
	std::cout << "actual value: ";
	storage.print();

	return 0;
}
