

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CGRAPHICOBJECT.CPP
* Author          :
* Description     :
*
*
****************************************************************************/


//System Include Files
#include <iostream>

using namespace std;

//Own Include Files
#include "CGraphicObject.h"

//Method Implementations



CGraphicObject::CGraphicObject(std::string name, unsigned short noCoordinates)
{
	m_name =name;

	//CHeck for illegal size value 0
	if (noCoordinates > 0)
	{
		//Valid
		m_noCoordinates = noCoordinates;
	}
	else
	{
		//Invalid case
		m_noCoordinates = 1;
	}

	//Now all attributes have the correct value, we can use them
	m_pCoordinate = new CCoordinate[m_noCoordinates];

}

bool CGraphicObject::set(unsigned short index, unsigned short int x, unsigned short int y)
{
	if (index < m_noCoordinates)
	{
		//Valid range
		m_pCoordinate[index] = CCoordinate(x,y);
		return true;
	}
	else
	{
		cout << "ERROR in CGraphicObject::set index out of range" << endl;
		return false;

	}
}

bool CGraphicObject::set(unsigned short index, CCoordinate const& c)
{
	if (index < m_noCoordinates)
	{
		//Valid range
		m_pCoordinate[index] = c;
		return true;
	}
	else
	{
		cout << "ERROR in CGraphicObject::set index out of range" << endl;
		return false;

	}
}

void CGraphicObject::print()
{
	cout << endl << endl << "Print graphical object: " << m_name << endl;
	for (unsigned int i = 0; i < m_noCoordinates; i++)
	{
		m_pCoordinate[i].print();
	}
}

bool CGraphicObject::move(signed short dx, signed short dy)
{
	return false;
	//Will be implemented later
}

CGraphicObject& CGraphicObject::operator =(const CGraphicObject& origin)
{
	m_name = origin.m_name;
	m_noCoordinates = origin.m_noCoordinates;

	//Because object already exists, we have to delete the memory before allocating it again
	delete[] m_pCoordinate;

	m_pCoordinate = new CCoordinate[origin.m_noCoordinates];

	//Deep copy logic
	for (unsigned int i = 0; i < m_noCoordinates; i++)
	{
		m_pCoordinate[i] = origin.m_pCoordinate[i];
	}

	return *this;
}

std::string CGraphicObject::getName()
{
	return m_name;
}

CGraphicObject::~CGraphicObject()
{
	delete[] m_pCoordinate;
}
