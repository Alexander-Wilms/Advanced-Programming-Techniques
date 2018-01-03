/*
 * CSort.cpp
 *
 *  Created on: 05.11.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CSort.h"
#include <iostream>
#include <iomanip>

CSort::CSort(int initialMaxElements, int addElements) {
	m_pList = new int[initialMaxElements];
	m_maxElements = initialMaxElements;
	m_addElements = addElements;
	m_numberElements = 0;
}

CSort::~CSort() {
	delete[] m_pList;
}

void CSort::addElement(int a) {
	// if m_pList is full
	if(m_numberElements >= m_maxElements) {
		// allocate a new, bigger array
		int* m_pListCopy = new int[m_maxElements+m_addElements];
		// copy the values from the old into the new array
		for(int i = 0; i < m_numberElements; i++) {
			m_pListCopy[i] = m_pList[i];
		}
		// free the memory
		delete[] m_pList;
		// allocate new memory
		m_pList = m_pListCopy;
		m_maxElements += m_addElements;
	}
	m_pList[m_numberElements] = a;
	m_numberElements++;
}

void CSort::printList() {
	std::cout << "[";

	for(int i = 0; i < m_numberElements; i++) {
		std::cout << std::setw(2) << m_pList[i] << " ";
	}
	std::cout << "]" << std::endl;
}

void CSort::sortList() {
	quicksort(m_pList, 0, m_numberElements-1);
}

/**
 * https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
 */
void CSort::quicksort(int* pList, int lo, int hi) {
	if(lo < hi) {
		int p = partition(pList, lo, hi);
		quicksort(pList, lo, p);
		quicksort(pList, p + 1, hi);
	}
}

int CSort::partition(int* pList, int lo, int hi) {
	int pivot = pList[lo];
	int i = lo - 1;
	int j = hi + 1;
	while(true) {
		do {
			i++;
		} while(pList[i] < pivot);

		do {
			j--;
		} while(pList[j] > pivot);

		if(i >= j) {
			return j;
		}

		int tmp;
		tmp = pList[i];
		pList[i] = pList[j];
		pList[j] = tmp;
	}
}
