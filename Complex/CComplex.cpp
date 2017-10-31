/*
 * CComplex.cpp
 *
 *  Created on: 22.10.2017
 *      Author: awilms
 */

#include "CComplex.h"
#include <cmath>
#include <iostream>

CComplex::CComplex(float real, float imaginary) {
	if(-100 < real && real < 100 && -100 < imaginary && imaginary < 100) {
		m_real = real;
		m_imaginary = imaginary;
	} else {
		m_real = 0;
		m_imaginary = 0;
	}

	std::cout << "CComplex object generated at " << this << std:endl;
	std::cout << "Value = ";
	print();
}

CComplex::CComplex(const CComplex& c) {
	if(-100 < c.m_real && c.m_real < 100 && -100 < c.m_imaginary && c.m_imaginary < 100) {
		m_real = c.m_real;
		m_imaginary = c.m_imaginary;
	} else {
		m_real = 0;
		m_imaginary = 0;
	}
}

void CComplex::set(float real, float imaginary) {
	if(-100 < real && real < 100 && -100 < imaginary && imaginary < 100) {
		m_real = real;
		m_imaginary = imaginary;
	} else {
		m_real = 0;
		m_imaginary = 0;
	}
}

float CComplex::abs() {
	return sqrt(m_real*m_real+m_imaginary*m_imaginary);
}

void CComplex::print() {
	std::cout << m_real << " + i" << m_imaginary << std::endl;
}

CComplex& CComplex::operator ++() {
}

CComplex CComplex::operator ++(int int1) {
}
