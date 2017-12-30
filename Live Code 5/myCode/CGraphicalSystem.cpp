

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CGRAPHICALSYSTEM.CPP
* Author          :
* Description     :
*
*
****************************************************************************/


//System Include Files
#include <iostream>
using namespace std;

//Own Include Files
#include "CGraphicalSystem.h"

//Method Implementations



CGraphicalSystem::CGraphicalSystem()
{
	m_screen.connect(&m_database);


}

void CGraphicalSystem::print()
{


	m_database.addElement(CIRCLE, "cc1");
	m_database.addElement(CIRCLE, "cc2");
	m_database.addElement(TRIANGLE, "tt1");


	//m_database.print();

	cout << "Printing a screen" << endl;

	//Note: the name has been changed by the constructor of the triangle
	m_screen.addElement("cc1");
	m_screen.addElement("tt1");
	m_screen.addElement("t3");

	m_screen.print();
}
