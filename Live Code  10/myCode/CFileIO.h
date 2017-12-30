/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        :
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CFILEIO_H
#define CFILEIO_H

#include <string>
#include <fstream>


namespace myIO
{


enum t_direction{IN, OUT, UNDEF};


/**
 * CFileIO: Provides some basic textfile input and output operations. Shows the usage of streams in this context. 
 */
class CFileIO {
private:

	t_direction m_dir;
	std::fstream m_file;

public:

	CFileIO();

	CFileIO(std::string fileName, t_direction dir);

	~CFileIO();


    bool closeFile();

    bool openFile(std::string fileName, t_direction dir);

    bool writeLine(std::string s);

    bool readLine(std::string& s);
};
/********************
**  CLASS END
*********************/
}; //namespace
#endif /* CFILEIO_H */
