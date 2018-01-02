/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        :
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CSTRINGIO_H
#define CSTRINGIO_H



#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

namespace myIO
{

/**
 * Variant 1: CString as a specialisation of string, providing additional features. 
 */
class CString : public std::string {

public:
	/**
     * Constructor, passes the value on to the string class 
     */

	CString(std::string s="");

	/**
     * Returns a substring without leading and trailing characters, defined by the parameter t. 
	 * t usually is a whitespace character. 
     */
	std::string trim(const std::string& t = " ");

    /**
     * Returns only digit characters of the string 
     */	
	std::string getDigits();

	
    /**
     * Gets all digits from a string and returns it into an integer. 
     */
	int string2Int();
    
	/**
     * Turns an integer into a string
     */
	void int2String(int value);

    /**
     * Returns true if the substring exists 
     */
	bool contains(const std::string& sub);

    /**
     * Returns the left substring until the character provided by the parameter t. 
	 * Original string contains the right hand substring. 
     */
	std::string cutLeft(const std::string& t = " ");

};


/**
 * Variant2: C-like functions. As no member attribute access is required, the functions
 * are declared static. 
 */
class CString2
{
public:
    /**
     * Returns a substring without leading and trailing characters, defined by the parameter t. 
	 * t usually is a whitespace character. 
     */
	static std::string trim(const std::string& source,
							 const std::string& t = " ");

    /**
     * Returns only digit characters of the string 
     */
	static std::string getDigits(const std::string& source);

    /**
     * Gets all digits from a string and returns it into an integer. 
     */
	static int string2Int(const std::string& source);
   
	/**
     * Turns an integer into a string
     */
	static std::string int2String(int value);

    /**
     * Returns true if the substring exists 
     */
	static bool contains(const std::string& source, const std::string& sub);

    /**
     * Returns the left substring until the character provided by the parameter t. 
	 * Original string contains the right hand substring. 
     */
	static std::string cutLeft(std::string& source,
			                     const std::string& t = " ");

};
/********************
**  CLASS END
*********************/
}; //namespace
#endif /* CSTRINGIO_H */
