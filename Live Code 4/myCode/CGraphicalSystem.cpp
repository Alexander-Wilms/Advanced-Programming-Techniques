

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


//Own Include Files
#include "CGraphicalSystem.h"

//Method Implementations



CGraphicalSystem::CGraphicalSystem()
{
	m_screen.connect(&m_database);


}

void CGraphicalSystem::print()
{
	//Just a testcase
	CTriangle t1("t1", CCoordinate(11,11), CCoordinate(22,22), CCoordinate(33,33));
	CTriangle t2("t2", CCoordinate(11,11), CCoordinate(22,22), CCoordinate(33,33));

	m_database.addElement(t1);
	m_database.addElement(t2);

	m_screen.addElement("t1");
	m_screen.addElement("t3");

	m_screen.print();
}
