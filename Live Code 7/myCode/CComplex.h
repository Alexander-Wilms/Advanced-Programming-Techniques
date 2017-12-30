/*
 * CComplex.h
 *
 *  Created on: 20.11.2017
 *      Author: Fromm
 */

#ifndef CCOMPLEX_H_
#define CCOMPLEX_H_



#include <ostream>

class CComplex
{

	//friend functions may be placed anywhere, but semantically belong to the method block
	friend CComplex operator+ (float lop, CComplex const& rop);

private:
	float m_r;
	float m_i;
public:

	enum complex_t{ZERO, ONE};

	explicit CComplex(float r = 0, float i = 0);
	CComplex(complex_t init);

	//Our first overloaded operator
	//Return value as defined by the operation
	//Left hand operand : this
	//Right hand operand : parameter
	CComplex operator+(CComplex const& rop);

	//ostream operator
	friend std::ostream& operator<<(std::ostream& out, CComplex const& rop);


	//Some more complex operators
	CComplex& operator=(CComplex const& rop);

	CComplex& operator+=(float rop);




};

//CComplex operator+ (float lop, CComplex const& rop);

#endif /* CCOMPLEX_H_ */
