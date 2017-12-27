/*
 * CJsonScanner.h
 *
 *  Created on: 10.12.2015
 *      Author: mnl
 */

#ifndef MYCODE_CJSONSCANNER_H_
#define MYCODE_CJSONSCANNER_H_

#include <string>

#ifndef yyFlexLexer
#define yyFlexLexer jsonFlexLexer
#include "FlexLexer.h"
#endif

#include "CJsonToken.h"

namespace APT {

class CJsonScanner : private jsonFlexLexer {

private:

    /**
     * @link aggregationByValue 
     */
	CJsonToken* token;

    /** @link dependency */
    /*# CJsonToken lnkCJsonToken; */

	int yylex();

public:

	/**
	 * Create a new scanner that reads the given input stream.
	 */
	CJsonScanner(std::istream& input);

	/**
	 * Frees all allocated resources.
	 */
	~CJsonScanner();

	/**
	 * Returns the next token from the input. The pointer returned points
	 * to an object managed by this class. It is only valid until the next
	 * invocation of the method.
	 *
	 * If the input is exhausted, the method returns 0.
	 */
	CJsonToken* nextToken();

	/**
	 * Return the line number of the input where last token (returned
	 * by nextToken()) was found.
	 */
	int scannedLine();
};

} /* namespace APT */

#endif /* MYCODE_CJSONSCANNER_H_ */
