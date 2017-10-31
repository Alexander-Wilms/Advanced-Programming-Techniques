/*
 * main.cpp
 *
 *  Created on: 22.10.2017
 *      Author: awilms
 */

#include <iostream>
#include "CComplex.h"

int main(void) {
	CComplex c1;
	CComplex c2(1,3);
	CComplex c3(4);
	CComplex c4(c3);

	return 0;
}
