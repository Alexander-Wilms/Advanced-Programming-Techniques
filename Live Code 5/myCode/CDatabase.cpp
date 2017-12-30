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

#include "CCircle.h"
#include "CTriangle.h"
#include "CRectangle.h"


//Method Implementations



CDatabase::CDatabase(unsigned int size)
{
	//Todo: Range check to be added later
	m_size = size;
	m_nextFreeObject = 0;
	m_pObject = new CGraphicObject*[m_size];

	for (unsigned int i = 0; i < m_size; i++)
	{
		//Setting the pointers to invlaid == 0
		m_pObject[i] = 0;
	}
}

CDatabase::~CDatabase()
{
	for (unsigned int i = 0; i < m_nextFreeObject; i++)
	{
		if (m_pObject[i] != 0)
		{
			//We have an object, thus we delete it
			delete m_pObject[i];
			m_pObject[i] = 0;
		}
	}
	delete[] m_pObject;
}

void CDatabase::print()
{
	cout << "printing a database..." << endl;

	//Todo: m_next ... later
	for (unsigned int i = 0; i < m_nextFreeObject; i++)
	{
		cout << endl << "Object no " << i << endl;

		if (m_pObject[i] != 0)
		{
			m_pObject[i]->print();
		}

	}
}



CGraphicObject* CDatabase::getAdressOfObject(std::string name)
{


	for (unsigned int i = 0; i < m_nextFreeObject; i++)
	{
		if (m_pObject[i] != 0)
		{
			if (name == m_pObject[i]->getName())
			{
				return m_pObject[i];
			}
		}
	}


	return 0; //Errorcase, no triangle has been found
}



bool CDatabase::addElement(object_t type, string name)
{
	//CHeck if we can add another object
	if (m_nextFreeObject < m_size)
	{
		switch (type)
		{
		case CIRCLE : m_pObject[m_nextFreeObject++] = new CCircle(name); break;
		case TRIANGLE : m_pObject[m_nextFreeObject++] = new CTriangle(name); break;
		case RECTANGLE : m_pObject[m_nextFreeObject++] = new CRectangle(name); break;
		default: cout << "ERROR, you forgot to add this type in addElement" << endl;

		}

		return true;
	}
	else
	{
		return false;
	}
}


