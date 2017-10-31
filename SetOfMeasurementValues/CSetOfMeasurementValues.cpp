/*
 * CSetOfMeasurementValues.cpp
 *
 *  Created on: 22.10.2017
 *      Author: awilms
 */

#include "CSetOfMeasurementValues.h"
#include <iostream>
#include <random>

CSetOfMeasurementValues::CSetOfMeasurementValues(std::string name,
		t_unit unit) {
	for(int i = 0; i < 10; i++) {
		m_value[i] = NOVALUE;
	}

	m_name = name;
	m_unit = unit;

	std::cout << "Created object at: " << this << std::endl;
}

void CSetOfMeasurementValues::setValue(unsigned int pos, double value) {
	if(pos < 0 || pos >= 10) {
		std::cout << "ERROR setValue: Position out of bounds" << std::endl;
	} else {
		m_value[pos] = value;
	}
}

void CSetOfMeasurementValues::setRandomValues(int min, int max) {
	srand(time(NULL));

	for(int i = 0; i < 10; i++) {
		m_value[i] = (double) (min*10 + rand()%(max*10))/10;
	}
}

void CSetOfMeasurementValues::print() {
	for(int i = 0; i < 10; i++) {
		if(m_value[i] != NOVALUE) {
			printSingleValue(i);
		}
	}

	std::cout << "\tMax Value: " << getMax() << std::endl;
	std::cout << "\tMin Value: " << getMin() << std::endl;
	std::cout << "\tAvg Value: " << getAverage() << std::endl;
}

double CSetOfMeasurementValues::getValue(unsigned int pos) {
	double returnValue;

	if(pos < 0 || pos >= 10) {
		std::cout << "ERROR getValue: Position out of bounds" << std::endl;
		returnValue = NOVALUE;
	} else {
		returnValue = m_value[pos];
	}

	std::cout << "Returning a value: " << returnValue << std::endl;
	return returnValue;
}

double CSetOfMeasurementValues::getAverage() {
	int NoOfValidValues = 0;
	double sum = 0, average;

	for(int i = 0; i < 10; i++) {
		if(m_value[i] != NOVALUE) {
			NoOfValidValues++;
			sum += m_value[i];
		}
	}

	average = sum/NoOfValidValues;

	return average;
}

double CSetOfMeasurementValues::getMax() {
	double max = NOVALUE;
	bool initialized = false;

	for(int i = 0; i < 10; i++) {
		if(!initialized && m_value[i] != NOVALUE) {
			max = m_value[i];
			initialized = true;
		} else if (m_value[i] > max && m_value[i] != NOVALUE) {
			max = m_value[i];
		}
	}

	return max;
}

double CSetOfMeasurementValues::getMin() {
	double min = NOVALUE;
	bool initialized = false;

	for(int i = 0; i < 10; i++) {
		if(!initialized && m_value[i] != NOVALUE) {
			min = m_value[i];
			initialized = true;
		} else if (m_value[i] < min && m_value[i] != NOVALUE) {
			min = m_value[i];
		}
	}

	return min;
}

void CSetOfMeasurementValues::printSingleValue(unsigned int pos) {
	std::cout << "\tValue[" << pos << "]: " << m_value[pos] << " ";
	switch(m_unit) {
	case A:
		std::cout << "Ampere";
		break;
	case V:
		std::cout << "Volt";
		break;
	case S:
		std::cout << "seconds";
		break;
	case W:
		std::cout << "Watt";
		break;
	case NONE:
		;
	}

	std::cout << std::endl;
}
