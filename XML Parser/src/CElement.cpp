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
CNode(ELEMENT),
m_tag(""),
m_contentNodes(0) {
	m_content = new CNode*[10];
}

CElement::~CElement() {
	// first recursively call the destructors of all children
	for(int i = 0; i < m_contentNodes; i++) {
		delete m_content[i];
	}
	delete[] m_content;
}

bool CElement::parseInput(const std::string& input, unsigned int& parsePosition) {
	bool startTag;

#ifdef DEBUG
	std::cout << "Parse start tag and save tag name" << std::endl;
#endif
	if(!parseStartOrEndTag(input, parsePosition, startTag, m_tag)) {
		// parsing start or end tag failed
		return false;
	}

	while (parsePosition < input.size()) {
		m_tag = "";

		if (input.substr(parsePosition, 2) == "</") { // [looking at "</"]
#ifdef DEBUG
			std::cout << "Parse end tag" << std::endl;
#endif
			if(!parseStartOrEndTag(input, parsePosition, startTag, m_tag)) {
				// parsing start or end tag failed
				return false;
			}
			return true;
		} else if (input.substr(parsePosition, 1) == "<") { // [looking at "<"]
#ifdef DEBUG
			std::cout << "Create new CElement and save as child" << std::endl;
#endif
			CElement* childElement = new CElement();
			if(!addToContentChildren((CNode*) childElement)) {
				// adding to content children failed
				return false;
			}
#ifdef DEBUG
			std::cout << "Invoke parseInput() for newly created object" << std::endl;
#endif
			if(!childElement->parseInput(input, parsePosition)) {
				// parse input failed
				return false;
			}
		} else {
#ifdef DEBUG
			std::cout << "Create new CText and invoke parseInput() for newly created object" << std::endl;
#endif
			CText* childText = new CText();
			if(!addToContentChildren((CNode*) childText)) {
				// adding to content children failed
				return false;
			}
			childText->parseInput(input, parsePosition);
		}
	}

	return true;
}

// print all nodes recursively
void CElement::print(int indent) {
	for(int i = 0; i < indent; i++) {
		std::cout << "\t";
	}
	std::cout << "CElement[m_tag=\"" << m_tag << "\"]" << std::endl;

	if (m_contentNodes != 0) {
		// element has children
		for (int i = 0; i < m_contentNodes; i++) {
			// handmade polymorphism
			switch (m_content[i]->getNodeType()) {
			case ELEMENT:
				((CElement*) m_content[i])->print(indent+1);
				break;
			case TEXT:
				((CText*) m_content[i])->print(indent+1);
				break;
			default:
				std::cout << "error: unknown node type " << m_content[i]->getNodeType() << std::endl;
			}
		}
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
		std::cout << "node " << m_tag << " has too many children" << std::endl;
		return false;
	}
}

bool CElement::parseStartOrEndTag(const std::string& input,
		unsigned int& parsePosition, bool& isStartTag, std::string& tag) {
	if (input.substr(parsePosition, 2) == "<"
			&& input.substr(parsePosition + 1, 1) != "/") {
		// this is a start tag
		isStartTag = true;
		parsePosition++;
	} else if (input.substr(parsePosition, 2) == "</") {
		// this is an end tag
		isStartTag = false;
		parsePosition += 2;
	} else {
		std::cout << "expected start or end tag" << std::endl;
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

	parsePosition++;

	return true;
}
