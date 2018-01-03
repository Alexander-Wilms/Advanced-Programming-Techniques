/*
 * CLifoBuffer.h
 *
 *  Created on: 03.11.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef SRC_CLIFOBUFFER_H_
#define SRC_CLIFOBUFFER_H_

#include "CFraction.h"

class CLifoBuffer {
public:
	CLifoBuffer(int size);
	~CLifoBuffer();
	void print();
	bool push(const CFraction& data);
	bool pop(CFraction& data);
private:
	int m_size;
	int m_tos;
	CFraction* m_pBuffer;
};

#endif /* SRC_CLIFOBUFFER_H_ */
