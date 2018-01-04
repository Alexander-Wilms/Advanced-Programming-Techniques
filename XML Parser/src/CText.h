/*
 * CText.h
 *
 *  Created on: 04.11.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef SRC_CTEXT_H_
#define SRC_CTEXT_H_

#include "CNode.h"
#include <string>

class CText : public CNode {
public:
	CText();
	virtual ~CText();
	std::string getText();
	void setText(std::string text);
	bool parseInput(const std::string& input, unsigned int& parsePosition);
	void print(int indent);
	virtual node_t getNodeType();
//private:
	std::string m_text;
};

#endif /* SRC_CTEXT_H_ */
