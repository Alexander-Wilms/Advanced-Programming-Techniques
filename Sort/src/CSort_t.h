/*
 * CSort.h
 *
 *  Created on: 05.11.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CSORT_T_H_
#define CSORT_T_H_

#include <iostream>
#include <iomanip>

template <typename T>
class CSort_t {
public:
	CSort_t(int initialMaxElements = 10, int addElements = 5);
	~CSort_t();
	void addElement(T a);
	void printList();
	void sortList();
private:
	void quicksort(T* pList, int lo, int hi);
	int partition(T* pList, int lo, int hi);
	int m_numberElements;
	int m_maxElements;
	int m_addElements;
	T* m_pList;
};

template<typename T> CSort_t<T>::CSort_t(int initialMaxElements, int addElements) {
	m_pList = new T[initialMaxElements];
	m_maxElements = initialMaxElements;
	m_addElements = addElements;
	m_numberElements = 0;
}

template<typename T> CSort_t<T>::~CSort_t() {
	delete[] m_pList;
}

template<typename T> void CSort_t<T>::addElement(T a) {
	// if m_pList is full
	if(m_numberElements >= m_maxElements) {
		// allocate a new, bigger array
		T* m_pListCopy = new T[m_maxElements+m_addElements];
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

template<typename T> void CSort_t<T>::printList() {
	std::cout << "[";

	for(int i = 0; i < m_numberElements; i++) {
		std::cout << std::setw(2) << m_pList[i] << " ";
	}
	std::cout << "]" << std::endl;
}

template<typename T> void CSort_t<T>::sortList() {
	quicksort(m_pList, 0, m_numberElements-1);
}

/**
 * https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
 */
template<typename T> void CSort_t<T>::quicksort(T* pList, int lo, int hi) {
	if(lo < hi) {
		int p = partition(pList, lo, hi);
		quicksort(pList, lo, p);
		quicksort(pList, p + 1, hi);
	}
}

template<typename T> int CSort_t<T>::partition(T* pList, int lo, int hi) {
	T pivot = pList[lo];
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

		T tmp;
		tmp = pList[i];
		pList[i] = pList[j];
		pList[j] = tmp;
	}
}

#endif /* CSORT_T_H_ */
