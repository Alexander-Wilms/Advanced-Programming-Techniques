/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CDATABASE.CPP
* Author          :
* Description     :
*
*
****************************************************************************/


//System Include Files
#include <iostream>
using namespace std;


//Own Include Files
#include "CDatabase.h"

//Method Implementations



CDatabase::CDatabase(unsigned int size)
{
	//Todo: Range check to be added later
	m_size = size;
	m_nextFreeTriangle = 0;
	m_triangle = new CTriangle[m_size];

	//To be added later
	m_circle = 0;
	m_rectangle = 0;
}

void CDatabase::print()
{
	cout << "printing a database..." << endl;

	//Todo: m_next ... later
	for (unsigned int i = 0; i < m_size; i++)
	{
		cout << "Triangle no " << i << endl;
		m_triangle[i].print();
	}
}

bool CDatabase::addElement(const CTriangle& t)
{
	//CHeck if we can add another triangle
	if (m_nextFreeTriangle < m_size)
	{
		m_triangle[m_nextFreeTriangle++] = t;
		return true;
	}
	else
	{
		return false;
	}
}

CTriangle* CDatabase::getAdressOfTriangle(std::string name)
{
	for (unsigned int i = 0; i < m_nextFreeTriangle; i++)
	{
		if (name == m_triangle[i].getName())
		{
			return &m_triangle[i];
		}
	}

	return 0; //Errorcase, no triangle has been found
}
