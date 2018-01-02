/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        :
* Author          :
* Description     :
*
*
****************************************************************************/


#include "CString.h"
#include "stdlib.h"
using namespace std;

namespace myIO {

CString::CString(string s) : string(s)
{
}

string CString::trim(const string& t)
{
	string content = *this;
	content.erase( content.find_last_not_of(t) + 1);
	content.erase( 0, content.find_first_not_of(t));
	return content;
}

string CString::getDigits()
{
	string str = *this;
	string result = "";
	
	for (size_t i=0; i<str.length();i++)
	{
		char d = str[i];
		if (d >= '0' && d <= '9')
		{
			result += d;
		}
	}
	
	return result;
}
	
int CString::string2Int()
{
	string str = this->getDigits();
	//The good old fashioned atoi routine
	return atoi(str.c_str());
}

void CString::int2String(int value)
{	
	char str[10];
	//The good old fashioned sprintf routine
	sprintf(str,"%d",value);
	*this = CString(string(str));
}


bool CString::contains(const string& sub)
{
	return this->find(sub)!=string::npos;
}

string CString::cutLeft(const string& t)
{
	string str = *this;
	size_t pos = this->find(t);
	if (pos != string::npos)
	{
		str = str.substr(0,pos);
		this->erase(0,pos+1);
	}
	
	return str;
}


/**
 * Variant2: C-like functions. As no member attribute access is required, the functions are declared static. 
 */
string CString2::trim(const string& source, const string& t)
{	
	string result = source;
	result.erase( result.find_last_not_of(t) + 1);
	result.erase( 0, result.find_first_not_of(t));
	return result;
}

/**
 * Returns only digit characters of the string 
 */
string CString2::getDigits(const string& source)
{
	string result = "";
	
	for (size_t i=0; i<source.length();i++)
	{
		char d = source[i];
		if (d >= '0' && d <= '9')
		{
			result += d;
		}
	}

	return result;
}

/**
 * Gets all digits from a string and returns it into an integer. 
 */
int CString2::string2Int(const string& source)
{
	//Use stringstream to convert the data

	int digits = 0;
	istringstream instr;
	
	//Strip all none digits from the input string
	string onlydigits = getDigits(source);
	
	//Convert the string into a stream
	instr.str(onlydigits);
	
	//Store the stream content in an integer variable
	instr >> digits;
	
	return digits;
}

string CString2::int2String(int value)
{
	//Use a stringstream to convert a int into a string;

	stringstream iostr;
	string str;
	
	// Read the value into the outstream
	iostr << value;
	iostr >> str;

	return str;
}

/**
 * Returns true if the substring exists 
 */
bool CString2::contains(const string& source, const string& sub)
{
	return (source.find(sub)!=string::npos);
}

/**
 * Returns the left substring until the character provided by the parameter t. Original string contains the right hand substring. 
 */
string CString2::cutLeft(string& source, const string& t)
{
	string str = source;
	size_t pos = str.find(t);
	if (pos != string::npos)
	{
		str = str.substr(0,pos);
		source.erase(0,pos+1);
	}
	
	return str;
}

} // namespace
