/*
 * CFraction.h
 *
 *  Created on: 03.11.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CFRACTION_H_
#define CFRACTION_H_

#include <iostream>

class CFraction {
public:
	CFraction(long numerator = 0, long denominator = 1);
	void set(long numerator, long denominator);
	double toDouble();
	void print();
	CFraction& operator ++();
	CFraction operator ++(int input);
	friend std::ostream& operator<< (std::ostream& out, const CFraction& f);
	friend bool operator== (const CFraction& l, const CFraction& r);
	CFraction operator+ (const CFraction& f);
	CFraction operator- (const CFraction& f);
	CFraction operator* (const CFraction& f);
	CFraction operator/ (const CFraction& f);
private:
	long m_numerator;
	long m_denominator;
	void shorten();
};

#endif /* CFRACTION_H_ */
