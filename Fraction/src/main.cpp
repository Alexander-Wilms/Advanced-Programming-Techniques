//============================================================================
// Name        : Fraction.cpp
// Author      : Fabian Alexander Wilms
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "CFraction.h"
#include <iostream>
using namespace std;

int main() {
	CFraction f1;
	CFraction f2(1,3);
	CFraction f3(24, 3);

	f1.print();
	f2.print();
	f3.print();

	std::cout << f2.toDouble() << std::endl;

	CFraction f4(1,10);
	CFraction f5(4,10);

	CFraction tmp;

	tmp = f4 + f5;
	std::cout << "f4 + f5: " << tmp << std::endl;

	tmp = f4 - f5;
	std::cout << "f4 - f5: " << tmp << std::endl;

	tmp = f4 * f5;
	std::cout << "f4 * f5: " << tmp << std::endl;

	tmp = f4 / f5;
	std::cout << "f4 / f5: " << tmp << std::endl;

	CFraction f(1,3);
	CFraction g;
	g = ++f;
	std::cout << "++f == " << f << "; (g=++f) == " << g << std::endl;
	f.set(1,3);
	g = f++;
	std::cout << "f++ == " << f << "; (g=f++) == " << g << std::endl;

	return 0;
}
