/*
 * CRpnCalculator.h
 *
 *  Created on: 03.11.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef SRC_CRPNCALCULATOR_H_
#define SRC_CRPNCALCULATOR_H_

#include "CLifoBuffer.h"

class CRpnCalculator {
public:
	CRpnCalculator();
	~CRpnCalculator();
	bool pushValue(const CFraction& data);
	bool popResult(CFraction& data);
	void add();
	void substract();
	void multiply();
	void divide();
private:
	CLifoBuffer stack;
};

#endif /* SRC_CRPNCALCULATOR_H_ */
