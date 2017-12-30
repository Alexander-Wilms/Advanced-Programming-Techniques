

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
#include "CTriangle.h"

//Method Implementations

void CScreen::print()
{
	cout << "Printing the tringles on the screen" << endl;
	for (unsigned int i = 0; i < m_nextFreeTriangle; i++)
	{
		if (m_pTriangle[i] != 0)
		{
			m_pTriangle[i]->print();
		}

	}
}

CScreen::CScreen(unsigned int size)
{
	m_size = size;
	m_nextFreeTriangle = 0;
	m_pDatabase = 0;

	m_pTriangle = new CTriangle* [m_size];

	for (unsigned int i = 0; i < m_size; i++)
	{
		m_pTriangle[i] = 0; // NULL
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

	if (m_nextFreeTriangle < m_size)
	{
		//Some free space...
		CTriangle* adressTriangle = m_pDatabase->getAdressOfTriangle(name);

		if (adressTriangle != 0)
		{
			m_pTriangle[m_nextFreeTriangle++] = adressTriangle;
			return true;
		}
	}

	return false;
}
