/*
 * CComplex.h
 *
 *  Created on: 22.10.2017
 *      Author: awilms
 */

#ifndef CCOMPLEX_H_
#define CCOMPLEX_H_

#include <iostream>

class CComplex {
public:
	CComplex(float real = 0, float imaginary = 0);
	CComplex(CComplex const& c);
	void set(float real, float imaginary);
	float abs();
	void print();
	CComplex operator++();
	CComplex operator++(int real);
	CComplex operator+(const CComplex& c);
	CComplex operator-(const CComplex& c);
	CComplex operator*(const CComplex& c);
	CComplex operator/(const CComplex& c);
	friend std::ostream& operator <<(std::ostream& out, CComplex& c);

private:
	float m_real;
	float m_imaginary;
};

#endif /* CCOMPLEX_H_ */
