/*
 * CText.cpp
 *
 *  Created on: 04.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CText.h"
#include <iostream>

CText::CText() : CNode(TEXT) {
}

std::string CText::getText() {
	return m_text;
}

void CText::setText(std::string text) {
	m_text = text;
}

bool CText::parseInput(const std::string& input, unsigned int& parsePosition) {

	bool done = false;
	while(!done) {
		if(input.substr(parsePosition, 1) != "<") {
			m_text.append(input.substr(parsePosition, 1));
			parsePosition++;
		} else {
			done = true;
			return true;
		}
	}
	std::cout << "Parsed text: " << m_text << std::endl;
	return false;
}

void CText::print(int indent) {
	std::cout << "CText[m_text=\"" << m_text << "\"]" << std::endl;
}

node_t CText::getNodeType() {
	return TEXT;
}
