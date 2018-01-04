/*
 * CNode.cpp
 *
 *  Created on: 04.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CNode.h"

CNode::CNode(node_t nodeType) {
	m_node = nodeType;
}

node_t CNode::getNodeType() {
	return ELEMENT;
}
