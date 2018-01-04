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
	~CElement();
	bool parseInput(const std::string& input, unsigned int& parsePosition);
	void print(int indent);
	node_t getNodeType();
// make everything public for unit testing
// private:
	bool addToContentChildren(CNode* child);
	bool parseStartOrEndTag(const std::string& input, unsigned int& parsePosition, bool& isStartTag, std::string& tag);
	CNode* m_content[10];
	int m_contentNodes;
	std::string m_tag;
};

#endif /* SRC_CELEMENT_H_ */
