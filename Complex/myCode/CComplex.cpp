/*
 * CComplex.cpp
 *
 *  Created on: 22.10.2017
 *      Author: Fabian Alexander Wilms
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

	std::cout << "CComplex object generated at " << this << std::endl;
	std::cout << "Value = ";
	print();
}

/**
 * copy constructor
 */
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

/**
 * Pre-increment operator
 */
CComplex CComplex::operator ++() {
	m_real++;
	m_imaginary++;
	return *this;
}

/**
 * post-increment operator
 */
CComplex CComplex::operator ++(int real) {
	CComplex oldValue(*this);
	m_real++;
	m_imaginary++;
	return oldValue;
}

CComplex CComplex::operator+(const CComplex& c) {
	float real, imaginary;
	real = m_real + c.m_real;
	imaginary = m_imaginary + c.m_imaginary;
	return CComplex(real, imaginary);
}

CComplex CComplex::operator-(const CComplex& c) {
	float real, imaginary;
	real = m_real - c.m_real;
	imaginary = m_imaginary - c.m_imaginary;
	return CComplex(real, imaginary);
}

CComplex CComplex::operator*(const CComplex& c) {
	float real, imaginary;
	real = m_real * c.m_real - m_imaginary * c.m_imaginary;
	imaginary = m_real * c.m_imaginary + m_imaginary * c.m_real;
	return CComplex(real, imaginary);
}

CComplex CComplex::operator/(const CComplex& c) {
	float real, imaginary;
	// http://mathworld.wolfram.com/ComplexDivision.html
	real = (m_real * c.m_real + m_imaginary * c.m_imaginary)/(c.m_real * c.m_real + c.m_imaginary * c.m_imaginary);
	imaginary = (m_imaginary * c.m_real - m_real * c.m_imaginary)/(c.m_real * c.m_real + c.m_imaginary * c.m_imaginary);
	return CComplex(real, imaginary);
}

std::ostream& operator <<(std::ostream& out, CComplex& c) {
	out << c.m_real;

	if(c.m_imaginary > 0) {
		 out << " + i" << c.m_imaginary;
	} else if(c.m_imaginary < 0) {
		out << " - i" << abs(c.m_imaginary);
	} else if(c.m_imaginary == 0) {
		// print nothing else
	}
	return out;
}
