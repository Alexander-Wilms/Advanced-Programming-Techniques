/*
 * CLifoBuffer.cpp
 *
 *  Created on: 03.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CLifoBuffer.h"
#include <iostream>

CLifoBuffer::CLifoBuffer(int size) {

	if(2 <= size && size <= 10) {
		m_size = size;
	} else {
		m_size = 5;
	}

	/*
	 * use the actual input-validated value of m_size, not size!
	 * this caused an error that was triggered by a CppUnit test,
	 * and was very hard to debug:
	 *
	 * o run sudo dnf debuginfo-install glibc-2.26-20.fc27.x86_64
	 * o debug
	 */
	m_pBuffer = new CFraction[m_size];

	m_tos = -1;

	//std::cout << "content of m_pBuffer in the constructor:" << std::endl;
	//print();
}

CLifoBuffer::~CLifoBuffer() {
	delete[] m_pBuffer;
}

void CLifoBuffer::print() {
	std::cout << "m_pBuffer address: " << m_pBuffer << std::endl;
	std::cout << "m_pBuffer elements: " << std::endl;
	for(int i = 0; i < m_size; i++) {
		std::cout << "m_pBuffer[" << i << "]: " << m_pBuffer[i] << std::endl;
	}
	std::cout << "m_size: " << m_size << std::endl;
	std::cout << "m_tos: " << m_tos << std::endl;
}

bool CLifoBuffer::push(const CFraction& data) {
	// if there is still memory left
	if(m_tos <= m_size-2) {
		m_tos++;
		m_pBuffer[m_tos] = data;
		return true;
	}

	return false;
}

bool CLifoBuffer::pop(CFraction& data) {
	// if there is still memory left
	if(m_tos >= 0) {
		data = m_pBuffer[m_tos];
		m_tos--;
		return true;
	}

	return false;
}
