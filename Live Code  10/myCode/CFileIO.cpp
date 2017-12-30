/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/

// System Headers


#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Own Headers
#include "CFileIO.h"

namespace myIO {

// Implementation
CFileIO::CFileIO()
{
	m_dir = UNDEF;
	m_file.clear();
}

CFileIO::CFileIO(string fileName, t_direction dir)
{
	if (!openFile(fileName, dir))
	{
		cout << "Error opening file" << endl;
	}
}

CFileIO::~CFileIO()
{
	closeFile();
}


bool CFileIO::openFile(string fileName, t_direction dir)
{
	switch (dir)
	{
	case IN : // Open the file
		m_file.open(fileName.c_str(),fstream::in);
		if (!m_file.is_open()) {
			return false;
		}
		// Go to the first position
		m_file.seekg(0, ios::beg);
		break;
	case OUT: m_file.open(fileName.c_str(),fstream::out);
		m_file.seekp(0, ios::beg);
		break;
	default:
			break;
	}

	m_dir = dir;

	//Dummy, may be used later on
	return true;
}

bool CFileIO::readLine(string& s)
{
	//Read until the next whitespace
	if ((m_file.is_open()) && (!m_file.eof()))
	{
		//m_file >> s;
		getline(m_file,s); //Better
		return true;
	}
	else
	{
		return false;
	}
}



bool CFileIO::writeLine(string s)
{
	if (m_file.is_open())
	{
		//Write a single line
		m_file << s << endl;
		return true;
	}
	else
	{
		return false;
	}
}


bool CFileIO::closeFile()
{
	//Clode the requested file in case they have not been closed before
	if (m_file.is_open()) m_file.close();
	
	//Dummy, may be used later on
	return true;
}

} // namespace
