/*
 * CLifoBuffer.cpp
 *
 *  Created on: 03.11.2017
 *      Author: awilms
 */

#include "CLifoBuffer.h"
#include <iostream>

CLifoBuffer::CLifoBuffer(int size) {
	m_pBuffer = new CFraction[size];
	m_size = size;
	m_tos = -1;

	print();
}

CLifoBuffer::~CLifoBuffer() {
	delete[] m_pBuffer;
}

void CLifoBuffer::print() {
	std::cout << "m_pBuffer: " << m_pBuffer << std::endl;
	std::cout << "m_pBuffer elements: " << std::endl;
	for(int i = 0; i < m_size; i++) {
		std::cout << "m_pBuffer[" << i << "]: " << m_pBuffer[i] << std::endl;
	}
	std::cout << "m_size: " << m_size << std::endl;
	std::cout << "m_tos: " << m_tos << std::endl;
}

bool CLifoBuffer::push(const CFraction& data) {
	// if there is still memory left
	if(m_tos != m_size) {
		m_tos++;
		m_pBuffer[m_tos] = data;
	}
}

bool CLifoBuffer::pop(CFraction& data) {
	// if there is still memory left
	if(m_tos != -1) {
		data = m_pBuffer[m_tos];
		m_tos--;
	}
}
