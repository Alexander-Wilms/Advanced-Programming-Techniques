/*
 * CElement.h
 *
 *  Created on: 05.11.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef SRC_CELEMENT_H_
#define SRC_CELEMENT_H_

#include "CNode.h"
#include <string>

class CElement : public CNode {
public:
	CElement();
	virtual ~CElement();
	bool parseInput(const std::string& input, unsigned int& parsePosition);
	void print(int indent);
	virtual node_t getNodeType();
// make everything public for unit testing
// private:
	bool addToContentChildren(CNode* child);
	bool parseStartOrEndTag(const std::string& input, unsigned int& parsePosition, bool& isStartTag, std::string& tag);
	std::string m_tag;
	CNode** m_content; // static array of pointers to CNode objects -> double pointer!
	int m_contentNodes;

};

#endif /* SRC_CELEMENT_H_ */
