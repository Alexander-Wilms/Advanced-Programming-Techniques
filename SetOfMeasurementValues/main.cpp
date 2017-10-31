/*
 * main.cpp
 *
 *  Created on: 22.10.2017
 *      Author: awilms
 */

#include "CSetOfMeasurementValues.h"
#include <iostream>

int main(void) {
	std::cout << "Testing a first object....." << std::endl;

	CSetOfMeasurementValues myVoltageValues = CSetOfMeasurementValues("myVoltageValues", V);
	myVoltageValues.setValue(1, 10);
	myVoltageValues.setValue(3, 20);
	myVoltageValues.print();

	std::cout << "Testing some exceptions....." << std::endl;

	myVoltageValues.setValue(30, 20);
	myVoltageValues.getValue(77);

	CSetOfMeasurementValues myCurrentValues = CSetOfMeasurementValues("myCurrentValues", A);
	myCurrentValues.setRandomValues(0, 100);
	myCurrentValues.print();

	return 0;
}
