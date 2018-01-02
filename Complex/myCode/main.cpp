/*
 * main.cpp
 *
 *  Created on: 22.10.2017
 *      Author: awilms
 */

#include <iostream>
#include "CComplex.h"

int main(void) {
	std::cout << "Some Objects" << std::endl
			  << "============" << std::endl;
	CComplex c1;
	CComplex c2(1,3);
	CComplex c3(4);
	CComplex c4(c3);

	std::cout << "Some Calculations" << std::endl
			  << "=================" << std::endl;

	CComplex c5(1,2);
	CComplex tmp;
	std::cout << "c5: " << c5 << std::endl;

	tmp = c5 + 2;
	std::cout << "c5 + 2: " << tmp << std::endl;

	tmp = c5 - 2;
	std::cout << "c5 - 2: " << tmp << std::endl;

	tmp = c5 * 2;
	std::cout << "c5 * 2: " << tmp << std::endl;

	tmp = c5 / 2;
	std::cout << "c5 / 2: " << tmp << std::endl;

	CComplex c6(3,4);
	std::cout << "c6: " << c6 << std::endl;

	tmp = c5 + c6;
	std::cout << "c5 + c6: " << tmp << std::endl;

	tmp = c5 - c6;
	std::cout << "c5 - c6: " << tmp << std::endl;

	tmp = c5 * c6;
	std::cout << "c5 * c6: " << tmp << std::endl;

	tmp = c5 / c6;
	std::cout << "c5 / c6: " << tmp << std::endl;

	std::cout << "Post and Pre-Increment" << std::endl
			  << "======================" << std::endl;
	int a = 0, b;

	std::cout << "++a = " << ++a;
	a = 0;
	b = ++a;
	std::cout << "; b=++a = " << b << std::endl;

	std::cout << "a++ = " << a++;
	a = 0;
	b=a++;
	std::cout << "; b=a++ = " << b << std::endl;

	CComplex c;
	CComplex d;

	d = ++c;
	std::cout << "++c = " << c << "; d=++c = " << d << std::endl;

	d.set(0,0);
	d = c++;
	std::cout << "c++ = " << c << "; d=++c = " << d << std::endl;

	return 0;
}
