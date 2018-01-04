/*
 * CElement.cpp
 *
 *  Created on: 05.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CElement.h"
#include "CText.h"
#include <iostream>

CElement::CElement() :
		CNode(ELEMENT) {
	m_contentNodes = 0;
}

CElement::~CElement() {
}

bool CElement::parseInput(const std::string& input,
		unsigned int& parsePosition) {
	std::cout << "parseInput()" << std::endl;
	bool startTag;


	std::cout << "Parse start tag and save tag name" << std::endl;
	parseStartOrEndTag(input, parsePosition, startTag, m_tag);

	while (parsePosition < input.size()) {
		m_tag = "";

		if (input.substr(parsePosition, 2) == "</") { // [looking at "</"]
			std::cout << "Parse end tag" << std::endl;
			parseStartOrEndTag(input, parsePosition, startTag, m_tag);
			std::cout << "parsing complete" << std::endl;
			return true;
		} else if (input.substr(parsePosition, 1) == "<") { // [looking at "<"]
			std::cout << "Create new CElement and save as child" << std::endl;
			CElement* childElement = new CElement();
			addToContentChildren((CNode*) childElement);
			std::cout << "Invoke parseInput() for newly created object" << std::endl;
			childElement->parseInput(input, parsePosition);
		} else {
			std::cout << "Create new CText and invoke parseInput for newly created object" << std::endl;
			CText* childText = new CText();
			addToContentChildren((CNode*) childText);
			childText->parseInput(input, parsePosition);
		}
	}

	return true;
}

// print all nodes recursively
void CElement::print(int indent) {
	if (m_contentNodes != 0) {
		for (int i = 0; i < m_contentNodes + 1; i++) {
			std::cout << m_content[i]->getNodeType() << std::endl;
			switch (m_content[i]->getNodeType()) {
			case ELEMENT:
				((CElement*) m_content)[i].print(indent);
				break;
			case TEXT:
				((CText*) m_content)[i].print(indent);
			}
		}
	} else {
		std::cout << "CElement[m_tag=\"" << m_tag << "\"]" << std::endl;
	}
}

node_t CElement::getNodeType() {
	return ELEMENT;
}

bool CElement::addToContentChildren(CNode* child) {
	if (m_contentNodes < 10) {
		m_content[m_contentNodes] = child;
		m_contentNodes++;
		return true;
	} else {
		return false;
	}
}

bool CElement::parseStartOrEndTag(const std::string& input,
		unsigned int& parsePosition, bool& isStartTag, std::string& tag) {
	if (input.substr(parsePosition, 1) == "<"
			&& input.substr(parsePosition + 1, 1) != "/") {
		// this is a start tag
		isStartTag = true;
		parsePosition++;
	} else if (input.substr(parsePosition, 1) == "<"
			&& input.substr(parsePosition + 1, 1) == "/") {
		// this is an end tag
		isStartTag = false;
		parsePosition += 2;
	}

	bool done = false;

	while (!done) {
		// check for closing bracket of tag
		if (input.substr(parsePosition, 1) != ">") {
			tag.append(input.substr(parsePosition, 1));
			parsePosition++;
		} else {
			done = true;
		}
	}

	if(isStartTag) {
		std::cout << "<";
	} else {
		std::cout << "</";
	}
	std::cout << tag << ">" << std::endl;

	parsePosition++;

	return true;
}
