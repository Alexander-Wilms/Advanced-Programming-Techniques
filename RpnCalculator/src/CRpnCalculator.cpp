/*
 * CRpnCalculator.cpp
 *
 *  Created on: 03.11.2017
 *      Author: awilms
 */

#include "CRpnCalculator.h"

CRpnCalculator::CRpnCalculator() : stack(10){
}

CRpnCalculator::~CRpnCalculator() {
	// TODO Auto-generated destructor stub
}

bool CRpnCalculator::pushValue(const CFraction& data) {
	return stack.push(data);
}

bool CRpnCalculator::popResult(CFraction& data) {
	return stack.pop(data);
}

void CRpnCalculator::add() {
	CFraction operand1, operand2;
	stack.pop(operand1);
	stack.pop(operand2);
	stack.push(operand1 + operand2);
}

void CRpnCalculator::substract() {
	CFraction operand1, operand2;
	// pay attention to the operator order!
	stack.pop(operand2);
	stack.pop(operand1);
	stack.push(operand1 - operand2);
}

void CRpnCalculator::multiply() {
	CFraction operand1, operand2;
	stack.pop(operand1);
	stack.pop(operand2);
	stack.push(operand1 * operand2);
}

void CRpnCalculator::divide() {
	CFraction operand1, operand2;
	// pay attention to the operator order!
	stack.pop(operand2);
	stack.pop(operand1);
	stack.push(operand1 / operand2);
}
