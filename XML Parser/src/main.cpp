/*
 * main.cpp
 *
 *  Created on: 04.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CNode.h"
#include "CElement.h"
#include "CText.h"
#include <iostream>

int main(void) {
	unsigned pos = 0;
	CElement doc;
	if (!doc.parseInput("<top>\n<nested>some data</nested>\n more data\n</top>", pos)) {
		std::cout << "Parsing failed at position " << pos << std::endl;
	} else {
		//doc.print(0);
	}

	return 0;
}
