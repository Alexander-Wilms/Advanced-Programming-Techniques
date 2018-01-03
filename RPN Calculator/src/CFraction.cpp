/*
 * CFraction.cpp
 *
 *  Created on: 03.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CFraction.h"
#include <iostream>

CFraction::CFraction(long numerator, long denominator) {
	m_numerator = numerator;

	if(denominator != 0) {
		m_denominator = denominator;
	} else {
		std::cout << "denominator may not be 0. Setting it to 1 instead." << std::endl;
		m_denominator = 1;
	}
}

void CFraction::set(long numerator, long denominator) {
	m_numerator = numerator;

	if(denominator != 0) {
		m_denominator = denominator;
	} else {
		std::cout << "denominator may not be 0. Keeping the old value." << std::endl;
	}
}

double CFraction::toDouble() {
	return (double) m_numerator/m_denominator;
}

void CFraction::print() {
	std::cout << "CFraction[m_numerator=" << m_numerator << "; m_denominator=" << m_denominator << "]" << std::endl;
}

//preincrement
CFraction& CFraction::operator ++() {
	m_numerator += m_denominator;
	shorten();
	return *this;
}

// postincrement
CFraction CFraction::operator ++(int input) {
	CFraction original(m_numerator, m_denominator);
	m_numerator += m_denominator;
	shorten();
	return original;
}

std::ostream& operator <<(std::ostream& out, const CFraction& f) {
	out << "(" << f.m_numerator << "/" << f.m_denominator << ")";
	return out;
}

CFraction CFraction::operator +(const CFraction& f) {
	long numerator = m_numerator*f.m_denominator + f.m_numerator * m_denominator;
	long denominator = m_denominator * f.m_denominator;
	CFraction result(numerator, denominator);
	result.shorten();
	return result;
}

CFraction CFraction::operator -(const CFraction& f) {
	long numerator = m_numerator*f.m_denominator - f.m_numerator * m_denominator;
	long denominator = m_denominator * f.m_denominator;
	CFraction result(numerator, denominator);
	result.shorten();
	return result;
}

CFraction CFraction::operator *(const CFraction& f) {
	long numerator = m_numerator*f.m_numerator;
	long denominator = m_denominator * f.m_denominator;
	CFraction result(numerator, denominator);
	result.shorten();
	return result;
}

CFraction CFraction::operator /(const CFraction& f) {
	long numerator = m_numerator*f.m_denominator;
	long denominator = m_denominator * f.m_numerator;
	CFraction result(numerator, denominator);
	result.shorten();
	return result;
}

void CFraction::shorten() {
	long greatestCommonDivisor;
	long a = m_numerator;
	long b = m_denominator;

	// non-recursive gcd algorithm
	// http://www.borismod.net/2008/10/non-recursive-implementation-of.html
	if (a < b) {
		a += b;
		b = a - b;
		a -= b;
	}

	if (b == 0) {
		greatestCommonDivisor = a;
	} else {

		while (a % b != 0) {
			a += b;
			b = a - b;
			a -= b;
			b %= a;
		}
		greatestCommonDivisor = b;
	}

	m_numerator /= greatestCommonDivisor;
	m_denominator /= greatestCommonDivisor;
}

bool operator== (const CFraction& l, const CFraction& r) {
	return l.m_numerator == r.m_numerator && l.m_denominator == r.m_denominator;
}
