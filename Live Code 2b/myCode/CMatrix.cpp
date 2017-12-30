

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CMATRIX.CPP
* Author          :
* Description     :
*
*
****************************************************************************/


//System Include Files
#include <iostream>
using namespace std;

//Own Include Files
#include "CMatrix.h"

//Method Implementations

//This value will be compared with an 16 bit unsigend value, i.e. range: 0...65xyz
#define MAXMATRIXDIMENSION 100

CMatrix::CMatrix(unsigned short noRows, unsigned short noColumns,
		matrixInit_t init)
{
	//Checked and corrected the parameters
	if (noRows == 0 || noRows > MAXMATRIXDIMENSION)
	{
		noRows = 1;
	}

	if (noColumns == 0 || noColumns > MAXMATRIXDIMENSION)
	{
		noColumns = 1;
	}

	//We are now sure that the values are correct, no matter what has happened
	m_noRows = noRows;
	m_noColumns = noColumns;

	m_pData = new matrixdata_t[m_noRows * m_noColumns];

	switch (init)
	{
	case ZERO :
		for (unsigned int i = 0; i < m_noColumns * m_noRows; i++)
		{
			m_pData[i] = 0;
		}
		break;
	case ONE :
		for (unsigned int i = 0; i < m_noColumns * m_noRows; i++)
		{
			m_pData[i] = 1;
		}
		break;
	case INDEX :
		for (unsigned int i = 0; i < m_noColumns * m_noRows; i++)
		{
			m_pData[i] = i;
		}
		break;
	case UNIT:
		for (unsigned int i = 0; i < m_noColumns * m_noRows; i++)
		{
			m_pData[i] = 0;
		}
		if (m_noRows == m_noColumns)
		{
			for (unsigned int i = 0; i < m_noColumns; i++)
			{
				m_pData[getIndex(i,i)] = 1;
			}
		}
		else
		{
			cout << "Check your math...." << endl;
		}
		//TODO: Here we have to turn our brain on
		break;
	default:
		cout << "ERROR in Matrix: oops, this shpould not have happened" << endl;
		break;

	}

}

CMatrix::~CMatrix()
{
	delete[] m_pData;
}

void CMatrix::print()
{
	for (int r = 0; r < m_noRows; r++)
	{
		for (int c = 0; c < m_noColumns; c++)
		{
			cout << m_pData[getIndex(r,c)] << " ";
		}
		cout << endl;
	}

}

unsigned int CMatrix::getIndex(unsigned short row, unsigned short column)
{
	return row * m_noColumns + column;
}
