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
	bool done = false;
	bool startTag;

	// Parse start tag and save tag name
	//std::cout << "Now comes a start tag" << std::endl;
	//parseStartOrEndTag(input, parsePosition, startTag, m_tag);
	while (parsePosition < input.size()) {
		if (input.substr(parsePosition, 2) == "</") { // Looking at "</"?
			std::cout << "Now comes an end tag" << std::endl;
			parseStartOrEndTag(input, parsePosition, startTag, m_tag);
		} else if (input.substr(parsePosition, 1) == "<") { // Looking at "<"?
			std::cout << "Now comes a CElement child" << std::endl;
			CElement childElement;
			addToContentChildren((CNode*) &childElement);
			childElement.parseInput(input, parsePosition);
//		parseInput(input, parsePosition);
		} else { // Create new CText and invoke parseInput for newly created object
			std::cout << "Now comes a CText child" << std::endl;
			CText childText;
			addToContentChildren((CNode*) &childText);
			childText.parseInput(input, parsePosition);
			//	parseInput(input, parsePosition);
		}
	}

	return true;
}

// print all nodes recursively
void CElement::print(int indent) {

	std::cout << "m_contentNodes: " << m_contentNodes << std::endl;
	std::cout << "  ";
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
		isStartTag = true;
		parsePosition++;
	} else if (input.substr(parsePosition, 1) == "<"
			&& input.substr(parsePosition + 1, 1) == "/") {
		isStartTag = false;
		parsePosition += 2;
	}

	bool done = false;

	while (!done) {
		if (input.substr(parsePosition, 1) != ">") {
			tag.append(input.substr(parsePosition, 1));
			parsePosition++;
		} else {
			done = true;
		}
	}

	parsePosition++;

	return true;
}
