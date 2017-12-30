

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CSCREEN.CPP
* Author          :
* Description     :
*
*
****************************************************************************/


//System Include Files
#include <iostream>
using namespace std;


//Own Include Files
#include "CScreen.h"
#include "CDatabase.h"
#include "CGraphicObject.h"

//Method Implementations

CScreen::CScreen(unsigned int size)
{
	m_size = size;
	m_nextFreeObject = 0;
	m_pDatabase = 0;

	m_pObject = new CGraphicObject* [m_size];

	for (unsigned int i = 0; i < m_size; i++)
	{
		m_pObject[i] = 0; // NULL
	}
}

CScreen::~CScreen()
{
	delete[] m_pObject;
}

void CScreen::print()
{
	cout << "Printing the tringles on the screen" << endl;
	for (unsigned int i = 0; i < m_nextFreeObject; i++)
	{
		if (m_pObject[i] != 0)
		{
			m_pObject[i]->print();
		}

	}
}



void CScreen::connect(CDatabase* db)
{
	m_pDatabase = db;
}

bool CScreen::addElement(std::string name)
{
	if (m_pDatabase == 0)
	{
		cout << "Error db not connected " << endl;
		return false;
	}


	if (m_nextFreeObject < m_size)
	{
		//Some free space...
		CGraphicObject* adressObject = m_pDatabase->getAdressOfObject(name);

		if (adressObject != 0)
		{
			m_pObject[m_nextFreeObject++] = adressObject;
			return true;
		}
		else
		{
			cout << "No Object found: " << name << endl;
		}
	}
	else
	{
		cout << "Not enough space to store triangle: " << name << endl;
	}

	return false;
}
