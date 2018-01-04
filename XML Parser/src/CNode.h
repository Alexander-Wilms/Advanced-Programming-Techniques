/*
 * CNode.h
 *
 *  Created on: 04.11.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef SRC_CNODE_H_
#define SRC_CNODE_H_

enum node_t {ELEMENT, TEXT};

class CNode {
public:
	CNode(node_t nodeType);
	virtual ~CNode(); // pure virtual
	virtual node_t getNodeType() = 0;
private:
	node_t m_node;
};

#endif /* SRC_CNODE_H_ */
