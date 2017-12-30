/*
 * Coordinate.h
 *
 *  Created on: 27.11.2017
 *      Author: Fromm
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>

template <class T>
class Coordinate
{
private:
	T m_x;
	T m_y;
public:
	Coordinate(T x = T(), T y = T());

	bool operator>(Coordinate const& rop);

	void print();


	friend std::ostream& operator << (std::ostream& out, Coordinate<T> const& rop)
	{
		out << "(" << rop.m_x << ", " << rop.m_y << ")";
		return out;
	}
};

template<class T>
Coordinate<T>::Coordinate(T x, T y)
{
	// TODO Auto-generated constructor stub

	m_x = x;
	m_y = y;
}

template<class T>
bool Coordinate<T>::operator >(const Coordinate& rop)
{
	return ((m_x * m_x + m_y * m_y) > (rop.m_x * rop.m_x + rop.m_y * rop.m_y));
}

template<class T>
void Coordinate<T>::print()
{
	std::cout << "(" << m_x << ", " << m_y << ")";

	//a = 0;
	//This is no c++ code at all
}

/*
template <class U>
std::ostream& operator << (std::ostream& out, Coordinate<T> const& rop)
{
	out << "(" << rop.m_x << ", " << rop.m_y << ")";
	return out;
}
*/

#endif /* COORDINATE_H_ */
