/*
 * CComplex.cpp
 *
 *  Created on: 20.11.2017
 *      Author: Fromm
 */

#include "CComplex.h"

#include <iostream>
using namespace std;


CComplex::CComplex(float r, float i)
{
	m_r = r;
	m_i = i;
}

CComplex::CComplex(complex_t init)
{
	switch (init)
	{
	case ZERO : m_r = 0; m_i = 0; break;
	case ONE : m_r = 1; m_i = 1; break;
	default :;
	}
}

CComplex CComplex::operator +(const CComplex& rop)
{
	CComplex result;

	//This is lop
	result.m_r = this->m_r + rop.m_r;
	result.m_i = this->m_i + rop.m_i;

	return result;
}

CComplex operator+ (float lop, CComplex const& rop)
{
	CComplex result;

	//result = CComplex(lop) + rop;
	result.m_r = lop + rop.m_r;
	result.m_i = rop.m_i;

	return result;

}

std::ostream& operator<<(std::ostream& out, CComplex const& rop)
{
	out << rop.m_r << " +i " << rop.m_i;
	return out;
}


//SLightly an overkill, because the compiler will create default assignemt as bytewise copy
//Mandatory for objects requiring special assignemnt behaviour, e.g. dynamic memory
CComplex& CComplex::operator =(const CComplex& rop)
{
	//lop is this
	this->m_r = rop.m_r;
	this->m_i =rop.m_i;

	return *this;
}

CComplex& CComplex::operator +=(float rop)
{
	(*this) = (*this) + CComplex(rop);
	return *this;
}
