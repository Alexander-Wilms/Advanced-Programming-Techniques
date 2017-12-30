/*
 * BasicTest.h
 *
 *  Created on: 05.09.2012
 *      Author: mnl
 */

#ifndef BASICTEST_H_
#define BASICTEST_H_

#include "CAddressDB.h"

namespace Test {

class BasicTest {
private:
	APT::CAddressDB* m_db;
    int menu();
    /**
     * Get recordset from keyboard
     */
    void appendFromKeyboard();


public:
    /**
     * Test loop
     */
	void run();
};

} /* namespace APT */
#endif /* BASICTEST_H_ */
