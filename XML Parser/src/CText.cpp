/*
 * CText.cpp
 *
 *  Created on: 04.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CText.h"
#include <iostream>
#include <regex>

//#define DEBUG

CText::CText() : CNode(TEXT) {
}

std::string CText::getText() {
	return m_text;
}

void CText::setText(std::string text) {
	m_text = text;
}

bool CText::parseInput(const std::string& input, unsigned int& parsePosition) {
#ifdef DEBUG
	std::cout << "parsing: " << input.substr(parsePosition)<< std::endl;
#endif
	bool done = false;

	while(!done && parsePosition < input.size()) {
		if(input.substr(parsePosition, 1) != "<") {
			m_text.append(input.substr(parsePosition, 1));
			parsePosition++;
		} else {
			done = true;
			return true;
		}
	}

	return false;
}

void CText::print(int indent) {
	std::string output = m_text;
	std::string indentiationString = "\n";
	std::string replacementString = "";

	for(int i = 0; i < indent; i++) {
		std::cout << "\t";
		indentiationString += "\t";
	}

	// if m_text contains newlines, indent them as well
	if(m_text.find("\n") != std::string::npos) {
		output.replace(output.find("\n"), 1, indentiationString);
	}

	std::cout << "CText[m_text=\"" << output << "\"]" << std::endl;
}

node_t CText::getNodeType() {
	return TEXT;
}

CText::~CText() {
}
