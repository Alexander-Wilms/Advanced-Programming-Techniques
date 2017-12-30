/*
 * CMatrix.h
 *
 *  Created on: 27.11.2017
 *      Author: Fromm
 */

#ifndef CMATRIX_H_
#define CMATRIX_H_

#include "Coordinate.h"

//Template template parameters including default types
template <template <class TCONTENT> class TDATA, class TCONTENT = int>
class CMatrix
{
private:
	TDATA<TCONTENT>* m_buffer;
public:
	CMatrix(unsigned int rows, unsigned int columns);
};

template<template<class TCONTENT> class TDATA, class TCONTENT>
inline CMatrix<TDATA, TCONTENT>::CMatrix(unsigned int rows, unsigned int columns)
{
	m_buffer = new TDATA<TCONTENT>[rows * columns];
}

#endif /* CMATRIX_H_ */
